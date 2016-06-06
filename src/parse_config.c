#include <stdio.h>
#include <string.h>

#include <parse_config.h>
#include <recon_structs.h>

size_t find_char(char * str, char delim){
    int i=0;
    while ((str[i]!=delim)&&(i<strlen(str)))
	i++;

    return i;
}

void parse_config(char * config_file, STRUCT_TYPE * structure){

    FILE * conf=fopen(config_file,"r");
    
    char raw_line[1024];
    char line_no_comments[1024];
    char * token;
	
    while (fgets(raw_line,1024,conf)!=NULL){
	// Strip comments off of the line
	size_t first_delim=find_char(raw_line,'%');
	memcpy(line_no_comments,raw_line,first_delim);	

	// Parse tokens and values
	if (strcmp(line_no_comments,"")!=0&&strcmp(line_no_comments,"\n")!=0){
	    token=strtok(line_no_comments," \t");

#include "config_core.c"
	    
	}
	else{
	}

	memset(line_no_comments,0,1024);
    }

    fclose(conf);
}
