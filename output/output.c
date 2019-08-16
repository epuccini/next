#include "output.h"

int mod(int a, int b) {
	return a % b;
}

int int_mod_int(int a, int b) {
	return a % b;
}

void print_int(int val) {
    printf("%d", val);
}

void print_long(long val) {
    printf("%l", val);
}

void print_float(float val) {
    printf("%f", val);
}

void print_double(double val) {
    printf("%d", val);
}

void print_str(const char* str) {
    printf(str);
}

void println_int(int val) {
    printf("%d\n", val);
}

void println_long(long val) {
    printf("%l\n", val);
}

void println_float(float val) {
    printf("%f\n", val);
}

void println_double(double val) {
    printf("%d\n", val);
}

void println_str(const char* str) {
    printf("%s\n", str);
}
int main () {
    println_str("HelloWorld");
println_int(10);

}