/*
  Pthread no danger!  With timers.

  Jim Teresco
  Williams College
  Mount Holyoke College
  Siena College
*/

/* include some stuff we need */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
/* including the pthread header file */
#include <pthread.h>

#include "timer.h"

/* a shared counter */
int counter;

/* and a mutex to protect modification of the counter */
pthread_mutex_t mutex;

/* This is our thread function */
void *count_up(void *args) {
  int i;

  for (i=0; i<100000; i++) {
    /* before we modify counter, we need to lock the mutex... */
    pthread_mutex_lock(&mutex);
    counter++;
    /* but we don't want to hold the lock any longer than necessary */
    pthread_mutex_unlock(&mutex);
  }

  pthread_exit(0);
}

/* The main program starts here */
int main(int argc, char *argv[]) {

  int numthreads;
  pthread_t *thread_ids;
  pthread_attr_t attr;
  int i, rc;

  struct timeval start, stop;

  /* number of workers is specified on the command-line */
  numthreads=1;
  if (argc > 1) numthreads=atoi(argv[1]);
  printf("Creating %d child threads.\n", numthreads);

  thread_ids = (pthread_t *)malloc(numthreads*sizeof(pthread_t));

  /* some pthread setup */
  pthread_setconcurrency(numthreads+1);
  pthread_attr_init(&attr);
  pthread_attr_setscope(&attr, PTHREAD_SCOPE_PROCESS);

  /* initialize our counter */
  counter=0;

  /* initialize the mutex for concurrent access to counter */
  pthread_mutex_init(&mutex, NULL);

  /* start timing right before firing up threads */
  gettimeofday(&start, NULL);

  /* start threads */
  for (i=0; i<numthreads; i++) {
    rc=pthread_create(&(thread_ids[i]), &attr, count_up, NULL);
    if (rc != 0) {
      fprintf(stderr, "Could not create thread %d\n", i);
      exit(1);
    }
  }

  /* threads working.... */

  /* wait for threads to finish */
  for (i=0; i<numthreads; i++) {
    pthread_join(thread_ids[i], NULL);
  }
 
  /* done counting, stop the timer */
  gettimeofday(&stop, NULL);
  printf("Counting took: %f seconds\n", diffgettime(start,stop));

  pthread_mutex_destroy(&mutex);
  free(thread_ids);

  /* Print counter */
  printf("counter is %d\n", counter);

  /* and be done. */
  return 0;
}
