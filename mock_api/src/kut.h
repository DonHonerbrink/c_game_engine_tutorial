#pragma once
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct KUTRandom KUTRandom;
typedef struct KUTVec2 KUTVec2;
typedef struct KUTVec3 KUTVec3;
typedef struct KUTVec4 KUTVec4;
typedef struct KUTMat4 KUTMat4;
typedef struct KUTRect2 KUTRect2;
typedef struct KUTCube KUTCube;
typedef enum KUTTweenType KUTTweenType;

//********************************************************************
// UTILITY: Common utilities that do not maintain state
//********************************************************************
#ifdef KUT_STRIP_NAMESPACE
// all typedefs would be in here and would strip out the prefix. I.E.
//KUTRandom -> Random
//KUTVec3 -> Vec3
#endif

// random
int kut_random_init(KUTRandom *random, uint32_t seed);
int kut_random_get_u32(KUTRandom *random, uint32_t *value);
int kut_random_get_f(KUTRandom *random, float *value);
int kut_random_get_v2(KUTRandom *random, KUTVec2 *value);
int kut_random_get_v3(KUTRandom *random, KUTVec3 *value);
int kut_random_get_v4(KUTRandom *random, KUTVec4 *value);

// tween
float kut_tween_calculate(int type, float t, float b, float c, float d);
float kut_tween_linear(float t, float b, float c, float d);
float kut_tween_ease_in_quad(float t, float b, float c, float d);
float kut_tween_ease_out_quad(float t, float b, float c, float d);
float kut_tween_ease_in_out_quad(float t, float b, float c, float d);
float kut_tween_ease_in_cubic(float t, float b, float c, float d);
float kut_tween_ease_out_cubic(float t, float b, float c, float d);
float kut_tween_ease_in_out_cubic(float t, float b, float c, float d);
float kut_tween_ease_in_quart(float t, float b, float c, float d);
float kut_tween_ease_out_quart(float t, float b, float c, float d);
float kut_tween_ease_in_out_quart(float t, float b, float c, float d);
float kut_tween_ease_in_quint(float t, float b, float c, float d);
float kut_tween_ease_out_quint(float t, float b, float c, float d);
float kut_tween_ease_in_out_quint(float t, float b, float c, float d);
float kut_tween_ease_in_sine(float t, float b, float c, float d);
float kut_tween_ease_out_sine(float t, float b, float c, float d);
float kut_tween_ease_in_out_sine(float t, float b, float c, float d);
float kut_tween_ease_in_expo(float t, float b, float c, float d);
float kut_tween_ease_out_expo(float t, float b, float c, float d);
float kut_tween_ease_in_out_expo(float t, float b, float c, float d);
float kut_tween_ease_in_circ(float t, float b, float c, float d);
float kut_tween_ease_out_circ(float t, float b, float c, float d);
float kut_tween_ease_in_out_circ(float t, float b, float c, float d);
float kut_tween_ease_in_elastic(float t, float b, float c, float d);
float kut_tween_ease_out_elastic(float t, float b, float c, float d);
float kut_tween_ease_in_out_elastic(float t, float b, float c, float d);
float kut_tween_ease_in_bounce(float t, float b, float c, float d);
float kut_tween_ease_out_bounce(float t, float b, float c, float d);
float kut_tween_ease_in_out_bounce(float t, float b, float c, float d);
float kut_tween_ease_in_back(float t, float b, float c, float d);

// math
unsigned int kut_aabb(KUTVec2 p0, KUTVec2 s0, KUTVec2 p1, KUTVec2 s1);
unsigned int kut_aabb2(KUTRect2 a, KUTRect2 b);
unsigned int kut_aabb3(KUTCube a, KUTCube b);
KUTVec2 kut_vec2_add(KUTVec2 a, KUTVec2 b);
KUTVec2 kut_vec2_sub(KUTVec2 a, KUTVec2 b);
KUTVec2 kut_vec2_mul(KUTVec2 a, KUTVec2 b);
KUTVec2 kut_vec2_div(KUTVec2 a, KUTVec2 b);
KUTVec2 kut_vec2_addf(KUTVec2 a, float b);
KUTVec2 kut_vec2_subf(KUTVec2 a, float b);
KUTVec2 kut_vec2_mulf(KUTVec2 a, float b);
KUTVec2 kut_vec2_divf(KUTVec2 a, float b);
KUTVec3 kut_vec3_add(KUTVec3 a, KUTVec3 b);
KUTVec3 kut_vec3_sub(KUTVec3 a, KUTVec3 b);
KUTVec3 kut_vec3_mul(KUTVec3 a, KUTVec3 b);
KUTVec3 kut_vec3_div(KUTVec3 a, KUTVec3 b);
KUTVec3 kut_vec3_addf(KUTVec3 a, float b);
KUTVec3 kut_vec3_subf(KUTVec3 a, float b);
KUTVec3 kut_vec3_mulf(KUTVec3 a, float b);
KUTVec3 kut_vec3_divf(KUTVec3 a, float b);
KUTVec4 kut_vec4_add(KUTVec4 a, KUTVec4 b);
KUTVec4 kut_vec4_sub(KUTVec4 a, KUTVec4 b);
KUTVec4 kut_vec4_mul(KUTVec4 a, KUTVec4 b);
KUTVec4 kut_vec4_div(KUTVec4 a, KUTVec4 b);
KUTVec4 kut_vec4_addf(KUTVec4 a, float b);
KUTVec4 kut_vec4_subf(KUTVec4 a, float b);
KUTVec4 kut_vec4_mulf(KUTVec4 a, float b);
KUTVec4 kut_vec4_divf(KUTVec4 a, float b);
KUTMat4 kut_mat4_mul(KUTMat4 a, KUTMat4 b);
KUTVec4 kut_mat4_mul_v4(KUTMat4 m, KUTVec4 v);
KUTMat4 kut_mat4_mulf(KUTMat4 m, float v);
KUTMat4 kut_mat4_inverse(const KUTMat4 mat);
KUTMat4 kut_mat4_transpose(KUTMat4 *m);
KUTMat4 kut_mat4_translate(KUTVec3 pos);
KUTMat4 kut_rotatex(float angle);
KUTMat4 kut_rotatey(float angle);
KUTMat4 kut_rotatez(float angle);
KUTMat4 kut_mat4_scale(KUTVec3 scale);
KUTMat4 kut_look_at(KUTVec3 eye, KUTVec3 target, KUTVec3 up);
KUTMat4 kut_ortho_projection(float left, float right, float bottom, float top, float near, float far);
KUTMat4 kut_perspective_projection(float fovy, float aspect, float near, float far);
KUTVec3 kut_unproject(KUTVec3 pos, KUTMat4 viewproj, KUTVec4 viewport);
KUTVec3 kut_screen_to_world_coord(KUTMat4 projection, KUTMat4 view, KUTVec4 viewport, KUTVec2 coord);
float kut_clampf(float value, float min, float max);
float kut_deg_to_rad(float deg);
float kut_rad_to_deg(float rad);
int32_t kut_line_intersect(KUTVec3 p0, KUTVec3 v0, KUTVec3 p1, KUTVec3 v1, KUTVec3 *c);
float kut_vec2_dot_product(KUTVec2 a, KUTVec2 b);
float kut_vec3_dot_product(KUTVec3 a, KUTVec3 b);
float kut_vec4_dot_product(KUTVec4 a, KUTVec4 b);
KUTVec3 kut_cross_product(KUTVec3 a, KUTVec3 b);
KUTVec2 kut_vec2_project(KUTVec2 u, KUTVec2 v);
KUTVec3 kut_vec3_project(KUTVec3 u, KUTVec3 v);
KUTVec4 kut_vec4_project(KUTVec4 u, KUTVec4 v);
float kut_vec2_length(KUTVec2 v);
float kut_vec3_length(KUTVec3 v);
float kut_vec4_length(KUTVec4 v);
float kut_vec2_length2(KUTVec2 v);
float kut_vec3_length2(KUTVec3 v);
float vec4_length2(KUTVec4 v);
KUTVec2 kut_vec2_normal(KUTVec2 v);
KUTVec3 kut_vec3_normal(KUTVec3 v);
KUTVec4 kut_vec4_normal(KUTVec4 v);
KUTVec2 kut_vec2_negative(KUTVec2 v);
KUTVec3 kut_vec3_negative(KUTVec3 v);
KUTVec4 kut_vec4_negative(KUTVec4 v);
int kut_signi(int sign);
KUTVec2 kut_vec2_sign(KUTVec2 v);
KUTVec3 kut_vec3_sign(KUTVec3 v);
KUTVec4 kut_vec4_sign(KUTVec4 v);
KUTVec2 kut_vec2_abs(KUTVec2 v);
KUTVec3 kut_vec3_abs(KUTVec3 v);
KUTVec4 kut_vec4_abs(KUTVec4 v);
KUTVec2 kut_vec2_clamp(KUTVec2 v, KUTVec2 min, KUTVec2 max);
KUTVec3 kut_vec3_clamp(KUTVec3 v, KUTVec3 min, KUTVec3 max);
KUTVec4 kut_vec4_clamp(KUTVec4 v, KUTVec4 min, KUTVec4 max);
KUTVec2 kut_vec2_zero();
KUTVec3 kut_vec3_zero();
KUTVec4 kut_vec4_zero();
KUTMat4 kut_mat4_zero();
KUTVec2 kut_vec2_identity();
KUTVec3 kut_vec3_identity();
KUTVec4 kut_vec4_identity();
KUTMat4 kut_mat4_identity();
KUTVec2 kut_vec2(float x, float y);
KUTVec3 kut_vec3(float x, float y, float z);
KUTVec4 kut_vec4(float x, float y, float z, float w);
KUTVec2 kut_vec3_to_2(KUTVec3 v);
KUTVec2 kut_vec4_to_2(KUTVec4 v);
KUTVec3 kut_vec2_to_3(KUTVec2 v);
KUTVec3 kut_vec4_to_3(KUTVec4 v);
KUTVec4 kut_vec2_to_4(KUTVec2 v);
KUTVec4 kut_vec3_to_4(KUTVec3 v);
void kut_vec3_order(KUTVec3 *p0, KUTVec3 *p1);
KUTVec2 kut_line_line_intersect_point(KUTVec2 p0, KUTVec2 p1, KUTVec2 q0, KUTVec2 q1);
bool kut_circle_circle_intersect(KUTVec2 p0, float r0, KUTVec2 p1, float r1);
float kut_line_slope(KUTVec2 p0, KUTVec2 p1);
float kut_line_normal_slope(KUTVec2 p0, KUTVec2 p1);
bool kut_line_circle_collision(KUTVec2 p0, KUTVec2 p1, KUTVec2 c, float r, KUTVec2 *intersect);
bool kut_point_line_bounce(KUTVec2 c0, KUTVec2 vel, KUTVec2 p0, KUTVec2 p1, KUTVec2 *p_intersect, KUTVec2 *c_out, KUTVec2 *dir);

