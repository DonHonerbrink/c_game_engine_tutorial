//********************************************************************
// OPENGL: Helper functions for kek 
//********************************************************************
int kgl_shader_compile(ql_uint shaderid, const char *code, char *error_buffer, size_t error_buffer_capacity);
int kgl_shader_program_link(gl_uint shader_program_id, gl_uint *shaders, size_t count);
int kgl_shader_program_create(gl_uint *shader_program, const char *vertfile, const char *fragfile);
int kgl_texture_load_file(gl_uint texture, const char *file, unsigned int *width, unsigned int *height);
int kgl_texture_bind_array(gl_uint *textures, int count);
