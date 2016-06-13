import sys
import os
import csv
import jinja2
import argparse
from argparse import ArgumentParser

def main():

    parser=ArgumentParser(description="Generate C source and header files for parsing configuration files")
    parser.add_argument("config_dict",help='File containing the configuration dictionary.',type=argparse.FileType('r'))
    args=parser.parse_args()
    f=args.config_dict

    template_path=r"../../resources"

    # Prepare our input data
    data=compile_strings(f)

    # Call jinja to actually run the templating
    loader = jinja2.FileSystemLoader(searchpath=template_path)
    env = jinja2.Environment(loader=loader)
    vars = {
        "data":data,
    }
    
    # Render our source
    template = env.get_template("parse_config_src.tpl")
    with open("parse_config.c","w") as f:
        f.write(template.render(vars))
    
    # Render our header    
    template = env.get_template("parse_config_header.tpl")    
    with open("parse_config.h","w") as f:    
        f.write(template.render(vars))



        
def generate_code_string(row,i):
    
    type_dict={
        "int":"%d",
        "unsigned int":"%u",
        "float":"%f",
        "char":"%s"
    }
    
    if row['array_size']=='':
        struct_dest_str="&structure->%s" % (row['struct_field']);
    else:
        struct_dest_str="structure->%s" % (row['struct_field']);

    if i==0:
        code_string="""
if (strcmp(token,\"%s\")==0){
    printf("Token \\"%%s\\" detected\\n",token);
    token=strtok(NULL," \\t");
    sscanf(token,\"%s\",%s);
}""" % (row['token'],type_dict[row['type']],struct_dest_str)

    else:
        code_string="""
else if (strcmp(token,\"%s\")==0){
    printf("Token \\"%%s\\" detected\\n",token);        
    token=strtok(NULL," \\t");
    sscanf(token,\"%s\",%s);
}""" % (row['token'],type_dict[row['type']],struct_dest_str)

    return code_string

def neighborhood(iterable):
    iterator = iter(iterable)
    prev = None
    item = iterator.next()  # throws StopIteration if empty.
    for next in iterator:
        yield (prev,item,next)
        prev = item
        item = next
    yield (prev,item,None)
    
def compile_strings(f):
    # Declare strings we will return
    config_core_str=""
    config_struct_str=""
    config_empty_file_str=""
    
    struct_name=f.readline().rstrip('\n')
    comment_delim=f.readline().rstrip('\n')
    
    rest_of_file=f.read()
    with open("temp.csv","w") as f:
        f.write(rest_of_file)

    with open("temp.csv","r") as csvfile:
        i=0;
        reader=csv.DictReader(csvfile)
        for prev_row,row,next_row in neighborhood(reader):
            # Add to config core string
            config_core_str += generate_code_string(row,i)
            
            # Add to empty config file function creation string
            config_empty_file_str += ('"%s\\n"\n' % row['token']);

            # Add to structure definition string
            # Check to make sure we're not declaring two of the same field (if we have two possible names for the same thing)
            if prev_row != None:
                if prev_row['struct_field']==row['struct_field']:
                    continue

            if row['array_size']=='':
                config_struct_str=config_struct_str + ("    %s %s;\n" % (row['type'],row['struct_field']))
            else:
                config_struct_str=config_struct_str + ("    %s %s[%s];\n" % (row['type'],row['struct_field'],row['array_size']))

        string_dict={
            "struct_type":struct_name,
            "comment_delim":comment_delim,
            "config_core":config_core_str,
            "empty_config_string":config_empty_file_str,
            "struct_def_string":config_struct_str
        }


        os.remove("temp.csv")
        return string_dict

if __name__=="__main__":
    main()
