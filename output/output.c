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


float test_1(float op1_1,float op2_1)
{
return(add_double(2,op1_1,op2_1));
}
int do_1(int argc_1)
{
println_float32(test_1(5.5,6.6));
println_str("RET");
{
float float1_2=0.0;
float float2_2=0.0;
int array_2[]={1, 2, 3, 4, 5, 6};
set_float32(&float1_2,666.0);
set_int32(&argc_1,add_int(2,100,max_int(1000,500)));
println_int32(argc_1);
set_int32(&argc_1,add_int(2,100,sub_int(2,1000,999)));
println_int32(argc_1);
int cnt_3=0;
for(cnt_3=0;cnt_3<5;cnt_3++)
{
set_int32(elt_int32(array_2,cnt_3),1000);
print_str("ELT:");
print_format("%d",*elt_int32(array_2,cnt_3));
print_str("CNT:");
if(cnt_3==3)
{
if(cnt_3==4)
{
println_str("Notpossible");
}
else
{
println_str("ELSECNT=3!!");
}
}
else
{
println_str("CNT!=3");
}
println_int32(cnt_3);
}
println_float32(float1_2);
println_float32(float2_2);
println_int32(argc_1);
println_str("ENDE");
}
println_int32(argc_1);
return(2);
}
int main()
{
return(do_1(777));
}



