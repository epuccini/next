#include <stdio.h>
#include <stdarg.h>

int mod(int a, int b);
int int_mod_int(int a, int b);
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
char plus_byte(int size, ...);
short plus_short(int size, ...);
int plus_int32(int size, ...);
long plus_int64(int size, ...);
float plus_float32(int size, ...);
double plus_float64(int size, ...);

