#include <stdbool.h>
#include <stdio.h>
#include <stdarg.h>
#include <math.h>

int mod(int a, int b);
int int32_mod_int32(int a, int b);
bool bool_not_bool(bool a);
int int32_not_int32(int a);
void print_byte(char val);
void print_char(char val);
void print_int16(short val);
void print_int32(int val);
void print_int64(long val);
void print_float32(float val);
void print_float64(double val);
void print_str(const char* str);
void println_byte(char val);
void println_char(char val);
void println_int16(short val);
void println_int32(int val);
void println_int64(long val);
void println_float32(float val);
void println_float64(double val);
void println_str(const char* str);
void print_format(const char* fmt, ...);
bool* elt_bool(bool* ptr, int idx);
char* elt_byte(char* ptr, int idx);
short* elt_int16(short* ptr, int idx);
int* elt_int32(int* ptr, int idx);
long* elt_int64(long* ptr, short idx);
float* elt_float32(float* ptr, short idx);
double* elt_float64(double* ptr, int idx);
char** elt_string(char** ptr, int idx);
void set_bool(bool* ptr, bool val);
void set_byte(char* ptr, char val);
void set_int16(short* ptr, short val);
void set_int32(int* ptr, int val);
void set_int64(long* ptr, long val);
void set_float32(float* ptr, float val);
void set_float64(double* ptr, double val);
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
define_lt(short)
define_lt(int)
define_lt(long)
define_lt(float)
define_lt(double)

define_leqt(bool)
define_leqt(short)
define_leqt(int)
define_leqt(long)
define_leqt(float)
define_leqt(double)

define_gt(bool)
define_gt(short)
define_gt(int)
define_gt(long)
define_gt(float)
define_gt(double)

define_geqt(bool)
define_geqt(short)
define_geqt(int)
define_geqt(long)
define_geqt(float)
define_geqt(double)

define_neq(bool)
define_neq(short)
define_neq(int)
define_neq(long)
define_neq(float)
define_neq(double)

define_eq(bool)
define_eq(short)
define_eq(int)
define_eq(long)
define_eq(float)
define_eq(double)

#define define_add_typed(T) \
T add_typed_##T(T a, T b){ \
    return a+b; \
}

define_add_typed(short)
define_add_typed(int)
define_add_typed(long)
define_add_typed(float)
define_add_typed(double)

#define define_sub_typed(T) \
T sub_typed_##T(T a, T b){ \
    return a-b; \
}

define_sub_typed(short)
define_sub_typed(int)
define_sub_typed(long)
define_sub_typed(float)
define_sub_typed(double)

#define define_mul_typed(T) \
T mul_typed_##T(T a, T b){ \
    return a*b; \
}

define_mul_typed(short)
define_mul_typed(int)
define_mul_typed(long)
define_mul_typed(float)
define_mul_typed(double)

#define define_div_typed(T) \
T div_typed_##T(T a, T b){ \
	if (b != 0) \
		return a/b; \
	else \
		return b; \
}

define_div_typed(short)
define_div_typed(int)
define_div_typed(long)
define_div_typed(float)
define_div_typed(double)

#define define_add(T) \
T add_##T(int size, ...){ \
    va_list arglist; \
    va_start(arglist, size); \
    T result = 0; \
    \
    for (int i = 0; i < size; i++) { \
        result += (T)va_arg(arglist, T); \
    } \
    return (T)result; \
}


define_add(int)
define_add(double)

#define define_sub(T) \
T sub_##T(int size, ...){ \
    va_list arglist; \
    va_start(arglist, size); \
    T result = va_arg(arglist, T); \
    \
    for (int i = 1; i < size; i++) { \
        result -= (T)va_arg(arglist, T); \
    } \
    return (T)result; \
}

define_sub(int)
define_sub(double)

#define define_mul(T) \
T mul_##T(int size, ...){ \
    va_list arglist; \
    va_start(arglist, size); \
    T result = 0; \
    \
    for (int i = 0; i < size; i++) { \
        result *= (T)va_arg(arglist, T); \
    } \
    return (T)result; \
}

define_mul(int)
define_mul(double)

#define define_div(T) \
T div_##T(int size, ...){ \
    va_list arglist; \
    va_start(arglist, size); \
    T result = va_arg(arglist, T); \
    \
    for (int i = 1; i < size; i++) { \
		if (va_arg(arglist, int) != 0) \
        result /= (T)va_arg(arglist, T); \
    } \
    return (T)result; \
}

define_div(int)
define_div(double)

#define define_sqrt(T) \
T sqrt_##T(T a){ \
	return (T)sqrt(a); \
}

define_sqrt(short)
define_sqrt(int)
define_sqrt(long)
define_sqrt(float)
define_sqrt(double)

#define define_power(T) \
T power_##T(T a, T b){ \
	return (T)pow(a, b) ; \
}

define_power(short)
define_power(int)
define_power(long)
define_power(float)
define_power(double)

#define define_max(T) \
T max_##T(T a, T b){ \
 \
	if (a > b) \
		return a; \
	else \
		return b; \
} 

define_max(short)
define_max(int)
define_max(long)
define_max(float)
define_max(double)

#define define_min(T) \
T min_##T(T a, T b) { \
 \
	if (a < b) \
		return a; \
	else \
		return b; \
} 

define_min(short)
define_min(int)
define_min(long)
define_min(float)
define_min(double)

