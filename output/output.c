#include "output.h"

int32 mod(int32 a, int32 b) {
	return a % b;
}

int32 int32_mod_int32(int32 a, int32 b) {
    return a % b;
}

bool bool_not_bool(bool a) {
    return !a;
}

int32 int32_not_int32(int32 a) {
    return !a;
}

void print_char(char val) {
    printf("%c", val);
}

void print_byte(char val) {
    printf("%d", val);
}

void print_int16(int16 val) {
    printf("%d", val);
}

void print_int32(int32 val) {
    printf("%d", val);
}

void print_int64(long val) {
    printf("%ld", val);
}

void print_float32(float32 val) {
    printf("%f", val);
}

void print_float64(float64 val) {
    printf("%lf", val);
}

void print_string(const char* str) {
    printf("%s", str);
}

void println_byte(char val) {
    printf("%d\n", val);
}

void println_char(char val) {
    printf("%c\n", val);
}

void println_int16(int16 val) {
    printf("%d\n", val);
}

void println_int32(int32 val) {
    printf("%d \n", val);
}

void println_int64(long val) {
    printf("%ld \n", val);
}

void println_float32(float32 val) {
    printf("%f \n", val);
}

void println_float64(float64 val) {
    printf("%lf \n", val);
}

void println_string(const char* str) {
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
                int32 val = va_arg(arglist, int32);
                printf("%d", val);
            }
            if (*p == 's') {
                char* val = va_arg(arglist, char*);
                printf("%s", val);
            }
             if (*p == 'c') {
                 int32 val = va_arg(arglist, int32);
                 printf("%c", val);
            }
            continue;
        }
    };
    va_end(arglist);
    printf("\n");
}

bool* elt_bool(bool* ptr, int32 idx) {
    return (bool*)&ptr[idx];
}

char* elt_byte(char* ptr, int32 idx) {
    return (char*)&ptr[idx];
}

int16* elt_int16(int16* ptr, int32 idx) {
    return (int16*)&ptr[idx];
}

int32* elt_int32(int32* ptr, int32 idx) {
    return (int32*)&ptr[idx];
}

long* elt_int64(long* ptr, int16 idx) {
    return (long*)&ptr[idx];
}

float32* elt_float32(float32* ptr, int16 idx) {
    return (float32*)&ptr[idx];
}

float64* elt_float64(float64* ptr, int32 idx) {
    return (float64*)&ptr[idx];
}

char** elt_string(char** ptr, int32 idx) {
    return (char**)&ptr[idx];
}

void set_bool(bool* ptr, bool val) {
    *ptr = val;
}

void set_byte(char* ptr, char val) {
    *ptr= val;
}

void set_int16(int16* ptr, int16 val) {
    *ptr= val;
}

void set_int32(int32* ptr, int32 val) {
    *ptr = val;
}

void set_int64(long* ptr, long val) {
    *ptr = val;
}

void set_float32(float32* ptr, float32 val) {
    *ptr = val;
}

void set_float64(float64* ptr, float64 val) {
    *ptr = val;
}

void set_string(char** ptr, char* val) {
    *ptr = val;
}


float32 mapit_1(float32 op_1)
{
print_string("Map");
println_float64((float64)add_float64(2,op_1,op_1));
return(add_float64(2,op_1,op_1));
}
float32 reduceit_1(float32 op1_1,float32 op2_1)
{
print_string("Reduce");
println_float64(add_float64(2,op1_1,op2_1));
return(add_float64(2,op1_1,op2_1));
}
int32 do_1(int32 argc_1)
{
println_float32(mapit_1(5.5));
println_string("RET");
{
float32 float1_2=0.0;
float32 float2_2=0.0;
int32 array_2[]={1, 2, 3, 4, 5, 6};
float32 values_2[]={1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
char string_2[]={'a', 'b', 'c'};
map_float32(mapit_1,values_2);
reduce_float32(reduceit_1,values_2);
println_string(string_2);
set_float32(&float1_2,666.0);
set_int32(&argc_1,add_int32(2,100,max_int32(1000,500)));
println_int32(argc_1);
set_int32(&argc_1,add_int32(2,100,sub_int32(2,1000,999)));
println_int32(argc_1);
int32 cnt_3=0;
for(cnt_3=0;cnt_3<max_int32(20,10);cnt_3++)
{
set_int32(elt_int32(array_2,cnt_3),1000);
print_format("%d",power_int32(2,8));
print_string("ELT:");
print_format("%d",*elt_int32(array_2,cnt_3));
print_string("CNT:");
if(cnt_3==max_int32(1,3))
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
println_int32(cnt_3);
}
println_float32(float1_2);
println_float32(float2_2);
println_int32(argc_1);
println_string("ENDE");
}
println_int32(argc_1);
return(2);
}
int32 main()
{
return(do_1(777));
}



