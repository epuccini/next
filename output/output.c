#include "output.h"

int mod(int a, int b) {
	return a % b;
}

int int32_mod_int32(int a, int b) {
    return a % b;
}

bool bool_not_bool(bool a) {
    return !a;
}

int int32_not_int32(int a) {
    return !a;
}

void print_char(char val) {
    printf("%c", val);
}

void print_byte(char val) {
    printf("%d", val);
}

void print_int16(short val) {
    printf("%d", val);
}

void print_int32(int val) {
    printf("%d", val);
}

void print_int64(long val) {
    printf("%ld", val);
}

void print_float32(float val) {
    printf("%f", val);
}

void print_float64(double val) {
    printf("%lf", val);
}

void print_str(const char* str) {
    printf("%s", str);
}

void println_byte(char val) {
    printf("%d\n", val);
}

void println_char(char val) {
    printf("%c\n", val);
}

void println_int16(short val) {
    printf("%d\n", val);
}

void println_int32(int val) {
    printf("%d \n", val);
}

void println_int64(long val) {
    printf("%ld \n", val);
}

void println_float32(float val) {
    printf("%f \n", val);
}

void println_float64(double val) {
    printf("%lf \n", val);
}

void println_str(const char* str) {
    printf("%s \n", str);
}

void print_format(const char* fmt, ...) {
    va_list arglist;
    va_start(arglist, fmt);
    const char* p;
    
    for(p = fmt; *p != '\0'; p++) {
        if (*p == '%') {
            p++;
            if (*p == 'd')
                printf("%d", va_arg(arglist, int));
            if (*p == 's')
                printf("%s", va_arg(arglist, char*));
            if (*p == 'c')
                printf("%c", va_arg(arglist, int));
            continue;
        }
    };
    va_end(arglist);
    printf("\n");
}

short plus_byte(int size, ...) {
    va_list arglist;
    va_start(arglist, size);
    char result = 0;
    
    for (int i = 0; i < size; i++) {
        result += (char)va_arg(arglist, int);
    }
    return (short)result;
}

short plus_int16(int size, ...) {
    va_list arglist;
    va_start(arglist, size);
    short result = 0;
    
    for (int i = 0; i < size; i++) {
        result += (short) va_arg(arglist, int);
    }
    return result;
}

int plus_int32(int size, ...) {
    va_list arglist;
    va_start(arglist, size);
    int result = 0;
    
    for (int i = 0; i < size; i++) {
        result += va_arg(arglist, int);
    }
    return result;
}

long plus_int64(int size, ...) {
    va_list arglist;
    va_start(arglist, size);
    long result = 0;
    
    for (int i = 0; i < size; i++) {
        result += va_arg(arglist, long);
    }
    return result;
}

float plus_float32(int size, ...) {
    va_list arglist;
    va_start(arglist, size);
    float result = 0;
    
    for (int i = 0; i < size; i++) {
        result += (float) va_arg(arglist, double);
    }
    return result;
}

double plus_float64(int size, ...) {
    va_list arglist;
    va_start(arglist, size);
    double result = 0;
    
    for (int i = 0; i < size; i++) {
        result += va_arg(arglist, double);
    }
    return result;
}


int test_1(int op1_1,float op2_1)
{
println_int32(op1_1);
println_float32(op2_1);
return(111);
}
int main()
{
{
float arg1_2=0.0;
float arg2_2=0.0;
print_float32(arg1_2);
print_float32(arg2_2);
print_str("ENDE");
}
}


mod(9,5);
mod(9,mod(12,10));
mod(9,mod(12,mod(4,9)));
mod(9,mod(12,mod(9,mod(4,3))));
{
char* arg_1="";
int block_1=0;
print_str("HELLO");
}

