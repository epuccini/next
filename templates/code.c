#include "$(OUTPUT_H)"

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
            if (*p == 'd') {
                int val = va_arg(arglist, int);
                printf("%d", val);
            }
            if (*p == 's') {
                char* val = va_arg(arglist, char*);
                printf("%s", val);
            }
             if (*p == 'c') {
                 int val = va_arg(arglist, int);
                 printf("%c", val);
            }
            continue;
        }
    };
    va_end(arglist);
    printf("\n");
}

bool* elt_bool(bool* ptr, int idx) {
    return (bool*)&ptr[idx];
}

char* elt_byte(char* ptr, int idx) {
    return (char*)&ptr[idx];
}

short* elt_int16(short* ptr, int idx) {
    return (short*)&ptr[idx];
}

int* elt_int32(int* ptr, int idx) {
    return (int*)&ptr[idx];
}

long* elt_int64(long* ptr, short idx) {
    return (long*)&ptr[idx];
}

float* elt_float32(float* ptr, short idx) {
    return (float*)&ptr[idx];
}

double* elt_float64(double* ptr, int idx) {
    return (double*)&ptr[idx];
}

char** elt_string(char** ptr, int idx) {
    return (char**)&ptr[idx];
}

void set_bool(bool* ptr, bool val) {
    *ptr = val;
}

void set_byte(char* ptr, char val) {
    *ptr= val;
}

void set_int16(short* ptr, short val) {
    *ptr= val;
}

void set_int32(int* ptr, int val) {
    *ptr = val;
}

void set_int64(long* ptr, long val) {
    *ptr = val;
}

void set_float32(float* ptr, float val) {
    *ptr = val;
}

void set_float64(double* ptr, double val) {
    *ptr = val;
}

void set_string(char** ptr, char* val) {
    *ptr = val;
}

$(IMPLEMENTATION)
