#include "output.h"


static f80 acc_0=0;
static f80 den_0=1;
static f80 num_0=1;
f80 extract_digit_0(f80 nth_1)
{
return(trunc((((num_0*nth_1)+acc_0)/den_0)));
}
void eliminate_digit_0(ui64 d_1)
{
set_pointer_f80(&acc_0,(acc_0-(den_0*d_1)));
set_pointer_f80(&acc_0,(acc_0*10));
set_pointer_f80(&num_0,(num_0*10));
}
void next_term_0(ui64 k_1)
{
{
ui64 k2_2=(1+(k_1*2));
set_pointer_f80(&acc_0,(acc_0+(num_0*2)));
set_pointer_f80(&acc_0,(acc_0*k2_2));
set_pointer_f80(&den_0,(den_0*k2_2));
set_pointer_f80(&num_0,(num_0*k_1));
}
}
i32 main(i32 argc_1,string* argv_1)
{
{
ui64 d_2=0;
ui64 k_2=0;
ui64 i_2=0;
ui64 n_2=10000;
set_pointer_ui64(&n_2,480);
while(i_2<n_2)
{
set_pointer_ui64(&k_2,(k_2+1));
next_term_0(k_2);
if(num_0>acc_0)
{
continue;
}
set_pointer_ui64(&d_2,extract_digit_0(3));
if(d_2!=extract_digit_0(4))
{
continue;
}
print_ui64(d_2);
print_string(" ");
set_pointer_ui64(&i_2,(1+i_2));
if(mod(i_2,10)==0)
{
println_ui64(i_2);
}
eliminate_digit_0(d_2);
continue;
};
return(0);
}
destroy_ptr(pointer_list);
}





