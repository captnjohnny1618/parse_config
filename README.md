# parse_config

## A little code generator for parsing CTBangBang style config files

This tool quickly generates the header and source files to parse tab-delimited, comment-able configuration files.

## How it works

The makefile calls "src/scripts/compile_source.py" which in turn reads from the "src/config_dict.txt" to generate our source code.  A sample program is created ready to parse the config files. Copies of the generated source is also placed in the "build/" directory to be copied into the final project directory.  

## License

GNU GPLv2

Copyright 2016 John Hoffman