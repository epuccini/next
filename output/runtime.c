#include "runtime.h"

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

void print_ui16(ui16 val) {
	printf("%d", val);
}

void print_ui32(ui32 val) {
	printf("%d", val);
}

void print_ui64(ui64 val) {
	printf("%ld", val);
}

void print_f32(f32 val) {
    printf("%f", val);
}

void print_f64(f64 val) {
	printf("%lf", val);
}

void print_f80(f80 val) {
	printf("%Lf", val);
}

void print_string(cstring str) {
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

void println_ui16(ui16 val) {
	printf("%d\n", val);
}

void println_ui32(ui32 val) {
	printf("%d \n", val);
}

void println_ui64(ui64 val) {
	printf("%ld \n", val);
}

void println_f32(f32 val) {
    printf("%f \n", val);
}

void println_f64(f64 val) {
	printf("%lf \n", val);
}

void println_f80(f80 val) {
	printf("%Lf \n", val);
}

void println_string(cstring str) {
	printf("%s \n", str);
}

void prnl_ixx(ixx num) {
	gmp_printf("%Zd \n", num);
}

void prn_ixx(ixx num) {
	gmp_printf("%Zd", num);
}

void print_format(cstring fmt, ...) {
    va_list arglist;
    va_start(arglist, fmt);
    cstring p;
    
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
	return (b8*)&ptr[idx];
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

i64* elt_array_i64(i64* ptr, i16 idx) {
	return (i64*)&ptr[idx];
}

ui16* elt_array_ui16(ui16* ptr, i32 idx) {
	return (ui16*)&ptr[idx];
}

ui32* elt_array_ui32(ui32* ptr, i32 idx) {
	return (ui32*)&ptr[idx];
}

ui64* elt_array_ui64(ui64* ptr, i16 idx) {
	return (ui64*)&ptr[idx];
}

f32* elt_array_f32(f32* ptr, i16 idx) {
	return (f32*)&ptr[idx];
}

f64* elt_array_f64(f64* ptr, i32 idx) {
	return (f64*)&ptr[idx];
}

f80* elt_array_f80(f80* ptr, i32 idx) {
	return (f80*)&ptr[idx];
}

c8** elt_array_string(c8** ptr, i32 idx) {
	return (c8**)&ptr[idx];
}

void set_pointer_bool(bool* ptr, bool val) {
	*ptr = val;
}

void set_pointer_b8(b8* ptr, b8 val) {
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

void set_pointer_ui16(ui16* ptr, ui16 val) {
	*ptr = val;
}

void set_pointer_ui32(ui32* ptr, ui32 val) {
	*ptr = val;
}

void set_pointer_ui64(ui64* ptr, ui64 val) {
	*ptr = val;
}

void set_pointer_f32(f32* ptr, f32 val) {
	*ptr = val;
}

void set_pointer_f64(f64* ptr, f64 val) {
	*ptr = val;
}

void set_pointer_f80(f80* ptr, f80 val) {
	*ptr = val;
}

void set_pointer_string(c8** ptr, c8* val) {
	*ptr = val;
}

void set_pointer_file(file* ptr, file val) {
	*ptr = val;
}

void set_pointer_ixx(ixx* ptr, ixx val) {
	mpz_set(*ptr, val);
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
define_lt(ui16)
define_lt(ui32)
define_lt(ui64)
define_lt(f32)
define_lt(f64)
define_lt(f80)

define_leqt(bool)
define_leqt(i16)
define_leqt(i32)
define_leqt(i64)
define_leqt(ui16)
define_leqt(ui32)
define_leqt(ui64)
define_leqt(f32)
define_leqt(f64)
define_leqt(f80)

define_gt(bool)
define_gt(i16)
define_gt(i32)
define_gt(i64)
define_gt(ui16)
define_gt(ui32)
define_gt(ui64)
define_gt(f32)
define_gt(f64)
define_gt(f80)

define_geqt(bool)
define_geqt(i16)
define_geqt(i32)
define_geqt(i64)
define_geqt(ui16)
define_geqt(ui32)
define_geqt(ui64)
define_geqt(f32)
define_geqt(f64)
define_geqt(f80)

define_neq(bool)
define_neq(i16)
define_neq(i32)
define_neq(i64)
define_neq(f32)
define_neq(f64)
define_neq(f80)

define_eq(bool)
define_eq(i16)
define_eq(i32)
define_eq(i64)
define_eq(ui16)
define_eq(ui32)
define_eq(ui64)
define_eq(f32)
define_eq(f64)
define_eq(f80)

#define define_sqrt(T) \
T sqrt_##T(T a){ \
	return (T)sqrt(a); \
}

define_sqrt(i16)
define_sqrt(i32)
define_sqrt(i64)
define_sqrt(ui16)
define_sqrt(ui32)
define_sqrt(ui64)
define_sqrt(f32)
define_sqrt(f64)
define_sqrt(f80)

#define define_power(T) \
T power_##T(T a, T b){ \
	return (T)pow(a, b) ; \
} \

define_power(i16)
define_power(i32)
define_power(i64)
define_power(ui16)
define_power(ui32)
define_power(ui64)
define_power(f32)
define_power(f64)
define_power(f80)

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
define_max(ui16)
define_max(ui32)
define_max(ui64)
define_max(f32)
define_max(f64)
define_max(f80)

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
define_min(ui16)
define_min(ui32)
define_min(ui64)
define_min(f32)
define_min(f64)
define_min(f80)

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
				else
					temp_after = NULL;
				free(temp);
				if (temp_before->next->next != NULL)
					temp_before->next = temp_after;
				else
					temp_before->next = NULL;
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
				//if (e->type == IXX) {
				//	mpz_clear(e->value);
				//}
				if (e->type != ARRAY && e->type != VARIABLE && e->type != INTERMEDIATE_ARRAY
					&& e->type != INTERMEDIATE_LIST && e->type != INTERMEDIATE_POINTER)
                    free(e);
                e = NULL;
                e = temp;
                temp = e->next;
            } while (e->next != NULL);
        }
        else {
			//if (e->type == IXX) {
			//	mpz_clear(e->value);
			//}
			if (e->type != ARRAY && e->type != VARIABLE && e->type != INTERMEDIATE_ARRAY
				&& e->type != INTERMEDIATE_LIST && e->type != INTERMEDIATE_POINTER)
                free(e);
        }
	}
	return 0;
}

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
define_length_list(ui16)
define_length_list(ui32)
define_length_list(ui64)
define_length_list(f32)
define_length_list(f64)
define_length_list(f80)

#define define_length_array(T) \
i32 length_array_##T(T* array) {  \
	return length(array); \
} \

define_length_array(bool)
define_length_array(c8)
define_length_array(b8)
define_length_array(i16)
define_length_array(i32)
define_length_array(i64)
define_length_array(ui16)
define_length_array(ui32)
define_length_array(ui64)
define_length_array(f32)
define_length_array(f64)
define_length_array(f80)

#define define_length_pointer(T) \
i32 length_pointer_##T(T* pointer) {  \
	return length(pointer); \
} \

define_length_pointer(bool)
define_length_pointer(c8)
define_length_pointer(b8)
define_length_pointer(i16)
define_length_pointer(i32)
define_length_pointer(i64)
define_length_pointer(ui16)
define_length_pointer(ui32)
define_length_pointer(ui64)
define_length_pointer(f32)
define_length_pointer(f64)
define_length_pointer(f80)

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
define_append_list(ui16)
define_append_list(ui32)
define_append_list(ui64)
define_append_list(f32)
define_append_list(f64)
define_append_list(f80)

#define define_append_array(T) \
T* append_array_##T(T* array, T value) {  \
    int size = length_array_##T(array); \
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
	define_append_array(ui16)
	define_append_array(ui32)
	define_append_array(ui64)
	define_append_array(f32)
	define_append_array(f64)
	define_append_array(f80)

#define define_append_pointer(T) \
T* append_pointer_##T(T* pointer, T value) {  \
    int size = length_pointer_##T(pointer); \
    T* new_pointer = (T*) malloc((size+1)*sizeof(T)); \
    int cnt = 0; \
    for (cnt = 0; cnt < size; cnt++) { \
        new_pointer[cnt] = pointer[cnt]; \
    } \
    new_pointer[size] = value; \
    append_ptr(new_pointer, size+1, POINTER);             \
    remove_ptr(pointer);       \
    return new_pointer; \
}

	define_append_pointer(bool)
	define_append_pointer(c8)
	define_append_pointer(b8)
	define_append_pointer(i16)
	define_append_pointer(i32)
	define_append_pointer(i64)
	define_append_pointer(ui16)
	define_append_pointer(ui32)
	define_append_pointer(ui64)
	define_append_pointer(f32)
	define_append_pointer(f64)
	define_append_pointer(f80)

#define define_append_list_list(T) \
node_##T* append_list_list_##T(node_##T* lista, node_##T* listb) {  \
	node_##T* new_list = (node_##T*)malloc(sizeof(node_##T)); \
	node_##T* start = new_list; \
	int sizea = length_list_##T(lista); \
	int sizeb = length_list_##T(listb); \
	int new_size = sizea + sizeb; \
	do { \
		new_list->value = lista->value; \
		new_list->next = (node_##T*)malloc(sizeof(node_##T)); \
		new_list = new_list->next; \
		lista = lista->next; \
	} while (lista != NULL); \
	if (new_list == NULL) new_list = (node_##T*)malloc(sizeof(node_##T)); \
	do { \
		new_list->value = listb->value; \
		if(listb->next != NULL) { \
			new_list->next = (node_##T*)malloc(sizeof(node_##T)); \
			new_list = new_list->next; \
		} \
		listb = listb->next; \
	} while (listb != NULL); \
	new_list->next = NULL; \
	new_list = NULL; \
	append_ptr(start, new_size, LIST); \
	return start; \
} \

define_append_list_list(bool)
define_append_list_list(c8)
define_append_list_list(b8)
define_append_list_list(i16)
define_append_list_list(i32)
define_append_list_list(i64)
define_append_list_list(ui16)
define_append_list_list(ui32)
define_append_list_list(ui64)
define_append_list_list(f32)
define_append_list_list(f64)
define_append_list_list(f80)

#define define_append_array_array(T) \
T* append_array_array_##T(T* arraya, T* arrayb) {  \
	int sizea = length(arraya); \
	int sizeb = length(arrayb); \
	int new_size = sizea + sizeb; \
	T* new_array = malloc(new_size*sizeof(T));  \
	int cnt = 0; \
	for(cnt = 0; cnt < sizea; cnt++) { \
		new_array[cnt] = arraya[cnt]; \
	} \
	cnt = 0; \
	for(cnt = 0; cnt < sizeb; cnt++) { \
		new_array[sizea+cnt] = arrayb[cnt]; \
	} \
    append_ptr(new_array, new_size, POINTER); \
    return new_array; \
}

	define_append_array_array(bool)
	define_append_array_array(c8)
	define_append_array_array(b8)
	define_append_array_array(i16)
	define_append_array_array(i32)
	define_append_array_array(i64)
	define_append_array_array(ui16)
	define_append_array_array(ui32)
	define_append_array_array(ui64)
	define_append_array_array(f32)
	define_append_array_array(f64)
	define_append_array_array(f80)

#define define_append_pointer_pointer(T) \
T* append_pointer_pointer_##T(T* pointera, T* pointerb) {  \
	int sizea = length(pointera); \
	int sizeb = length(pointerb); \
	int new_size = sizea + sizeb; \
	T* new_pointer = malloc(new_size*sizeof(T));  \
	int cnt = 0; \
	for(cnt = 0; cnt < sizea; cnt++) { \
		new_pointer[cnt] = pointera[cnt]; \
	} \
	cnt = 0; \
	for(cnt = 0; cnt < sizeb; cnt++) { \
		new_pointer[sizea+cnt] = pointerb[cnt]; \
	} \
    append_ptr(new_pointer, new_size, POINTER); \
    return new_pointer; \
}

	define_append_pointer_pointer(bool)
	define_append_pointer_pointer(c8)
	define_append_pointer_pointer(b8)
	define_append_pointer_pointer(i16)
	define_append_pointer_pointer(i32)
	define_append_pointer_pointer(i64)
	define_append_pointer_pointer(ui16)
	define_append_pointer_pointer(ui32)
	define_append_pointer_pointer(ui64)
	define_append_pointer_pointer(f32)
	define_append_pointer_pointer(f64)
	define_append_pointer_pointer(f80)

#define define_reverse_list(T) \
node_##T* reverse_list_##T(node_##T* head) {  \
	/* copy list */ \
	node_##T* new_list = (node_##T*)malloc(sizeof(node_##T)); \
	node_##T* start = new_list; \
	node_##T* list = head; \
	int size = length(head); \
	while (list != NULL) { \
		new_list->value = list->value; \
		if (list->next != NULL) { \
			new_list->next = (node_##T*)malloc(sizeof(node_##T)); \
			new_list = new_list->next; \
		} \
		else \
			new_list->next = NULL; \
		list = list->next; \
	} \
	/* reverse list */ \
	node_##T* current = start; \
	node_##T *prev = NULL, *next = NULL; \
	while (current != NULL) { \
		next = current->next; \
		current->next = prev; \
		prev = current; \
		current = next; \
	} \
	start = prev; \
	append_ptr(start, size, POINTER); \
	return start; \
} \

	define_reverse_list(bool)
	define_reverse_list(c8)
	define_reverse_list(b8)
	define_reverse_list(i16)
	define_reverse_list(i32)
	define_reverse_list(i64)
	define_reverse_list(ui16)
	define_reverse_list(ui32)
	define_reverse_list(ui64)
	define_reverse_list(f32)
	define_reverse_list(f64)
	define_reverse_list(f80)

#define define_reverse_array(T) \
T* reverse_array_##T(T* array) {  \
	int size = length(array); \
	T* new_array = (T*)malloc(sizeof(T)*size); \
	int cnt = 0; \
	for (cnt = 0; cnt < size; cnt++) { \
		new_array[cnt] = array[size-cnt-1]; \
	} \
	append_ptr(new_array, size, POINTER); \
	return new_array; \
} \

define_reverse_array(bool)
define_reverse_array(c8)
define_reverse_array(b8)
define_reverse_array(i16)
define_reverse_array(i32)
define_reverse_array(i64)
define_reverse_array(ui16)
define_reverse_array(ui32)
define_reverse_array(ui64)
define_reverse_array(f32)
define_reverse_array(f64)
define_reverse_array(f80)

#define define_reverse_pointer(T) \
T* reverse_pointer_##T(T* pointer) {  \
	int size = length(pointer); \
	T* new_pointer = (T*)malloc(sizeof(T)*size); \
	int cnt = 0; \
	for (cnt = 0; cnt < size; cnt++) { \
		new_pointer[cnt] = pointer[size-cnt-1]; \
	} \
	append_ptr(new_pointer, size, POINTER); \
	return new_pointer; \
} \

define_reverse_pointer(bool)
define_reverse_pointer(c8)
define_reverse_pointer(b8)
define_reverse_pointer(i16)
define_reverse_pointer(i32)
define_reverse_pointer(i64)
define_reverse_pointer(ui16)
define_reverse_pointer(ui32)
define_reverse_pointer(ui64)
define_reverse_pointer(f32)
define_reverse_pointer(f64)
define_reverse_pointer(f80)

#define define_push_list(T) \
node_##T* push_list_##T(node_##T** list, T value) {  \
	node_##T* head = (node_##T*)malloc(sizeof(node_##T)); \
	head->next = (*list); \
	head->value = value; \
	append_ptr((void*)head, length_list_##T(*list)+1, LIST);       \
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
define_push_list(ui16)
define_push_list(ui32)
define_push_list(ui64)
define_push_list(f32)
define_push_list(f64)
define_push_list(f80)

#define define_pop_list(T) \
T pop_list_##T(node_##T** list) {  \
	T value = (*list)->value; \
	remove_ptr(*list);       \
	if ((*list)->next != NULL) { \
		*list = (*list)->next; \
	} \
	append_ptr((*list), length_list_##T(*list)-1, LIST);       \
	return value; \
} \

define_pop_list(bool)
define_pop_list(c8)
define_pop_list(b8)
define_pop_list(i16)
define_pop_list(i32)
define_pop_list(i64)
define_pop_list(ui16)
define_pop_list(ui32)
define_pop_list(ui64)
define_pop_list(f32)
define_pop_list(f64)
define_pop_list(f80)

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
define_remove_list(ui16)
define_remove_list(ui32)
define_remove_list(ui64)
define_remove_list(f32)
define_remove_list(f64)
define_remove_list(f80)

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
define_car_list(ui16)
define_car_list(ui32)
define_car_list(ui64)
define_car_list(f32)
define_car_list(f64)
define_car_list(f80)

#define define_car_array(T) \
T car_array_##T(T* array) { \
	return array[0]; \
} \

define_car_array(bool)
define_car_array(c8)
define_car_array(b8)
define_car_array(i16)
define_car_array(i32)
define_car_array(i64)
define_car_array(ui16)
define_car_array(ui32)
define_car_array(ui64)
define_car_array(f32)
define_car_array(f64)
define_car_array(f80)

#define define_cdr_list(T) \
node_##T* cdr_list_##T(node_##T* list) { \
	int size = length_list_##T(list)-1; \
	append_ptr(&(list->next), size, INTERMEDIATE_LIST); \
	if(list->next != NULL) \
		return list->next; \
	return NULL; \
} \

define_cdr_list(bool)
define_cdr_list(c8)
define_cdr_list(b8)
define_cdr_list(i16)
define_cdr_list(i32)
define_cdr_list(i64)
define_cdr_list(ui16)
define_cdr_list(ui32)
define_cdr_list(ui64)
define_cdr_list(f32)
define_cdr_list(f64)
define_cdr_list(f80)

#define define_cdr_array(T) \
T* cdr_array_##T(T* array) { \
	int size = length(array)-1; \
	append_ptr(&array[1], size, INTERMEDIATE_ARRAY); \
	return &array[1]; \
} \

define_cdr_array(bool)
define_cdr_array(c8)
define_cdr_array(b8)
define_cdr_array(i16)
define_cdr_array(i32)
define_cdr_array(i64)
define_cdr_array(ui16)
define_cdr_array(ui32)
define_cdr_array(ui64)
define_cdr_array(f32)
define_cdr_array(f64)
define_cdr_array(f80)

#define define_cdr_pointer(T) \
T* cdr_pointer_##T(T* pointer) { \
	int size = length(pointer)-1; \
	append_ptr(&pointer[1], size, INTERMEDIATE_POINTER); \
	return &pointer[1]; \
} \

	define_cdr_pointer(bool)
	define_cdr_pointer(c8)
	define_cdr_pointer(b8)
	define_cdr_pointer(i16)
	define_cdr_pointer(i32)
	define_cdr_pointer(i64)
	define_cdr_pointer(ui16)
	define_cdr_pointer(ui32)
	define_cdr_pointer(ui64)
	define_cdr_pointer(f32)
	define_cdr_pointer(f64)
	define_cdr_pointer(f80)

#define define_cdrn_list(T) \
node_##T* cdrn_list_##T(node_##T* list) { \
	node_##T* start = NULL; \
	node_##T* copy = NULL; \
	int size = length((void*)list); \
	if (list->next != NULL) \
	{ \
		list = list->next; \
		copy = (node_##T*)malloc(sizeof(node_##T)); \
		start = copy; \
		do \
		{  \
			copy->value = list->value; \
			if (list->next != NULL) \
				copy->next = (node_##T*)malloc(sizeof(node_##T)); \
			else \
				copy->next = NULL; \
			list = list->next; \
			copy = copy->next; \
		} while (list != NULL); \
	} \
	copy = start; \
	append_ptr(copy, size-1, POINTER); \
	return copy; \
} \

	define_cdrn_list(bool)
	define_cdrn_list(c8)
	define_cdrn_list(b8)
	define_cdrn_list(i16)
	define_cdrn_list(i32)
	define_cdrn_list(i64)
	define_cdrn_list(ui16)
	define_cdrn_list(ui32)
	define_cdrn_list(ui64)
	define_cdrn_list(f32)
	define_cdrn_list(f64)
	define_cdrn_list(f80)

#define define_cdrn_array(T) \
T* cdrn_array_##T(T* array) { \
	int size = length(array); \
	T* new_array = malloc(sizeof(T)*(size-1)); \
	int cnt = 0; \
	for(cnt = 1; cnt <= size-1; cnt++) \
		new_array[cnt-1] = array[cnt]; \
	append_ptr((void*)new_array, size-1, POINTER); \
	return new_array; \
} \

	define_cdrn_array(bool)
	define_cdrn_array(c8)
	define_cdrn_array(b8)
	define_cdrn_array(i16)
	define_cdrn_array(i32)
	define_cdrn_array(i64)
	define_cdrn_array(ui16)
	define_cdrn_array(ui32)
	define_cdrn_array(ui64)
	define_cdrn_array(f32)
	define_cdrn_array(f64)
	define_cdrn_array(f80)

#define define_cdrn_pointer(T) \
T* cdrn_pointer_##T(T* pointer) { \
	int size = length(pointer); \
	T* new_pointer = malloc(sizeof(T)*(size-1)); \
	int cnt = 0; \
	for(cnt = 1; cnt < size-1; cnt++) \
		new_pointer[cnt-1] = pointer[cnt]; \
	append_ptr((void*)new_pointer, size-1, POINTER); \
	return new_pointer; \
} \

	define_cdrn_pointer(bool)
	define_cdrn_pointer(c8)
	define_cdrn_pointer(b8)
	define_cdrn_pointer(i16)
	define_cdrn_pointer(i32)
	define_cdrn_pointer(i64)
	define_cdrn_pointer(ui16)
	define_cdrn_pointer(ui32)
	define_cdrn_pointer(ui64)
	define_cdrn_pointer(f32)
	define_cdrn_pointer(f64)
	define_cdrn_pointer(f80)

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
define_destroy(ui16)
define_destroy(ui32)
define_destroy(ui64)
define_destroy(f32)
define_destroy(f64)
define_destroy(f80)

#define define_create_list(T) \
node_##T* create_list_##T(T list[], int size) {  \
	int cnt = 0; \
	node_##T* mem = NULL; \
	node_##T** start = &mem; \
	for (cnt = 0; cnt < size; cnt++) { \
		mem = append_list_##T(mem, list[cnt]);  \
	} \
	mem = *start; \
	append_ptr(mem, size, LIST); \
	return mem; \
} \

define_create_list(bool)
define_create_list(c8)
define_create_list(b8)
define_create_list(i16)
define_create_list(i32)
define_create_list(i64)
define_create_list(ui16)
define_create_list(ui32)
define_create_list(ui64)
define_create_list(f32)
define_create_list(f64)
define_create_list(f80)

#define define_create_array(T) \
T* create_array_##T(T list[], int size) {  \
	int cnt = 0; \
	T* mem = NULL; \
	for (cnt = 0; cnt < size-1; cnt++) { \
		mem[cnt] = list[cnt];  \
	} \
	append_ptr(mem, size, POINTER); \
	return mem; \
} \

define_create_array(bool)
define_create_array(c8)
define_create_array(b8)
define_create_array(i16)
define_create_array(i32)
define_create_array(i64)
define_create_array(ui16)
define_create_array(ui32)
define_create_array(ui64)
define_create_array(f32)
define_create_array(f64)
define_create_array(f80)

void create_ixx(ixx z, i32 a[], i32 size) {
	mpz_import(z, 20, 1, sizeof(a[0]), 0, 0, a);
}

i32 create_str_ixx(ixx z, const c8* val) {
	i32 err = mpz_set_str(z, val, 10);
	return err;
}


#define define_map_array(T) \
T* map_array_##T(single_fn_##T a, T* b) { \
    i32 cnt = 0; \
    for (cnt = 0; cnt < sizeof(b)-2; cnt++) { \
        b[cnt] = (*a)(b[cnt]); \
    } \
    return b; \
}

	define_map_array(bool)
	define_map_array(b8)
	define_map_array(c8)
	define_map_array(i16)
	define_map_array(i32)
	define_map_array(i64)
	define_map_array(ui16)
	define_map_array(ui32)
	define_map_array(ui64)
	define_map_array(f32)
	define_map_array(f64)
	define_map_array(f80)

#define define_map_list(T) \
node_##T* map_list_##T(single_fn_##T a, node_##T* b) { \
    i32 cnt = 0; \
	int size = length_list_##T(b); \
    for (cnt = 0; cnt < size-1; cnt++) { \
        b->value = (*a)(b->value); \
		if(b->next != NULL) \
			b = b->next; \
    } \
    return b; \
}

define_map_list(bool)
define_map_list(b8)
define_map_list(c8)
define_map_list(i16)
define_map_list(i32)
define_map_list(i64)
define_map_list(ui16)
define_map_list(ui32)
define_map_list(ui64)
define_map_list(f32)
define_map_list(f64)
define_map_list(f80)

#define define_mapn_array(T) \
T* mapn_array_##T(single_fn_##T a, T* b) { \
    T* ptr = (T*) malloc(sizeof(b) * sizeof(T)); \
	append_ptr((void*)ptr, sizeof(b)-2, POINTER);\
	i32 cnt = 0; \
    for (cnt = 0; cnt < sizeof(b)-2; cnt++) { \
        ptr[cnt] = (*a)(b[cnt]); \
    } \
    return ptr; \
}

	define_mapn_array(bool)
	define_mapn_array(b8)
	define_mapn_array(c8)
	define_mapn_array(i16)
	define_mapn_array(i32)
	define_mapn_array(i64)
	define_mapn_array(ui16)
	define_mapn_array(ui32)
	define_mapn_array(ui64)
	define_mapn_array(f32)
	define_mapn_array(f64)
	define_mapn_array(f80)

#define define_mapn_list(T) \
node_##T* mapn_list_##T(single_fn_##T a, node_##T* b) { \
    node_##T* ptr = (node_##T*) malloc(sizeof(node_##T)); \
	int size = length_list_##T(b); \
	i32 cnt = 0; \
    for (cnt = 0; cnt < sizeof(b)-2; cnt++) { \
        ptr->value = (*a)(b->value); \
		ptr->next = (node_##T*) malloc(sizeof(node_##T)); \
		ptr = ptr->next; \
    } \
	append_ptr((void*)ptr, size-1, POINTER); \
    return ptr; \
}

	define_mapn_list(bool)
	define_mapn_list(b8)
	define_mapn_list(c8)
	define_mapn_list(i16)
	define_mapn_list(i32)
	define_mapn_list(i64)
	define_mapn_list(ui16)
	define_mapn_list(ui32)
	define_mapn_list(ui64)
	define_mapn_list(f32)
	define_mapn_list(f64)
	define_mapn_list(f80)

#define define_reduce_array(T) \
T reduce_array_##T(dual_fn_##T a, T* b) { \
    i32 cnt = 0; \
    T result = b[0]; \
    for (cnt = 1; cnt < sizeof(b)-2; cnt++) { \
      result = (*a)(result, b[cnt]);           \
    } \
    return result; \
} 

	define_reduce_array(bool)
	define_reduce_array(c8)
	define_reduce_array(i16)
	define_reduce_array(i32)
	define_reduce_array(i64)
	define_reduce_array(ui16)
	define_reduce_array(ui32)
	define_reduce_array(ui64)
	define_reduce_array(f32)
	define_reduce_array(f64)
	define_reduce_array(f80)

#define define_reduce_list(T) \
T reduce_list_##T(dual_fn_##T a, node_##T* b) { \
    i32 cnt = 0; \
    T result = b->value; \
	int size = length_list_##T(b); \
	if (b->next != NULL) \
		b = b->next; \
    for (cnt = 1; cnt < size-1; cnt++) { \
		result = (*a)(result, b->value);           \
		if(b->next != NULL) \
			b = b->next; \
    } \
    return result; \
} 

	define_reduce_list(bool)
	define_reduce_list(c8)
	define_reduce_list(i16)
	define_reduce_list(i32)
	define_reduce_list(i64)
	define_reduce_list(ui16)
	define_reduce_list(ui32)
	define_reduce_list(ui64)
	define_reduce_list(f32)
	define_reduce_list(f64)
	define_reduce_list(f80)


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
	define_new(ui16)
	define_new(ui32)
	define_new(ui64)
	define_new(f32)
	define_new(f64)
	define_new(f80)

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
define_println_list(ui16)
define_println_list(ui32)
define_println_list(ui64)
define_println_list(f32)
define_println_list(f64)
define_println_list(f80)

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
define_print_list(ui16)
define_print_list(ui32)
define_print_list(ui64)
define_print_list(f32)
define_print_list(f64)
define_print_list(f80)

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
define_println_array(ui16)
define_println_array(ui32)
define_println_array(ui64)
define_println_array(f32)
define_println_array(f64)
define_println_array(f80)

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
define_print_array(ui16)
define_print_array(ui32)
define_print_array(ui64)
define_print_array(f32)
define_print_array(f64)
define_print_array(f80)

#define define_println_pointer(T) \
void println_pointer_##T(T* pointer) {  \
	int size = length(pointer); \
	int cnt = 0; \
	if (size == 0) { \
		print_##T(*pointer); \
		printf("\n"); \
	} else { \
		for (cnt = 0; cnt < size; cnt++) { \
            print_##T(pointer[cnt]); \
			printf(" "); \
		} \
		printf("\n"); \
	} \
} \

define_println_pointer(b8)
define_println_pointer(c8)
define_println_pointer(i16)
define_println_pointer(i32)
define_println_pointer(i64)
define_println_pointer(ui16)
define_println_pointer(ui32)
define_println_pointer(ui64)
define_println_pointer(f32)
define_println_pointer(f64)
define_println_pointer(f80)

#define define_print_pointer(T) \
void print_pointer_##T(T* pointer) {  \
    int size = length((void*)pointer); \
	int cnt = 0; \
	if (size == 0) { \
		print_##T(*pointer); \
		printf("\n"); \
	} else { \
		for (cnt = 0; cnt < size; cnt++) { \
			print_##T(pointer[cnt]); \
		} \
	} \
} \

define_print_pointer(b8)
define_print_pointer(c8)
define_print_pointer(i16)
define_print_pointer(i32)
define_print_pointer(i64)
define_print_pointer(ui16)
define_print_pointer(ui32)
define_print_pointer(ui64)
define_print_pointer(f32)
define_print_pointer(f64)
define_print_pointer(f80)

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
define_elt_list(ui16)
define_elt_list(ui32)
define_elt_list(ui64)
define_elt_list(f32)
define_elt_list(f64)
define_elt_list(f80)

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
define_set_list(ui16)
define_set_list(ui32)
define_set_list(ui64)
define_set_list(f32)
define_set_list(f64)
define_set_list(f80)

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
define_set_pointer_list(ui16)
define_set_pointer_list(ui32)
define_set_pointer_list(ui64)
define_set_pointer_list(f32)
define_set_pointer_list(f64)
define_set_pointer_list(f80)
define_set_pointer_list(string)
define_set_pointer_list(file)

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
define_set_pointer_array(ui16)
define_set_pointer_array(ui32)
define_set_pointer_array(ui64)
define_set_pointer_array(f32)
define_set_pointer_array(f64)
define_set_pointer_array(f80)
define_set_pointer_array(string)
define_set_pointer_array(file)

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
define_set_pointer_pointer(ui16)
define_set_pointer_pointer(ui32)
define_set_pointer_pointer(ui64)
define_set_pointer_pointer(f32)
define_set_pointer_pointer(f64)
define_set_pointer_pointer(f80)
define_set_pointer_pointer(string)
define_set_pointer_pointer(file)

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

void print_str_pointer_ui16(c8* pointer, ui16* value) {
	int cnt = 0;
	for (cnt = 0; cnt < length(pointer); cnt++)
		sprintf(pointer, "%d", value[cnt]);
}

void print_str_array_ui16(c8* pointer, ui16* value) {
	int cnt = 0;
	for (cnt = 0; cnt < length(pointer); cnt++)
		sprintf(pointer, "%d", value[cnt]);
}

void print_str_pointer_ui32(c8* pointer, ui32* value) {
	int cnt = 0;
	for (cnt = 0; cnt < length(pointer); cnt++)
		sprintf(pointer, "%d", value[cnt]);
}

void print_str_array_ui32(c8* pointer, ui32* value) {
	int cnt = 0;
	for (cnt = 0; cnt < length(pointer); cnt++)
		sprintf(pointer, "%d", value[cnt]);
}

void print_str_pointer_ui64(c8* pointer, ui64* value) {
	int cnt = 0;
	for (cnt = 0; cnt < length(pointer); cnt++)
		sprintf(pointer, "%ld", value[cnt]);
}

void print_str_array_ui64(c8* pointer, ui64* value) {
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

void print_str_pointer_f80(c8* pointer, f80* value) {
	int cnt = 0;
	for (cnt = 0; cnt < length(pointer); cnt++)
		sprintf(pointer, "%Lf", value[cnt]);
}

void print_str_array_f80(c8* pointer, f80* value) {
	int cnt = 0;
	for (cnt = 0; cnt < length(pointer); cnt++)
		sprintf(pointer, "%Lf", value[cnt]);
}

#define define_floor(T) \
T floor_##T(T val) { \
	return floor(val); \
} \

define_floor(c8)
define_floor(i16)
define_floor(i32)
define_floor(i64)
define_floor(ui16)
define_floor(ui32)
define_floor(ui64)
define_floor(f32)
define_floor(f64)
define_floor(f80)

#define define_ceil(T) \
T ceil_##T(T val) { \
	return ceil(val); \
} \

define_ceil(c8)
define_ceil(i16)
define_ceil(i32)
define_ceil(i64)
define_ceil(ui16)
define_ceil(ui32)
define_ceil(ui64)
define_ceil(f32)
define_ceil(f64)
define_ceil(f80)

#define define_round(T) \
T round_##T(T val) { \
	return round(val); \
} \

define_round(c8)
define_round(i16)
define_round(i32)
define_round(i64)
define_round(ui16)
define_round(ui32)
define_round(ui64)
define_round(f32)
define_round(f64)
define_round(f80)

#define define_acos(T) \
T acos_##T(T val) { \
	return acos(val); \
} \

define_acos(c8)
define_acos(i16)
define_acos(i32)
define_acos(i64)
define_acos(ui16)
define_acos(ui32)
define_acos(ui64)
define_acos(f32)
define_acos(f64)
define_acos(f80)

#define define_asin(T) \
T asin_##T(T val) { \
	return asin(val); \
} \

define_asin(c8)
define_asin(i16)
define_asin(i32)
define_asin(i64)
define_asin(ui16)
define_asin(ui32)
define_asin(ui64)
define_asin(f32)
define_asin(f64)
define_asin(f80)

#define define_atan(T) \
T atan_##T(T val) { \
	return atan(val); \
} \

define_atan(c8)
define_atan(i16)
define_atan(i32)
define_atan(i64)
define_atan(ui16)
define_atan(ui32)
define_atan(ui64)
define_atan(f32)
define_atan(f64)
define_atan(f80)

#define define_atan2(T) \
T atan2_##T(T vala, T valb) { \
	return atan2(vala,valb); \
} \

define_atan2(c8)
define_atan2(i16)
define_atan2(i32)
define_atan2(i64)
define_atan2(ui16)
define_atan2(ui32)
define_atan2(ui64)
define_atan2(f32)
define_atan2(f64)
define_atan2(f80)

#define define_cos(T) \
T cos_##T(T val) { \
	return cos(val); \
} \

define_cos(c8)
define_cos(i16)
define_cos(i32)
define_cos(i64)
define_cos(ui16)
define_cos(ui32)
define_cos(ui64)
define_cos(f32)
define_cos(f64)
define_cos(f80)

#define define_cosh(T) \
T cosh_##T(T val) { \
	return cosh(val); \
} \

define_cosh(c8)
define_cosh(i16)
define_cosh(i32)
define_cosh(i64)
define_cosh(ui16)
define_cosh(ui32)
define_cosh(ui64)
define_cosh(f32)
define_cosh(f64)
define_cosh(f80)

#define define_sin(T) \
T sin_##T(T val) { \
	return sin(val); \
} \

define_sin(c8)
define_sin(i16)
define_sin(i32)
define_sin(i64)
define_sin(ui16)
define_sin(ui32)
define_sin(ui64)
define_sin(f32)
define_sin(f64)
define_sin(f80)

#define define_sinh(T) \
T sinh_##T(T val) { \
	return sinh(val); \
} \

define_sinh(c8)
define_sinh(i16)
define_sinh(i32)
define_sinh(i64)
define_sinh(ui16)
define_sinh(ui32)
define_sinh(ui64)
define_sinh(f32)
define_sinh(f64)
define_sinh(f80)

#define define_tanh(T) \
T tanh_##T(T val) { \
	return tanh(val); \
} \

define_tanh(c8)
define_tanh(i16)
define_tanh(i32)
define_tanh(i64)
define_tanh(ui16)
define_tanh(ui32)
define_tanh(ui64)
define_tanh(f32)
define_tanh(f64)
define_tanh(f80)

#define define_exp(T) \
T exp_##T(T val) { \
	return exp(val); \
} \

define_exp(c8)
define_exp(i16)
define_exp(i32)
define_exp(i64)
define_exp(ui16)
define_exp(ui32)
define_exp(ui64)
define_exp(f32)
define_exp(f64)
define_exp(f80)

#define define_frexp(T) \
T frexp_##T(T val, int* ptr) { \
	return frexp(val, ptr); \
} \

define_frexp(c8)
define_frexp(i16)
define_frexp(i32)
define_frexp(i64)
define_frexp(ui16)
define_frexp(ui32)
define_frexp(ui64)
define_frexp(f32)
define_frexp(f64)
define_frexp(f80)

#define define_ldexp(T) \
T ldexp_##T(T val, int b) { \
	return (T)ldexp(val, b); \
} \

define_ldexp(c8)
define_ldexp(i16)
define_ldexp(i32)
define_ldexp(i64)
define_ldexp(ui16)
define_ldexp(ui32)
define_ldexp(ui64)
define_ldexp(f32)
define_ldexp(f64)
define_ldexp(f80)

#define define_log(T) \
T log_##T(T val) { \
	return log(val); \
} \

define_log(c8)
define_log(i16)
define_log(i32)
define_log(i64)
define_log(ui16)
define_log(ui32)
define_log(ui64)
define_log(f32)
define_log(f64)
define_log(f80)

#define define_log10(T) \
T log10_##T(T val) { \
	return (T)log10(val); \
} \

define_log10(c8)
define_log10(i16)
define_log10(i32)
define_log10(i64)
define_log10(ui16)
define_log10(ui32)
define_log10(ui64)
define_log10(f32)
define_log10(f64)
define_log10(f80)

#define define_modf(T) \
T modf_##T(T val, double* ptr) { \
	return modf(val, ptr); \
} \

define_modf(c8)
define_modf(i16)
define_modf(i32)
define_modf(i64)
define_modf(ui16)
define_modf(ui32)
define_modf(ui64)
define_modf(f32)
define_modf(f64)
define_modf(f80)

#define define_fabs(T) \
T fabs_##T(T val) { \
	return fabs(val); \
} \

define_fabs(f32)
define_fabs(f64)

#define define_fmod(T) \
T fmod_##T(T vala, T valb) { \
	return fmod(vala, valb); \
} \

define_fmod(c8)
define_fmod(i16)
define_fmod(i32)
define_fmod(i64)
define_fmod(ui16)
define_fmod(ui32)
define_fmod(ui64)
define_fmod(f32)
define_fmod(f64)
define_fmod(f80)

file open(cstring filename, cstring mode) {
	return fopen(filename,mode);
} 
ui64 read_binary(void *ptr, ui64 size_of_elements, ui64 number_of_elements, file infile) {
	return fread(ptr, size_of_elements, number_of_elements, infile);
}

ui64 write_binary(const void *ptr, ui64 size_of_elements, ui64 number_of_elements, file outfile) {
	return fwrite(ptr, size_of_elements, number_of_elements, outfile);
}

int write_line(file outfile, cstring line) {
	i32 ret = fputs(line, outfile);
	return ret;
}

c8* read_line(file infile) {
	c8* buff = (c8*)malloc(255 * sizeof(c8));
	append_ptr(buff, 255, POINTER);
	c8* ret = fgets(buff, 255, infile);
	return ret;
}

i32 close(file file) {
	return fclose(file);
}

#define define_or(T) \
T or_##T(T vala, T valb) { \
    return (vala || valb); \
} \

define_or(bool)
define_or(b8)
define_or(c8)
define_or(i16)
define_or(i32)
define_or(i64)
define_or(ui16)
define_or(ui32)
define_or(ui64)
define_or(f32)
define_or(f64)
define_or(f80)

#define define_not(T) \
T not_##T(T val) { \
return (!val); \
} \

define_not(bool)
define_not(b8)
define_not(c8)
define_not(i16)
define_not(i32)
define_not(i64)
define_not(ui16)
define_not(ui32)
define_not(ui64)
define_not(f32)
define_not(f64)
define_not(f80)

#define define_and(T) \
T and_##T(T vala, T valb) { \
    return (vala && valb); \
} \

define_and(bool)
define_and(b8)
define_and(c8)
define_and(i16)
define_and(i32)
define_and(i64)
define_and(ui16)
define_and(ui32)
define_and(ui64)
define_and(f32)
define_and(f64)
define_and(f80)

#define define_equal(T) \
T equal_##T(T vala, T valb) { \
    return (vala == valb); \
} \

define_equal(bool)
define_equal(b8)
define_equal(c8)
define_equal(i16)
define_equal(i32)
define_equal(i64)
define_equal(ui16)
define_equal(ui32)
define_equal(ui64)
define_equal(f32)
define_equal(f64)
define_equal(f80)

bool equal_string(string vala, string valb) {
    return strncmp(vala, valb, length(vala));
}

#define define_equal_array(T) \
bool equal_array_##T(T* vala, T* valb) { \
    int cnt = 0; \
    for(cnt = 0; cnt < length(vala); cnt++) { \
        if(vala[cnt] != valb[cnt]) { \
            return false; \
        } \
    } \
    return true; \
} \

define_equal_array(bool)
define_equal_array(b8)
define_equal_array(c8)
define_equal_array(i16)
define_equal_array(i32)
define_equal_array(i64)
define_equal_array(ui16)
define_equal_array(ui32)
define_equal_array(ui64)
define_equal_array(f32)
define_equal_array(f64)
define_equal_array(f80)

#define define_equal_pointer(T) \
bool equal_pointer_##T(T* vala, T* valb) {  \
    int cnt = 0; \
    for(cnt = 0; cnt < length(vala); cnt++) { \
        if(vala[cnt] != valb[cnt]) { \
            return false; \
        } \
    } \
    return true; \
} \

define_equal_pointer(bool)
define_equal_pointer(b8)
define_equal_pointer(c8)
define_equal_pointer(i16)
define_equal_pointer(i32)
define_equal_pointer(i64)
define_equal_pointer(ui16)
define_equal_pointer(ui32)
define_equal_pointer(ui64)
define_equal_pointer(f32)
define_equal_pointer(f64)
define_equal_pointer(f80)

#define define_equal_list(T) \
bool equal_list_##T(node_##T* vala, node_##T* valb) { \
    i32 cnt = 0; \
    int sizea = length_list_##T(vala); \
    int sizeb = length_list_##T(valb); \
    if (sizea != sizeb) { \
        return false; \
    } \
    for (cnt = 0; cnt < sizea-1; cnt++) { \
        if (vala->value != valb->value) { \
            return false; \
        } \
        if (vala->next != NULL && valb->next != NULL)  { \
            vala = vala->next; \
            valb = valb->next; \
        } \
    } \
    return true; \
}

define_equal_list(bool)
define_equal_list(b8)
define_equal_list(c8)
define_equal_list(i16)
define_equal_list(i32)
define_equal_list(i64)
define_equal_list(ui16)
define_equal_list(ui32)
define_equal_list(ui64)
define_equal_list(f32)
define_equal_list(f64)
