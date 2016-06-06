CC=gcc

EXE_NAME=parse_sample

ODIR=obj

IDIR=../include
INCLUDES=-I$(IDIR)

LIBS=

CFLAGS=$(INCLUDES) -g -Wall -std=c99

_OBJ=parse_config.o main.o 
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ));

all: ../$(EXE_NAME)

../$(EXE_NAME): $(OBJ)
	(cd obj && $(CC) -g -o ../../$(EXE_NAME) *.o $(LIBS))

obj/main.o: main.c
	$(CC) $(CFLAGS) -c -o $@ $<

obj/parse_config.o: parse_config.c
	python generate_config_header.py
	mv parse_config.h $(IDIR)/parse_config.h
	python generate_config_core.py
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: all test clean

clean:
	rm obj/*.o; rm -rf ../*~

