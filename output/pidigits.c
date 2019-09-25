
#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

mpz_t tmp1, tmp2, acc, den, num;
typedef unsigned int ui;

ui extract_digit(mpz_t result, ui nth) {
   // joggling between tmp1 and tmp2, so GMP won't have to use temp buffers
  mpz_t nth_2;
  mpz_init(nth_2);
  mpz_set_ui(nth_2, nth);
  mpz_mul(tmp1, num, nth_2);
  mpz_add(tmp2, tmp1, acc);
  mpz_div(tmp1, tmp2, den);
  mpz_set(result, tmp1);
}

void eliminate_digit(ui d) {
  mpz_t d_2;
  mpz_init(d_2);
  mpz_set_ui(d_2, d);
  mpz_submul(acc, den, d_2);
  mpz_mul_ui(acc, acc, 10);
  mpz_mul_ui(num, num, 10);
}

void next_term(ui k) {
   ui k2 = k * 2U + 1U;

   mpz_t k_2;
   mpz_init(k_2);
   mpz_set_ui(k_2, k);
   mpz_t k2_2;
   mpz_init(k2_2);
   mpz_set_ui(k2_2, k2);
   mpz_addmul_ui(acc, num, 2U);
   mpz_mul(acc, acc, k2_2);
   mpz_mul(den, den, k2_2);
   mpz_mul(num, num, k_2);
}

int main(int argc, char **argv) {
   ui d, k, i;
   mpz_t result;
   int n = 10000; 

   mpz_init(tmp1);
   mpz_init(tmp2);
   mpz_init(result);
   
   mpz_init_set_ui(acc, 0);
   mpz_init_set_ui(den, 1);
   mpz_init_set_ui(num, 1);

   for (i = k = 0; i < n;) {
      next_term(++k);
      if (mpz_cmp(num, acc) > 0)
         continue;
      
      extract_digit(result,3);
      d = mpz_get_ui(result);
      extract_digit(result,4);
      if (d != mpz_get_ui(result))
         continue;

      putchar('0' + d);
      if (++i % 10 == 0)
         printf("\t:%u\n", i);
      eliminate_digit(d);
   }

   return 0;
}
