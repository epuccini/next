#include "output.h"


static ixx acc_0;
static ixx den_0;
static ixx num_0;
ixx_cast extract_digit_0_ixx(ixx nth_1)
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
return((ixx_cast)(G549));
}
void eliminate_digit_0_ixx(ixx d_1)
{
mpz_t G556;
mpz_init_set(G556,acc_0);
mpz_t G559;
mpz_init_set(G559,den_0);
mpz_t G560;
mpz_init_set_str(G560,"0",10);
mpz_mul(G559,G559,d_1);
mpz_sub(G556,G556,G559);
set_pointer_ixx(&acc_0,(G556));
mpz_t G562;
mpz_init_set(G562,acc_0);
mpz_t G563;
mpz_init_set_str(G563,"10",10);
mpz_mul(G562,G562,G563);
set_pointer_ixx(&acc_0,(G562));
mpz_t G565;
mpz_init_set(G565,num_0);
mpz_t G566;
mpz_init_set_str(G566,"10",10);
mpz_mul(G565,G565,G566);
set_pointer_ixx(&num_0,(G565));
}
void next_term_0_ixx(ixx k_1)
{
{
mpz_t G568;
mpz_init_set_str(G568,"1",10);
mpz_t G571;
mpz_init_set(G571,k_1);
mpz_t G572;
mpz_init_set_str(G572,"2",10);
mpz_mul(G571,G571,G572);
mpz_add(G568,G568,G571);
mpz_t G574;
mpz_init_set(G574,acc_0);
mpz_t G577;
mpz_init_set(G577,num_0);
mpz_t G578;
mpz_init_set_str(G578,"2",10);
mpz_mul(G577,G577,G578);
mpz_add(G574,G574,G577);
ixx k2_2;
mpz_init(k2_2);
mpz_set(k2_2,(G568));
set_pointer_ixx(&acc_0,(G574));
mpz_t G580;
mpz_init_set(G580,acc_0);
mpz_t G581;
mpz_init_set_str(G581,"0",10);
mpz_mul(G580,G580,k2_2);
set_pointer_ixx(&acc_0,(G580));
mpz_t G583;
mpz_init_set(G583,den_0);
mpz_t G584;
mpz_init_set_str(G584,"0",10);
mpz_mul(G583,G583,k2_2);
set_pointer_ixx(&den_0,(G583));
mpz_t G586;
mpz_init_set(G586,num_0);
mpz_t G587;
mpz_init_set_str(G587,"0",10);
mpz_mul(G586,G586,k_1);
set_pointer_ixx(&num_0,(G586));
}
}
i32 main(i32 argc_1,string* argv_1)
{
{
mpz_t G589;
mpz_init_set_str(G589,"0",10);
mpz_t G590;
mpz_init_set_str(G590,"0",10);
mpz_t G591;
mpz_init_set_str(G591,"0",10);
mpz_t G592;
mpz_init_set_str(G592,"10000",10);
mpz_t G593;
mpz_init_set(G593,k_2);
mpz_t G594;
mpz_init_set_str(G594,"1",10);
mpz_add(G593,G593,G594);
ixx d_2;
mpz_init(d_2);
mpz_set(d_2,G589);
ixx k_2;
mpz_init(k_2);
mpz_set(k_2,G590);
ixx i_2;
mpz_init(i_2);
mpz_set(i_2,G591);
ixx n_2;
mpz_init(n_2);
mpz_set(n_2,G592);
while(lt_ixx(i_2,n_2))
{
set_pointer_ixx(&k_2,(G593));
next_term_0_ixx(k_2);
mpz_t G596;
mpz_init_set_str(G596,"3",10);
if(gt_ixx(num_0,acc_0))
{
continue;
}
set_pointer_ixx(&d_2,extract_digit_0_ixx(G596));
mpz_t G597;
mpz_init_set_str(G597,"4",10);
if(neq_ixx(d_2,extract_digit_0_ixx(G597)))
{
continue;
}
prn_ixx(d_2);
print_string(" ");
mpz_t G598;
mpz_init_set_str(G598,"1",10);
mpz_t G599;
mpz_init_set_str(G599,"0",10);
mpz_add(G598,G598,i_2);
set_pointer_ixx(&i_2,(G598));
mpz_t G601;
mpz_init_set_str(G601,"10",10);
mpz_t G602;
mpz_init_set_str(G602,"0",10);
if(eq_i32(mod_ixx(i_2,G601),G602))
{
prnl_ixx(i_2);
}
eliminate_digit_0_ixx(d_2);
};
return(0);
}
destroy_ptr(pointer_list);
}





