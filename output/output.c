#include "output.h"


static ixx acc_0;
static ixx den_0;
static ixx num_0;
void extract_digit_0_ixx(ixx result_1,ixx nth_1)
{
mpz_t G547;
mpz_init(G547);
mpz_mul(G547,num_0,nth_1);
mpz_add(G547,G547,acc_0);
mpz_div(G547,G547,den_0);
set_pointer_ixx(result_1,(G547));
}
void eliminate_digit_0_ui64(ui64 d_1)
{
mpz_t G554;
mpz_init_set(G554,acc_0);
mpz_t G557;
mpz_init(G557);
mpz_mul_si(G557,den_0,d_1);
mpz_sub(G554,G554,G557);
set_pointer_ixx(acc_0,(G554));
mpz_t G560;
mpz_init_set(G560,acc_0);
mpz_t G561;
mpz_init_set_str(G561,"10",10);
mpz_mul(G560,G560,G561);
set_pointer_ixx(acc_0,(G560));
mpz_t G563;
mpz_init_set(G563,num_0);
mpz_t G564;
mpz_init_set_str(G564,"10",10);
mpz_mul(G563,G563,G564);
set_pointer_ixx(num_0,(G563));
}
void next_term_0_ui64(ui64 k_1)
{
{
mpz_t G566;
mpz_init_set(G566,acc_0);
mpz_t G569;
mpz_init(G569);
mpz_t G570;
mpz_init_set_str(G570,"2",10);
mpz_mul(G569,num_0,G570);
mpz_add(G566,G566,G569);
ui64 k2_2=(1+(k_1*2));
set_pointer_ixx(acc_0,(G566));
mpz_t G572;
mpz_init_set(G572,acc_0);
mpz_mul_si(G572,G572,k2_2);
set_pointer_ixx(acc_0,(G572));
mpz_t G575;
mpz_init_set(G575,den_0);
mpz_mul_si(G575,G575,k2_2);
set_pointer_ixx(den_0,(G575));
mpz_t G578;
mpz_init_set(G578,num_0);
mpz_mul_si(G578,G578,k_1);
set_pointer_ixx(num_0,(G578));
}
}
i32 main(i32 argc_1,string* argv_1)
{
mpz_init_set_si(acc_0,0);
mpz_init_set_si(den_0,1);
mpz_init_set_si(num_0,1);
{
mpz_t G581;
mpz_init_set_str(G581,"0",10);
ui64 d_2=0;
ui64 k_2=0;
ui64 i_2=0;
ui64 n_2=10000;
ixx result_2;
mpz_init(result_2);
mpz_set(result_2,G581);
while(lt_ui64(i_2,n_2))
{
set_pointer_ui64(&k_2,(k_2+1));
next_term_0_ui64(k_2);
if(gt_ixx(num_0,acc_0))
{
continue;
}
mpz_t G582;
mpz_init_set_str(G582,"3",10);
extract_digit_0_ixx(result_2,G582);
set_pointer_ui64(&d_2,mpz_get_ui(result_2));
mpz_t G583;
mpz_init_set_str(G583,"4",10);
extract_digit_0_ixx(result_2,G583);
if(neq_ui64(d_2,mpz_get_ui(result_2)))
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





