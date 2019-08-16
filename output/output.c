#include "output.h"

int mod(int a, int b) {
	return a % b;
}

int int_mod_int(int a, int b) {
	return a % b;
}
int main() {
    return mod(13,mod(13,5));
}
