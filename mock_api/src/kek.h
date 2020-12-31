#include "kut.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

//********************************************************************
// ENGINE: Memory and configuration management.
//********************************************************************
typedef enum KEKReturn KEKReturn;
typedef enum KEKSceneTween KEKSceneTween;
typedef union KEKObjectId KEKObjectId;
typedef struct KEKCameraSequence KEKCameraSequence;
typedef struct KEKParticleAttribValue KEKParticleAttribValue;
typedef uint32_t KEKEntityType;
typedef uint32_t KEKSceneKey;
typedef uint32_t KEKSoundKey;
typedef uint32_t KEKShaderKey;
typedef uint32_t KEKVertexBufferKey;
typedef uint32_t KEKVertexAttributeType; // todo: make enum
typedef uint32_t KEKTextureKey;
typedef uint32_t KEKTextureClipKey;
typedef uint32_t KUTMaterialMapKey;
typedef uint32_t KUTMaterialConfigKey;
typedef uint32_t KUTMaterialKey;
typedef uint32_t KEKRenderPassKey;
typedef uint32_t KEKMeshConfigKey;
typedef uint32_t KEKMeshKey;
typedef uint32_t KEKModelConfigKey;
typedef uint32_t KEKModelKey;
typedef uint32_t KEKSpriteAnimationConfigKey;
typedef uint32_t KEKSpriteAnimationKey;
typedef uint32_t KEKParticleConfigKey;
typedef uint32_t KEKParticleKey;
typedef uint32_t KEKLightConfigKey;
typedef uint32_t KEKLightAttribValue;
typedef uint32_t KEKLightKey;
typedef uint32_t KEKRenderPassKey;
typedef uint32_t KEKRenderPassFilter;
typedef uint32_t KEKRenderPipelineKey;
typedef void (*KEKSceneTransitionFn)(KEKSceneKey key, float elapsed, float duration, void *ctx);
typedef void (*KEKRenderPassFn)(void);
typedef void (*KEKEntityInitFn)(void);
typedef void (*KEKEntityUpdateFn)(void);
typedef void (*KEKEntityTerminateFn)(void);
typedef void (*KEKEntityRenderFn)(void);
typedef void (*KEKCameraMoveFn)(void);
typedef void (*KEKMousePositionFn)(void);
typedef void (*KEKMousePressFn)(void);
typedef void (*KEKCommandFn)(void);
typedef void (*KEKEventFn)(void);
typedef void (*KEKAliasFn)(void);

union KEKObjectId {
    struct {
        uint32_t type: 8;
        uint32_t counter: 24;
    };
    int32_t raw;
};

enum KEKReturn {
    KEK_OK,
    KEK_ERROR,
    KEK_INIT_ERROR,
    KEK_BAD_PARAM,
    KEK_UNKNOWN_ERROR,
    KEK_NOT_IMPLEMENTED,
    KEK_WINDOW_OPEN_FAIL,
    KEK_WINDOW_ALREADY_OPEN,
    KEK_WINDOW_NOT_OPEN,
    KEK_WINDOW_SWAP_BUFFER_ERROR,
    KEK_WINDOW_POLL_ERROR,
    KEK_WINDOW_SET_SIZE_ERROR,
    KEK_WINDOW_GET_SIZE_ERROR,

};

// private
struct KEKObject {
    KEKObjectId id;
    //KUTVec3 position;

    //union {
        //KEKSpriteAnimation sprite_animation;
        //KEKLight light;
        //KEKParticle particle;
        //KEKTexture texture;
    //};
};
// game engine specific functions
// do things like load textures with a key value pair and manage resources

// engine calls calls externed function void KEKUserMain(int argc, char **argv)
// kek_user_enter() is responsible for game setup and starting the game engine
// kek_user_exit() is called when kek_run_loop() completes

//**********************************************************
// window 
//**********************************************************
KEKReturn kek_window_set_title(const char *title);
KEKReturn kek_window_set_size(unsigned int width, unsigned int height);
KEKReturn kek_window_get_size(unsigned int *width, unsigned int *height);
KEKReturn kek_window_open(const char *title, unsigned int width, unsigned int height);

//**********************************************************
// commands expect some form of processing to occur and are typically deferred
//**********************************************************
KEKReturn kek_command_add_callback(int type, KEKCommandFn callback, void *ctx);
KEKReturn kek_command_remove_callback(int type, KEKCommandFn callback, void *ctx);
KEKReturn kek_command_submit(int type, void *data);

//**********************************************************
// events do not expect any form of processing and are executed immediately 
//**********************************************************
KEKReturn kek_event_add_callback(int type, KEKEventFn callback, void *ctx);
KEKReturn kek_event_remove_callback(int type, KEKEventFn callback, void *ctx);
KEKReturn kek_event_submit(int type, void *data);

//**********************************************************
// key binding
//**********************************************************
KEKReturn kek_alias_bind_keyboard_key(int alias, int keyboard);
KEKReturn kek_alias_bind_mouse(int alias, int mouse_key);
KEKReturn kek_alias_add_callback(int alias, KEKAliasFn callback, void *ctx);
KEKReturn kek_alias_remove_callback(int alias, KEKAliasFn callback, void *ctx);
bool kek_alias_is_pressed(int alias);
bool kek_alias_is_pressed_frame(int alias);

//**********************************************************
// raw mouse callbacks
//**********************************************************
KEKReturn kek_mouse_add_press_callback(int mouse_button, KEKMousePressFn callback, void *ctx);
KEKReturn kek_mouse_remove_press_callback(int mouse_button, KEKMousePressFn callback, void *ctx);
KEKReturn kek_mouse_position_add_callback(KEKMousePositionFn callback, void *ctx);
KEKReturn kek_mouse_position_remove_callback(KEKMousePositionFn callback, void *ctx);

//**********************************************************
// camera
//**********************************************************
KEKReturn kek_camera_create(KEKObjectId *object_id);
KEKReturn kek_camera_set_target(KEKObjectId id, KUTVec3 target);
KEKReturn kek_camera_set_position(KEKObjectId id, KUTVec3 position);
KEKReturn kek_camera_tween(KUTVec3 camera_destination, KUTVec3 target_destination, float time, KUTTweenType tween_type);
KEKReturn kek_camera_move(KUTVec3 destination, float time, KEKCameraMoveFn callback);
KEKReturn kek_camera_run_sequence(KEKCameraSequence *sequence);
bool kek_camera_is_moving(KEKObjectId *object_id);

//**********************************************************
// entity
//**********************************************************
// Memory laid out in the following
// |E|G|E|G|E|G|E|G|E|G|E|G|E|G where
// E = entity struct, G = custom game data struct
// functions are used to allocate and determine stride lengths for the 
// entity structure
KEKReturn kek_entity_set_user_data_size(size_t user_data_size);
KEKReturn kek_entity_set_max_entities(size_t max_entities);
KEKReturn kek_entity_set_init_callback(KEKEntityType type, KEKEntityInitFn callback);
KEKReturn kek_entity_set_update_callback(KEKEntityType type, KEKEntityUpdateFn callback);
KEKReturn kek_entity_set_terminate_callback(KEKEntityType type, KEKEntityTerminateFn callback);
KEKReturn kek_entity_set_render_callback(KEKEntityType type, KEKEntityRenderFn callback);
KEKReturn kek_entity_get_user_data(KEKObjectId id, void **user_data);

KEKReturn kek_entity_create(KEKEntityType type, KEKObjectId *id);
KEKReturn kek_entity_delete(KEKObjectId id);

//**********************************************************
// scene
//**********************************************************
KEKReturn kek_scene_create(KEKSceneKey *key);
KEKReturn kek_scene_destroy(KEKSceneKey key);
KEKReturn kek_scene_add_object(KEKSceneKey scene_key, KEKObjectId id);
KEKReturn kek_scene_remove_object(KEKSceneKey scene_key, KEKObjectId id);
KEKReturn kek_scene_set_active(KEKSceneKey key);
KEKReturn kek_scene_set_camera(KEKObjectId id);
KEKReturn kek_scene_start_custom_tween(KEKSceneKey key, KEKSceneTransitionFn callback, void *ctx);
KEKReturn kek_scene_start_tween(KEKSceneKey key, KEKSceneTween tween);

//**********************************************************
//sound
//**********************************************************
KEKReturn kek_sound_create(KEKSoundKey *key);
KEKReturn kek_sound_load(KEKSoundKey key, const char *file);
KEKReturn kek_sound_free(KEKSoundKey key);

//**********************************************************
// shader
//**********************************************************
KEKReturn kek_shader_create(KEKShaderKey *key);
KEKReturn kek_shader_destroy(KEKShaderKey key);
KEKReturn kek_shader_load(KEKShaderKey key, const char *file);
KEKReturn kek_shader_free(KEKShaderKey key);
KEKReturn kek_shader_bind(KEKShaderKey key);
KEKReturn kek_shader_set_uniform_i(KEKShaderKey key, int value);
KEKReturn kek_shader_set_uniform_ui(KEKShaderKey key, unsigned int value);
KEKReturn kek_shader_set_uniform_f(KEKShaderKey key, float value);
KEKReturn kek_shader_set_uniform_vec2(KEKShaderKey key, const KUTVec2 *value);
KEKReturn kek_shader_set_uniform_vec3(KEKShaderKey key, const KUTVec3 *value);
KEKReturn kek_shader_set_uniform_vec4(KEKShaderKey key, const KUTVec4 *value);
KEKReturn kek_shader_set_uniform_mat4(KEKShaderKey key, const KUTMat4 *value);

//**********************************************************
// vertex buffer for raw operations
//**********************************************************
KEKReturn kek_vertex_buffer_create(KEKVertexBufferKey *key);
KEKReturn kek_vertex_buffer_destroy(KEKVertexBufferKey key);
KEKReturn kek_vertex_buffer_get_capacity(KEKVertexBufferKey key);
KEKReturn kek_vertex_buffer_set_capacity(KEKVertexBufferKey key, size_t capacity);
KEKReturn kek_vertex_buffer_get_size(KEKVertexBufferKey key);
KEKReturn kek_vertex_buffer_clear(KEKVertexBufferKey key);
KEKReturn kek_vertex_buffer_set_attributes(KEKVertexBufferKey key, KEKVertexAttributeType *types, size_t count);
KEKReturn kek_vertex_buffer_write(KEKVertexBufferKey key, uint8_t *data, size_t size);
KEKReturn kek_vertex_buffer_peek(KEKVertexBufferKey key, uint8_t **data);

//todo: design note - under the hood, write() and peek() will manage auto-mapping of buffers
//the functions below will likely be static in a .c file 
KEKReturn kek_vertex_buffer_map_begin(KEKVertexBufferKey key);
KEKReturn kek_vertex_buffer_map_end(KEKVertexBufferKey key);

//**********************************************************
// textures
//**********************************************************
KEKReturn kek_texture_load(KEKTextureKey key, const char *file);
KEKReturn kek_texture_free(KEKTextureKey key);
KEKReturn kek_texture_size(KEKTextureKey key);
KEKReturn kek_texture_bind(KEKTextureKey key, unsigned int index);

//**********************************************************
// texture clips
//**********************************************************
KEKReturn kek_texture_clip_create(KEKTextureClipKey *key, KEKTextureKey texture_key);
KEKReturn kek_texture_clip_destroy(KEKTextureClipKey key);
KEKReturn kek_texture_clip_get_size(KEKTextureClipKey id, unsigned int *width, unsigned int *height);

//**********************************************************
// material maps (i.e. albedo, metallic, diffuse, normal, occlusion, etc)
//**********************************************************
KEKReturn kek_material_map_create(KUTMaterialMapKey *key);
KEKReturn kek_material_map_destroy(KUTMaterialMapKey key);
KEKReturn kek_material_map_set_texture(KUTMaterialMapKey key, KEKTextureKey texture_id);
KEKReturn kek_material_map_set_value_f(KUTMaterialMapKey key, float value);
KEKReturn kek_material_map_set_value_vec2(KUTMaterialMapKey key, const KUTVec2 *value);
KEKReturn kek_material_map_set_value_vec3(KUTMaterialMapKey key, const KUTVec3 *value);
KEKReturn kek_material_map_set_value_vec4(KUTMaterialMapKey key, const KUTVec4 *value);

//**********************************************************
// materials
//**********************************************************
KEKReturn kek_material_config_create(KUTMaterialConfigKey *key, const char *file);
KEKReturn kek_material_config_destroy(KUTMaterialConfigKey key);

KEKReturn kek_material_create(KUTMaterialKey *key);
KEKReturn kek_material_load(KUTMaterialKey key, KUTMaterialConfigKey config);
KEKReturn kek_material_destroy(KUTMaterialKey key);
KEKReturn kek_material_get_shader(KUTMaterialKey key, KEKShaderKey *shader);
KEKReturn kek_material_set_shader(KUTMaterialKey key, KEKShaderKey shader);
KEKReturn kek_material_get_maps(KUTMaterialKey key, const KUTMaterialMapKey *maps, size_t count);
KEKReturn kek_material_set_maps(KUTMaterialKey key, KUTMaterialMapKey **maps, size_t *count);
KEKReturn kek_material_get_render_pass(KUTMaterialKey key, KEKRenderPassKey *render_pass);
KEKReturn kek_material_set_render_pass(KUTMaterialKey key, const KEKRenderPassKey *render_pass);

//**********************************************************
// meshes
//**********************************************************
KEKReturn kek_mesh_config_create(KEKMeshConfigKey *key, const char *file);
KEKReturn kek_mesh_config_destroy(KEKMeshConfigKey key);

KEKReturn kek_mesh_create(KEKMeshKey *key);
KEKReturn kek_mesh_load(KEKMeshKey key, KEKMeshConfigKey config);
KEKReturn kek_mesh_destroy(KEKMeshKey key);
KEKReturn kek_mesh_get_vertices(KEKMeshKey key, KUTVec3 **vertices, size_t *count);
KEKReturn kek_mesh_set_vertices(KEKMeshKey key, KUTVec3 *vertices, size_t count);

//**********************************************************
// models
//**********************************************************
KEKReturn kek_model_config_create(KEKModelConfigKey *key, const char *file);
KEKReturn kek_model_config_destroy(KEKModelConfigKey key);

KEKReturn kek_model_create(KEKModelKey *key);
KEKReturn kek_model_load(KEKModelKey model_config_key, KEKModelConfigKey config);
KEKReturn kek_model_destroy(KEKModelKey key);
KEKReturn kek_model_add_material(KEKModelKey key, KUTMaterialKey material);
KEKReturn kek_model_add_materials(KEKModelKey key, KUTMaterialKey *material, size_t count);
KEKReturn kek_model_get_materials(KEKModelKey key, KUTMaterialKey **materials, size_t *count);
KEKReturn kek_model_add_mesh(KEKModelKey key, KEKMeshKey mesh);
KEKReturn kek_model_add_meshes(KEKModelKey key, KEKMeshKey *meshes, size_t count);
KEKReturn kek_model_get_meshes(KEKModelKey key, KEKMeshKey *meshes, size_t *count);
KEKReturn kek_model_remove_all_materials(KEKModelKey key);
KEKReturn kek_model_remove_all_meshes(KEKModelKey key);
//todo: what about mapping the meshes to the materials?

//**********************************************************
// sprites
//**********************************************************
KEKReturn kek_sprite_animation_config_create(KEKSpriteAnimationConfigKey *key, const char *config_file);
KEKReturn kek_sprite_animation_config_destroy(KEKSpriteAnimationConfigKey key);

// can this be somehow used with model/material configs?
KEKReturn kek_sprite_animation_create(KEKSpriteAnimationKey *key);
KEKReturn kek_sprite_animation_load(KEKSpriteAnimationKey key, KEKSpriteAnimationConfigKey config);
KEKReturn kek_sprite_animation_destroy(KEKSpriteAnimationKey id);

//**********************************************************
// particle system
//**********************************************************
KEKReturn kek_particle_config_load(KEKParticleConfigKey key, const char *config_file);
KEKReturn kek_particle_config_free(KEKParticleConfigKey key);

KEKReturn kek_particle_create(KEKParticleKey *key);
KEKReturn kek_particle_load(KEKParticleKey key, KEKParticleConfigKey config);
KEKReturn kek_particle_destroy(KEKParticleKey key);
KEKReturn kek_particle_set_attrib(KEKParticleKey key, unsigned int attrib_id, const KEKParticleAttribValue *attrib);
KEKReturn kek_particle_get_attrib(KEKParticleKey key, unsigned int attrib_id, KEKParticleAttribValue *attrib);

//**********************************************************
// lighting
//**********************************************************
KEKReturn kek_light_config_load(KEKLightConfigKey key, const char *config_file);
KEKReturn kek_light_config_free(KEKLightConfigKey key);

KEKReturn kek_light_create(KEKLightKey *key);
KEKReturn kek_light_load(KEKLightKey key, KEKLightConfigKey config);
KEKReturn kek_light_destroy(KEKLightKey key);
KEKReturn kek_light_set_attrib(KEKLightKey key, unsigned int attrib_id, const KEKLightAttribValue *attrib);
KEKReturn kek_light_get_attrib(KEKLightKey  id, unsigned int attrib_id, KEKLightAttribValue *attrib);

//**********************************************************
// render pass
//**********************************************************
KEKReturn kek_render_pass_create(KEKRenderPassKey *key);
KEKReturn kek_render_pass_destroy(KEKRenderPassKey key);
KEKReturn kek_render_pass_get_default(KEKRenderPassKey *key);
KEKReturn kek_render_pass_set_proc_callback(KEKRenderPassKey key, KEKRenderPassFn fn, void *ctx);
KEKReturn kek_render_pass_set_filter_mask(KEKRenderPassKey key, KEKRenderPassFilter mask);
KEKReturn kek_render_pass_set_enabled(KEKRenderPassKey key, bool enable);
KEKReturn kek_render_pass_is_enabled(KEKRenderPassKey key);

//**********************************************************
// render pipeline
//**********************************************************
KEKReturn kek_render_pipeline_create(KEKRenderPipelineKey *key);
KEKReturn kek_render_pipeline_destroy(KEKRenderPipelineKey key);
KEKReturn kek_render_pipeline_remove_passes(KEKRenderPipelineKey key);
KEKReturn kek_render_pipeline_add_pass(KEKRenderPipelineKey key, KEKRenderPassKey pass);
KEKReturn kek_render_pipeline_remove_pass(KEKRenderPipelineKey key, KEKRenderPassKey pass);
KEKReturn kek_render_pipeline_get_pass_count(KEKRenderPipelineKey key, size_t *count);
KEKReturn kek_render_pipeline_set_pass(KEKRenderPipelineKey key, KEKRenderPassKey pass, unsigned int index);
KEKReturn kek_render_pipeline_insert_pass(KEKRenderPipelineKey key, KEKRenderPassKey pass, unsigned int index);



