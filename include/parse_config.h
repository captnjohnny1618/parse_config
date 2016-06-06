#ifndef parse_config_h
#define parse_config_h

#include <stdlib.h>
#include <stdio.h>

#define STRUCT_TYPE struct recon_params
#define COMMENT_DELIM '%'

struct recon_params {
    char raw_data_dir[4096];
    char raw_data_file[255];
    char output_dir[4096];
    char output_file[255];
    int n_rows;
    float coll_slicewidth;
    float start_pos;
    float end_pos;
    float pitch_value;
    float slice_thickness;
    float acq_fov;
    float recon_fov;
    int recon_kernel;
    int n_readings;
    float x_origin;
    float y_origin;
    int z_ffs;
    int phi_ffs;
    char scanner[4351];
    int file_type;
    int file_subtype;
    int raw_data_offset;
    unsigned int nx;
    unsigned int ny;
    float tube_start_angle;
    float adaptive_filtration_s;
    int n_slices;
};
inline void empty_config(const char * filepath){
char fullpath[4096+255]={0};
strcpy(fullpath,filepath);

FILE * fid = fopen(fullpath,"w");

fprintf(fid,
"RawDataDir:\n"
"RawDataFile:\n"
"OutputDir:\n"
"OutputFile:\n"
"Nrows:\n"
"CollSlicewidth:\n"
"StartPos:\n"
"EndPos:\n"
"TableFeed:\n"
"SliceThickness:\n"
"AcqFOV:\n"
"ReconFOV:\n"
"ReconKernel:\n"
"Readings:\n"
"Xorigin:\n"
"Yorigin:\n"
"Zffs:\n"
"Phiffs:\n"
"Scanner:\n"
"FileType:\n"
"FileSubType:\n"
"RawOffset:\n"
"Nx:\n"
"Ny:\n"
"TubeStartAngle:\n"
"AdaptiveFiltration:\n"
"NSlices:\n"
);

    fclose(fid);
    exit(0);
};


void parse_config(char * config_file, STRUCT_TYPE * structure);

#endif
