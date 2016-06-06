import os
import sys
import csv

type_dict={
    "int":"%d",
    "unsigned int":"%u",
    "float":"%f",
    "char":"%s"
}

with open("config_dict.txt","r") as f:

    # Read first line to get the structure name
    target_struct_name=f.readline().rstrip('\n')
    print("Target structure: %s" % (target_struct_name));

    # Read second line to get comment identifier
    comment_delim=f.readline().rstrip('\n')
    print("Comment delimeter: %s" % (comment_delim));

    # Parse rest of file as CSV
    rest_of_file=f.read();

with open("temp.csv","w") as f:
    f.write(rest_of_file);

def generate_code_string(row,i):
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

def printout(f,s):
    f.write(s)

output_file="config_core.c"
f=open(output_file,"w");
    
with open("temp.csv","r") as csvfile:
    i=0;
    reader=csv.DictReader(csvfile)
    for row in reader:
        printout(f,generate_code_string(row,i))

        i+=1
        
    #finally:
    printout(f,"""
else{
    printf("Warning: token \\"%s\\" not recognized\\n",token);
}""")

# Get rid of our temporary file
os.remove("temp.csv")
f.close()
