#include "output.h"


static ixx acc_0;
static ixx den_0;
static ixx num_0;
void extract_digit_0_ixx(ixx result_1,ixx nth_1)
{
mpz_t G547;
mpz_init_set_str(G547,"0",10);
mpz_t G550;
mpz_init_set(G550,num_0);
mpz_t G551;
mpz_init_set_str(G551,"0",10);
mpz_mul(G550,G550,nth_1);
mpz_t G553;
mpz_init_set_str(G553,"0",10);
mpz_add(G550,G550,acc_0);
mpz_t G555;
mpz_init_set_str(G555,"0",10);
mpz_t G557;
mpz_init_set_str(G557,"1",10);
if(neq_ixx(den_0,G547))
{
mpz_div(G550,G550,den_0);
set_pointer_ixx(result_1,(G550));
}
else
{
set_pointer_ixx(result_1,G557);
}
}
void eliminate_digit_0_ixx(ixx d_1)
{
mpz_t G558;
mpz_init_set(G558,acc_0);
mpz_t G561;
mpz_init_set(G561,den_0);
mpz_t G562;
mpz_init_set_str(G562,"0",10);
mpz_mul(G561,G561,d_1);
mpz_sub(G558,G558,G561);
set_pointer_ixx(acc_0,(G558));
mpz_t G564;
mpz_init_set(G564,acc_0);
mpz_t G565;
mpz_init_set_str(G565,"10",10);
mpz_mul(G564,G564,G565);
set_pointer_ixx(acc_0,(G564));
mpz_t G567;
mpz_init_set(G567,num_0);
mpz_t G568;
mpz_init_set_str(G568,"10",10);
mpz_mul(G567,G567,G568);
set_pointer_ixx(num_0,(G567));
}
void next_term_0_ixx(ixx k_1)
{
{
mpz_t G570;
mpz_init_set_str(G570,"1",10);
mpz_t G573;
mpz_init_set(G573,k_1);
mpz_t G574;
mpz_init_set_str(G574,"2",10);
mpz_mul(G573,G573,G574);
mpz_add(G570,G570,G573);
mpz_t G576;
mpz_init_set(G576,acc_0);
mpz_t G579;
mpz_init_set(G579,num_0);
mpz_t G580;
mpz_init_set_str(G580,"2",10);
mpz_mul(G579,G579,G580);
mpz_add(G576,G576,G579);
ixx k2_2;
mpz_init(k2_2);
mpz_set(k2_2,(G570));
set_pointer_ixx(acc_0,(G576));
mpz_t G582;
mpz_init_set(G582,acc_0);
mpz_t G583;
mpz_init_set_str(G583,"0",10);
mpz_mul(G582,G582,k2_2);
set_pointer_ixx(acc_0,(G582));
mpz_t G585;
mpz_init_set(G585,den_0);
mpz_t G586;
mpz_init_set_str(G586,"0",10);
mpz_mul(G585,G585,k2_2);
set_pointer_ixx(den_0,(G585));
mpz_t G588;
mpz_init_set(G588,num_0);
mpz_t G589;
mpz_init_set_str(G589,"0",10);
mpz_mul(G588,G588,k_1);
set_pointer_ixx(num_0,(G588));
}
}
i32 main(i32 argc_1,string* argv_1)
{
{
mpz_t G591;
mpz_init_set_str(G591,"0",10);
mpz_t G592;
mpz_init_set_str(G592,"0",10);
mpz_t G593;
mpz_init_set_str(G593,"0",10);
mpz_t G594;
mpz_init_set_str(G594,"10000",10);
mpz_t G595;
mpz_init_set_str(G595,"0",10);
ixx d_2;
mpz_init(d_2);
mpz_set(d_2,G591);
ixx k_2;
mpz_init(k_2);
mpz_set(k_2,G592);
ixx i_2;
mpz_init(i_2);
mpz_set(i_2,G593);
ixx n_2;
mpz_init(n_2);
mpz_set(n_2,G594);
ixx result_2;
mpz_init(result_2);
mpz_set(result_2,G595);
while(lt_ixx(i_2,n_2))
{
mpz_t G596;
mpz_init_set(G596,k_2);
mpz_t G597;
mpz_init_set_str(G597,"1",10);
mpz_add(G596,G596,G597);
set_pointer_ixx(k_2,(G596));
next_term_0_ixx(k_2);
if(gt_ixx(num_0,acc_0))
{
continue;
}
mpz_t G599;
mpz_init_set_str(G599,"3",10);
extract_digit_0_ixx(result_2,G599);
set_pointer_ixx(d_2,result_2);
mpz_t G600;
mpz_init_set_str(G600,"4",10);
extract_digit_0_ixx(result_2,G600);
if(neq_ixx(d_2,result_2))
{
continue;
}
prn_ixx(d_2);
print_string(" ");
mpz_t G601;
mpz_init_set_str(G601,"1",10);
mpz_t G602;
mpz_init_set_str(G602,"0",10);
mpz_add(G601,G601,i_2);
set_pointer_ixx(i_2,(G601));
mpz_t G604;
mpz_init_set_str(G604,"10",10);
mpz_t G605;
mpz_init_set_str(G605,"0",10);
if(eq_ixx(mod_ixx(i_2,G604),G605))
{
prnl_ixx(i_2);
}
eliminate_digit_0_ixx(d_2);
};
return(0);
}
destroy_ptr(pointer_list);
}





