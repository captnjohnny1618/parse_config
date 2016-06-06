#ifndef parse_config_h
#define parse_config_h

#include <recon_structs.h>

#define STRUCT_TYPE struct recon_params

void parse_config(char * config_file, STRUCT_TYPE * structure);

#endif
