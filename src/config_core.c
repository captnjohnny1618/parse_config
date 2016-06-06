
if (strcmp(token,"RawDataDir:")==0){
    printf("Token \"%s\" detected\n",token);
    token=strtok(NULL," \t");
    sscanf(token,"%s",structure->raw_data_dir);
}
else if (strcmp(token,"RawDataFile:")==0){
    printf("Token \"%s\" detected\n",token);        
    token=strtok(NULL," \t");
    sscanf(token,"%s",structure->raw_data_file);
}
else if (strcmp(token,"OutputDir:")==0){
    printf("Token \"%s\" detected\n",token);        
    token=strtok(NULL," \t");
    sscanf(token,"%s",structure->output_dir);
}
else if (strcmp(token,"OutputFile:")==0){
    printf("Token \"%s\" detected\n",token);        
    token=strtok(NULL," \t");
    sscanf(token,"%s",structure->output_file);
}
else if (strcmp(token,"Nrows:")==0){
    printf("Token \"%s\" detected\n",token);        
    token=strtok(NULL," \t");
    sscanf(token,"%d",&structure->n_rows);
}
else if (strcmp(token,"CollSlicewidth:")==0){
    printf("Token \"%s\" detected\n",token);        
    token=strtok(NULL," \t");
    sscanf(token,"%f",&structure->coll_slicewidth);
}
else if (strcmp(token,"StartPos:")==0){
    printf("Token \"%s\" detected\n",token);        
    token=strtok(NULL," \t");
    sscanf(token,"%f",&structure->start_pos);
}
else if (strcmp(token,"EndPos:")==0){
    printf("Token \"%s\" detected\n",token);        
    token=strtok(NULL," \t");
    sscanf(token,"%f",&structure->end_pos);
}
else if (strcmp(token,"TableFeed:")==0){
    printf("Token \"%s\" detected\n",token);        
    token=strtok(NULL," \t");
    sscanf(token,"%f",&structure->pitch_value);
}
else if (strcmp(token,"PitchValue:")==0){
    printf("Token \"%s\" detected\n",token);        
    token=strtok(NULL," \t");
    sscanf(token,"%f",&structure->pitch_value);
}
else if (strcmp(token,"SliceThickness:")==0){
    printf("Token \"%s\" detected\n",token);        
    token=strtok(NULL," \t");
    sscanf(token,"%f",&structure->slice_thickness);
}
else if (strcmp(token,"AcqFOV:")==0){
    printf("Token \"%s\" detected\n",token);        
    token=strtok(NULL," \t");
    sscanf(token,"%f",&structure->acq_fov);
}
else if (strcmp(token,"ReconFOV:")==0){
    printf("Token \"%s\" detected\n",token);        
    token=strtok(NULL," \t");
    sscanf(token,"%f",&structure->recon_fov);
}
else if (strcmp(token,"ReconKernel:")==0){
    printf("Token \"%s\" detected\n",token);        
    token=strtok(NULL," \t");
    sscanf(token,"%d",&structure->recon_kernel);
}
else if (strcmp(token,"Readings:")==0){
    printf("Token \"%s\" detected\n",token);        
    token=strtok(NULL," \t");
    sscanf(token,"%d",&structure->n_readings);
}
else if (strcmp(token,"Xorigin:")==0){
    printf("Token \"%s\" detected\n",token);        
    token=strtok(NULL," \t");
    sscanf(token,"%f",&structure->x_origin);
}
else if (strcmp(token,"Yorigin:")==0){
    printf("Token \"%s\" detected\n",token);        
    token=strtok(NULL," \t");
    sscanf(token,"%f",&structure->y_origin);
}
else if (strcmp(token,"Zffs:")==0){
    printf("Token \"%s\" detected\n",token);        
    token=strtok(NULL," \t");
    sscanf(token,"%d",&structure->z_ffs);
}
else if (strcmp(token,"Phiffs:")==0){
    printf("Token \"%s\" detected\n",token);        
    token=strtok(NULL," \t");
    sscanf(token,"%d",&structure->phi_ffs);
}
else if (strcmp(token,"Scanner:")==0){
    printf("Token \"%s\" detected\n",token);        
    token=strtok(NULL," \t");
    sscanf(token,"%s",structure->scanner);
}
else if (strcmp(token,"FileType:")==0){
    printf("Token \"%s\" detected\n",token);        
    token=strtok(NULL," \t");
    sscanf(token,"%d",&structure->file_type);
}
else if (strcmp(token,"FileSubType:")==0){
    printf("Token \"%s\" detected\n",token);        
    token=strtok(NULL," \t");
    sscanf(token,"%d",&structure->file_subtype);
}
else if (strcmp(token,"RawOffset:")==0){
    printf("Token \"%s\" detected\n",token);        
    token=strtok(NULL," \t");
    sscanf(token,"%d",&structure->raw_data_offset);
}
else if (strcmp(token,"Nx:")==0){
    printf("Token \"%s\" detected\n",token);        
    token=strtok(NULL," \t");
    sscanf(token,"%u",&structure->nx);
}
else if (strcmp(token,"Ny:")==0){
    printf("Token \"%s\" detected\n",token);        
    token=strtok(NULL," \t");
    sscanf(token,"%u",&structure->ny);
}
else if (strcmp(token,"TubeStartAngle:")==0){
    printf("Token \"%s\" detected\n",token);        
    token=strtok(NULL," \t");
    sscanf(token,"%f",&structure->tube_start_angle);
}
else if (strcmp(token,"AdaptiveFiltration:")==0){
    printf("Token \"%s\" detected\n",token);        
    token=strtok(NULL," \t");
    sscanf(token,"%f",&structure->adaptive_filtration_s);
}
else if (strcmp(token,"NSlices:")==0){
    printf("Token \"%s\" detected\n",token);        
    token=strtok(NULL," \t");
    sscanf(token,"%d",&structure->n_slices);
}
else{
    printf("Warning: token \"%s\" not recognized\n",token);
}