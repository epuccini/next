#include "output.h"


static ixx acc_0;
static ixx den_0;
static ixx num_0;
void extract_digit_0_ixx(ixx result_1,ixx nth_1)
{
mpz_t G549;
mpz_init_set(G549,num_0);
mpz_t G550;
mpz_init_set_str(G550,"0",10);
mpz_mul(G549,G549,nth_1);
mpz_t G552;
mpz_init_set_str(G552,"0",10);
mpz_add(G549,G549,acc_0);
mpz_t G554;
mpz_init_set_str(G554,"0",10);
mpz_div(G549,G549,den_0);
set_pointer_ixx(result_1,(G549));
}
void eliminate_digit_0_ui64(ui64 d_1)
{
mpz_t G556;
mpz_init_set(G556,acc_0);
mpz_t G559;
mpz_init_set(G559,den_0);
mpz_t G560;
mpz_set_si(G560,d_1);
mpz_mul(G559,G559,G560);
mpz_sub(G556,G556,G559);
set_pointer_ixx(acc_0,(G556));
mpz_t G562;
mpz_init_set(G562,acc_0);
mpz_t G563;
mpz_init_set_str(G563,"10",10);
mpz_mul(G562,G562,G563);
set_pointer_ixx(acc_0,(G562));
mpz_t G565;
mpz_init_set(G565,num_0);
mpz_t G566;
mpz_init_set_str(G566,"10",10);
mpz_mul(G565,G565,G566);
set_pointer_ixx(num_0,(G565));
}
void next_term_0_ui64(ui64 k_1)
{
{
mpz_t G568;
mpz_init_set(G568,acc_0);
mpz_t G571;
mpz_init_set(G571,num_0);
mpz_t G572;
mpz_init_set_str(G572,"2",10);
mpz_mul(G571,G571,G572);
mpz_add(G568,G568,G571);
ui64 k2_2=(1+(k_1*2));
set_pointer_ixx(acc_0,(G568));
mpz_t G574;
mpz_init_set(G574,acc_0);
mpz_t G575;
mpz_set_si(G575,k2_2);
mpz_mul(G574,G574,G575);
set_pointer_ixx(acc_0,(G574));
mpz_t G577;
mpz_init_set(G577,den_0);
mpz_t G578;
mpz_set_si(G578,k2_2);
mpz_mul(G577,G577,G578);
set_pointer_ixx(den_0,(G577));
mpz_t G580;
mpz_init_set(G580,num_0);
mpz_t G581;
mpz_set_si(G581,k_1);
mpz_mul(G580,G580,G581);
set_pointer_ixx(num_0,(G580));
}
}
i32 main(i32 argc_1,string* argv_1)
{
printf("Start");
{
printf("Start");
mpz_t G583;
mpz_init_set_str(G583,"0",10);
ui64 d_2=0;
ui64 k_2=0;
ui64 i_2=0;
ui64 n_2=10000;
ixx result_2;
mpz_init(result_2);
mpz_set(result_2,G583);
printf("While");
while(lt_ui64(i_2,n_2))
{
set_pointer_ui64(&k_2,(k_2+1));
next_term_0_ui64(k_2);
printf("IF");
if(gt_ixx(num_0,acc_0))
{
continue;
}
mpz_t G584;
mpz_init_set_str(G584,"3",10);
extract_digit_0_ixx(result_2,G584);
set_pointer_ui64(&d_2,mpz_get_si(result_2));
mpz_t G585;
mpz_init_set_str(G585,"4",10);
extract_digit_0_ixx(result_2,G585);
if(neq_ui64(d_2,mpz_get_si(result_2)))
{
continue;
}
print_ui64(d_2);
print_string(" ");
set_pointer_ui64(&i_2,(1+i_2));
if(eq_i32(mod_ui64(i_2,10),0))
{
println_ui64(i_2);
}
eliminate_digit_0_ui64(d_2);
};
return(0);
}
destroy_ptr(pointer_list);
}





