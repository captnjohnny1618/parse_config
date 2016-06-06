#ifndef parse_config_h
#define parse_config_h

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

void parse_config(char * config_file, STRUCT_TYPE * structure);

#endif
