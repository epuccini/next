#include "$(OUTPUT_H)"

i32 mod(i32 a, i32 b) {
	return a % b;
}

i32 i32_mod_i32(i32 a, i32 b) {
    return a % b;
}

bool bool_not_bool(bool a) {
    return !a;
}

i32 i32_not_i32(i32 a) {
    return !a;
}

void print_c8(c8 val) {
    printf("%c", val);
}

void print_b8(c8 val) {
    printf("%d", val);
}

void print_i16(i16 val) {
    printf("%d", val);
}

void print_i32(i32 val) {
    printf("%d", val);
}

void print_i64(long val) {
    printf("%ld", val);
}

void print_f32(f32 val) {
    printf("%f", val);
}

void print_f64(f64 val) {
    printf("%lf", val);
}

void print_string(const c8* str) {
    printf("%s", str);
}

void println_b8(c8 val) {
    printf("%d\n", val);
}

void println_c8(c8 val) {
    printf("%c\n", val);
}

void println_i16(i16 val) {
    printf("%d\n", val);
}

void println_i32(i32 val) {
    printf("%d \n", val);
}

void println_i64(long val) {
    printf("%ld \n", val);
}

void println_f32(f32 val) {
    printf("%f \n", val);
}

void println_f64(f64 val) {
    printf("%lf \n", val);
}

void println_string(const c8* str) {
    printf("%s \n", str);
}

void print_format(const c8* fmt, ...) {
    va_list arglist;
    va_start(arglist, fmt);
    const c8* p;
    
    for(p = fmt; *p != '\0'; p++) {
        if (*p == '%') {
            p++;
            if (*p == 'd') {
                i32 val = va_arg(arglist, i32);
                printf("%d", val);
            }
            if (*p == 's') {
                c8* val = va_arg(arglist, c8*);
                printf("%s", val);
            }
             if (*p == 'c') {
                 i32 val = va_arg(arglist, i32);
                 printf("%c", val);
            }
            continue;
        }
    };
    va_end(arglist);
    printf("\n");
}

bool* elt_bool(bool* ptr, i32 idx) {
    return (bool*)&ptr[idx];
}

c8* elt_b8(c8* ptr, i32 idx) {
    return (c8*)&ptr[idx];
}

i16* elt_i16(i16* ptr, i32 idx) {
    return (i16*)&ptr[idx];
}

i32* elt_i32(i32* ptr, i32 idx) {
    return (i32*)&ptr[idx];
}

long* elt_i64(long* ptr, i16 idx) {
    return (long*)&ptr[idx];
}

f32* elt_f32(f32* ptr, i16 idx) {
    return (f32*)&ptr[idx];
}

f64* elt_f64(f64* ptr, i32 idx) {
    return (f64*)&ptr[idx];
}

c8** elt_string(c8** ptr, i32 idx) {
    return (c8**)&ptr[idx];
}

void set_bool(bool* ptr, bool val) {
    *ptr = val;
}

void set_b8(c8* ptr, c8 val) {
    *ptr= val;
}

void set_i16(i16* ptr, i16 val) {
    *ptr= val;
}

void set_i32(i32* ptr, i32 val) {
    *ptr = val;
}

void set_i64(long* ptr, long val) {
    *ptr = val;
}

void set_f32(f32* ptr, f32 val) {
    *ptr = val;
}

void set_f64(f64* ptr, f64 val) {
    *ptr = val;
}

void set_string(c8** ptr, c8* val) {
    *ptr = val;
}

$(IMPLEMENTATION)

