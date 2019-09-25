#include "output.h"


static ixx acc_0;
static ixx den_0;
static ixx num_0;
void extract_digit_0_ixx(ixx result_1,ixx nth_1)
{
mpz_t G547;
mpz_init_set(G547,num_0);
mpz_t G548;
mpz_init_set_str(G548,"0",10);
mpz_mul(G547,G547,nth_1);
mpz_t G550;
mpz_init_set_str(G550,"0",10);
mpz_add(G547,G547,acc_0);
mpz_t G552;
mpz_init_set_str(G552,"0",10);
mpz_div(G547,G547,den_0);
set_pointer_ixx(result_1,(G547));
}
void eliminate_digit_0_ui64(ui64 d_1)
{
mpz_t G554;
mpz_init_set(G554,acc_0);
mpz_t G557;
mpz_init_set(G557,den_0);
mpz_t G558;
mpz_init_set_str(G558,"0",10);
mpz_mul(G557,G557,d_1);
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
void next_term_0_ixx(ixx k_1)
{
{
mpz_t G566;
mpz_init_set_str(G566,"1",10);
mpz_t G569;
mpz_init_set(G569,k_1);
mpz_t G570;
mpz_init_set_str(G570,"2",10);
mpz_mul(G569,G569,G570);
mpz_add(G566,G566,G569);
mpz_t G572;
mpz_init_set(G572,acc_0);
mpz_t G575;
mpz_init_set(G575,num_0);
mpz_t G576;
mpz_init_set_str(G576,"2",10);
mpz_mul(G575,G575,G576);
mpz_add(G572,G572,G575);
ixx k2_2;
mpz_init(k2_2);
mpz_set(k2_2,(G566));
set_pointer_ixx(acc_0,(G572));
mpz_t G578;
mpz_init_set(G578,acc_0);
mpz_t G579;
mpz_init_set_str(G579,"0",10);
mpz_mul(G578,G578,k2_2);
set_pointer_ixx(acc_0,(G578));
mpz_t G581;
mpz_init_set(G581,den_0);
mpz_t G582;
mpz_init_set_str(G582,"0",10);
mpz_mul(G581,G581,k2_2);
set_pointer_ixx(den_0,(G581));
mpz_t G584;
mpz_init_set(G584,num_0);
mpz_t G585;
mpz_init_set_str(G585,"0",10);
mpz_mul(G584,G584,k_1);
set_pointer_ixx(num_0,(G584));
}
}
i32 main(i32 argc_1,string* argv_1)
{
{
mpz_t G587;
mpz_init_set_str(G587,"0",10);
mpz_t G588;
mpz_init_set_str(G588,"0",10);
mpz_t G589;
mpz_init_set_str(G589,"10000",10);
mpz_t G590;
mpz_init_set_str(G590,"0",10);
ui64 d_2=0;
ixx k_2;
mpz_init(k_2);
mpz_set(k_2,G587);
ixx i_2;
mpz_init(i_2);
mpz_set(i_2,G588);
ixx n_2;
mpz_init(n_2);
mpz_set(n_2,G589);
ixx result_2;
mpz_init(result_2);
mpz_set(result_2,G590);
while(lt_ixx(i_2,n_2))
{
mpz_t G591;
mpz_init_set(G591,k_2);
mpz_t G592;
mpz_init_set_str(G592,"1",10);
mpz_add(G591,G591,G592);
set_pointer_ixx(k_2,(G591));
next_term_0_ixx(k_2);
if(gt_ixx(num_0,acc_0))
{
continue;
}
mpz_t G594;
mpz_init_set_str(G594,"3",10);
extract_digit_0_ixx(result_2,G594);
set_pointer_ui64(&d_2,result_2);
mpz_t G595;
mpz_init_set_str(G595,"4",10);
extract_digit_0_ixx(result_2,G595);
if(neq_ui64(d_2,result_2))
{
continue;
}
print_ui64(d_2);
print_string(" ");
mpz_t G596;
mpz_init_set_str(G596,"1",10);
mpz_t G597;
mpz_init_set_str(G597,"0",10);
mpz_add(G596,G596,i_2);
set_pointer_ixx(i_2,(G596));
mpz_t G599;
mpz_init_set_str(G599,"10",10);
mpz_t G600;
mpz_init_set_str(G600,"0",10);
if(eq_ixx(mod_ixx(i_2,G599),G600))
{
prnl_ixx(i_2);
}
eliminate_digit_0_ui64(d_2);
};
return(0);
}
destroy_ptr(pointer_list);
}





