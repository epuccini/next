#include "output.h"


static i32 layer__test_1=0;
i32 layer__fun1_1_void()
{
println_string("Module function fun1");
return(999);
}
i32 layer__fun2_1_void()
{
println_string("Module function fun2");
return(888);
}
f32 mapit_0_f32(f32 op_1)
{
print_string("Map f32 ");
println_f64((op_1+op_1));
return((op_1+op_1));
}
f32 map_once_0_f32(f32 op_1)
{
print_string("Map-once f32 ");
println_f64((op_1+op_1));
return((op_1+op_1));
}
i32 map_once_0_i32(i32 op_1)
{
print_string("Map-once i32 ");
println_f64((op_1+op_1));
return((op_1+op_1));
}
f32 reduceit_0_f32(f32 op1_1,f32 op2_1)
{
print_string("Reduce ");
println_f32((f32)(op1_1+op2_1));
return((op1_1+op2_1));
}
f32 work_0_f32(f32 (*f_1)(f32),f32 arg_1)
{
println_string("Work!!!");
return((*f_1)(arg_1));
}
void modules_0_void()
{
println_string("Modules!!!");
layer__fun1_1_void();
layer__fun2_1_void();
set_pointer_i32(&layer__test_1,1000);
print_string("Test module variable: ");
println_i32(layer__test_1);
}
i32 arrays_and_lists_0_i32(i32 argc_1)
{
println_string("Arrays and lists!!!");
mapit_0_f32(5.5);
map_once_0_f32(5.5);
map_once_0_i32(5);
{
f32 float1_2=0.0;
f32 float2_2=(10.0+10.0);
i32 array_2[]={1, 2, 3, 4, 5, 6};
append_ptr(array_2, sizeof(array_2)/sizeof(i32), ARRAY);
i32 arrayb_2[]={9, 8, 7, 6, 5, 4, 3, 2, 1};
append_ptr(arrayb_2, sizeof(arrayb_2)/sizeof(i32), ARRAY);
i32* append_array_2=append_array_array_i32(array_2,arrayb_2);
append_ptr(append_array_2, 1, VARIABLE);
i32* rev_array_2=reverse_pointer_i32(append_array_2);
append_ptr(rev_array_2, 1, VARIABLE);
i32* cdr_array_2=cdr_array_i32(array_2);
append_ptr(cdr_array_2, 1, VARIABLE);
f32 values_2[]={1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
append_ptr(values_2, sizeof(values_2)/sizeof(f32), ARRAY);
f32* my_new_array_2=mapn_array_f32(mapit_0_f32,values_2);
append_ptr(my_new_array_2, 1, VARIABLE);
f32* my_new_floats_2=new_f32(10);
append_ptr(my_new_floats_2, 1, VARIABLE);
f32* my_new_array2_2=append_array_f32(values_2,1000.0);
append_ptr(my_new_array2_2, 1, VARIABLE);
f32* my_new_array3_2=append_pointer_f32(my_new_array2_2,2000.0);
append_ptr(my_new_array3_2, 1, VARIABLE);
node_f32* my_list_2=create_list_f32((f32[]){1.0, 2.0, 3.0, 4.0, 5.0, 6.0},6);
node_f32* my_listb_2=create_list_f32((f32[]){7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0},8);
node_f32* append_my_list_2=append_list_list_f32(my_list_2,my_listb_2);
node_f32* rev_list_2=reverse_list_f32(append_my_list_2);
node_f32* cdr_my_list_2=cdr_list_f32(my_list_2);
string string_2="abcdefg";
c8 chars_2[]={'a', 'b', 'c', 'd', 'e', 'f', 'g'};
append_ptr(chars_2, sizeof(chars_2)/sizeof(c8), ARRAY);
c8 new_string_2[]="Just a string";
append_ptr(new_string_2, sizeof(new_string_2)/sizeof(c8), ARRAY);
f32 (*myfun_2)(f32)=mapit_0_f32;
set_pointer_f32((f32*)elt_array_f32(my_new_floats_2,0),888.0);
print_string("my-new-floats set 1. element: ");
println_pointer_f32(my_new_floats_2);
print_string("array: ");
println_array_i32(sizeof(array_2),array_2);
print_string("cdr-array: ");
println_pointer_i32(cdr_array_2);
print_string("append-array: ");
println_pointer_i32(append_array_2);
print_string("rev-array: ");
println_pointer_i32(rev_array_2);
print_string("my-list: ");
println_list_f32(my_list_2);
print_string("cdr-my-list: ");
println_list_f32(cdr_my_list_2);
print_string("append-my-list: ");
println_list_f32(append_my_list_2);
print_string("rev-list: ");
println_list_f32(rev_list_2);
print_string("My new array1: ");
println_pointer_f32(my_new_array_2);
print_string("My new array1 length: ");
println_i32(length_pointer_f32(my_new_array_2));
print_string("My new array2: ");
println_pointer_f32(my_new_array2_2);
print_string("My new array3: ");
println_pointer_f32(my_new_array3_2);
print_string("My new array3 gets array values: ");
set_pointer_pointer_f32(&my_new_array3_2,values_2);
println_pointer_f32(my_new_array3_2);
print_string("string print to string: ");
println_array_c8(sizeof(new_string_2),new_string_2);
print_str_array_c8(new_string_2,"EDWARD");
println_array_c8(sizeof(new_string_2),new_string_2);
print_string("My list push ");
push_list_f32(&my_list_2,888.0);
println_list_f32(my_list_2);
print_string("My list set/push ");
set_pointer_list_f32(&my_list_2,push_list_f32(&my_list_2,777.0));
println_list_f32(my_list_2);
print_string("My list length ");
println_i32(length_list_f32(my_list_2));
print_string("My list length after push ");
println_i32(length_pointer_f32((f32*)push_list_f32(&my_list_2,100.0)));
print_string("My list car ");
println_f32((f32)car_list_f32(my_list_2));
print_string("My list remove 3 ");
remove_list_f32(my_list_2,3);
println_list_f32(my_list_2);
print_string("My list pop ");
println_f32((f32)pop_list_f32(&my_list_2));
print_string("My list length ");
println_i32(length_list_f32(my_list_2));
print_string("My list append ");
append_list_f32(my_list_2,666.0);
println_list_f32(my_list_2);
print_string("My list element ");
println_f32((f32)*elt_list_f32(my_list_2,3));
set_pointer_f32((f32*)elt_list_f32(my_list_2,3),100.0);
print_string("My list set ");
println_list_f32(my_list_2);
print_string("My values ");
println_array_f32(sizeof(values_2),values_2);
myfun_2(1000.0);
work_0_f32(mapit_0_f32,100);
map_array_f32(mapit_0_f32,values_2);
reduce_array_f32(reduceit_0_f32,values_2);
print_string("String: ");
println_string(string_2);
print_string("Chars: ");
println_array_c8(sizeof(chars_2),chars_2);
print_string("sizeof: ");
println_i32(sizeof(string_2));
set_pointer_f32(&float1_2,666.0);
set_pointer_i32(&argc_1,(100+(1000-500)+100+(1000*500)));
println_i32(argc_1);
set_pointer_i32(&argc_1,(100+(1000-999)));
println_i32(argc_1);
delete_ptr(my_new_array_2);
delete_ptr(my_new_floats_2);
delete_ptr(my_new_array2_2);
delete_ptr(my_new_array3_2);
i32 cnt_3=0;
for(cnt_3=0;cnt_3<max_i32(length_array_i32(array_2),1);cnt_3++)
{
set_pointer_i32(elt_array_i32(array_2,cnt_3),(cnt_3*1000));
if(or_bool(equal_i32(cnt_3,3),eq_i32(cnt_3,4)))
{
println_string("COUNT IS 3||4");
}
else
{
println_string("COUNT NOT 3||4");
}
printf("2^cnt = %d\n",power_i32(2,cnt_3));
printf("ELT = %d\n",*elt_array_i32(array_2,cnt_3));
printf("CNT: %d\n",cnt_3);
}
delete_ptr(array_2);
println_f32(float1_2);
println_f32(float2_2);
println_i32(argc_1);
println_string("ENDE");
}
println_i32(argc_1);
println_string("");
return(2);
}
void pointers_0_void()
{
{
i32 value_2=1000;
i32 value2_2=2000;
i32 value3_2=3000;
f32 other_2=1.0;
f32* other_ptr_2=(&other_2);
append_ptr(other_ptr_2, 1, VARIABLE);
i32* value_ptr_2=&value_2;
append_ptr(value_ptr_2, 1, VARIABLE);
i32** value_ptr_ptr_2=&value_ptr_2;
append_ptr(value_ptr_ptr_2, 1, VARIABLE);
i32* new_value_ptr_2=&value2_2;
append_ptr(new_value_ptr_2, 1, VARIABLE);
println_string("Pointers!!!");
print_string("Value ");
println_i32(value_2);
print_string("Pointer print ");
println_pointer_i32(value_ptr_2);
print_string("deref Pointer ");
println_pointer_i32((i32*)(*value_ptr_ptr_2));
print_string("Other value ");
println_f32(other_2);
print_string("Pointer deeref ");
println_f32((f32)(*other_ptr_2));
print_string("Value 2 ");
set_pointer_i32(&value2_2,4000);
println_pointer_i32(new_value_ptr_2);
print_string("New Value Pointer: Value 3 ");
set_pointer_pointer_i32(&new_value_ptr_2,(&value3_2));
println_i32((i32)(*new_value_ptr_2));
print_string("New Value Pointer: Value 3/alt ");
println_pointer_i32(new_value_ptr_2);
println_string("");
}
}
static i32 param1_0=1;
volatile i32 param2_0=2;
void math_0_void()
{
{
f64 a_2=10.0;
f64 b_2=20.0;
f64 c_2=15.5;
f64 d_2=round_f64(c_2);
register i32 param3_2=3;
println_string("Math!!!");
println_f32(0.5);
println_f64(0.5f);
println_i32(param1_0);
println_i32(param2_0);
println_i32(param3_2);
printf("shift left: 1 << 8 = %d\n",1<<8);
print_string("d = round(c) = ");
println_f64(d_2);
print_string("exp(a) = ");
println_f64(exp_f64(a_2));
print_string("sin(b) = ");
println_f64(sin_f64(b_2));
println_string("");
if(a_2>not_i32(0))
{
println_string("a > not 0");
}
println_string("");
}
}
struct monolith_0
{
string string;
i32 a;
f32 b;
};
typedef struct monolith_0 monolith_0;
struct betalith_0
{
f64 d;
f80 e;
struct monolith_0 g;
};
typedef struct betalith_0 betalith_0;
struct deltalith_0
{
string h;
file i;
struct betalith_0 j;
};
typedef struct deltalith_0 deltalith_0;
void compositions_0_void()
{
{
struct monolith_0 mono_2={0};
struct betalith_0 beta_2={0};
struct deltalith_0 delta_2={0};
println_string("Composition!!!");
set_pointer_i32((i32*)(&(mono_2.a)),1000);
print_string("mono.a = ");
println_i32((i32)(mono_2.a));
set_pointer_i32((i32*)(&mono_2.a),2000);
set_pointer_i32(&mono_2.a,3000);
print_string("mono.a = ");
println_i32(mono_2.a);
println_string("");
print_string("beta.g.a = ");
set_pointer_i32((i32*)(&((beta_2.g).a)),9000);
println_i32((i32)((beta_2.g).a));
print_string("beta.g.a = ");
set_pointer_i32(&beta_2.g.a,8000);
println_i32(beta_2.g.a);
print_string("delta.j.g.a = ");
set_pointer_i32(&delta_2.j.g.a,5000);
println_i32(delta_2.j.g.a);
println_string("");
}
}
void files_0_void()
{
{
string read_name_2="output.h";
string write_name_2="temp.txt";
string mode_read_2="r";
string mode_write_2="w";
file test_file_2=open(read_name_2,mode_read_2);
string line_2=(c8*)1;
println_string("files!!!");
while(line_2!=0)
{
set_pointer_string(&line_2,read_line(test_file_2));
print_string("line: ");
print_string(line_2);
delete_ptr(line_2);
};
close(test_file_2);
println_string("\nRead sussess!");
set_pointer_file(&test_file_2,open(write_name_2,mode_write_2));
write_line(test_file_2,"TEST");
close(test_file_2);
println_string("Write sussess!");
println_string("");
}
}
i32 pidigits_0_void()
{
{
i32 max_2=5600;
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
for(;;)
{
set_pointer_i32(&d_2,(d_2+(*elt_array_i32(r_2,i_3)*10000)));
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
printf("%.4d",(i32)(c_2+(d_2/10000)));
if(mod(k_3,10)==0)
{
printf(" %d\n",((max_2-k_3)/7));
}
set_pointer_i32(&c_2,mod(d_2,10000));
set_pointer_i32(&k_3,(k_3-13));
}
println_string("");
return(0);
}
}
void bigints_0_void()
{
{
ixx value1_2;
mpz_init(value1_2);
create_str_ixx(value1_2,"5000");
append_ptr(value1_2, sizeof(value1_2)/sizeof(ixx), IXX);
ixx value2_2;
mpz_init(value2_2);
create_str_ixx(value2_2,"2");
append_ptr(value2_2, sizeof(value2_2)/sizeof(ixx), IXX);
ixx value3_2;
mpz_init(value3_2);
create_str_ixx(value3_2,"3");
append_ptr(value3_2, sizeof(value3_2)/sizeof(ixx), IXX);
println_string("Bigints!!!");
mpz_t G545;
mpz_init_set_str(G545,"0",10);
create_str_ixx(G545,"10000");
prnl_ixx(G545);
prnl_ixx(value1_2);
prnl_ixx(value2_2);
mpz_t G546;
mpz_init_set(G546,value1_2);
mpz_t G547;
mpz_init_set_str(G547,"500",10);
mpz_add(G546,G546,G547);
mpz_t G548;
mpz_init_set_str(G548,"0",10);
mpz_add(G546,G546,value2_2);
mpz_t G549;
mpz_init_set_str(G549,"0",10);
mpz_add(G546,G546,value3_2);
mpz_t G550;
mpz_init_set_str(G550,"1000",10);
mpz_add(G546,G546,G550);
prnl_ixx((pixx)(G546));
mpz_t G551;
mpz_init_set(G551,value1_2);
mpz_t G553;
mpz_init_set(G553,value1_2);
mpz_t G554;
mpz_init_set_str(G554,"0",10);
mpz_mul(G553,G553,value2_2);
mpz_sub(G551,G551,G553);
mpz_t G555;
mpz_init_set_str(G555,"0",10);
mpz_sub(G551,G551,value2_2);
prnl_ixx((pixx)(G551));
mpz_t G556;
mpz_init_set(G556,value1_2);
mpz_t G557;
mpz_init_set_str(G557,"0",10);
mpz_mul(G556,G556,value2_2);
prnl_ixx((pixx)(G556));
mpz_t G558;
mpz_init_set(G558,value1_2);
mpz_t G559;
mpz_init_set_str(G559,"0",10);
mpz_div(G558,G558,value2_2);
prnl_ixx((pixx)(G558));
mpz_t G561;
mpz_init_set_str(G561,"100000",10);
mpz_t G562;
mpz_init_set_str(G562,"100",10);
mpz_div(G561,G561,G562);
mpz_t G564;
mpz_init_set_str(G564,"1000",10);
mpz_t G565;
mpz_init_set_str(G565,"500",10);
mpz_sub(G564,G564,G565);
mpz_mul(G561,G561,G564);
prnl_ixx((pixx)(G561));
mpz_t G567;
mpz_init_set_str(G567,"100000",10);
mpz_t G568;
mpz_init_set_str(G568,"100",10);
mpz_div(G567,G567,G568);
mpz_t G570;
mpz_init_set_str(G570,"1000",10);
mpz_t G571;
mpz_init_set_str(G571,"500",10);
mpz_sub(G570,G570,G571);
mpz_mul(G567,G567,G570);
prnl_ixx((pixx)(pixx)(pixx)(G567));
}
}
i32 main()
{
{
i32 ret_2=arrays_and_lists_0_i32(77);
layer__fun1_1_void();
layer__fun2_1_void();
println_string("");
pointers_0_void();
math_0_void();
compositions_0_void();
files_0_void();
pidigits_0_void();
modules_0_void();
bigints_0_void();
return(ret_2);
}
destroy_ptr(pointer_list);
}





