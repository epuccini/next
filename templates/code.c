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

#define define_println_list(T) \
void println_list_##T(node_##T* list) {  \
	node_##T* tmp = list; \
	do { \
		print_##T(tmp->value); \
		printf(" "); \
		tmp = tmp->next; \
	} while (tmp != NULL); \
	printf("\n"); \
} \

define_println_list(b8)
define_println_list(c8)
define_println_list(i16)
define_println_list(i32)
define_println_list(i64)
define_println_list(f32)
define_println_list(f64)

#define define_print_list(T) \
void print_list_##T(node_##T* list) {  \
	node_##T* tmp = list; \
	do { \
		print_##T(tmp->value); \
		printf(" "); \
		tmp = tmp->next; \
	} while (tmp != NULL); \
} \

define_print_list(b8)
define_print_list(c8)
define_print_list(i16)
define_print_list(i32)
define_print_list(i64)
define_print_list(f32)
define_print_list(f64)

#define define_println_array(T) \
void println_array_##T(int size, const T* array) {  \
	int cnt = 0; \
	for (cnt = 0; cnt < size/sizeof(T); cnt++) { \
		print_##T(array[cnt]); \
		printf(" "); \
	} \
	printf("\n"); \
} \

	define_println_array(b8)
	define_println_array(c8)
	define_println_array(i16)
	define_println_array(i32)
	define_println_array(i64)
	define_println_array(f32)
	define_println_array(f64)

#define define_print_array(T) \
void print_array_##T(int size, const T* array) {  \
	int cnt = 0; \
	for (cnt = 0; cnt < size/sizeof(T); cnt++) { \
		print_##T(array[cnt]); \
		printf(" "); \
	} \
} \

	define_print_array(b8)
	define_print_array(c8)
	define_print_array(i16)
	define_print_array(i32)
	define_print_array(i64)
	define_print_array(f32)
	define_print_array(f64)

#define define_elt_list(T) \
T* elt_list_##T(node_##T* list, i32 idx) { \
	int cnt; \
	do { \
		cnt++; \
		if (list->next != NULL) { \
			list = list->next; \
		} \
	} while(cnt != idx); \
	return (T*)&list->value; \
} \

	define_elt_list(b8)
	define_elt_list(c8)
	define_elt_list(i16)
	define_elt_list(i32)
	define_elt_list(i64)
	define_elt_list(f32)
	define_elt_list(f64)

#define define_set_list(T) \
void set_list_##T(node_##T* list, T val) { \
	list->value = val; \
	return; \
} \

	define_set_list(b8)
	define_set_list(c8)
	define_set_list(i16)
	define_set_list(i32)
	define_set_list(i64)
	define_set_list(f32)
	define_set_list(f64)


bool* elt_array_bool(bool* ptr, i32 idx) {
    return (bool*)&ptr[idx];
}

b8* elt_array_b8(b8* ptr, i32 idx) {
	return (c8*)&ptr[idx];
}

c8* elt_array_c8(c8* ptr, i32 idx) {
	return (c8*)&ptr[idx];
}

i16* elt_array_i16(i16* ptr, i32 idx) {
    return (i16*)&ptr[idx];
}

i32* elt_array_i32(i32* ptr, i32 idx) {
    return (i32*)&ptr[idx];
}

long* elt_array_i64(long* ptr, i16 idx) {
    return (long*)&ptr[idx];
}

f32* elt_array_f32(f32* ptr, i16 idx) {
    return (f32*)&ptr[idx];
}

f64* elt_array_f64(f64* ptr, i32 idx) {
    return (f64*)&ptr[idx];
}

c8** elt_array_string(c8** ptr, i32 idx) {
	return (c8**)&ptr[idx];
}

void set_pointer_bool(bool* ptr, bool val) {
    *ptr = val;
}

void set_pointer_b8(c8* ptr, c8 val) {
	*ptr = val;
}

void set_pointer_c8(c8* ptr, c8 val) {
	*ptr = val;
}

void set_pointer_i16(i16* ptr, i16 val) {
    *ptr= val;
}

void set_pointer_i32(i32* ptr, i32 val) {
    *ptr = val;
}

void set_pointer_i64(long* ptr, long val) {
    *ptr = val;
}

void set_pointer_f32(f32* ptr, f32 val) {
    *ptr = val;
}

void set_pointer_f64(f64* ptr, f64 val) {
    *ptr = val;
}

void set_pointer_string(c8** ptr, c8* val) {
	*ptr = val;
}

$(IMPLEMENTATION)

