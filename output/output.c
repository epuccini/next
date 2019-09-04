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


i32 layer__fun1_0()
{
println_string("Modulefunctionfun1");
return(999);
}
i32 layer__fun2_0()
{
println_string("Modulefunctionfun2");
return(888);
}
f32 mapit_0(f32 op_1)
{
print_string("Map");
println_f64((op_1+op_1));
return((op_1+op_1));
}
f32 reduceit_0(f32 op1_1,f32 op2_1)
{
print_string("Reduce");
println_f32((f32)(op1_1+op2_1));
return((op1_1+op2_1));
}
void work_0(f32 (*f_1)(f32),i32 arg_1)
{
print_format("%f",(*f_1)(arg_1));
}
i32 do_0(i32 argc_1)
{
mapit_0(5.5);
println_string("RET");
layer__fun1_0();
layer__fun2_0();
{
f32 float1_2=0.0;
f32 float2_2=(0.0+0.0);
i32 array_2[]={1, 2, 3, 4, 5, 6};
f32 values_2[]={1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
f32* my_new_array_2=mapn_f32(mapit_0,values_2);
f32* my_new_floats_2=new_f32(10);
char* string_2="abc";
const char chars_2[]={'a', 'b', 'c'};
f32 (*myfun_2)(f32)=mapit_0;
set_f32((f32*)elt_f32(my_new_array_2,0),888.0);
print_string("Mynewarray/firstelementis:");
println_f32((f32)*elt_f32(my_new_array_2,0));
mapit_0(1000.0);
work_0(mapit_0,100);
map_f32(mapit_0,values_2);
reduce_f32(reduceit_0,values_2);
print_string("String:");
println_string(string_2);
print_string("Chars:");
println_string(chars_2);
print_string("sizeof:");
println_i32(sizeof(string_2));
set_f32(&float1_2,666.0);
set_i32(&argc_1,(100+(1000-500)+100+(1000*500)));
println_i32(argc_1);
set_i32(&argc_1,(100+(1000-999)));
println_i32(argc_1);
i32 cnt_3=0;
for(cnt_3=0;cnt_3<max_i32(20,10);cnt_3++)
{
set_i32(elt_i32(array_2,cnt_3),1000);
print_format("%d",power_i32(2,8));
print_string("ELT:");
print_format("%d",*elt_i32(array_2,cnt_3));
print_string("CNT:");
if(cnt_3==max_i32(1,3))
{
if(cnt_3==4)
{
println_string("Notpossible");
}
else
{
println_string("ELSECNT=3!!");
}
}
else
{
println_string("CNT!=3");
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



i32 main () 
{
pointer_list = init_ptr();
pointer_list->start = pointer_list;
pointer_list->next = (void*)NULL;

do_0(77);


destroy_ptr(pointer_list);
return 0;
}