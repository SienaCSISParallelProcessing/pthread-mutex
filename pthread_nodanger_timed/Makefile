# Makefile for pthread no danger program
#
# Jim Teresco, CS 338, Williams College
# CS 341, Mount Holyoke College
# CS 400, Siena College
#
CFILES=pthread_nodanger.c timer.c
OFILES=$(CFILES:.c=.o)
CC=gcc
CFLAGS=-g

pthread_nodanger:	$(OFILES)
	$(CC) -o pthread_nodanger $(OFILES) -lpthread

clean::
	/bin/rm -f pthread_nodanger $(OFILES)
