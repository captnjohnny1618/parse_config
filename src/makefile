CC=gcc

ODIR=obj

IDIR=../include
INCLUDES=-I$(IDIR)

LIBS=

CFLAGS=$(INCLUDES) -g -Wall -std=c99

_OBJ=main.o parse_config.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ));

all: ../a.out

../a.out: $(OBJ)
	(cd obj && $(CC) -g -o ../../a.out *.o $(LIBS))

obj/main.o: main.c $(IDIR)/recon_structs.h
	$(CC) $(CFLAGS) -c -o $@ $<

obj/parse_config.o: parse_config.c $(IDIR)/parse_config.h $(IDIR)/recon_structs.h
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: all test clean

clean:
	rm obj/*.o; rm -rf ../*~

