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

send_to_ctbb:
	cp -u build/parse_config.h ../CTBangBang/include/
	cp -u build/parse_config.c ../CTBangBang/src/parse_config.cu

send_to_ctbb_icd:
	cp -u build/parse_config.h ../CTBangBang_ICD/src/
	cp -u build/parse_config.c ../CTBangBang_ICD/src/parse_config.cpp

.PHONY: all clean

clean:
	$(MAKE) -C src clean
