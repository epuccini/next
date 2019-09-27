#include "output.h"


static ixx acc_0;
static ixx den_0;
static ixx num_0;
static ixx result_extract_digit_0_ixx;
void extract_digit_0_ui64(ui64 nth_1)
{
mpz_t G549;
mpz_init(G549);
mpz_mul_si(G549,num_0,nth_1);
mpz_add(G549,G549,acc_0);
mpz_div(G549,G549,den_0);
mpz_set(result_extract_digit_0_ixx,(G549));
}
void eliminate_digit_0_ui64(ui64 d_1)
{
mpz_t G556;
mpz_init_set_si(G556,10);
mpz_t G559;
mpz_init(G559);
mpz_t G562;
mpz_init(G562);
mpz_mul_si(G562,den_0,d_1);
mpz_sub(G559,acc_0,G562);
mpz_mul(G556,G556,G559);
set_pointer_ixx(acc_0,(G556));
mpz_t G565;
mpz_init_set(G565,num_0);
mpz_t G566;
mpz_init_set_si(G566,10);
mpz_mul(G565,G565,G566);
set_pointer_ixx(num_0,(G565));
}
void next_term_0_ui64(ui64 k_1)
{
{
ui64 k2_2=(1+(k_1*2));
mpz_t G568;
mpz_init_set_ui(G568,k2_2);
mpz_t G571;
mpz_init(G571);
mpz_t G574;
mpz_init(G574);
mpz_t G575;
mpz_init_set_si(G575,2);
mpz_mul(G574,num_0,G575);
mpz_add(G571,acc_0,G574);
mpz_mul(G568,G568,G571);
set_pointer_ixx(acc_0,(G568));
mpz_t G577;
mpz_init_set(G577,den_0);
mpz_mul_si(G577,G577,k2_2);
set_pointer_ixx(den_0,(G577));
mpz_t G580;
mpz_init_set(G580,num_0);
mpz_mul_si(G580,G580,k_1);
set_pointer_ixx(num_0,(G580));
}
}
i32 main(i32 argc_1,string* argv_1)
{
mpz_init_set_si(acc_0,0);
mpz_init_set_si(den_0,1);
mpz_init_set_si(num_0,1);
{
mpz_t G583;
mpz_init_set_str(G583,"0",10);
ui64 d_2=0;
ui64 k_2=0;
ui64 i_2=0;
ui64 n_2=10000;
ixx result_2;
mpz_init(result_2);
mpz_set(result_2,G583);
while(lt_ui64(i_2,n_2))
{
set_pointer_ui64(&k_2,(k_2+1));
next_term_0_ui64(k_2);
if(gt_ixx(num_0,acc_0))
{
continue;
}
extract_digit_0_ui64(3);
set_pointer_ui64(&d_2,mpz_get_si(result_extract_digit_0_ixx));
extract_digit_0_ui64(4);
if(neq_ui64(d_2,mpz_get_si(result_extract_digit_0_ixx)))
{
continue;
}
print_ui64(d_2);
set_pointer_ui64(&i_2,(1+i_2));
if(eq_i32(mod_ui64(i_2,10),0))
{
printf(" %lu\n",i_2);
}
eliminate_digit_0_ui64(d_2);
};
return(0);
}
destroy_ptr(pointer_list);
}





