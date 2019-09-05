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
	*ptr = val;
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

#define define_addn(T) \
T addn_##T(T* array) { \
    T result = array[0]; \
    int cnt = 0; \
    for (cnt = 1; cnt < sizeof(array)-1; cnt++) { \
        result += array[cnt]; \
    } \
    return result; \
} \

	define_addn(i32)
	define_addn(i64)
	define_addn(f32)
	define_addn(f64)

#define define_subn(T) \
T subn_##T(T* array) { \
    T result = array[0]; \
    int cnt = 0; \
    for (cnt = 1; cnt < sizeof(array)-1; cnt++) { \
        result -= array[cnt]; \
    } \
    return result; \
} \

	define_subn(i32)
	define_subn(i64)
	define_subn(f32)
	define_subn(f64)

#define define_muln(T) \
T muln_##T(T* array) { \
    T result = array[0]; \
    int cnt = 0; \
    for (cnt = 1; cnt < sizeof(array)-1; cnt++) { \
        result *= array[cnt]; \
    } \
    return result; \
} \

	define_muln(i32)
	define_muln(i64)
	define_muln(f32)
	define_muln(f64)

#define define_divn(T) \
T divn_##T(T* array) { \
    T result = array[0]; \
    int cnt = 0; \
    for (cnt = 1; cnt < sizeof(array)-1; cnt++) { \
        result /= array[cnt]; \
    } \
    return result; \
} \

	define_divn(i32)
	define_divn(i64)
	define_divn(f32)
	define_divn(f64)

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
} \

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
} \

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
} \

	define_min(i16)
	define_min(i32)
	define_min(i64)
	define_min(f32)
	define_min(f64)

#define define_single_fn(T) \
typedef T (*single_fn_##T)(T); \

	define_single_fn(bool)
	define_single_fn(b8)
	define_single_fn(c8)
	define_single_fn(i16)
	define_single_fn(i32)
	define_single_fn(i64)
	define_single_fn(f32)
	define_single_fn(f64)

#define define_dual_fn(T) \
typedef T (*dual_fn_##T)(T, T); \

	define_dual_fn(bool)
	define_dual_fn(b8)
	define_dual_fn(c8)
	define_dual_fn(i16)
	define_dual_fn(i32)
	define_dual_fn(i64)
	define_dual_fn(f32)
	define_dual_fn(f64)

typedef struct node_ptr {
	int length;
	void* value;
	struct node_ptr* next;
} node_ptr_t;

static node_ptr_t* pointer_list = NULL;

node_ptr_t* append_ptr(void* value, int size) {
	node_ptr_t* head;
	if (pointer_list == NULL) {
		pointer_list = (node_ptr_t*)malloc(sizeof(node_ptr_t));
		pointer_list->next = NULL;
		pointer_list->value = value;
		pointer_list->length = size; 
	} 
	else {
		head = pointer_list;
		do
		{
			if (pointer_list->next != NULL)
				pointer_list = pointer_list->next;
		} while (pointer_list->next != NULL);
		pointer_list->next = (node_ptr_t*)malloc(sizeof(node_ptr_t));
		pointer_list->next->value = value;
		pointer_list = pointer_list->next;
		pointer_list->length = size; 
		pointer_list->next = NULL;
		pointer_list = head; 
	} 
	return pointer_list; 
}

node_ptr_t* remove_ptr(int pos) {
	node_ptr_t* start = pointer_list; \
	node_ptr_t* tmp_before; \
	node_ptr_t* tmp_after; \
	int cnt = 0; \
	do \
	{ \
		cnt++; \
		tmp_before = pointer_list; \
		pointer_list = pointer_list->next; \
	} while (cnt != pos); \
	tmp_after = pointer_list; \
	tmp_before->next = tmp_after->next; \
	free(pointer_list); \
	pointer_list = start; \
	return pointer_list; \
}

int length(void* pointer) {
	node_ptr_t* temp = pointer_list;
	do
	{
		if (temp->value == pointer)
			return temp->length;
		temp = temp->next;
	} while (temp != NULL);
	return 0;
}

void inc_length(void* pointer) {
	node_ptr_t* temp = pointer_list;
	do
	{
		if (temp->value == pointer) {
			temp->length += 1;
			return;
		}
		temp = temp->next;
	} while (temp != NULL);
	return;
}

void destroy_ptr(node_ptr_t* e) {
	if (e != NULL) {
		node_ptr_t* temp = e->next;
		do
		{
			if (e->value)
				free(e->value);
			free(e);
			e = NULL;
			if (temp) {
				e = temp;
				temp = e->next;
			}
		} while (e != NULL);
	}
}

#define define_node(T) \
typedef struct node_##T { \
	T value; \
	struct node_##T * next; \
} node_##T;\

define_node(bool)
define_node(c8)
define_node(b8)
define_node(i16)
define_node(i32)
define_node(i64)
define_node(f32)
define_node(f64)

#define define_append_list(T) \
node_##T* append_list_##T(node_##T* list, T value) {  \
	node_##T* head; \
	if (list == NULL) { \
		list = (node_##T*)malloc(sizeof(node_##T)); \
		list->next = NULL; \
		list->value = value; \
	} \
	else { \
		head = list; \
		do \
		{ \
			if (list->next != NULL) \
				list = list->next; \
		} while (list->next != NULL); \
		list->next = (node_##T*)malloc(sizeof(node_##T)); \
		list->next->value = value; \
		list = list->next; \
		list->next = NULL; \
		list = head; \
	} \
	return list; \
} \

define_append_list(bool)
define_append_list(c8)
define_append_list(b8)
define_append_list(i16)
define_append_list(i32)
define_append_list(i64)
define_append_list(f32)
define_append_list(f64)

#define define_push_list(T) \
node_##T* push_list_##T(node_##T* list, T value) {  \
	node_##T* head = (node_##T*)malloc(sizeof(node_##T)); \
	head->next = list; \
	head->value = value; \
	list = head; \
	return list; \
} \

define_push_list(bool)
define_push_list(c8)
define_push_list(b8)
define_push_list(i16)
define_push_list(i32)
define_push_list(i64)
define_push_list(f32)
define_push_list(f64)

#define define_pop_list(T) \
T pop_list_##T(node_##T** list) {  \
	T value = (*list)->value; \
	if ((*list)->next != NULL) { \
		*list = (*list)->next; \
	} \
	return value; \
} \

define_pop_list(bool)
define_pop_list(c8)
define_pop_list(b8)
define_pop_list(i16)
define_pop_list(i32)
define_pop_list(i64)
define_pop_list(f32)
define_pop_list(f64)

#define define_remove_list(T) \
node_##T* remove_list_##T(node_##T* list, int pos) { \
	node_##T* start = list; \
	node_##T* tmp_before; \
	node_##T* tmp_after; \
	int cnt = 0; \
	do \
	{ \
		tmp_before = list; \
		list = list->next; \
		cnt++; \
	} while (cnt != pos-1); \
	tmp_after = list; \
	tmp_before->next = tmp_after->next; \
	free(list); \
	list = start; \
	return list; \
} \

define_remove_list(bool)
define_remove_list(c8)
define_remove_list(b8)
define_remove_list(i16)
define_remove_list(i32)
define_remove_list(i64)
define_remove_list(f32)
define_remove_list(f64)

#define define_car_list(T) \
T car_list_##T(node_##T* list) { \
return list->value; \
} \

define_car_list(bool)
define_car_list(c8)
define_car_list(b8)
define_car_list(i16)
define_car_list(i32)
define_car_list(i64)
define_car_list(f32)
define_car_list(f64)

#define define_cdr_list(T) \
node_##T* cdr_list_##T(node_##T* list) { \
	return list->next; \
} \

define_cdr_list(bool)
define_cdr_list(c8)
define_cdr_list(b8)
define_cdr_list(i16)
define_cdr_list(i32)
define_cdr_list(i64)
define_cdr_list(f32)
define_cdr_list(f64)

#define define_destroy(T) \
void destroy_list_##T(node_##T* e) { \
	if (e != NULL) { \
		node_##T* temp = e->next; \
		do \
		{ \
			free(e); \
			e = NULL; \
			if (temp) { \
				e = temp; \
				temp = e->next; \
			} \
		} while (e != NULL); \
	} \
} \

define_destroy(bool)
define_destroy(c8)
define_destroy(b8)
define_destroy(i16)
define_destroy(i32)
define_destroy(i64)
define_destroy(f32)
define_destroy(f64)

#define define_create_list(T) \
node_##T* create_list_##T(T list[], int size) {  \
	int cnt = 0; \
	node_##T* ret = NULL; \
	for (cnt = 0; cnt < size; cnt++) { \
		ret = append_list_##T(ret, list[cnt]);  \
	} \
	if(pointer_list != NULL) \
		append_ptr(list, size); \
	return ret; \
} \

	define_create_list(bool)
	define_create_list(c8)
	define_create_list(b8)
	define_create_list(i16)
	define_create_list(i32)
	define_create_list(i64)
	define_create_list(f32)
	define_create_list(f64)

#define define_map(T) \
T* map_##T(single_fn_##T a, T* b) { \
    i32 cnt = 0; \
    for (cnt = 0; cnt < sizeof(b)-2; cnt++) { \
        b[cnt] = (*a)(b[cnt]); \
    } \
    return b; \
}

	define_map(bool)
	define_map(b8)
	define_map(c8)
	define_map(i16)
	define_map(i32)
	define_map(i64)
	define_map(f32)
	define_map(f64)

#define define_mapn(T) \
T* mapn_##T(single_fn_##T a, T* b) { \
    T* ptr = (T*) malloc(sizeof(b) * sizeof(T)); \
	append_ptr((void*)ptr, sizeof(b)-2);\
	i32 cnt = 0; \
    for (cnt = 0; cnt < sizeof(b)-2; cnt++) { \
        ptr[cnt] = (*a)(b[cnt]); \
    } \
    return ptr; \
}

	define_mapn(bool)
	define_mapn(b8)
	define_mapn(c8)
	define_mapn(i16)
	define_mapn(i32)
	define_mapn(i64)
	define_mapn(f32)
	define_mapn(f64)

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


#define define_new(T) \
T* new_##T(int size) { \
	T* mem = (T*)malloc(size*sizeof(T)); \
	append_ptr((void*)mem, size); \
	int cnt = 0; \
	for(cnt = 0; cnt < size; cnt++) \
		mem[cnt] = 0; \
    return mem; \
}

define_new(bool)
define_new(c8)
define_new(i16)
define_new(i32)
define_new(i64)
define_new(f32)
define_new(f64)

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

#define define_println_pointer(T) \
void println_pointer_##T(T* pointer) {  \
	int size = length(pointer); \
	int cnt = 0; \
	for (cnt = 0; cnt < size; cnt++) { \
		print_##T(pointer[cnt]); \
		printf(" "); \
	} \
	printf("\n"); \
} \

	define_println_pointer(b8)
	define_println_pointer(c8)
	define_println_pointer(i16)
	define_println_pointer(i32)
	define_println_pointer(i64)
	define_println_pointer(f32)
	define_println_pointer(f64)

#define define_print_pointer(T) \
void print_pointer_##T(T* pointer) {  \
	int size = length((void*)pointer); \
	int cnt = 0; \
	for (cnt = 0; cnt < size; cnt++) { \
		print_##T(pointer[cnt]); \
		printf(" "); \
	} \
} \

	define_print_pointer(b8)
	define_print_pointer(c8)
	define_print_pointer(i16)
	define_print_pointer(i32)
	define_print_pointer(i64)
	define_print_pointer(f32)
	define_print_pointer(f64)

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

#define define_append_array(T) \
T* append_array_##T(T* array, T value) {  \
    int size = length(array); \
    T* new_array = (T*) malloc((size+1)*sizeof(T)); \
	int cnt = 0; \
	for (cnt = 0; cnt < size; cnt++) { \
		new_array[cnt] = array[cnt]; \
	} \
	new_array[size] = value; \
	append_ptr(new_array, size+1); \
	return new_array; \
} 

	define_append_array(bool)
	define_append_array(c8)
	define_append_array(b8)
	define_append_array(i16)
	define_append_array(i32)
	define_append_array(i64)
	define_append_array(f32)
	define_append_array(f64)

#define define_append_pointer(T) \
T* append_pointer_##T(T* array, T value) {  \
    int size = length(array); \
    T* new_array = (T*) malloc((size+1)*sizeof(T)); \
	int cnt = 0; \
	for (cnt = 0; cnt < size; cnt++) { \
		new_array[cnt] = array[cnt]; \
	} \
	new_array[size] = value; \
	append_ptr(new_array, size+1); \
	return new_array; \
} 

		define_append_pointer(bool)
		define_append_pointer(c8)
		define_append_pointer(b8)
		define_append_pointer(i16)
		define_append_pointer(i32)
		define_append_pointer(i64)
		define_append_pointer(f32)
		define_append_pointer(f64)

$(IMPLEMENTATION)

