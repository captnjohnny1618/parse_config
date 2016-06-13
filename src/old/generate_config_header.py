import os
import sys
import csv

### Open up our dictionary file and parse contents
with open("config_dict.txt","r") as f:
   struct_type=f.readline().rstrip()
   comment_delim=f.readline().rstrip()
   rest_of_file=f.read()

with open("temp.csv","w") as f:
    f.write(rest_of_file);

### BUILD our structure definition and empty configuration file
### creation function strings
struct_def_string="""struct %s {
""" % (struct_type)

empty_config_string="""inline void empty_config(const char * filepath){
char fullpath[4096+255]={0};
strcpy(fullpath,filepath);

FILE * fid = fopen(fullpath,"w");

fprintf(fid,
"""

def neighborhood(iterable):
    iterator = iter(iterable)
    prev = None
    item = iterator.next()  # throws StopIteration if empty.
    for next in iterator:
        yield (prev,item,next)
        prev = item
        item = next
    yield (prev,item,None)
    
with open("temp.csv","r") as csvfile:
    reader=csv.DictReader(csvfile);
    for prev_row,row,next_row in neighborhood(reader):
        if prev_row != None:
            if prev_row['struct_field']==row['struct_field']:
                continue

        # Add to empty_config function creation
        empty_config_string += ('"%s\\n"\n' % row['token']);
                
        # Add to structure definition string        
        if row['array_size']=='':
            struct_def_string=struct_def_string + ("    %s %s;\n" % (row['type'],row['struct_field']))
        else:
            struct_def_string=struct_def_string + ("    %s %s[%s];\n" % (row['type'],row['struct_field'],row['array_size']))


# Close the struct_def and empty config strings            
struct_def_string=struct_def_string+"};"
empty_config_string+=""");

    fclose(fid);
    exit(0);
};
"""

### Create our final header string and write to file
header_string="""#ifndef parse_config_h
#define parse_config_h

#include <stdlib.h>
#include <stdio.h>

#define STRUCT_TYPE struct %s
#define COMMENT_DELIM '%s'

%s
%s

void parse_config(char * config_file, STRUCT_TYPE * structure);

#endif
""" % (struct_type,comment_delim,struct_def_string,empty_config_string)

with open("parse_config.h","w") as f:
    f.write(header_string);

### Clean up our temporary file    
os.remove("temp.csv")    
