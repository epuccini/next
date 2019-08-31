#include <stdbool.h>
#include <stdio.h>
#include <stdarg.h>
#include <math.h>

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
bool* elt_bool(bool* ptr, i32 idx);
c8* elt_b8(c8* ptr, i32 idx);
i16* elt_i16(i16* ptr, i32 idx);
i32* elt_i32(i32* ptr, i32 idx);
i64* elt_i64(i64* ptr, i16 idx);
f32* elt_f32(f32* ptr, i16 idx);
f64* elt_f64(f64* ptr, i32 idx);
c8** elt_string(c8** ptr, i32 idx);
void set_bool(bool* ptr, bool val);
void set_b8(c8* ptr, c8 val);
void set_i16(i16* ptr, i16 val);
void set_i32(i32* ptr, i32 val);
void set_i64(i64* ptr, i64 val);
void set_f32(f32* ptr, f32 val);
void set_f64(f64* ptr, f64 val);
void set_string(c8** ptr, c8* val);

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
define_lt(i16)
define_lt(i32)
define_lt(i64)
define_lt(f32)
define_lt(f64)

define_leqt(bool)
define_leqt(i16)
define_leqt(i32)
define_leqt(i64)
define_leqt(f32)
define_leqt(f64)

define_gt(bool)
define_gt(i16)
define_gt(i32)
define_gt(i64)
define_gt(f32)
define_gt(f64)

define_geqt(bool)
define_geqt(i16)
define_geqt(i32)
define_geqt(i64)
define_geqt(f32)
define_geqt(f64)

define_neq(bool)
define_neq(i16)
define_neq(i32)
define_neq(i64)
define_neq(f32)
define_neq(f64)

define_eq(bool)
define_eq(i16)
define_eq(i32)
define_eq(i64)
define_eq(f32)
define_eq(f64)

#define define_add_typed(T) \
T add_typed_##T(T a, T b){ \
    return a+b; \
}

define_add_typed(i16)
define_add_typed(i32)
define_add_typed(i64)
define_add_typed(f32)
define_add_typed(f64)

#define define_sub_typed(T) \
T sub_typed_##T(T a, T b){ \
    return a-b; \
}

define_sub_typed(i16)
define_sub_typed(i32)
define_sub_typed(i64)
define_sub_typed(f32)
define_sub_typed(f64)

#define define_mul_typed(T) \
T mul_typed_##T(T a, T b){ \
    return a*b; \
}

define_mul_typed(i16)
define_mul_typed(i32)
define_mul_typed(i64)
define_mul_typed(f32)
define_mul_typed(f64)

#define define_div_typed(T) \
T div_typed_##T(T a, T b){ \
	if (b != 0) \
		return a/b; \
	else \
		return b; \
}

define_div_typed(i16)
define_div_typed(i32)
define_div_typed(i64)
define_div_typed(f32)
define_div_typed(f64)

#define define_add(T) \
T add_##T(i32 size, ...){ \
    va_list arglist; \
    va_start(arglist, size); \
    T result = 0; \
    \
    for (i32 i = 0; i < size; i++) { \
        result += (T)va_arg(arglist, T); \
    } \
    return (T)result; \
}


define_add(i32)
define_add(f64)

#define define_sub(T) \
T sub_##T(i32 size, ...){ \
    va_list arglist; \
    va_start(arglist, size); \
    T result = va_arg(arglist, T); \
    \
    for (i32 i = 1; i < size; i++) { \
        result -= (T)va_arg(arglist, T); \
    } \
    return (T)result; \
}

define_sub(i32)
define_sub(f64)

#define define_mul(T) \
T mul_##T(i32 size, ...){ \
    va_list arglist; \
    va_start(arglist, size); \
    T result = 0; \
    \
    for (i32 i = 0; i < size; i++) { \
        result *= (T)va_arg(arglist, T); \
    } \
    return (T)result; \
}

define_mul(i32)
define_mul(f64)

#define define_div(T) \
T div_##T(i32 size, ...){ \
    va_list arglist; \
    va_start(arglist, size); \
    T result = va_arg(arglist, T); \
    \
    for (i32 i = 1; i < size; i++) { \
		if (va_arg(arglist, i32) != 0) \
        result /= (T)va_arg(arglist, T); \
    } \
    return (T)result; \
}

define_div(i32)
define_div(f64)

#define define_sqrt(T) \
T sqrt_##T(T a){ \
	return (T)sqrt(a); \
}

define_sqrt(i16)
define_sqrt(i32)
define_sqrt(i64)
define_sqrt(f32)
define_sqrt(f64)

#define define_power(T) \
T power_##T(T a, T b){ \
	return (T)pow(a, b) ; \
}

define_power(i16)
define_power(i32)
define_power(i64)
define_power(f32)
define_power(f64)

#define define_max(T) \
T max_##T(T a, T b){ \
 \
	if (a > b) \
		return a; \
	else \
		return b; \
} 

define_max(i16)
define_max(i32)
define_max(i64)
define_max(f32)
define_max(f64)

#define define_min(T) \
T min_##T(T a, T b) { \
 \
	if (a < b) \
		return a; \
	else \
		return b; \
} 

define_min(i16)
define_min(i32)
define_min(i64)
define_min(f32)
define_min(f64)

#define define_single_fn(T) \
typedef T (*single_fn_##T)(T); \

define_single_fn(bool)
define_single_fn(c8)
define_single_fn(i16)
define_single_fn(i32)
define_single_fn(i64)
define_single_fn(f32)
define_single_fn(f64)

#define define_dual_fn(T) \
typedef T (*dual_fn_##T)(T, T); \

define_dual_fn(bool)
define_dual_fn(c8)
define_dual_fn(i16)
define_dual_fn(i32)
define_dual_fn(i64)
define_dual_fn(f32)
define_dual_fn(f64)

#define define_map(T) \
T* map_##T(single_fn_##T a, T* b) { \
    i32 cnt = 0; \
    for (cnt = 0; cnt < sizeof(b)-2; cnt++) { \
        b[cnt] = (*a)(b[cnt]); \
    } \
    return b; \
}

define_map(bool)
define_map(c8)
define_map(i16)
define_map(i32)
define_map(i64)
define_map(f32)
define_map(f64)
  
#define define_reduce(T) \
T reduce_##T(dual_fn_##T a, T* b) { \
    i32 cnt = 0; \
    T result = b[0]; \
    for (cnt = 1; cnt < sizeof(b)-2; cnt++) { \
      result = (*a)(result, b[cnt]);           \
    } \
    return result; \
}

define_reduce(bool)
define_reduce(c8)
define_reduce(i16)
define_reduce(i32)
define_reduce(i64)
define_reduce(f32)
define_reduce(f64)
