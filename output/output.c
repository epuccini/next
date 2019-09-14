#include "output.h"


i32 main()
{
{
i32 max_2=56000;
i32* r_2=new_i32((max_2+1));
append_ptr(r_2, 1, VARIABLE);
i32 b_2=0;
i32 d_2=0;
i32 c_2=0;
i32 i_3=0;
for(i_3=0;i_3<max_2;i_3++)
{
set_pointer_i32(elt_array_i32(r_2,i_3),2000);
}
i32 k_3=max_2;
for(k_3=max_2;k_3>0;k_3--)
{
set_pointer_i32(&d_2,0);
set_pointer_i32(&i_3,k_3);
i32 m_4=0;
for(m_4=0;m_4!=100000;m_4++)
{
set_pointer_i32(&d_2,(d_2+(*elt_array_i32(r_2,i_3)*100000)));
set_pointer_i32(&b_2,((2*i_3)-1));
set_pointer_i32(elt_array_i32(r_2,i_3),mod(d_2,b_2));
set_pointer_i32(&d_2,(d_2/b_2));
set_pointer_i32(&i_3,(i_3-1));
if(i_3==0)
{
break;
}
set_pointer_i32(&d_2,(d_2*i_3));
}
printf("%.4d",(i32)(c_2+(d_2/100000)));
if(mod(k_3,10)==0)
{
printf(" %d\n",((max_2-k_3)/7));
}
set_pointer_i32(&c_2,mod(d_2,100000));
set_pointer_i32(&k_3,(k_3-13));
}
return(0);
}
destroy_ptr(pointer_list);
}





