SRC_DIR=$(shell pwd)/

all: mksrc rebuild

mksrc:
	mkdir -p build/
	$(MAKE) -C src compile_source
	cp src/parse_config.c build/
	cp include/parse_config.h build/

rebuild:
	mkdir -p src/obj	
	$(MAKE) -C src ../parse_sample

.PHONY: all clean

clean:
	$(MAKE) -C src clean
