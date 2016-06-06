import os
import sys
import csv

with open("config_dict.txt","r") as f:
   struct_type=f.readline().rstrip()
   comment_delim=f.readline().rstrip()
   rest_of_file=f.read()

with open("temp.csv","w") as f:
    f.write(rest_of_file);

struct_def_string="""struct %s {
""" % (struct_type)

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

        if row['array_size']=='':
            struct_def_string=struct_def_string + ("    %s %s;\n" % (row['type'],row['struct_field']))
        else:
            struct_def_string=struct_def_string + ("    %s %s[%s];\n" % (row['type'],row['struct_field'],row['array_size']))


struct_def_string=struct_def_string+"};"
            
header_string="""#ifndef parse_config_h
#define parse_config_h

#define STRUCT_TYPE struct %s
#define COMMENT_DELIM '%s'

%s

void parse_config(char * config_file, STRUCT_TYPE * structure);

#endif
""" % (struct_type,comment_delim,struct_def_string)

with open("parse_config.h","w") as f:
    f.write(header_string);
