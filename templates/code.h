#include <stdbool.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <memory.h>

typedef char b8;
typedef char c8;
typedef short i16;
typedef int i32;
typedef long i64;
typedef float f32;
typedef double f64;

i32 mod(i32 a, i32 b);
i32 i32_mod_i32(i32 a, i32 b);
bool bool_not_bool(bool a);
i32 i32_not_i32(i32 a);
void print_b8(c8 val);
void print_c8(c8 val);
void print_i16(i16 val);
void print_i32(i32 val);
void print_i64(i64 val);
void print_f32(f32 val);
void print_f64(f64 val);
void print_string(const c8* str);
void println_b8(c8 val);
void println_c8(c8 val);
void println_i16(i16 val);
void println_i32(i32 val);
void println_i64(i64 val);
void println_f32(f32 val);
void println_f64(f64 val);
void println_string(const c8* str);
void print_format(const c8* fmt, ...);

bool* elt_array_bool(bool* ptr, i32 idx);
b8* elt_array_b8(b8* ptr, i32 idx);
c8* elt_array_c8(c8* ptr, i32 idx);
i16* elt_array_i16(i16* ptr, i32 idx);
i32* elt_array_i32(i32* ptr, i32 idx);
i64* elt_array_i64(i64* ptr, i16 idx);
f32* elt_array_f32(f32* ptr, i16 idx);
f64* elt_array_f64(f64* ptr, i32 idx);
c8** elt_array_string(c8** ptr, i32 idx);

void set_pointer_bool(bool* ptr, bool val);
void set_pointer_b8(c8* ptr, c8 val);
void set_pointer_c8(c8* ptr, c8 val);
void set_pointer_i16(i16* ptr, i16 val);
void set_pointer_i32(i32* ptr, i32 val);
void set_pointer_i64(i64* ptr, i64 val);
void set_pointer_f32(f32* ptr, f32 val);
void set_pointer_f64(f64* ptr, f64 val);
void set_pointer_string(c8** ptr, c8* val);

typedef enum PTR_TYPE {
	ARRAY = 0,
	POINTER = 1,
	LIST = 2,
    VARIABLE = 3
} PTR_TYPE_t;

typedef struct node_ptr {
	int length;
	void* value;
	struct node_ptr* next;
	PTR_TYPE_t type;
} node_ptr_t;

static node_ptr_t* pointer_list = NULL;
