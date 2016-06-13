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


#ifndef parse_config_h
#define parse_config_h

#include <stdlib.h>
#include <stdio.h>

#define COMMENT_DELIM '{{data['comment_delim']}}'

struct {{data['struct_type']}} {
    {{data['struct_def_string']}}
};

static inline void empty_config(const char * filepath){
    char fullpath[4096+255]={0};
    strcpy(fullpath,filepath);

    FILE * fid = fopen(fullpath,"w");

    fprintf(fid,

    {{data['empty_config_string']}}

    );

    fclose(fid);
    exit(0);
};

void parse_config(char * config_file, struct {{data['struct_type']}} * structure);

#endif
