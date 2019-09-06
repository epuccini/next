#include "output.h"

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

node_ptr_t* append_ptr(void* value, int size, PTR_TYPE_t type) {
	node_ptr_t* head;
	if (pointer_list == NULL) {
		pointer_list = (node_ptr_t*)malloc(sizeof(node_ptr_t));
		pointer_list->next = NULL;
		pointer_list->value = value;
		pointer_list->type = type;
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
		pointer_list->next->type = type;
		pointer_list = pointer_list->next;
		pointer_list->length = size; 
		pointer_list->next = NULL;
		pointer_list = head; 
	} 
	return pointer_list; 
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
i32 length_list(node_ptr_t* list) {
	
	int cnt = 0; 
	if (list != NULL) { 
		cnt = 1; 
		node_ptr_t* temp = list->next;
		do 
		{ 
			cnt++; \
			temp = temp->next; 
		} while (temp->next != NULL); 
	} 
	return cnt; 
} 

void remove_ptr(void* pointer) {
	node_ptr_t* temp = pointer_list;
	node_ptr_t* temp_before = pointer_list;
	node_ptr_t* temp_after = pointer_list;

	do
	{	
		if (temp_before->value == pointer) {
			pointer_list = temp_before->next;
			free(temp_before);
			return;
		}
		if (temp_before->next != NULL) {
			if (temp_before->next->value == pointer) {
				temp = temp_before->next;
				if (temp_before->next->next != NULL)
					temp_after = temp_before->next->next;
				free(temp);
				if (temp_before->next->next != NULL)
					temp_before->next = temp_after;
				return;
			}
		}
		temp_before = temp_before->next;
	} while (temp_before != NULL);
	return;
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

void delete_ptr(void* pointer) {
    node_ptr_t* temp = pointer_list;
    do
    {
        if (temp->value == pointer) {
            if (temp->type != ARRAY && temp->type != VARIABLE)
                free(pointer);
            return;
        }
        temp = temp->next;
    } while (temp != NULL);
    return;
}

int destroy_ptr(node_ptr_t* e) {
	if (e != NULL) {
        if (e->next != NULL) {
            node_ptr_t* temp = e->next;
            do
            {
                if (e->type != ARRAY && e->type != VARIABLE)
                    free(e);
                e = NULL;
                e = temp;
                temp = e->next;
            } while (e->next != NULL);
        }
        else {
            if (e->type != ARRAY && e->type != VARIABLE)
                free(e);
        }
	}
	return 0;
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

#define define_append_array(T) \
T* append_array_##T(T* array, T value) {  \
    int size = length(array); \
    T* new_array = (T*) malloc((size+1)*sizeof(T)); \
    int cnt = 0; \
    for (cnt = 0; cnt < size; cnt++) { \
        new_array[cnt] = array[cnt]; \
    } \
    new_array[size] = value; \
    append_ptr(new_array, size+1, POINTER);             \
    remove_ptr(array);       \
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

#define define_length_list(T) \
i32 length_list_##T(node_##T* list) {  \
	int cnt = 0; \
	if (list != NULL) { \
		cnt = 1; \
		node_##T* temp = list->next; \
		do \
		{ \
			cnt++; \
			temp = temp->next; \
		} while (temp != NULL); \
	} \
	return cnt; \
} \

define_length_list(bool)
define_length_list(c8)
define_length_list(b8)
define_length_list(i16)
define_length_list(i32)
define_length_list(i64)
define_length_list(f32)
define_length_list(f64)

#define define_length_array(T) \
i32 length_array_##T(void* array) {  \
	return length(array); \
} \

define_length_array(bool)
define_length_array(c8)
define_length_array(b8)
define_length_array(i16)
define_length_array(i32)
define_length_array(i64)
define_length_array(f32)
define_length_array(f64)

#define define_length_pointer(T) \
i32 length_pointer_##T(void* pointer) {  \
	return length(pointer); \
} \

define_length_pointer(bool)
define_length_pointer(c8)
define_length_pointer(b8)
define_length_pointer(i16)
define_length_pointer(i32)
define_length_pointer(i64)
define_length_pointer(f32)
define_length_pointer(f64)

#define define_push_list(T) \
node_##T* push_list_##T(node_##T** list, T value) {  \
	node_##T* head = (node_##T*)malloc(sizeof(node_##T)); \
	head->next = (*list); \
	head->value = value; \
	append_ptr((void*)head, length(*list)+1, LIST);       \
	remove_ptr((*list));       \
	*list = head; \
	return (*list); \
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
	remove_ptr(*list);       \
	if ((*list)->next != NULL) { \
		*list = (*list)->next; \
	} \
	append_ptr((*list), length(*list)-1, LIST);       \
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
	append_ptr(ret, size, LIST); \
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
	append_ptr((void*)ptr, sizeof(b)-2, POINTER);\
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
	append_ptr((void*)mem, size, POINTER);       \
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
	int cnt = 0; \
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

#define define_append_pointer(T) \
T* append_pointer_##T(T* array, T value) {  \
    int size = length(array); \
    T* new_array = (T*) malloc((size+1)*sizeof(T)); \
	int cnt = 0; \
	for (cnt = 0; cnt < size; cnt++) { \
		new_array[cnt] = array[cnt]; \
	} \
	new_array[size] = value; \
	append_ptr(new_array, size+1, POINTER); \
	remove_ptr(array);       \
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

#define define_set_pointer_list(T) \
void set_pointer_list_##T(node_##T** ptr, node_##T* val){ \
	(*ptr) = val; \
}

	define_set_pointer_list(bool)
	define_set_pointer_list(c8)
	define_set_pointer_list(b8)
	define_set_pointer_list(i16)
	define_set_pointer_list(i32)
	define_set_pointer_list(i64)
	define_set_pointer_list(f32)
	define_set_pointer_list(f64)

#define define_set_pointer_array(T) \
void set_pointer_array_##T(T** ptr, T* val){ \
	(*ptr) = val; \
}

	define_set_pointer_array(bool)
	define_set_pointer_array(c8)
	define_set_pointer_array(b8)
	define_set_pointer_array(i16)
	define_set_pointer_array(i32)
	define_set_pointer_array(i64)
	define_set_pointer_array(f32)
	define_set_pointer_array(f64)

#define define_set_pointer_pointer(T) \
void set_pointer_pointer_##T(T** ptr, T* val){ \
	(*ptr) = val; \
}

	define_set_pointer_pointer(bool)
	define_set_pointer_pointer(c8)
	define_set_pointer_pointer(b8)
	define_set_pointer_pointer(i16)
	define_set_pointer_pointer(i32)
	define_set_pointer_pointer(i64)
	define_set_pointer_pointer(f32)
	define_set_pointer_pointer(f64)

void print_str_pointer_c8(c8* array, c8* value) {
	sprintf(array, "%s", value);
}

void print_str_array_c8(c8* array, c8* value) {
	sprintf(array, "%s", value);
}

void print_str_string(c8* array, c8* value) {
	sprintf(array, "%s", value);
}

void print_str_pointer_i16(c8* pointer, i16* value) {
	int cnt = 0;
	for (cnt = 0; cnt < length(pointer); cnt++)
		sprintf(pointer, "%d", value[cnt]);
}

void print_str_array_i16(c8* pointer, i16* value) {
	int cnt = 0;
	for (cnt = 0; cnt < length(pointer); cnt++)
		sprintf(pointer, "%d", value[cnt]);
}

void print_str_pointer_i32(c8* pointer, i32* value) {
	int cnt = 0;
	for (cnt = 0; cnt < length(pointer); cnt++)
		sprintf(pointer, "%d", value[cnt]);
}

void print_str_array_i32(c8* pointer, i32* value) {
	int cnt = 0;
	for (cnt = 0; cnt < length(pointer); cnt++)
		sprintf(pointer, "%d", value[cnt]);
}

void print_str_pointer_i64(c8* pointer, i64* value) {
	int cnt = 0;
	for (cnt = 0; cnt < length(pointer); cnt++)
		sprintf(pointer, "%ld", value[cnt]);
}

void print_str_array_i64(c8* pointer, i64* value) {
	int cnt = 0;
	for (cnt = 0; cnt < length(pointer); cnt++)
		sprintf(pointer, "%ld", value[cnt]);
}

void print_str_pointer_f32(c8* pointer, f32* value) {
	int cnt = 0;
	for (cnt = 0; cnt < length(pointer); cnt++)
		sprintf(pointer, "%f", value[cnt]);
}

void print_str_array_f32(c8* pointer, f32* value) {
	int cnt = 0;
	for (cnt = 0; cnt < length(pointer); cnt++)
		sprintf(pointer, "%f", value[cnt]);
}

void print_str_pointer_f64(c8* pointer, f64* value) {
	int cnt = 0;
	for (cnt = 0; cnt < length(pointer); cnt++)
		sprintf(pointer, "%lf", value[cnt]);
}

void print_str_array_f64(c8* pointer, f64* value) {
	int cnt = 0;
	for (cnt = 0; cnt < length(pointer); cnt++)
		sprintf(pointer, "%lf", value[cnt]);
}




i32 layer__fun1_0()
{
println_string("Module function fun1");
return(999);
}
i32 layer__fun2_0()
{
layer__fun1_0();
println_string("Module function fun2");
return(888);
}
f32 mapit_0(f32 op_1)
{
print_string("Map ");
println_f64((op_1+op_1));
return((op_1+op_1));
}
f32 reduceit_0(f32 op1_1,f32 op2_1)
{
print_string("Reduce ");
println_f32((f32)(op1_1+op2_1));
return((op1_1+op2_1));
}
void work_0(f32 (*f_1)(f32),i32 arg_1)
{
print_format("%f",(*f_1)(arg_1));
}
i32 arrays_and_lists_0(i32 argc_1)
{
mapit_0(5.5);
println_string("Call module functions ");
layer__fun1_0();
layer__fun2_0();
{
f32 float1_2=0.0;
f32 float2_2=(0.0+0.0);
i32 array_2[]={1, 2, 3, 4, 5, 6};
append_ptr(array_2, sizeof(array_2)/sizeof(i32), ARRAY);
f32 values_2[]={1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
append_ptr(values_2, sizeof(values_2)/sizeof(f32), ARRAY);
f32* my_new_array_2=mapn_f32(mapit_0,values_2);
append_ptr(my_new_array_2, 1, VARIABLE);
f32* my_new_floats_2=new_f32(10);
append_ptr(my_new_floats_2, 1, VARIABLE);
f32* my_new_array2_2=append_array_f32(values_2,1000.0);
append_ptr(my_new_array2_2, 1, VARIABLE);
f32* my_new_array3_2=append_pointer_f32(my_new_array2_2,2000.0);
append_ptr(my_new_array3_2, 1, VARIABLE);
node_f32* my_list_2=create_list_f32((f32[]){1.0, 2.0, 3.0, 4.0, 5.0, 6.0},6);
const char* string_2="abcdefg";
c8 chars_2[]={'a', 'b', 'c', 'd', 'e', 'f', 'g'};
append_ptr(chars_2, sizeof(chars_2)/sizeof(c8), ARRAY);
c8 new_string_2[]="Just a string";
append_ptr(new_string_2, sizeof(new_string_2)/sizeof(c8), ARRAY);
f32 (*myfun_2)(f32)=mapit_0;
set_pointer_f32((f32*)elt_array_f32(my_new_floats_2,0),888.0);
print_string("my-new-floats set 1. element: ");
println_pointer_f32(my_new_floats_2);
print_string("My new array1: ");
println_pointer_f32(my_new_array_2);
print_string("My new array1 length: ");
println_i32(length_pointer_f32(my_new_array_2));
print_string("My new array2: ");
println_pointer_f32(my_new_array2_2);
print_string("My new array3: ");
println_pointer_f32(my_new_array3_2);
print_string("My new array3 gets array values: ");
set_pointer_pointer_f32(&my_new_array3_2,values_2);
println_pointer_f32(my_new_array3_2);
print_string("string print to string: ");
println_array_c8(sizeof(new_string_2),new_string_2);
print_str_array_c8(new_string_2,"EDWARD");
println_array_c8(sizeof(new_string_2),new_string_2);
print_string("My list push ");
push_list_f32(&my_list_2,888.0);
println_list_f32(my_list_2);
print_string("My list set/push ");
set_pointer_list_f32(&my_list_2,push_list_f32(&my_list_2,777.0));
println_list_f32(my_list_2);
print_string("My list length ");
println_i32(length_list_f32(my_list_2));
print_string("My list length after push ");
println_i32(length_pointer_f32((f32*)push_list_f32(&my_list_2,100.0)));
print_string("My list car ");
println_f32((f32)car_list_f32(my_list_2));
print_string("My list remove 3 ");
remove_list_f32(my_list_2,3);
println_list_f32(my_list_2);
print_string("My list pop ");
println_f32((f32)pop_list_f32(&my_list_2));
print_string("My list length ");
println_i32(length_list_f32(my_list_2));
print_string("My list append ");
append_list_f32(my_list_2,666.0);
println_list_f32(my_list_2);
print_string("My list element ");
println_i32(*elt_list_f32(my_list_2,3));
set_pointer_f32((f32*)elt_list_f32(my_list_2,3),100.0);
print_string("My list set ");
println_list_f32(my_list_2);
print_string("My values ");
println_array_f32(sizeof(values_2),values_2);
mapit_0(1000.0);
work_0(mapit_0,100);
map_f32(mapit_0,values_2);
reduce_f32(reduceit_0,values_2);
print_string("String: ");
println_string(string_2);
print_string("Chars: ");
println_array_c8(sizeof(chars_2),chars_2);
print_string("sizeof: ");
println_i32(sizeof(string_2));
set_pointer_f32(&float1_2,666.0);
set_pointer_i32(&argc_1,(100+(1000-500)+100+(1000*500)));
println_i32(argc_1);
set_pointer_i32(&argc_1,(100+(1000-999)));
println_i32(argc_1);
delete_ptr(my_new_array_2);
delete_ptr(my_new_floats_2);
delete_ptr(my_new_array2_2);
delete_ptr(my_new_array3_2);
i32 cnt_3=0;
for(cnt_3=0;cnt_3<max_i32(20,10);cnt_3++)
{
print_format("%d",power_i32(2,8));
print_string("ELT: ");
print_format("%d",*elt_array_i32(array_2,cnt_3));
print_string("CNT: ");
if(cnt_3==max_i32(1,3))
{
if(cnt_3==4)
{
println_string("Not possible");
}
else
{
println_string("ELSE CNT = 3!!");
}
}
else
{
println_string("CNT != 3");
}
println_i32(cnt_3);
}
println_f32(float1_2);
println_f32(float2_2);
println_i32(argc_1);
println_string("ENDE");
}
println_i32(argc_1);
return(2);
}
void pointers_0()
{
{
i32 value_2=1000;
i32* value_ptr_2=&value_2;
append_ptr(value_ptr_2, 1, VARIABLE);
print_string("Value ");
println_i32(value_2);
print_string("Pointer ");
println_pointer_i32(value_ptr_2);
}
}
i32 main()
{
{
i32 ret_2=arrays_and_lists_0(77);
pointers_0();
return(ret_2);
}
destroy_ptr(pointer_list);
}







