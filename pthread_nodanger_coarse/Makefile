# Makefile for pthread no danger program, coarse grained locking
#
# Jim Teresco, CS 338, Williams College
# CS 341, Mount Holyoke College
# CS 400, Siena College
#
CFILES=pthread_nodanger_coarse.c timer.c
OFILES=$(CFILES:.c=.o)
CC=gcc
CFLAGS=-g

pthread_nodanger_coarse:	$(OFILES)
	$(CC) -o pthread_nodanger_coarse $(OFILES) -lpthread

clean::
	/bin/rm -f pthread_nodanger_coarse $(OFILES)
