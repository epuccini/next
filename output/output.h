#include <stdbool.h>
#include <stdio.h>
#include <stdarg.h>

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
short add_byte(int size, ...);
short add_short(int size, ...);
int add_int32(int size, ...);
long add_int64(int size, ...);
float add_float32(int size, ...);
double add_float64(int size, ...);
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
