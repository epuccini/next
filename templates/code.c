#include "$(OUTPUT_H)"

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

void print_str(char* str) {
    printf("%s", str);
}
