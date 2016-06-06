SRC_DIR=$(shell pwd)/

all: rebuild

rebuild:
	mkdir -p src/obj
	$(MAKE) -C src ../parse_sample

.PHONY: all clean

clean:
	$(MAKE) -C src clean
