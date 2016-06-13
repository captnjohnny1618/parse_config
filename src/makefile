CC=gcc

EXE_NAME=parse_sample

ODIR=obj

IDIR=../include
INCLUDES=-I$(IDIR)

LIBS=

CFLAGS=$(INCLUDES) -g -Wall -std=c99

_OBJ=parse_config.o main.o 
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ));

all: compile_source ../$(EXE_NAME)

compile_source: ../$(wildcard *.tpl) config_dict.txt
	(cd scripts/ && python compile_source.py ../config_dict.txt)
	mv scripts/*.c ./
	mv scripts/*.h ../include/

../$(EXE_NAME): $(OBJ)
	(cd obj && $(CC) -g -o ../../$(EXE_NAME) *.o $(LIBS))

obj/main.o: main.c
	$(CC) $(CFLAGS) -c -o $@ $<

obj/parse_config.o: parse_config.c
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: all test clean

clean:
	rm obj/*.o; rm -rf ../*~

