/* FreeCT_wFBP is GPU and CPU CT reconstruction Software */
/* Copyright (C) 2015  John Hoffman */

/* This program is free software; you can redistribute it and/or */
/* modify it under the terms of the GNU General Public License */
/* as published by the Free Software Foundation; either version 2 */
/* of the License, or (at your option) any later version. */

/* This program is distributed in the hope that it will be useful, */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/* GNU General Public License for more details. */

/* You should have received a copy of the GNU General Public License */
/* along with this program; if not, write to the Free Software */
/* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA. */

/* Questions and comments should be directed to */
/* jmhoffman@mednet.ucla.edu with "CTBANGBANG" in the subject line*/

/* This file was automatically generated using a code-generation
   script.  Changes made directly to the .c file will likely be
   overwritten.  If you have suggested changes to the script we may
   implement them in the templates.  Please contact
   freect.project@gmail.com.*/

#include <stdio.h>
#include <string.h>

#include <parse_config.h>

size_t find_char(char * str, char delim){
    int i=0;
    while ((str[i]!=delim)&&(i<strlen(str)))
	i++;

    return i;
}

void parse_config(char * config_file, struct {{data['struct_type']}} * structure){

    FILE * conf=fopen(config_file,"r");
    
    char raw_line[1024];
    char line_no_comments[1024];
    char * token;
	
    while (fgets(raw_line,1024,conf)!=NULL){
	// Strip comments off of the line
	size_t first_delim=find_char(raw_line,COMMENT_DELIM);
	memcpy(line_no_comments,raw_line,first_delim);	

	// Parse tokens and values
	if (strcmp(line_no_comments,"")!=0&&strcmp(line_no_comments,"\n")!=0){
	    token=strtok(line_no_comments," \t");

	    {{data['config_core']}}

	}
	else{
	}

	memset(line_no_comments,0,1024);
    }

    fclose(conf);
}
