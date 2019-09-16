#include <stdbool.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <memory.h>
#include <gmp.h>

typedef unsigned char b8;
typedef char c8;
typedef short i16;
typedef int i32;
typedef long i64;
typedef unsigned short ui16;
typedef unsigned int ui32;
typedef unsigned long ui64;
typedef float f32;
typedef double f64;
typedef long double f80;
typedef const char* cstring;
typedef char* string;
typedef FILE* file;

i32 mod(i32 a, i32 b);
i32 i32_mod_i32(i32 a, i32 b);
bool bool_not_bool(bool a);
i32 i32_not_i32(i32 a);
void print_b8(c8 val);
void print_c8(c8 val);
void print_i16(i16 val);
void print_i32(i32 val);
void print_i64(i64 val);
void print_ui16(ui16 val);
void print_ui32(ui32 val);
void print_ui64(ui64 val);
void print_f32(f32 val);
void print_f64(f64 val);
void print_f80(f80 val);
void print_string(const c8* str);
void println_b8(c8 val);
void println_c8(c8 val);
void println_i16(i16 val);
void println_i32(i32 val);
void println_i64(i64 val);
void println_ui16(ui16 val);
void println_ui32(ui32 val);
void println_ui64(ui64 val);
void println_f32(f32 val);
void println_f64(f64 val);
void println_f80(f80 val);
void println_string(const c8* str);
void print_format(const c8* fmt, ...);

bool* elt_array_bool(bool* ptr, i32 idx);
b8* elt_array_b8(b8* ptr, i32 idx);
c8* elt_array_c8(c8* ptr, i32 idx);
i16* elt_array_i16(i16* ptr, i32 idx);
i32* elt_array_i32(i32* ptr, i32 idx);
i64* elt_array_i64(i64* ptr, i16 idx);
ui16* elt_array_ui16(ui16* ptr, i32 idx);
ui32* elt_array_ui32(ui32* ptr, i32 idx);
ui64* elt_array_ui64(ui64* ptr, i16 idx);
f32* elt_array_f32(f32* ptr, i16 idx);
f64* elt_array_f64(f64* ptr, i32 idx);
f80* elt_array_f80(f80* ptr, i32 idx);
c8** elt_array_string(c8** ptr, i32 idx);

void set_pointer_bool(bool* ptr, bool val);
void set_pointer_b8(b8* ptr, b8 val);
void set_pointer_c8(c8* ptr, c8 val);
void set_pointer_i16(i16* ptr, i16 val);
void set_pointer_i32(i32* ptr, i32 val);
void set_pointer_i64(i64* ptr, i64 val);
void set_pointer_ui16(ui16* ptr, ui16 val);
void set_pointer_ui32(ui32* ptr, ui32 val);
void set_pointer_ui64(ui64* ptr, ui64 val);
void set_pointer_f32(f32* ptr, f32 val);
void set_pointer_f64(f64* ptr, f64 val);
void set_pointer_f80(f80* ptr, f80 val);
void set_pointer_string(c8** ptr, c8* val);
void set_pointer_file(file* ptr, file val);

typedef enum PTR_TYPE {
	ARRAY = 0,
	POINTER,
	LIST,
	INTERMEDIATE_ARRAY,
	INTERMEDIATE_POINTER,
	INTERMEDIATE_LIST,
	VARIABLE = 3
} PTR_TYPE_t;

typedef struct node_ptr {
	int length;
	void* value;
	struct node_ptr* next;
	PTR_TYPE_t type;
} node_ptr_t;

static node_ptr_t* pointer_list = NULL;

#define define_header_lt(T) \
bool lt_##T(T a, T b);
#define define_header_leqt(T) \
bool let_##T(T a, T b);
#define define_header_gt(T) \
bool gt_##T(T a, T b);
#define define_header_geqt(T) \
bool get_##T(T a, T b);
#define define_header_neq(T) \
bool neq_##T(T a, T b);
#define define_header_eq(T) \
bool eq_##T(T a, T b);

define_header_lt(bool)
define_header_lt(i16)
define_header_lt(i32)
define_header_lt(i64)
define_header_lt(ui16)
define_header_lt(ui32)
define_header_lt(ui64)
define_header_lt(f32)
define_header_lt(f64)
define_header_lt(f80)

define_header_leqt(bool)
define_header_leqt(i16)
define_header_leqt(i32)
define_header_leqt(i64)
define_header_leqt(ui16)
define_header_leqt(ui32)
define_header_leqt(ui64)
define_header_leqt(f32)
define_header_leqt(f64)
define_header_leqt(f80)

define_header_gt(bool)
define_header_gt(i16)
define_header_gt(i32)
define_header_gt(i64)
define_header_gt(ui16)
define_header_gt(ui32)
define_header_gt(ui64)
define_header_gt(f32)
define_header_gt(f64)
define_header_gt(f80)

define_header_geqt(bool)
define_header_geqt(i16)
define_header_geqt(i32)
define_header_geqt(i64)
define_header_geqt(ui16)
define_header_geqt(ui32)
define_header_geqt(ui64)
define_header_geqt(f32)
define_header_geqt(f64)
define_header_geqt(f80)

define_header_neq(bool)
define_header_neq(i16)
define_header_neq(i32)
define_header_neq(i64)
define_header_neq(f32)
define_header_neq(f64)
define_header_neq(f80)

define_header_eq(bool)
define_header_eq(i16)
define_header_eq(i32)
define_header_eq(i64)
define_header_eq(ui16)
define_header_eq(ui32)
define_header_eq(ui64)
define_header_eq(f32)
define_header_eq(f64)
define_header_eq(f80)

#define define_header_sqrt(T) \
T sqrt_##T(T a); \

define_header_sqrt(i16)
define_header_sqrt(i32)
define_header_sqrt(i64)
define_header_sqrt(ui16)
define_header_sqrt(ui32)
define_header_sqrt(ui64)
define_header_sqrt(f32)
define_header_sqrt(f64)
define_header_sqrt(f80)

#define define_header_power(T) \
T power_##T(T a, T b); \

define_header_power(i16)
define_header_power(i32)
define_header_power(i64)
define_header_power(ui16)
define_header_power(ui32)
define_header_power(ui64)
define_header_power(f32)
define_header_power(f64)
define_header_power(f80)

#define define_header_max(T) \
T max_##T(T a, T b); \

define_header_max(i16)
define_header_max(i32)
define_header_max(i64)
define_header_max(ui16)
define_header_max(ui32)
define_header_max(ui64)
define_header_max(f32)
define_header_max(f64)
define_header_max(f80)

#define define_header_min(T) \
T min_##T(T a, T b); \

define_header_min(i16)
define_header_min(i32)
define_header_min(i64)
define_header_min(ui16)
define_header_min(ui32)
define_header_min(ui64)
define_header_min(f32)
define_header_min(f64)
define_header_min(f80)

#define define_header_single_fn(T) \
typedef T (*single_fn_##T)(T); \

define_header_single_fn(bool)
define_header_single_fn(b8)
define_header_single_fn(c8)
define_header_single_fn(i16)
define_header_single_fn(i32)
define_header_single_fn(i64)
define_header_single_fn(ui16)
define_header_single_fn(ui32)
define_header_single_fn(ui64)
define_header_single_fn(f32)
define_header_single_fn(f64)
define_header_single_fn(f80)

#define define_header_dual_fn(T) \
typedef T (*dual_fn_##T)(T, T); \

define_header_dual_fn(bool)
define_header_dual_fn(b8)
define_header_dual_fn(c8)
define_header_dual_fn(i16)
define_header_dual_fn(i32)
define_header_dual_fn(i64)
define_header_dual_fn(ui16)
define_header_dual_fn(ui32)
define_header_dual_fn(ui64)
define_header_dual_fn(f32)
define_header_dual_fn(f64)
define_header_dual_fn(f80)

node_ptr_t* append_ptr(void* value, int size, PTR_TYPE_t type);
int length(void* pointer);
i32 length_list(node_ptr_t* list);
void remove_ptr(void* pointer);
void inc_length(void* pointer);
void delete_ptr(void* pointer);
int destroy_ptr(node_ptr_t* e);

#define define_header_node(T) \
typedef struct node_##T { \
    T value; \
    struct node_##T * next; \
} node_##T;\

define_header_node(bool)
define_header_node(c8)
define_header_node(b8)
define_header_node(i16)
define_header_node(i32)
define_header_node(i64)
define_header_node(ui16)
define_header_node(ui32)
define_header_node(ui64)
define_header_node(f32)
define_header_node(f64)
define_header_node(f80)
define_header_node(string)
define_header_node(file)

#define define_header_length_list(T) \
i32 length_list_##T(node_##T* list);  \

define_header_length_list(bool)
define_header_length_list(c8)
define_header_length_list(b8)
define_header_length_list(i16)
define_header_length_list(i32)
define_header_length_list(i64)
define_header_length_list(ui16)
define_header_length_list(ui32)
define_header_length_list(ui64)
define_header_length_list(f32)
define_header_length_list(f64)
define_header_length_list(f80)

#define define_header_length_array(T) \
i32 length_array_##T(T* array);  \

define_header_length_array(bool)
define_header_length_array(c8)
define_header_length_array(b8)
define_header_length_array(i16)
define_header_length_array(i32)
define_header_length_array(i64)
define_header_length_array(ui16)
define_header_length_array(ui32)
define_header_length_array(ui64)
define_header_length_array(f32)
define_header_length_array(f64)
define_header_length_array(f80)

#define define_header_length_pointer(T) \
i32 length_pointer_##T(T* pointer); \

define_header_length_pointer(bool)
define_header_length_pointer(c8)
define_header_length_pointer(b8)
define_header_length_pointer(i16)
define_header_length_pointer(i32)
define_header_length_pointer(i64)
define_header_length_pointer(ui16)
define_header_length_pointer(ui32)
define_header_length_pointer(ui64)
define_header_length_pointer(f32)
define_header_length_pointer(f64)
define_header_length_pointer(f80)

#define define_header_append_list(T) \
node_##T* append_list_##T(node_##T* list, T value); \

define_header_append_list(bool)
define_header_append_list(c8)
define_header_append_list(b8)
define_header_append_list(i16)
define_header_append_list(i32)
define_header_append_list(i64)
define_header_append_list(ui16)
define_header_append_list(ui32)
define_header_append_list(ui64)
define_header_append_list(f32)
define_header_append_list(f64)
define_header_append_list(f80)

#define define_header_append_array(T) \
T* append_array_##T(T* array, T value);  \

define_header_append_array(bool)
define_header_append_array(c8)
define_header_append_array(b8)
define_header_append_array(i16)
define_header_append_array(i32)
define_header_append_array(i64)
define_header_append_array(ui16)
define_header_append_array(ui32)
define_header_append_array(ui64)
define_header_append_array(f32)
define_header_append_array(f64)
define_header_append_array(f80)

#define define_header_append_pointer(T) \
T* append_pointer_##T(T* pointer, T value);  \

define_header_append_pointer(bool)
define_header_append_pointer(c8)
define_header_append_pointer(b8)
define_header_append_pointer(i16)
define_header_append_pointer(i32)
define_header_append_pointer(i64)
define_header_append_pointer(ui16)
define_header_append_pointer(ui32)
define_header_append_pointer(ui64)
define_header_append_pointer(f32)
define_header_append_pointer(f64)
define_header_append_pointer(f80)

#define define_header_append_list_list(T) \
node_##T* append_list_list_##T(node_##T* lista, node_##T* listb); \

define_header_append_list_list(bool)
define_header_append_list_list(c8)
define_header_append_list_list(b8)
define_header_append_list_list(i16)
define_header_append_list_list(i32)
define_header_append_list_list(i64)
define_header_append_list_list(ui16)
define_header_append_list_list(ui32)
define_header_append_list_list(ui64)
define_header_append_list_list(f32)
define_header_append_list_list(f64)
define_header_append_list_list(f80)

#define define_header_append_array_array(T) \
T* append_array_array_##T(T* arraya, T* arrayb);  \

define_header_append_array_array(bool)
define_header_append_array_array(c8)
define_header_append_array_array(b8)
define_header_append_array_array(i16)
define_header_append_array_array(i32)
define_header_append_array_array(i64)
define_header_append_array_array(ui16)
define_header_append_array_array(ui32)
define_header_append_array_array(ui64)
define_header_append_array_array(f32)
define_header_append_array_array(f64)
define_header_append_array_array(f80)

#define define_header_append_pointer_pointer(T) \
T* append_pointer_pointer_##T(T* pointera, T* pointerb);  \

define_header_append_pointer_pointer(bool)
define_header_append_pointer_pointer(c8)
define_header_append_pointer_pointer(b8)
define_header_append_pointer_pointer(i16)
define_header_append_pointer_pointer(i32)
define_header_append_pointer_pointer(i64)
define_header_append_pointer_pointer(ui16)
define_header_append_pointer_pointer(ui32)
define_header_append_pointer_pointer(ui64)
define_header_append_pointer_pointer(f32)
define_header_append_pointer_pointer(f64)
define_header_append_pointer_pointer(f80)

#define define_header_reverse_list(T) \
node_##T* reverse_list_##T(node_##T* head);  \

define_header_reverse_list(bool)
define_header_reverse_list(c8)
define_header_reverse_list(b8)
define_header_reverse_list(i16)
define_header_reverse_list(i32)
define_header_reverse_list(i64)
define_header_reverse_list(ui16)
define_header_reverse_list(ui32)
define_header_reverse_list(ui64)
define_header_reverse_list(f32)
define_header_reverse_list(f64)
define_header_reverse_list(f80)

#define define_header_reverse_array(T) \
T* reverse_array_##T(T* array); \

define_header_reverse_array(bool)
define_header_reverse_array(c8)
define_header_reverse_array(b8)
define_header_reverse_array(i16)
define_header_reverse_array(i32)
define_header_reverse_array(i64)
define_header_reverse_array(ui16)
define_header_reverse_array(ui32)
define_header_reverse_array(ui64)
define_header_reverse_array(f32)
define_header_reverse_array(f64)
define_header_reverse_array(f80)

#define define_header_reverse_pointer(T) \
T* reverse_pointer_##T(T* pointer); \

define_header_reverse_pointer(bool)
define_header_reverse_pointer(c8)
define_header_reverse_pointer(b8)
define_header_reverse_pointer(i16)
define_header_reverse_pointer(i32)
define_header_reverse_pointer(i64)
define_header_reverse_pointer(ui16)
define_header_reverse_pointer(ui32)
define_header_reverse_pointer(ui64)
define_header_reverse_pointer(f32)
define_header_reverse_pointer(f64)
define_header_reverse_pointer(f80)

#define define_header_push_list(T) \
node_##T* push_list_##T(node_##T** list, T value);  \

define_header_push_list(bool)
define_header_push_list(c8)
define_header_push_list(b8)
define_header_push_list(i16)
define_header_push_list(i32)
define_header_push_list(i64)
define_header_push_list(ui16)
define_header_push_list(ui32)
define_header_push_list(ui64)
define_header_push_list(f32)
define_header_push_list(f64)
define_header_push_list(f80)

#define define_header_pop_list(T) \
T pop_list_##T(node_##T** list);  \

define_header_pop_list(bool)
define_header_pop_list(c8)
define_header_pop_list(b8)
define_header_pop_list(i16)
define_header_pop_list(i32)
define_header_pop_list(i64)
define_header_pop_list(ui16)
define_header_pop_list(ui32)
define_header_pop_list(ui64)
define_header_pop_list(f32)
define_header_pop_list(f64)
define_header_pop_list(f80)

#define define_header_remove_list(T) \
node_##T* remove_list_##T(node_##T* list, int pos); \

define_header_remove_list(bool)
define_header_remove_list(c8)
define_header_remove_list(b8)
define_header_remove_list(i16)
define_header_remove_list(i32)
define_header_remove_list(i64)
define_header_remove_list(ui16)
define_header_remove_list(ui32)
define_header_remove_list(ui64)
define_header_remove_list(f32)
define_header_remove_list(f64)
define_header_remove_list(f80)

#define define_header_car_list(T) \
T car_list_##T(node_##T* list); \

define_header_car_list(bool)
define_header_car_list(c8)
define_header_car_list(b8)
define_header_car_list(i16)
define_header_car_list(i32)
define_header_car_list(i64)
define_header_car_list(ui16)
define_header_car_list(ui32)
define_header_car_list(ui64)
define_header_car_list(f32)
define_header_car_list(f64)
define_header_car_list(f80)

#define define_header_car_array(T) \
T car_array_##T(T* array); \

define_header_car_array(bool)
define_header_car_array(c8)
define_header_car_array(b8)
define_header_car_array(i16)
define_header_car_array(i32)
define_header_car_array(i64)
define_header_car_array(ui16)
define_header_car_array(ui32)
define_header_car_array(ui64)
define_header_car_array(f32)
define_header_car_array(f64)
define_header_car_array(f80)

#define define_header_cdr_list(T) \
node_##T* cdr_list_##T(node_##T* list); \

define_header_cdr_list(bool)
define_header_cdr_list(c8)
define_header_cdr_list(b8)
define_header_cdr_list(i16)
define_header_cdr_list(i32)
define_header_cdr_list(i64)
define_header_cdr_list(ui16)
define_header_cdr_list(ui32)
define_header_cdr_list(ui64)
define_header_cdr_list(f32)
define_header_cdr_list(f64)
define_header_cdr_list(f80)

#define define_header_cdr_array(T) \
T* cdr_array_##T(T* array); \

define_header_cdr_array(bool)
define_header_cdr_array(c8)
define_header_cdr_array(b8)
define_header_cdr_array(i16)
define_header_cdr_array(i32)
define_header_cdr_array(i64)
define_header_cdr_array(ui16)
define_header_cdr_array(ui32)
define_header_cdr_array(ui64)
define_header_cdr_array(f32)
define_header_cdr_array(f64)
define_header_cdr_array(f80)

#define define_header_cdr_pointer(T) \
T* cdr_pointer_##T(T* pointer); \

define_header_cdr_pointer(bool)
define_header_cdr_pointer(c8)
define_header_cdr_pointer(b8)
define_header_cdr_pointer(i16)
define_header_cdr_pointer(i32)
define_header_cdr_pointer(i64)
define_header_cdr_pointer(ui16)
define_header_cdr_pointer(ui32)
define_header_cdr_pointer(ui64)
define_header_cdr_pointer(f32)
define_header_cdr_pointer(f64)
define_header_cdr_pointer(f80)

#define define_header_cdrn_list(T) \
node_##T* cdrn_list_##T(node_##T* list); \

define_header_cdrn_list(bool)
define_header_cdrn_list(c8)
define_header_cdrn_list(b8)
define_header_cdrn_list(i16)
define_header_cdrn_list(i32)
define_header_cdrn_list(i64)
define_header_cdrn_list(ui16)
define_header_cdrn_list(ui32)
define_header_cdrn_list(ui64)
define_header_cdrn_list(f32)
define_header_cdrn_list(f64)
define_header_cdrn_list(f80)

#define define_header_cdrn_array(T) \
T* cdrn_array_##T(T* array); \

define_header_cdrn_array(bool)
define_header_cdrn_array(c8)
define_header_cdrn_array(b8)
define_header_cdrn_array(i16)
define_header_cdrn_array(i32)
define_header_cdrn_array(i64)
define_header_cdrn_array(ui16)
define_header_cdrn_array(ui32)
define_header_cdrn_array(ui64)
define_header_cdrn_array(f32)
define_header_cdrn_array(f64)
define_header_cdrn_array(f80)

#define define_header_cdrn_pointer(T) \
T* cdrn_pointer_##T(T* pointer); \

define_header_cdrn_pointer(bool)
define_header_cdrn_pointer(c8)
define_header_cdrn_pointer(b8)
define_header_cdrn_pointer(i16)
define_header_cdrn_pointer(i32)
define_header_cdrn_pointer(i64)
define_header_cdrn_pointer(ui16)
define_header_cdrn_pointer(ui32)
define_header_cdrn_pointer(ui64)
define_header_cdrn_pointer(f32)
define_header_cdrn_pointer(f64)
define_header_cdrn_pointer(f80)

#define define_header_destroy(T) \
void destroy_list_##T(node_##T* e); \

define_header_destroy(bool)
define_header_destroy(c8)
define_header_destroy(b8)
define_header_destroy(i16)
define_header_destroy(i32)
define_header_destroy(i64)
define_header_destroy(ui16)
define_header_destroy(ui32)
define_header_destroy(ui64)
define_header_destroy(f32)
define_header_destroy(f64)
define_header_destroy(f80)

#define define_header_create_list(T) \
node_##T* create_list_##T(T list[], int size); \

define_header_create_list(bool)
define_header_create_list(c8)
define_header_create_list(b8)
define_header_create_list(i16)
define_header_create_list(i32)
define_header_create_list(i64)
define_header_create_list(ui16)
define_header_create_list(ui32)
define_header_create_list(ui64)
define_header_create_list(f32)
define_header_create_list(f64)
define_header_create_list(f80)

#define define_header_create_array(T) \
T* create_array_##T(T list[], int size); \

define_header_create_array(bool)
define_header_create_array(c8)
define_header_create_array(b8)
define_header_create_array(i16)
define_header_create_array(i32)
define_header_create_array(i64)
define_header_create_array(ui16)
define_header_create_array(ui32)
define_header_create_array(ui64)
define_header_create_array(f32)
define_header_create_array(f64)
define_header_create_array(f80)

#define define_header_map_array(T) \
T* map_array_##T(single_fn_##T a, T* b); \

define_header_map_array(bool)
define_header_map_array(b8)
define_header_map_array(c8)
define_header_map_array(i16)
define_header_map_array(i32)
define_header_map_array(i64)
define_header_map_array(ui16)
define_header_map_array(ui32)
define_header_map_array(ui64)
define_header_map_array(f32)
define_header_map_array(f64)
define_header_map_array(f80)

#define define_header_map_list(T) \
node_##T* map_list_##T(single_fn_##T a, node_##T* b); \

define_header_map_list(bool)
define_header_map_list(b8)
define_header_map_list(c8)
define_header_map_list(i16)
define_header_map_list(i32)
define_header_map_list(i64)
define_header_map_list(ui16)
define_header_map_list(ui32)
define_header_map_list(ui64)
define_header_map_list(f32)
define_header_map_list(f64)
define_header_map_list(f80)

#define define_header_mapn_array(T) \
T* mapn_array_##T(single_fn_##T a, T* b); \

define_header_mapn_array(bool)
define_header_mapn_array(b8)
define_header_mapn_array(c8)
define_header_mapn_array(i16)
define_header_mapn_array(i32)
define_header_mapn_array(i64)
define_header_mapn_array(ui16)
define_header_mapn_array(ui32)
define_header_mapn_array(ui64)
define_header_mapn_array(f32)
define_header_mapn_array(f64)
define_header_mapn_array(f80)

#define define_header_mapn_list(T) \
node_##T* mapn_list_##T(single_fn_##T a, node_##T* b); \

define_header_mapn_list(bool)
define_header_mapn_list(b8)
define_header_mapn_list(c8)
define_header_mapn_list(i16)
define_header_mapn_list(i32)
define_header_mapn_list(i64)
define_header_mapn_list(ui16)
define_header_mapn_list(ui32)
define_header_mapn_list(ui64)
define_header_mapn_list(f32)
define_header_mapn_list(f64)
define_header_mapn_list(f80)

#define define_header_reduce_array(T) \
T reduce_array_##T(dual_fn_##T a, T* b); \

define_header_reduce_array(bool)
define_header_reduce_array(c8)
define_header_reduce_array(i16)
define_header_reduce_array(i32)
define_header_reduce_array(i64)
define_header_reduce_array(ui16)
define_header_reduce_array(ui32)
define_header_reduce_array(ui64)
define_header_reduce_array(f32)
define_header_reduce_array(f64)
define_header_reduce_array(f80)

#define define_header_reduce_list(T) \
T reduce_list_##T(dual_fn_##T a, node_##T* b); \

define_header_reduce_list(bool)
define_header_reduce_list(c8)
define_header_reduce_list(i16)
define_header_reduce_list(i32)
define_header_reduce_list(i64)
define_header_reduce_list(ui16)
define_header_reduce_list(ui32)
define_header_reduce_list(ui64)
define_header_reduce_list(f32)
define_header_reduce_list(f64)
define_header_reduce_list(f80)


#define define_header_new(T) \
T* new_##T(int size); \

define_header_new(bool)
define_header_new(c8)
define_header_new(i16)
define_header_new(i32)
define_header_new(i64)
define_header_new(ui16)
define_header_new(ui32)
define_header_new(ui64)
define_header_new(f32)
define_header_new(f64)
define_header_new(f80)

#define define_header_println_list(T) \
void println_list_##T(node_##T* list);  \

define_header_println_list(b8)
define_header_println_list(c8)
define_header_println_list(i16)
define_header_println_list(i32)
define_header_println_list(i64)
define_header_println_list(ui16)
define_header_println_list(ui32)
define_header_println_list(ui64)
define_header_println_list(f32)
define_header_println_list(f64)
define_header_println_list(f80)

#define define_header_print_list(T) \
void print_list_##T(node_##T* list);  \

define_header_print_list(b8)
define_header_print_list(c8)
define_header_print_list(i16)
define_header_print_list(i32)
define_header_print_list(i64)
define_header_print_list(ui16)
define_header_print_list(ui32)
define_header_print_list(ui64)
define_header_print_list(f32)
define_header_print_list(f64)
define_header_print_list(f80)

#define define_header_println_array(T) \
void println_array_##T(int size, const T* array); \

define_header_println_array(b8)
define_header_println_array(c8)
define_header_println_array(i16)
define_header_println_array(i32)
define_header_println_array(i64)
define_header_println_array(ui16)
define_header_println_array(ui32)
define_header_println_array(ui64)
define_header_println_array(f32)
define_header_println_array(f64)
define_header_println_array(f80)

#define define_header_print_array(T) \
void print_array_##T(int size, const T* array);  \

define_header_print_array(b8)
define_header_print_array(c8)
define_header_print_array(i16)
define_header_print_array(i32)
define_header_print_array(i64)
define_header_print_array(ui16)
define_header_print_array(ui32)
define_header_print_array(ui64)
define_header_print_array(f32)
define_header_print_array(f64)
define_header_print_array(f80)

#define define_header_println_pointer(T) \
void println_pointer_##T(T* pointer);  \

define_header_println_pointer(b8)
define_header_println_pointer(c8)
define_header_println_pointer(i16)
define_header_println_pointer(i32)
define_header_println_pointer(i64)
define_header_println_pointer(ui16)
define_header_println_pointer(ui32)
define_header_println_pointer(ui64)
define_header_println_pointer(f32)
define_header_println_pointer(f64)
define_header_println_pointer(f80)

#define define_header_print_pointer(T) \
void print_pointer_##T(T* pointer);  \

define_header_print_pointer(b8)
define_header_print_pointer(c8)
define_header_print_pointer(i16)
define_header_print_pointer(i32)
define_header_print_pointer(i64)
define_header_print_pointer(ui16)
define_header_print_pointer(ui32)
define_header_print_pointer(ui64)
define_header_print_pointer(f32)
define_header_print_pointer(f64)
define_header_print_pointer(f80)

#define define_header_elt_list(T) \
T* elt_list_##T(node_##T* list, i32 idx); \

define_header_elt_list(b8)
define_header_elt_list(c8)
define_header_elt_list(i16)
define_header_elt_list(i32)
define_header_elt_list(i64)
define_header_elt_list(ui16)
define_header_elt_list(ui32)
define_header_elt_list(ui64)
define_header_elt_list(f32)
define_header_elt_list(f64)
define_header_elt_list(f80)

#define define_header_set_list(T) \
void set_list_##T(node_##T* list, T val); \

define_header_set_list(b8)
define_header_set_list(c8)
define_header_set_list(i16)
define_header_set_list(i32)
define_header_set_list(i64)
define_header_set_list(ui16)
define_header_set_list(ui32)
define_header_set_list(ui64)
define_header_set_list(f32)
define_header_set_list(f64)
define_header_set_list(f80)
define_header_set_list(string)
define_header_set_list(file)

#define define_header_set_pointer_list(T) \
void set_pointer_list_##T(node_##T** ptr, node_##T* val); \

define_header_set_pointer_list(bool)
define_header_set_pointer_list(c8)
define_header_set_pointer_list(b8)
define_header_set_pointer_list(i16)
define_header_set_pointer_list(i32)
define_header_set_pointer_list(i64)
define_header_set_pointer_list(ui16)
define_header_set_pointer_list(ui32)
define_header_set_pointer_list(ui64)
define_header_set_pointer_list(f32)
define_header_set_pointer_list(f64)
define_header_set_pointer_list(f80)
define_header_set_pointer_list(string)
define_header_set_pointer_list(file)

#define define_header_set_pointer_array(T) \
void set_pointer_array_##T(T** ptr, T* val); \

define_header_set_pointer_array(bool)
define_header_set_pointer_array(c8)
define_header_set_pointer_array(b8)
define_header_set_pointer_array(i16)
define_header_set_pointer_array(i32)
define_header_set_pointer_array(i64)
define_header_set_pointer_array(ui16)
define_header_set_pointer_array(ui32)
define_header_set_pointer_array(ui64)
define_header_set_pointer_array(f32)
define_header_set_pointer_array(f64)
define_header_set_pointer_array(f80)
define_header_set_pointer_array(string)
define_header_set_pointer_array(file)

#define define_header_set_pointer_pointer(T) \
void set_pointer_pointer_##T(T** ptr, T* val); \

define_header_set_pointer_pointer(bool)
define_header_set_pointer_pointer(c8)
define_header_set_pointer_pointer(b8)
define_header_set_pointer_pointer(i16)
define_header_set_pointer_pointer(i32)
define_header_set_pointer_pointer(i64)
define_header_set_pointer_pointer(ui16)
define_header_set_pointer_pointer(ui32)
define_header_set_pointer_pointer(ui64)
define_header_set_pointer_pointer(f32)
define_header_set_pointer_pointer(f64)
define_header_set_pointer_pointer(f80)
define_header_set_pointer_pointer(string)
define_header_set_pointer_pointer(file)

void print_str_pointer_c8(c8* array, c8* value);
void print_str_array_c8(c8* array, c8* value);
void print_str_string(c8* array, c8* value);
void print_str_pointer_i16(c8* pointer, i16* value);
void print_str_array_i16(c8* pointer, i16* value);
void print_str_pointer_i32(c8* pointer, i32* value);
void print_str_array_i32(c8* pointer, i32* value);
void print_str_pointer_i64(c8* pointer, i64* value);
void print_str_array_i64(c8* pointer, i64* value);
void print_str_pointer_ui16(c8* pointer, ui16* value);
void print_str_array_ui16(c8* pointer, ui16* value);
void print_str_pointer_ui32(c8* pointer, ui32* value);
void print_str_array_ui32(c8* pointer, ui32* value);
void print_str_pointer_ui64(c8* pointer, ui64* value);
void print_str_array_ui64(c8* pointer, ui64* value);
void print_str_pointer_f32(c8* pointer, f32* value);
void print_str_array_f32(c8* pointer, f32* value);
void print_str_pointer_f64(c8* pointer, f64* value);
void print_str_array_f64(c8* pointer, f64* value);
void print_str_pointer_f80(c8* pointer, f80* value);
void print_str_array_f80(c8* pointer, f80* value);

#define define_header_floor(T) \
T floor_##T(T val); \

define_header_floor(c8)
define_header_floor(i16)
define_header_floor(i32)
define_header_floor(i64)
define_header_floor(ui16)
define_header_floor(ui32)
define_header_floor(ui64)
define_header_floor(f32)
define_header_floor(f64)
define_header_floor(f80)

#define define_header_ceil(T) \
T ceil_##T(T val); \

define_header_ceil(c8)
define_header_ceil(i16)
define_header_ceil(i32)
define_header_ceil(i64)
define_header_ceil(ui16)
define_header_ceil(ui32)
define_header_ceil(ui64)
define_header_ceil(f32)
define_header_ceil(f64)
define_header_ceil(f80)

#define define_header_round(T) \
T round_##T(T val);

define_header_round(c8)
define_header_round(i16)
define_header_round(i32)
define_header_round(i64)
define_header_round(ui16)
define_header_round(ui32)
define_header_round(ui64)
define_header_round(f32)
define_header_round(f64)
define_header_round(f80)

#define define_header_acos(T) \
T acos_##T(T val); \

define_header_acos(c8)
define_header_acos(i16)
define_header_acos(i32)
define_header_acos(i64)
define_header_acos(ui16)
define_header_acos(ui32)
define_header_acos(ui64)
define_header_acos(f32)
define_header_acos(f64)
define_header_acos(f80)

#define define_header_asin(T) \
T asin_##T(T val); \

define_header_asin(c8)
define_header_asin(i16)
define_header_asin(i32)
define_header_asin(i64)
define_header_asin(ui16)
define_header_asin(ui32)
define_header_asin(ui64)
define_header_asin(f32)
define_header_asin(f64)
define_header_asin(f80)

#define define_header_atan(T) \
T atan_##T(T val); \

define_header_atan(c8)
define_header_atan(i16)
define_header_atan(i32)
define_header_atan(i64)
define_header_atan(ui16)
define_header_atan(ui32)
define_header_atan(ui64)
define_header_atan(f32)
define_header_atan(f64)
define_header_atan(f80)

#define define_header_atan2(T) \
T atan2_##T(T vala, T valb);  \

define_header_atan2(c8)
define_header_atan2(i16)
define_header_atan2(i32)
define_header_atan2(i64)
define_header_atan2(ui16)
define_header_atan2(ui32)
define_header_atan2(ui64)
define_header_atan2(f32)
define_header_atan2(f64)
define_header_atan2(f80)

#define define_header_cos(T) \
T cos_##T(T val); \

define_header_cos(c8)
define_header_cos(i16)
define_header_cos(i32)
define_header_cos(i64)
define_header_cos(ui16)
define_header_cos(ui32)
define_header_cos(ui64)
define_header_cos(f32)
define_header_cos(f64)
define_header_cos(f80)

#define define_header_cosh(T) \
T cosh_##T(T val); \

define_header_cosh(c8)
define_header_cosh(i16)
define_header_cosh(i32)
define_header_cosh(i64)
define_header_cosh(ui16)
define_header_cosh(ui32)
define_header_cosh(ui64)
define_header_cosh(f32)
define_header_cosh(f64)
define_header_cosh(f80)

#define define_header_sin(T) \
T sin_##T(T val); \

define_header_sin(c8)
define_header_sin(i16)
define_header_sin(i32)
define_header_sin(i64)
define_header_sin(ui16)
define_header_sin(ui32)
define_header_sin(ui64)
define_header_sin(f32)
define_header_sin(f64)
define_header_sin(f80)

#define define_header_sinh(T) \
T sinh_##T(T val); \

define_header_sinh(c8)
define_header_sinh(i16)
define_header_sinh(i32)
define_header_sinh(i64)
define_header_sinh(ui16)
define_header_sinh(ui32)
define_header_sinh(ui64)
define_header_sinh(f32)
define_header_sinh(f64)
define_header_sinh(f80)

#define define_header_tanh(T) \
T tanh_##T(T val); \

define_header_tanh(c8)
define_header_tanh(i16)
define_header_tanh(i32)
define_header_tanh(i64)
define_header_tanh(ui16)
define_header_tanh(ui32)
define_header_tanh(ui64)
define_header_tanh(f32)
define_header_tanh(f64)
define_header_tanh(f80)

#define define_header_exp(T) \
T exp_##T(T val); \

define_header_exp(c8)
define_header_exp(i16)
define_header_exp(i32)
define_header_exp(i64)
define_header_exp(ui16)
define_header_exp(ui32)
define_header_exp(ui64)
define_header_exp(f32)
define_header_exp(f64)
define_header_exp(f80)

#define define_header_frexp(T) \
T frexp_##T(T val, int* ptr); \

define_header_frexp(c8)
define_header_frexp(i16)
define_header_frexp(i32)
define_header_frexp(i64)
define_header_frexp(ui16)
define_header_frexp(ui32)
define_header_frexp(ui64)
define_header_frexp(f32)
define_header_frexp(f64)
define_header_frexp(f80)

#define define_header_ldexp(T) \
T ldexp_##T(T val, int b); \

define_header_ldexp(c8)
define_header_ldexp(i16)
define_header_ldexp(i32)
define_header_ldexp(i64)
define_header_ldexp(ui16)
define_header_ldexp(ui32)
define_header_ldexp(ui64)
define_header_ldexp(f32)
define_header_ldexp(f64)
define_header_ldexp(f80)

#define define_header_log(T) \
T log_##T(T val); \

define_header_log(c8)
define_header_log(i16)
define_header_log(i32)
define_header_log(i64)
define_header_log(ui16)
define_header_log(ui32)
define_header_log(ui64)
define_header_log(f32)
define_header_log(f64)
define_header_log(f80)

#define define_header_log10(T) \
T log10_##T(T val); \

define_header_log10(c8)
define_header_log10(i16)
define_header_log10(i32)
define_header_log10(i64)
define_header_log10(ui16)
define_header_log10(ui32)
define_header_log10(ui64)
define_header_log10(f32)
define_header_log10(f64)
define_header_log10(f80)

#define define_header_modf(T) \
T modf_##T(T val, double* ptr); \

define_header_modf(c8)
define_header_modf(i16)
define_header_modf(i32)
define_header_modf(i64)
define_header_modf(ui16)
define_header_modf(ui32)
define_header_modf(ui64)
define_header_modf(f32)
define_header_modf(f64)
define_header_modf(f80)

#define define_header_fabs(T) \
T fabs_##T(T val); \

define_header_fabs(f32)
define_header_fabs(f64)

#define define_header_fmod(T) \
T fmod_##T(T vala, T valb); \

define_header_fmod(c8)
define_header_fmod(i16)
define_header_fmod(i32)
define_header_fmod(i64)
define_header_fmod(ui16)
define_header_fmod(ui32)
define_header_fmod(ui64)
define_header_fmod(f32)
define_header_fmod(f64)
define_header_fmod(f80)

file open(cstring filename, cstring mode);
ui64 read_binary(void *ptr, ui64 size_of_elements, ui64 number_of_elements, file infile);
ui64 write_binary(const void *ptr, ui64 size_of_elements, ui64 number_of_elements, file outfile);
int write_line(file outfile, cstring line);
c8* read_line(file infile);
i32 close(file file);

#define define_header_or(T) \
T or_##T(T vala, T valb); \

define_header_or(bool)
define_header_or(b8)
define_header_or(c8)
define_header_or(i16)
define_header_or(i32)
define_header_or(i64)
define_header_or(ui16)
define_header_or(ui32)
define_header_or(ui64)
define_header_or(f32)
define_header_or(f64)
define_header_or(f80)

#define define_header_not(T) \
T not_##T(T val); \

define_header_not(bool)
define_header_not(b8)
define_header_not(c8)
define_header_not(i16)
define_header_not(i32)
define_header_not(i64)
define_header_not(ui16)
define_header_not(ui32)
define_header_not(ui64)
define_header_not(f32)
define_header_not(f64)
define_header_not(f80)

#define define_header_and(T) \
T and_##T(T vala, T valb); \

define_header_and(bool)
define_header_and(b8)
define_header_and(c8)
define_header_and(i16)
define_header_and(i32)
define_header_and(i64)
define_header_and(ui16)
define_header_and(ui32)
define_header_and(ui64)
define_header_and(f32)
define_header_and(f64)
define_header_and(f80)

#define define_header_equal(T) \
T equal_##T(T vala, T valb); \

define_header_equal(bool)
define_header_equal(b8)
define_header_equal(c8)
define_header_equal(i16)
define_header_equal(i32)
define_header_equal(i64)
define_header_equal(ui16)
define_header_equal(ui32)
define_header_equal(ui64)
define_header_equal(f32)
define_header_equal(f64)
define_header_equal(f80)

bool equal_string(string vala, string valb);
bool equal_cstring(cstring vala, cstring valb);

#define define_header_equal_array(T) \
bool equal_array_##T(T* vala, T* valb); \

define_header_equal_array(bool)
define_header_equal_array(b8)
define_header_equal_array(c8)
define_header_equal_array(i16)
define_header_equal_array(i32)
define_header_equal_array(i64)
define_header_equal_array(ui16)
define_header_equal_array(ui32)
define_header_equal_array(ui64)
define_header_equal_array(f32)
define_header_equal_array(f64)
define_header_equal_array(f80)

#define define_header_equal_pointer(T) \
bool equal_pointer_##T(T* vala, T* valb); \

define_header_equal_pointer(bool)
define_header_equal_pointer(b8)
define_header_equal_pointer(c8)
define_header_equal_pointer(i16)
define_header_equal_pointer(i32)
define_header_equal_pointer(i64)
define_header_equal_pointer(ui16)
define_header_equal_pointer(ui32)
define_header_equal_pointer(ui64)
define_header_equal_pointer(f32)
define_header_equal_pointer(f64)
define_header_equal_pointer(f80)

#define define_header_equal_list(T) \
bool equal_list_##T(node_##T* vala, node_##T* valb); \

define_header_equal_list(bool)
define_header_equal_list(b8)
define_header_equal_list(c8)
define_header_equal_list(i16)
define_header_equal_list(i32)
define_header_equal_list(i64)
define_header_equal_list(ui16)
define_header_equal_list(ui32)
define_header_equal_list(ui64)
define_header_equal_list(f32)
define_header_equal_list(f64)
define_header_equal_list(f80)
