# Makefile for pthread danger program
#
# Jim Teresco, CS 338, Williams College
# CS 341, Mount Holyoke College
# CS 400, Siena College
#
CFILES=pthread_danger.c
OFILES=$(CFILES:.c=.o)
CC=gcc
CFLAGS=-g

pthread_danger:	$(OFILES)
	$(CC) -o pthread_danger $(OFILES) -lpthread

clean::
	/bin/rm -f pthread_danger $(OFILES)
