#include <stdbool.h>
#include <stdio.h>
#include <stdarg.h>
#include <math.h>

typedef char byte;
typedef short int16;
typedef int int32;
typedef long int64;
typedef float float32;
typedef double float64;

int32 mod(int32 a, int32 b);
int32 int32_mod_int32(int32 a, int32 b);
bool bool_not_bool(bool a);
int32 int32_not_int32(int32 a);
void print_byte(char val);
void print_char(char val);
void print_int16(int16 val);
void print_int32(int32 val);
void print_int64(int64 val);
void print_float32(float32 val);
void print_float64(float64 val);
void print_string(const char* str);
void println_byte(char val);
void println_char(char val);
void println_int16(int16 val);
void println_int32(int32 val);
void println_int64(int64 val);
void println_float32(float32 val);
void println_float64(float64 val);
void println_string(const char* str);
void print_format(const char* fmt, ...);
bool* elt_bool(bool* ptr, int32 idx);
char* elt_byte(char* ptr, int32 idx);
int16* elt_int16(int16* ptr, int32 idx);
int32* elt_int32(int32* ptr, int32 idx);
int64* elt_int64(int64* ptr, int16 idx);
float32* elt_float32(float32* ptr, int16 idx);
float64* elt_float64(float64* ptr, int32 idx);
char** elt_string(char** ptr, int32 idx);
void set_bool(bool* ptr, bool val);
void set_byte(char* ptr, char val);
void set_int16(int16* ptr, int16 val);
void set_int32(int32* ptr, int32 val);
void set_int64(int64* ptr, int64 val);
void set_float32(float32* ptr, float32 val);
void set_float64(float64* ptr, float64 val);
void set_string(char** ptr, char* val);

#define define_lt(T) \
bool lt_##T(T a, T b){ \
	return a < b; \
}
#define define_leqt(T) \
bool let_##T(T a, T b){ \
	return a <= b; \
}

#define define_gt(T) \
bool gt_##T(T a, T b){ \
	return a > b; \
}
#define define_geqt(T) \
bool get_##T(T a, T b){ \
	return a >= b; \
}

#define define_neq(T) \
bool neq_##T(T a, T b){ \
	return a != b; \
}

#define define_eq(T) \
bool eq_##T(T a, T b){ \
	return a == b; \
}

define_lt(bool)
define_lt(int16)
define_lt(int32)
define_lt(int64)
define_lt(float32)
define_lt(float64)

define_leqt(bool)
define_leqt(int16)
define_leqt(int32)
define_leqt(int64)
define_leqt(float32)
define_leqt(float64)

define_gt(bool)
define_gt(int16)
define_gt(int32)
define_gt(int64)
define_gt(float32)
define_gt(float64)

define_geqt(bool)
define_geqt(int16)
define_geqt(int32)
define_geqt(int64)
define_geqt(float32)
define_geqt(float64)

define_neq(bool)
define_neq(int16)
define_neq(int32)
define_neq(int64)
define_neq(float32)
define_neq(float64)

define_eq(bool)
define_eq(int16)
define_eq(int32)
define_eq(int64)
define_eq(float32)
define_eq(float64)

#define define_add_typed(T) \
T add_typed_##T(T a, T b){ \
    return a+b; \
}

define_add_typed(int16)
define_add_typed(int32)
define_add_typed(int64)
define_add_typed(float32)
define_add_typed(float64)

#define define_sub_typed(T) \
T sub_typed_##T(T a, T b){ \
    return a-b; \
}

define_sub_typed(int16)
define_sub_typed(int32)
define_sub_typed(int64)
define_sub_typed(float32)
define_sub_typed(float64)

#define define_mul_typed(T) \
T mul_typed_##T(T a, T b){ \
    return a*b; \
}

define_mul_typed(int16)
define_mul_typed(int32)
define_mul_typed(int64)
define_mul_typed(float32)
define_mul_typed(float64)

#define define_div_typed(T) \
T div_typed_##T(T a, T b){ \
	if (b != 0) \
		return a/b; \
	else \
		return b; \
}

define_div_typed(int16)
define_div_typed(int32)
define_div_typed(int64)
define_div_typed(float32)
define_div_typed(float64)

#define define_add(T) \
T add_##T(int32 size, ...){ \
    va_list arglist; \
    va_start(arglist, size); \
    T result = 0; \
    \
    for (int32 i = 0; i < size; i++) { \
        result += (T)va_arg(arglist, T); \
    } \
    return (T)result; \
}


define_add(int32)
define_add(float64)

#define define_sub(T) \
T sub_##T(int32 size, ...){ \
    va_list arglist; \
    va_start(arglist, size); \
    T result = va_arg(arglist, T); \
    \
    for (int32 i = 1; i < size; i++) { \
        result -= (T)va_arg(arglist, T); \
    } \
    return (T)result; \
}

define_sub(int32)
define_sub(float64)

#define define_mul(T) \
T mul_##T(int32 size, ...){ \
    va_list arglist; \
    va_start(arglist, size); \
    T result = 0; \
    \
    for (int32 i = 0; i < size; i++) { \
        result *= (T)va_arg(arglist, T); \
    } \
    return (T)result; \
}

define_mul(int32)
define_mul(float64)

#define define_div(T) \
T div_##T(int32 size, ...){ \
    va_list arglist; \
    va_start(arglist, size); \
    T result = va_arg(arglist, T); \
    \
    for (int32 i = 1; i < size; i++) { \
		if (va_arg(arglist, int32) != 0) \
        result /= (T)va_arg(arglist, T); \
    } \
    return (T)result; \
}

define_div(int32)
define_div(float64)

#define define_sqrt(T) \
T sqrt_##T(T a){ \
	return (T)sqrt(a); \
}

define_sqrt(int16)
define_sqrt(int32)
define_sqrt(int64)
define_sqrt(float32)
define_sqrt(float64)

#define define_power(T) \
T power_##T(T a, T b){ \
	return (T)pow(a, b) ; \
}

define_power(int16)
define_power(int32)
define_power(int64)
define_power(float32)
define_power(float64)

#define define_max(T) \
T max_##T(T a, T b){ \
 \
	if (a > b) \
		return a; \
	else \
		return b; \
} 

define_max(int16)
define_max(int32)
define_max(int64)
define_max(float32)
define_max(float64)

#define define_min(T) \
T min_##T(T a, T b) { \
 \
	if (a < b) \
		return a; \
	else \
		return b; \
} 

define_min(int16)
define_min(int32)
define_min(int64)
define_min(float32)
define_min(float64)

#define define_single_fn(T) \
typedef T (*single_fn_##T)(T); \

define_single_fn(bool)
define_single_fn(char)
define_single_fn(int16)
define_single_fn(int32)
define_single_fn(int64)
define_single_fn(float32)
define_single_fn(float64)

#define define_dual_fn(T) \
typedef T (*dual_fn_##T)(T, T); \

define_dual_fn(bool)
define_dual_fn(char)
define_dual_fn(int16)
define_dual_fn(int32)
define_dual_fn(int64)
define_dual_fn(float32)
define_dual_fn(float64)

#define define_map(T) \
T* map_##T(single_fn_##T a, T* b) { \
    int32 cnt = 0; \
    for (cnt = 0; cnt < sizeof(b)-2; cnt++) { \
        b[cnt] = (*a)(b[cnt]); \
    } \
    return b; \
}

define_map(bool)
define_map(char)
define_map(int16)
define_map(int32)
define_map(int64)
define_map(float32)
define_map(float64)
  
#define define_reduce(T) \
T reduce_##T(dual_fn_##T a, T* b) { \
    int32 cnt = 0; \
    T result = b[0]; \
    for (cnt = 1; cnt < sizeof(b)-2; cnt++) { \
      result = (*a)(result, b[cnt]);           \
    } \
    return result; \
}

define_reduce(bool)
define_reduce(char)
define_reduce(int16)
define_reduce(int32)
define_reduce(int64)
define_reduce(float32)
define_reduce(float64)
