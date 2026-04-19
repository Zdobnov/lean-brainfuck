// Lean compiler output
// Module: Brainfuck.Step
// Imports: Init Brainfuck.Constants Brainfuck.Errors Brainfuck.Program Brainfuck.State Brainfuck.Tape
#include <lean/lean.h>
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wunused-label"
#elif defined(__GNUC__) && !defined(__CLANG__)
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif
#ifdef __cplusplus
extern "C" {
#endif
static lean_object* l_Brainfuck_step___closed__1;
lean_object* lean_array_fget(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Brainfuck_step___boxed(lean_object*, lean_object*);
static lean_object* l_Brainfuck_step___closed__2;
lean_object* l_List_appendTR___rarg(lean_object*, lean_object*);
uint8_t l_instDecidableNot___rarg(uint8_t);
lean_object* lean_nat_to_int(lean_object*);
LEAN_EXPORT lean_object* l___private_Brainfuck_Step_0__Brainfuck_jumpAfterPartner(lean_object*, lean_object*);
extern lean_object* l_Brainfuck_TAPE__LEN;
static lean_object* l_Brainfuck_step___closed__3;
LEAN_EXPORT lean_object* l___private_Brainfuck_Step_0__Brainfuck_jumpAfterPartner___boxed(lean_object*, lean_object*);
uint8_t lean_nat_dec_eq(lean_object*, lean_object*);
uint8_t lean_nat_dec_lt(lean_object*, lean_object*);
lean_object* l_Int_toNat(lean_object*);
uint8_t lean_int_dec_lt(lean_object*, lean_object*);
lean_object* lean_nat_sub(lean_object*, lean_object*);
lean_object* lean_array_get_size(lean_object*);
lean_object* lean_int_neg(lean_object*);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
lean_object* lean_nat_add(lean_object*, lean_object*);
static lean_object* l___private_Brainfuck_Step_0__Brainfuck_jumpAfterPartner___closed__1;
lean_object* l_Brainfuck_writeCell(lean_object*, lean_object*, lean_object*);
static lean_object* l_Brainfuck_step___closed__4;
LEAN_EXPORT lean_object* l_Brainfuck_step(lean_object*, lean_object*);
lean_object* l_Array_get_x3f___rarg(lean_object*, lean_object*);
static lean_object* _init_l___private_Brainfuck_Step_0__Brainfuck_jumpAfterPartner___closed__1() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = lean_unsigned_to_nat(0u);
x_2 = lean_nat_to_int(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* l___private_Brainfuck_Step_0__Brainfuck_jumpAfterPartner(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = l_Array_get_x3f___rarg(x_1, x_2);
if (lean_obj_tag(x_3) == 0)
{
lean_object* x_4; lean_object* x_5; 
x_4 = lean_unsigned_to_nat(1u);
x_5 = lean_nat_add(x_2, x_4);
return x_5;
}
else
{
lean_object* x_6; lean_object* x_7; uint8_t x_8; 
x_6 = lean_ctor_get(x_3, 0);
lean_inc(x_6);
lean_dec(x_3);
x_7 = l___private_Brainfuck_Step_0__Brainfuck_jumpAfterPartner___closed__1;
x_8 = lean_int_dec_lt(x_6, x_7);
if (x_8 == 0)
{
lean_object* x_9; lean_object* x_10; lean_object* x_11; 
x_9 = l_Int_toNat(x_6);
lean_dec(x_6);
x_10 = lean_unsigned_to_nat(1u);
x_11 = lean_nat_add(x_9, x_10);
lean_dec(x_9);
return x_11;
}
else
{
lean_object* x_12; lean_object* x_13; 
lean_dec(x_6);
x_12 = lean_unsigned_to_nat(1u);
x_13 = lean_nat_add(x_2, x_12);
return x_13;
}
}
}
}
LEAN_EXPORT lean_object* l___private_Brainfuck_Step_0__Brainfuck_jumpAfterPartner___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = l___private_Brainfuck_Step_0__Brainfuck_jumpAfterPartner(x_1, x_2);
lean_dec(x_2);
lean_dec(x_1);
return x_3;
}
}
static lean_object* _init_l_Brainfuck_step___closed__1() {
_start:
{
lean_object* x_1; lean_object* x_2; lean_object* x_3; 
x_1 = l_Brainfuck_TAPE__LEN;
x_2 = lean_unsigned_to_nat(1u);
x_3 = lean_nat_sub(x_1, x_2);
return x_3;
}
}
static lean_object* _init_l_Brainfuck_step___closed__2() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = lean_unsigned_to_nat(1u);
x_2 = lean_nat_to_int(x_1);
return x_2;
}
}
static lean_object* _init_l_Brainfuck_step___closed__3() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = l_Brainfuck_step___closed__2;
x_2 = lean_int_neg(x_1);
return x_2;
}
}
static lean_object* _init_l_Brainfuck_step___closed__4() {
_start:
{
lean_object* x_1; lean_object* x_2; 
x_1 = l_Brainfuck_step___closed__3;
x_2 = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(x_2, 0, x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* l_Brainfuck_step(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; lean_object* x_4; lean_object* x_5; lean_object* x_6; lean_object* x_7; lean_object* x_8; lean_object* x_9; uint8_t x_10; 
x_3 = lean_ctor_get(x_1, 0);
x_4 = lean_array_get_size(x_3);
x_5 = lean_ctor_get(x_2, 0);
lean_inc(x_5);
x_6 = lean_ctor_get(x_2, 1);
lean_inc(x_6);
x_7 = lean_ctor_get(x_2, 2);
lean_inc(x_7);
x_8 = lean_ctor_get(x_2, 3);
lean_inc(x_8);
x_9 = lean_ctor_get(x_2, 4);
lean_inc(x_9);
x_10 = lean_nat_dec_le(x_4, x_7);
lean_dec(x_4);
if (x_10 == 0)
{
lean_object* x_11; 
x_11 = l_Array_get_x3f___rarg(x_3, x_7);
if (lean_obj_tag(x_11) == 0)
{
lean_object* x_12; 
lean_dec(x_9);
lean_dec(x_8);
lean_dec(x_7);
lean_dec(x_6);
lean_dec(x_5);
x_12 = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(x_12, 0, x_2);
return x_12;
}
else
{
uint8_t x_13; 
x_13 = !lean_is_exclusive(x_11);
if (x_13 == 0)
{
lean_object* x_14; uint8_t x_15; 
x_14 = lean_ctor_get(x_11, 0);
x_15 = lean_unbox(x_14);
lean_dec(x_14);
switch (x_15) {
case 0:
{
lean_object* x_16; uint8_t x_17; 
x_16 = l_Brainfuck_step___closed__1;
x_17 = lean_nat_dec_eq(x_6, x_16);
if (x_17 == 0)
{
uint8_t x_18; 
x_18 = !lean_is_exclusive(x_2);
if (x_18 == 0)
{
lean_object* x_19; lean_object* x_20; lean_object* x_21; lean_object* x_22; lean_object* x_23; lean_object* x_24; lean_object* x_25; lean_object* x_26; 
x_19 = lean_ctor_get(x_2, 4);
lean_dec(x_19);
x_20 = lean_ctor_get(x_2, 3);
lean_dec(x_20);
x_21 = lean_ctor_get(x_2, 2);
lean_dec(x_21);
x_22 = lean_ctor_get(x_2, 1);
lean_dec(x_22);
x_23 = lean_ctor_get(x_2, 0);
lean_dec(x_23);
x_24 = lean_unsigned_to_nat(1u);
x_25 = lean_nat_add(x_6, x_24);
lean_dec(x_6);
x_26 = lean_nat_add(x_7, x_24);
lean_dec(x_7);
lean_ctor_set(x_2, 2, x_26);
lean_ctor_set(x_2, 1, x_25);
lean_ctor_set_tag(x_11, 0);
lean_ctor_set(x_11, 0, x_2);
return x_11;
}
else
{
lean_object* x_27; lean_object* x_28; lean_object* x_29; lean_object* x_30; 
lean_dec(x_2);
x_27 = lean_unsigned_to_nat(1u);
x_28 = lean_nat_add(x_6, x_27);
lean_dec(x_6);
x_29 = lean_nat_add(x_7, x_27);
lean_dec(x_7);
x_30 = lean_alloc_ctor(0, 5, 0);
lean_ctor_set(x_30, 0, x_5);
lean_ctor_set(x_30, 1, x_28);
lean_ctor_set(x_30, 2, x_29);
lean_ctor_set(x_30, 3, x_8);
lean_ctor_set(x_30, 4, x_9);
lean_ctor_set_tag(x_11, 0);
lean_ctor_set(x_11, 0, x_30);
return x_11;
}
}
else
{
lean_object* x_31; lean_object* x_32; lean_object* x_33; lean_object* x_34; 
lean_dec(x_9);
lean_dec(x_8);
lean_dec(x_7);
lean_dec(x_5);
x_31 = lean_unsigned_to_nat(1u);
x_32 = lean_nat_add(x_6, x_31);
lean_dec(x_6);
x_33 = lean_nat_to_int(x_32);
lean_ctor_set_tag(x_11, 0);
lean_ctor_set(x_11, 0, x_33);
x_34 = lean_alloc_ctor(2, 2, 0);
lean_ctor_set(x_34, 0, x_2);
lean_ctor_set(x_34, 1, x_11);
return x_34;
}
}
case 1:
{
lean_object* x_35; uint8_t x_36; 
x_35 = lean_unsigned_to_nat(0u);
x_36 = lean_nat_dec_eq(x_6, x_35);
if (x_36 == 0)
{
uint8_t x_37; 
x_37 = !lean_is_exclusive(x_2);
if (x_37 == 0)
{
lean_object* x_38; lean_object* x_39; lean_object* x_40; lean_object* x_41; lean_object* x_42; lean_object* x_43; lean_object* x_44; lean_object* x_45; 
x_38 = lean_ctor_get(x_2, 4);
lean_dec(x_38);
x_39 = lean_ctor_get(x_2, 3);
lean_dec(x_39);
x_40 = lean_ctor_get(x_2, 2);
lean_dec(x_40);
x_41 = lean_ctor_get(x_2, 1);
lean_dec(x_41);
x_42 = lean_ctor_get(x_2, 0);
lean_dec(x_42);
x_43 = lean_unsigned_to_nat(1u);
x_44 = lean_nat_sub(x_6, x_43);
lean_dec(x_6);
x_45 = lean_nat_add(x_7, x_43);
lean_dec(x_7);
lean_ctor_set(x_2, 2, x_45);
lean_ctor_set(x_2, 1, x_44);
lean_ctor_set_tag(x_11, 0);
lean_ctor_set(x_11, 0, x_2);
return x_11;
}
else
{
lean_object* x_46; lean_object* x_47; lean_object* x_48; lean_object* x_49; 
lean_dec(x_2);
x_46 = lean_unsigned_to_nat(1u);
x_47 = lean_nat_sub(x_6, x_46);
lean_dec(x_6);
x_48 = lean_nat_add(x_7, x_46);
lean_dec(x_7);
x_49 = lean_alloc_ctor(0, 5, 0);
lean_ctor_set(x_49, 0, x_5);
lean_ctor_set(x_49, 1, x_47);
lean_ctor_set(x_49, 2, x_48);
lean_ctor_set(x_49, 3, x_8);
lean_ctor_set(x_49, 4, x_9);
lean_ctor_set_tag(x_11, 0);
lean_ctor_set(x_11, 0, x_49);
return x_11;
}
}
else
{
lean_object* x_50; lean_object* x_51; 
lean_free_object(x_11);
lean_dec(x_9);
lean_dec(x_8);
lean_dec(x_7);
lean_dec(x_6);
lean_dec(x_5);
x_50 = l_Brainfuck_step___closed__4;
x_51 = lean_alloc_ctor(2, 2, 0);
lean_ctor_set(x_51, 0, x_2);
lean_ctor_set(x_51, 1, x_50);
return x_51;
}
}
case 2:
{
lean_object* x_52; uint8_t x_53; 
x_52 = l_Brainfuck_TAPE__LEN;
x_53 = lean_nat_dec_lt(x_6, x_52);
if (x_53 == 0)
{
lean_object* x_54; lean_object* x_55; 
lean_dec(x_9);
lean_dec(x_8);
lean_dec(x_7);
lean_dec(x_5);
x_54 = lean_nat_to_int(x_6);
lean_ctor_set_tag(x_11, 0);
lean_ctor_set(x_11, 0, x_54);
x_55 = lean_alloc_ctor(2, 2, 0);
lean_ctor_set(x_55, 0, x_2);
lean_ctor_set(x_55, 1, x_11);
return x_55;
}
else
{
uint8_t x_56; 
x_56 = !lean_is_exclusive(x_2);
if (x_56 == 0)
{
lean_object* x_57; lean_object* x_58; lean_object* x_59; lean_object* x_60; lean_object* x_61; lean_object* x_62; lean_object* x_63; lean_object* x_64; lean_object* x_65; lean_object* x_66; 
x_57 = lean_ctor_get(x_2, 4);
lean_dec(x_57);
x_58 = lean_ctor_get(x_2, 3);
lean_dec(x_58);
x_59 = lean_ctor_get(x_2, 2);
lean_dec(x_59);
x_60 = lean_ctor_get(x_2, 1);
lean_dec(x_60);
x_61 = lean_ctor_get(x_2, 0);
lean_dec(x_61);
x_62 = lean_array_fget(x_5, x_6);
x_63 = lean_unsigned_to_nat(1u);
x_64 = lean_nat_add(x_62, x_63);
lean_dec(x_62);
x_65 = l_Brainfuck_writeCell(x_5, x_6, x_64);
lean_dec(x_64);
x_66 = lean_nat_add(x_7, x_63);
lean_dec(x_7);
lean_ctor_set(x_2, 2, x_66);
lean_ctor_set(x_2, 0, x_65);
lean_ctor_set_tag(x_11, 0);
lean_ctor_set(x_11, 0, x_2);
return x_11;
}
else
{
lean_object* x_67; lean_object* x_68; lean_object* x_69; lean_object* x_70; lean_object* x_71; lean_object* x_72; 
lean_dec(x_2);
x_67 = lean_array_fget(x_5, x_6);
x_68 = lean_unsigned_to_nat(1u);
x_69 = lean_nat_add(x_67, x_68);
lean_dec(x_67);
x_70 = l_Brainfuck_writeCell(x_5, x_6, x_69);
lean_dec(x_69);
x_71 = lean_nat_add(x_7, x_68);
lean_dec(x_7);
x_72 = lean_alloc_ctor(0, 5, 0);
lean_ctor_set(x_72, 0, x_70);
lean_ctor_set(x_72, 1, x_6);
lean_ctor_set(x_72, 2, x_71);
lean_ctor_set(x_72, 3, x_8);
lean_ctor_set(x_72, 4, x_9);
lean_ctor_set_tag(x_11, 0);
lean_ctor_set(x_11, 0, x_72);
return x_11;
}
}
}
case 3:
{
lean_object* x_73; uint8_t x_74; 
x_73 = l_Brainfuck_TAPE__LEN;
x_74 = lean_nat_dec_lt(x_6, x_73);
if (x_74 == 0)
{
lean_object* x_75; lean_object* x_76; 
lean_dec(x_9);
lean_dec(x_8);
lean_dec(x_7);
lean_dec(x_5);
x_75 = lean_nat_to_int(x_6);
lean_ctor_set_tag(x_11, 0);
lean_ctor_set(x_11, 0, x_75);
x_76 = lean_alloc_ctor(2, 2, 0);
lean_ctor_set(x_76, 0, x_2);
lean_ctor_set(x_76, 1, x_11);
return x_76;
}
else
{
uint8_t x_77; 
x_77 = !lean_is_exclusive(x_2);
if (x_77 == 0)
{
lean_object* x_78; lean_object* x_79; lean_object* x_80; lean_object* x_81; lean_object* x_82; lean_object* x_83; lean_object* x_84; lean_object* x_85; lean_object* x_86; lean_object* x_87; lean_object* x_88; 
x_78 = lean_ctor_get(x_2, 4);
lean_dec(x_78);
x_79 = lean_ctor_get(x_2, 3);
lean_dec(x_79);
x_80 = lean_ctor_get(x_2, 2);
lean_dec(x_80);
x_81 = lean_ctor_get(x_2, 1);
lean_dec(x_81);
x_82 = lean_ctor_get(x_2, 0);
lean_dec(x_82);
x_83 = lean_array_fget(x_5, x_6);
x_84 = lean_unsigned_to_nat(255u);
x_85 = lean_nat_add(x_83, x_84);
lean_dec(x_83);
x_86 = l_Brainfuck_writeCell(x_5, x_6, x_85);
lean_dec(x_85);
x_87 = lean_unsigned_to_nat(1u);
x_88 = lean_nat_add(x_7, x_87);
lean_dec(x_7);
lean_ctor_set(x_2, 2, x_88);
lean_ctor_set(x_2, 0, x_86);
lean_ctor_set_tag(x_11, 0);
lean_ctor_set(x_11, 0, x_2);
return x_11;
}
else
{
lean_object* x_89; lean_object* x_90; lean_object* x_91; lean_object* x_92; lean_object* x_93; lean_object* x_94; lean_object* x_95; 
lean_dec(x_2);
x_89 = lean_array_fget(x_5, x_6);
x_90 = lean_unsigned_to_nat(255u);
x_91 = lean_nat_add(x_89, x_90);
lean_dec(x_89);
x_92 = l_Brainfuck_writeCell(x_5, x_6, x_91);
lean_dec(x_91);
x_93 = lean_unsigned_to_nat(1u);
x_94 = lean_nat_add(x_7, x_93);
lean_dec(x_7);
x_95 = lean_alloc_ctor(0, 5, 0);
lean_ctor_set(x_95, 0, x_92);
lean_ctor_set(x_95, 1, x_6);
lean_ctor_set(x_95, 2, x_94);
lean_ctor_set(x_95, 3, x_8);
lean_ctor_set(x_95, 4, x_9);
lean_ctor_set_tag(x_11, 0);
lean_ctor_set(x_11, 0, x_95);
return x_11;
}
}
}
case 4:
{
lean_object* x_96; uint8_t x_97; 
x_96 = l_Brainfuck_TAPE__LEN;
x_97 = lean_nat_dec_lt(x_6, x_96);
if (x_97 == 0)
{
lean_object* x_98; lean_object* x_99; 
lean_dec(x_9);
lean_dec(x_8);
lean_dec(x_7);
lean_dec(x_5);
x_98 = lean_nat_to_int(x_6);
lean_ctor_set_tag(x_11, 0);
lean_ctor_set(x_11, 0, x_98);
x_99 = lean_alloc_ctor(2, 2, 0);
lean_ctor_set(x_99, 0, x_2);
lean_ctor_set(x_99, 1, x_11);
return x_99;
}
else
{
uint8_t x_100; 
x_100 = !lean_is_exclusive(x_2);
if (x_100 == 0)
{
lean_object* x_101; lean_object* x_102; lean_object* x_103; lean_object* x_104; lean_object* x_105; lean_object* x_106; lean_object* x_107; lean_object* x_108; lean_object* x_109; lean_object* x_110; lean_object* x_111; 
x_101 = lean_ctor_get(x_2, 4);
lean_dec(x_101);
x_102 = lean_ctor_get(x_2, 3);
lean_dec(x_102);
x_103 = lean_ctor_get(x_2, 2);
lean_dec(x_103);
x_104 = lean_ctor_get(x_2, 1);
lean_dec(x_104);
x_105 = lean_ctor_get(x_2, 0);
lean_dec(x_105);
x_106 = lean_array_fget(x_5, x_6);
x_107 = lean_unsigned_to_nat(1u);
x_108 = lean_nat_add(x_7, x_107);
lean_dec(x_7);
x_109 = lean_box(0);
x_110 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_110, 0, x_106);
lean_ctor_set(x_110, 1, x_109);
x_111 = l_List_appendTR___rarg(x_9, x_110);
lean_ctor_set(x_2, 4, x_111);
lean_ctor_set(x_2, 2, x_108);
lean_ctor_set_tag(x_11, 0);
lean_ctor_set(x_11, 0, x_2);
return x_11;
}
else
{
lean_object* x_112; lean_object* x_113; lean_object* x_114; lean_object* x_115; lean_object* x_116; lean_object* x_117; lean_object* x_118; 
lean_dec(x_2);
x_112 = lean_array_fget(x_5, x_6);
x_113 = lean_unsigned_to_nat(1u);
x_114 = lean_nat_add(x_7, x_113);
lean_dec(x_7);
x_115 = lean_box(0);
x_116 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_116, 0, x_112);
lean_ctor_set(x_116, 1, x_115);
x_117 = l_List_appendTR___rarg(x_9, x_116);
x_118 = lean_alloc_ctor(0, 5, 0);
lean_ctor_set(x_118, 0, x_5);
lean_ctor_set(x_118, 1, x_6);
lean_ctor_set(x_118, 2, x_114);
lean_ctor_set(x_118, 3, x_8);
lean_ctor_set(x_118, 4, x_117);
lean_ctor_set_tag(x_11, 0);
lean_ctor_set(x_11, 0, x_118);
return x_11;
}
}
}
case 5:
{
if (lean_obj_tag(x_8) == 0)
{
lean_object* x_119; lean_object* x_120; 
lean_free_object(x_11);
lean_dec(x_9);
lean_dec(x_7);
lean_dec(x_6);
lean_dec(x_5);
x_119 = lean_box(1);
x_120 = lean_alloc_ctor(2, 2, 0);
lean_ctor_set(x_120, 0, x_2);
lean_ctor_set(x_120, 1, x_119);
return x_120;
}
else
{
uint8_t x_121; 
x_121 = !lean_is_exclusive(x_8);
if (x_121 == 0)
{
lean_object* x_122; lean_object* x_123; lean_object* x_124; uint8_t x_125; 
x_122 = lean_ctor_get(x_8, 0);
x_123 = lean_ctor_get(x_8, 1);
x_124 = l_Brainfuck_TAPE__LEN;
x_125 = lean_nat_dec_lt(x_6, x_124);
if (x_125 == 0)
{
lean_object* x_126; 
lean_dec(x_123);
lean_dec(x_122);
lean_dec(x_9);
lean_dec(x_7);
lean_dec(x_5);
x_126 = lean_nat_to_int(x_6);
lean_ctor_set_tag(x_11, 0);
lean_ctor_set(x_11, 0, x_126);
lean_ctor_set_tag(x_8, 2);
lean_ctor_set(x_8, 1, x_11);
lean_ctor_set(x_8, 0, x_2);
return x_8;
}
else
{
uint8_t x_127; 
lean_free_object(x_8);
x_127 = !lean_is_exclusive(x_2);
if (x_127 == 0)
{
lean_object* x_128; lean_object* x_129; lean_object* x_130; lean_object* x_131; lean_object* x_132; lean_object* x_133; lean_object* x_134; lean_object* x_135; 
x_128 = lean_ctor_get(x_2, 4);
lean_dec(x_128);
x_129 = lean_ctor_get(x_2, 3);
lean_dec(x_129);
x_130 = lean_ctor_get(x_2, 2);
lean_dec(x_130);
x_131 = lean_ctor_get(x_2, 1);
lean_dec(x_131);
x_132 = lean_ctor_get(x_2, 0);
lean_dec(x_132);
x_133 = l_Brainfuck_writeCell(x_5, x_6, x_122);
lean_dec(x_122);
x_134 = lean_unsigned_to_nat(1u);
x_135 = lean_nat_add(x_7, x_134);
lean_dec(x_7);
lean_ctor_set(x_2, 3, x_123);
lean_ctor_set(x_2, 2, x_135);
lean_ctor_set(x_2, 0, x_133);
lean_ctor_set_tag(x_11, 0);
lean_ctor_set(x_11, 0, x_2);
return x_11;
}
else
{
lean_object* x_136; lean_object* x_137; lean_object* x_138; lean_object* x_139; 
lean_dec(x_2);
x_136 = l_Brainfuck_writeCell(x_5, x_6, x_122);
lean_dec(x_122);
x_137 = lean_unsigned_to_nat(1u);
x_138 = lean_nat_add(x_7, x_137);
lean_dec(x_7);
x_139 = lean_alloc_ctor(0, 5, 0);
lean_ctor_set(x_139, 0, x_136);
lean_ctor_set(x_139, 1, x_6);
lean_ctor_set(x_139, 2, x_138);
lean_ctor_set(x_139, 3, x_123);
lean_ctor_set(x_139, 4, x_9);
lean_ctor_set_tag(x_11, 0);
lean_ctor_set(x_11, 0, x_139);
return x_11;
}
}
}
else
{
lean_object* x_140; lean_object* x_141; lean_object* x_142; uint8_t x_143; 
x_140 = lean_ctor_get(x_8, 0);
x_141 = lean_ctor_get(x_8, 1);
lean_inc(x_141);
lean_inc(x_140);
lean_dec(x_8);
x_142 = l_Brainfuck_TAPE__LEN;
x_143 = lean_nat_dec_lt(x_6, x_142);
if (x_143 == 0)
{
lean_object* x_144; lean_object* x_145; 
lean_dec(x_141);
lean_dec(x_140);
lean_dec(x_9);
lean_dec(x_7);
lean_dec(x_5);
x_144 = lean_nat_to_int(x_6);
lean_ctor_set_tag(x_11, 0);
lean_ctor_set(x_11, 0, x_144);
x_145 = lean_alloc_ctor(2, 2, 0);
lean_ctor_set(x_145, 0, x_2);
lean_ctor_set(x_145, 1, x_11);
return x_145;
}
else
{
lean_object* x_146; lean_object* x_147; lean_object* x_148; lean_object* x_149; lean_object* x_150; 
if (lean_is_exclusive(x_2)) {
 lean_ctor_release(x_2, 0);
 lean_ctor_release(x_2, 1);
 lean_ctor_release(x_2, 2);
 lean_ctor_release(x_2, 3);
 lean_ctor_release(x_2, 4);
 x_146 = x_2;
} else {
 lean_dec_ref(x_2);
 x_146 = lean_box(0);
}
x_147 = l_Brainfuck_writeCell(x_5, x_6, x_140);
lean_dec(x_140);
x_148 = lean_unsigned_to_nat(1u);
x_149 = lean_nat_add(x_7, x_148);
lean_dec(x_7);
if (lean_is_scalar(x_146)) {
 x_150 = lean_alloc_ctor(0, 5, 0);
} else {
 x_150 = x_146;
}
lean_ctor_set(x_150, 0, x_147);
lean_ctor_set(x_150, 1, x_6);
lean_ctor_set(x_150, 2, x_149);
lean_ctor_set(x_150, 3, x_141);
lean_ctor_set(x_150, 4, x_9);
lean_ctor_set_tag(x_11, 0);
lean_ctor_set(x_11, 0, x_150);
return x_11;
}
}
}
}
case 6:
{
lean_object* x_151; uint8_t x_152; 
x_151 = l_Brainfuck_TAPE__LEN;
x_152 = lean_nat_dec_lt(x_6, x_151);
if (x_152 == 0)
{
lean_object* x_153; lean_object* x_154; 
lean_dec(x_9);
lean_dec(x_8);
lean_dec(x_7);
lean_dec(x_5);
x_153 = lean_nat_to_int(x_6);
lean_ctor_set_tag(x_11, 0);
lean_ctor_set(x_11, 0, x_153);
x_154 = lean_alloc_ctor(2, 2, 0);
lean_ctor_set(x_154, 0, x_2);
lean_ctor_set(x_154, 1, x_11);
return x_154;
}
else
{
uint8_t x_155; 
x_155 = !lean_is_exclusive(x_2);
if (x_155 == 0)
{
lean_object* x_156; lean_object* x_157; lean_object* x_158; lean_object* x_159; lean_object* x_160; lean_object* x_161; lean_object* x_162; uint8_t x_163; 
x_156 = lean_ctor_get(x_2, 4);
lean_dec(x_156);
x_157 = lean_ctor_get(x_2, 3);
lean_dec(x_157);
x_158 = lean_ctor_get(x_2, 2);
lean_dec(x_158);
x_159 = lean_ctor_get(x_2, 1);
lean_dec(x_159);
x_160 = lean_ctor_get(x_2, 0);
lean_dec(x_160);
x_161 = lean_array_fget(x_5, x_6);
x_162 = lean_unsigned_to_nat(0u);
x_163 = lean_nat_dec_eq(x_161, x_162);
lean_dec(x_161);
if (x_163 == 0)
{
lean_object* x_164; lean_object* x_165; 
x_164 = lean_unsigned_to_nat(1u);
x_165 = lean_nat_add(x_7, x_164);
lean_dec(x_7);
lean_ctor_set(x_2, 2, x_165);
lean_ctor_set_tag(x_11, 0);
lean_ctor_set(x_11, 0, x_2);
return x_11;
}
else
{
lean_object* x_166; lean_object* x_167; 
x_166 = lean_ctor_get(x_1, 1);
x_167 = l___private_Brainfuck_Step_0__Brainfuck_jumpAfterPartner(x_166, x_7);
lean_dec(x_7);
lean_ctor_set(x_2, 2, x_167);
lean_ctor_set_tag(x_11, 0);
lean_ctor_set(x_11, 0, x_2);
return x_11;
}
}
else
{
lean_object* x_168; lean_object* x_169; uint8_t x_170; 
lean_dec(x_2);
x_168 = lean_array_fget(x_5, x_6);
x_169 = lean_unsigned_to_nat(0u);
x_170 = lean_nat_dec_eq(x_168, x_169);
lean_dec(x_168);
if (x_170 == 0)
{
lean_object* x_171; lean_object* x_172; lean_object* x_173; 
x_171 = lean_unsigned_to_nat(1u);
x_172 = lean_nat_add(x_7, x_171);
lean_dec(x_7);
x_173 = lean_alloc_ctor(0, 5, 0);
lean_ctor_set(x_173, 0, x_5);
lean_ctor_set(x_173, 1, x_6);
lean_ctor_set(x_173, 2, x_172);
lean_ctor_set(x_173, 3, x_8);
lean_ctor_set(x_173, 4, x_9);
lean_ctor_set_tag(x_11, 0);
lean_ctor_set(x_11, 0, x_173);
return x_11;
}
else
{
lean_object* x_174; lean_object* x_175; lean_object* x_176; 
x_174 = lean_ctor_get(x_1, 1);
x_175 = l___private_Brainfuck_Step_0__Brainfuck_jumpAfterPartner(x_174, x_7);
lean_dec(x_7);
x_176 = lean_alloc_ctor(0, 5, 0);
lean_ctor_set(x_176, 0, x_5);
lean_ctor_set(x_176, 1, x_6);
lean_ctor_set(x_176, 2, x_175);
lean_ctor_set(x_176, 3, x_8);
lean_ctor_set(x_176, 4, x_9);
lean_ctor_set_tag(x_11, 0);
lean_ctor_set(x_11, 0, x_176);
return x_11;
}
}
}
}
default: 
{
lean_object* x_177; uint8_t x_178; 
x_177 = l_Brainfuck_TAPE__LEN;
x_178 = lean_nat_dec_lt(x_6, x_177);
if (x_178 == 0)
{
lean_object* x_179; lean_object* x_180; 
lean_dec(x_9);
lean_dec(x_8);
lean_dec(x_7);
lean_dec(x_5);
x_179 = lean_nat_to_int(x_6);
lean_ctor_set_tag(x_11, 0);
lean_ctor_set(x_11, 0, x_179);
x_180 = lean_alloc_ctor(2, 2, 0);
lean_ctor_set(x_180, 0, x_2);
lean_ctor_set(x_180, 1, x_11);
return x_180;
}
else
{
uint8_t x_181; 
x_181 = !lean_is_exclusive(x_2);
if (x_181 == 0)
{
lean_object* x_182; lean_object* x_183; lean_object* x_184; lean_object* x_185; lean_object* x_186; lean_object* x_187; lean_object* x_188; uint8_t x_189; uint8_t x_190; 
x_182 = lean_ctor_get(x_2, 4);
lean_dec(x_182);
x_183 = lean_ctor_get(x_2, 3);
lean_dec(x_183);
x_184 = lean_ctor_get(x_2, 2);
lean_dec(x_184);
x_185 = lean_ctor_get(x_2, 1);
lean_dec(x_185);
x_186 = lean_ctor_get(x_2, 0);
lean_dec(x_186);
x_187 = lean_array_fget(x_5, x_6);
x_188 = lean_unsigned_to_nat(0u);
x_189 = lean_nat_dec_eq(x_187, x_188);
lean_dec(x_187);
x_190 = l_instDecidableNot___rarg(x_189);
if (x_190 == 0)
{
lean_object* x_191; lean_object* x_192; 
x_191 = lean_unsigned_to_nat(1u);
x_192 = lean_nat_add(x_7, x_191);
lean_dec(x_7);
lean_ctor_set(x_2, 2, x_192);
lean_ctor_set_tag(x_11, 0);
lean_ctor_set(x_11, 0, x_2);
return x_11;
}
else
{
lean_object* x_193; lean_object* x_194; 
x_193 = lean_ctor_get(x_1, 1);
x_194 = l___private_Brainfuck_Step_0__Brainfuck_jumpAfterPartner(x_193, x_7);
lean_dec(x_7);
lean_ctor_set(x_2, 2, x_194);
lean_ctor_set_tag(x_11, 0);
lean_ctor_set(x_11, 0, x_2);
return x_11;
}
}
else
{
lean_object* x_195; lean_object* x_196; uint8_t x_197; uint8_t x_198; 
lean_dec(x_2);
x_195 = lean_array_fget(x_5, x_6);
x_196 = lean_unsigned_to_nat(0u);
x_197 = lean_nat_dec_eq(x_195, x_196);
lean_dec(x_195);
x_198 = l_instDecidableNot___rarg(x_197);
if (x_198 == 0)
{
lean_object* x_199; lean_object* x_200; lean_object* x_201; 
x_199 = lean_unsigned_to_nat(1u);
x_200 = lean_nat_add(x_7, x_199);
lean_dec(x_7);
x_201 = lean_alloc_ctor(0, 5, 0);
lean_ctor_set(x_201, 0, x_5);
lean_ctor_set(x_201, 1, x_6);
lean_ctor_set(x_201, 2, x_200);
lean_ctor_set(x_201, 3, x_8);
lean_ctor_set(x_201, 4, x_9);
lean_ctor_set_tag(x_11, 0);
lean_ctor_set(x_11, 0, x_201);
return x_11;
}
else
{
lean_object* x_202; lean_object* x_203; lean_object* x_204; 
x_202 = lean_ctor_get(x_1, 1);
x_203 = l___private_Brainfuck_Step_0__Brainfuck_jumpAfterPartner(x_202, x_7);
lean_dec(x_7);
x_204 = lean_alloc_ctor(0, 5, 0);
lean_ctor_set(x_204, 0, x_5);
lean_ctor_set(x_204, 1, x_6);
lean_ctor_set(x_204, 2, x_203);
lean_ctor_set(x_204, 3, x_8);
lean_ctor_set(x_204, 4, x_9);
lean_ctor_set_tag(x_11, 0);
lean_ctor_set(x_11, 0, x_204);
return x_11;
}
}
}
}
}
}
else
{
lean_object* x_205; uint8_t x_206; 
x_205 = lean_ctor_get(x_11, 0);
lean_inc(x_205);
lean_dec(x_11);
x_206 = lean_unbox(x_205);
lean_dec(x_205);
switch (x_206) {
case 0:
{
lean_object* x_207; uint8_t x_208; 
x_207 = l_Brainfuck_step___closed__1;
x_208 = lean_nat_dec_eq(x_6, x_207);
if (x_208 == 0)
{
lean_object* x_209; lean_object* x_210; lean_object* x_211; lean_object* x_212; lean_object* x_213; lean_object* x_214; 
if (lean_is_exclusive(x_2)) {
 lean_ctor_release(x_2, 0);
 lean_ctor_release(x_2, 1);
 lean_ctor_release(x_2, 2);
 lean_ctor_release(x_2, 3);
 lean_ctor_release(x_2, 4);
 x_209 = x_2;
} else {
 lean_dec_ref(x_2);
 x_209 = lean_box(0);
}
x_210 = lean_unsigned_to_nat(1u);
x_211 = lean_nat_add(x_6, x_210);
lean_dec(x_6);
x_212 = lean_nat_add(x_7, x_210);
lean_dec(x_7);
if (lean_is_scalar(x_209)) {
 x_213 = lean_alloc_ctor(0, 5, 0);
} else {
 x_213 = x_209;
}
lean_ctor_set(x_213, 0, x_5);
lean_ctor_set(x_213, 1, x_211);
lean_ctor_set(x_213, 2, x_212);
lean_ctor_set(x_213, 3, x_8);
lean_ctor_set(x_213, 4, x_9);
x_214 = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(x_214, 0, x_213);
return x_214;
}
else
{
lean_object* x_215; lean_object* x_216; lean_object* x_217; lean_object* x_218; lean_object* x_219; 
lean_dec(x_9);
lean_dec(x_8);
lean_dec(x_7);
lean_dec(x_5);
x_215 = lean_unsigned_to_nat(1u);
x_216 = lean_nat_add(x_6, x_215);
lean_dec(x_6);
x_217 = lean_nat_to_int(x_216);
x_218 = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(x_218, 0, x_217);
x_219 = lean_alloc_ctor(2, 2, 0);
lean_ctor_set(x_219, 0, x_2);
lean_ctor_set(x_219, 1, x_218);
return x_219;
}
}
case 1:
{
lean_object* x_220; uint8_t x_221; 
x_220 = lean_unsigned_to_nat(0u);
x_221 = lean_nat_dec_eq(x_6, x_220);
if (x_221 == 0)
{
lean_object* x_222; lean_object* x_223; lean_object* x_224; lean_object* x_225; lean_object* x_226; lean_object* x_227; 
if (lean_is_exclusive(x_2)) {
 lean_ctor_release(x_2, 0);
 lean_ctor_release(x_2, 1);
 lean_ctor_release(x_2, 2);
 lean_ctor_release(x_2, 3);
 lean_ctor_release(x_2, 4);
 x_222 = x_2;
} else {
 lean_dec_ref(x_2);
 x_222 = lean_box(0);
}
x_223 = lean_unsigned_to_nat(1u);
x_224 = lean_nat_sub(x_6, x_223);
lean_dec(x_6);
x_225 = lean_nat_add(x_7, x_223);
lean_dec(x_7);
if (lean_is_scalar(x_222)) {
 x_226 = lean_alloc_ctor(0, 5, 0);
} else {
 x_226 = x_222;
}
lean_ctor_set(x_226, 0, x_5);
lean_ctor_set(x_226, 1, x_224);
lean_ctor_set(x_226, 2, x_225);
lean_ctor_set(x_226, 3, x_8);
lean_ctor_set(x_226, 4, x_9);
x_227 = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(x_227, 0, x_226);
return x_227;
}
else
{
lean_object* x_228; lean_object* x_229; 
lean_dec(x_9);
lean_dec(x_8);
lean_dec(x_7);
lean_dec(x_6);
lean_dec(x_5);
x_228 = l_Brainfuck_step___closed__4;
x_229 = lean_alloc_ctor(2, 2, 0);
lean_ctor_set(x_229, 0, x_2);
lean_ctor_set(x_229, 1, x_228);
return x_229;
}
}
case 2:
{
lean_object* x_230; uint8_t x_231; 
x_230 = l_Brainfuck_TAPE__LEN;
x_231 = lean_nat_dec_lt(x_6, x_230);
if (x_231 == 0)
{
lean_object* x_232; lean_object* x_233; lean_object* x_234; 
lean_dec(x_9);
lean_dec(x_8);
lean_dec(x_7);
lean_dec(x_5);
x_232 = lean_nat_to_int(x_6);
x_233 = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(x_233, 0, x_232);
x_234 = lean_alloc_ctor(2, 2, 0);
lean_ctor_set(x_234, 0, x_2);
lean_ctor_set(x_234, 1, x_233);
return x_234;
}
else
{
lean_object* x_235; lean_object* x_236; lean_object* x_237; lean_object* x_238; lean_object* x_239; lean_object* x_240; lean_object* x_241; lean_object* x_242; 
if (lean_is_exclusive(x_2)) {
 lean_ctor_release(x_2, 0);
 lean_ctor_release(x_2, 1);
 lean_ctor_release(x_2, 2);
 lean_ctor_release(x_2, 3);
 lean_ctor_release(x_2, 4);
 x_235 = x_2;
} else {
 lean_dec_ref(x_2);
 x_235 = lean_box(0);
}
x_236 = lean_array_fget(x_5, x_6);
x_237 = lean_unsigned_to_nat(1u);
x_238 = lean_nat_add(x_236, x_237);
lean_dec(x_236);
x_239 = l_Brainfuck_writeCell(x_5, x_6, x_238);
lean_dec(x_238);
x_240 = lean_nat_add(x_7, x_237);
lean_dec(x_7);
if (lean_is_scalar(x_235)) {
 x_241 = lean_alloc_ctor(0, 5, 0);
} else {
 x_241 = x_235;
}
lean_ctor_set(x_241, 0, x_239);
lean_ctor_set(x_241, 1, x_6);
lean_ctor_set(x_241, 2, x_240);
lean_ctor_set(x_241, 3, x_8);
lean_ctor_set(x_241, 4, x_9);
x_242 = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(x_242, 0, x_241);
return x_242;
}
}
case 3:
{
lean_object* x_243; uint8_t x_244; 
x_243 = l_Brainfuck_TAPE__LEN;
x_244 = lean_nat_dec_lt(x_6, x_243);
if (x_244 == 0)
{
lean_object* x_245; lean_object* x_246; lean_object* x_247; 
lean_dec(x_9);
lean_dec(x_8);
lean_dec(x_7);
lean_dec(x_5);
x_245 = lean_nat_to_int(x_6);
x_246 = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(x_246, 0, x_245);
x_247 = lean_alloc_ctor(2, 2, 0);
lean_ctor_set(x_247, 0, x_2);
lean_ctor_set(x_247, 1, x_246);
return x_247;
}
else
{
lean_object* x_248; lean_object* x_249; lean_object* x_250; lean_object* x_251; lean_object* x_252; lean_object* x_253; lean_object* x_254; lean_object* x_255; lean_object* x_256; 
if (lean_is_exclusive(x_2)) {
 lean_ctor_release(x_2, 0);
 lean_ctor_release(x_2, 1);
 lean_ctor_release(x_2, 2);
 lean_ctor_release(x_2, 3);
 lean_ctor_release(x_2, 4);
 x_248 = x_2;
} else {
 lean_dec_ref(x_2);
 x_248 = lean_box(0);
}
x_249 = lean_array_fget(x_5, x_6);
x_250 = lean_unsigned_to_nat(255u);
x_251 = lean_nat_add(x_249, x_250);
lean_dec(x_249);
x_252 = l_Brainfuck_writeCell(x_5, x_6, x_251);
lean_dec(x_251);
x_253 = lean_unsigned_to_nat(1u);
x_254 = lean_nat_add(x_7, x_253);
lean_dec(x_7);
if (lean_is_scalar(x_248)) {
 x_255 = lean_alloc_ctor(0, 5, 0);
} else {
 x_255 = x_248;
}
lean_ctor_set(x_255, 0, x_252);
lean_ctor_set(x_255, 1, x_6);
lean_ctor_set(x_255, 2, x_254);
lean_ctor_set(x_255, 3, x_8);
lean_ctor_set(x_255, 4, x_9);
x_256 = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(x_256, 0, x_255);
return x_256;
}
}
case 4:
{
lean_object* x_257; uint8_t x_258; 
x_257 = l_Brainfuck_TAPE__LEN;
x_258 = lean_nat_dec_lt(x_6, x_257);
if (x_258 == 0)
{
lean_object* x_259; lean_object* x_260; lean_object* x_261; 
lean_dec(x_9);
lean_dec(x_8);
lean_dec(x_7);
lean_dec(x_5);
x_259 = lean_nat_to_int(x_6);
x_260 = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(x_260, 0, x_259);
x_261 = lean_alloc_ctor(2, 2, 0);
lean_ctor_set(x_261, 0, x_2);
lean_ctor_set(x_261, 1, x_260);
return x_261;
}
else
{
lean_object* x_262; lean_object* x_263; lean_object* x_264; lean_object* x_265; lean_object* x_266; lean_object* x_267; lean_object* x_268; lean_object* x_269; lean_object* x_270; 
if (lean_is_exclusive(x_2)) {
 lean_ctor_release(x_2, 0);
 lean_ctor_release(x_2, 1);
 lean_ctor_release(x_2, 2);
 lean_ctor_release(x_2, 3);
 lean_ctor_release(x_2, 4);
 x_262 = x_2;
} else {
 lean_dec_ref(x_2);
 x_262 = lean_box(0);
}
x_263 = lean_array_fget(x_5, x_6);
x_264 = lean_unsigned_to_nat(1u);
x_265 = lean_nat_add(x_7, x_264);
lean_dec(x_7);
x_266 = lean_box(0);
x_267 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_267, 0, x_263);
lean_ctor_set(x_267, 1, x_266);
x_268 = l_List_appendTR___rarg(x_9, x_267);
if (lean_is_scalar(x_262)) {
 x_269 = lean_alloc_ctor(0, 5, 0);
} else {
 x_269 = x_262;
}
lean_ctor_set(x_269, 0, x_5);
lean_ctor_set(x_269, 1, x_6);
lean_ctor_set(x_269, 2, x_265);
lean_ctor_set(x_269, 3, x_8);
lean_ctor_set(x_269, 4, x_268);
x_270 = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(x_270, 0, x_269);
return x_270;
}
}
case 5:
{
if (lean_obj_tag(x_8) == 0)
{
lean_object* x_271; lean_object* x_272; 
lean_dec(x_9);
lean_dec(x_7);
lean_dec(x_6);
lean_dec(x_5);
x_271 = lean_box(1);
x_272 = lean_alloc_ctor(2, 2, 0);
lean_ctor_set(x_272, 0, x_2);
lean_ctor_set(x_272, 1, x_271);
return x_272;
}
else
{
lean_object* x_273; lean_object* x_274; lean_object* x_275; lean_object* x_276; uint8_t x_277; 
x_273 = lean_ctor_get(x_8, 0);
lean_inc(x_273);
x_274 = lean_ctor_get(x_8, 1);
lean_inc(x_274);
if (lean_is_exclusive(x_8)) {
 lean_ctor_release(x_8, 0);
 lean_ctor_release(x_8, 1);
 x_275 = x_8;
} else {
 lean_dec_ref(x_8);
 x_275 = lean_box(0);
}
x_276 = l_Brainfuck_TAPE__LEN;
x_277 = lean_nat_dec_lt(x_6, x_276);
if (x_277 == 0)
{
lean_object* x_278; lean_object* x_279; lean_object* x_280; 
lean_dec(x_274);
lean_dec(x_273);
lean_dec(x_9);
lean_dec(x_7);
lean_dec(x_5);
x_278 = lean_nat_to_int(x_6);
x_279 = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(x_279, 0, x_278);
if (lean_is_scalar(x_275)) {
 x_280 = lean_alloc_ctor(2, 2, 0);
} else {
 x_280 = x_275;
 lean_ctor_set_tag(x_280, 2);
}
lean_ctor_set(x_280, 0, x_2);
lean_ctor_set(x_280, 1, x_279);
return x_280;
}
else
{
lean_object* x_281; lean_object* x_282; lean_object* x_283; lean_object* x_284; lean_object* x_285; lean_object* x_286; 
lean_dec(x_275);
if (lean_is_exclusive(x_2)) {
 lean_ctor_release(x_2, 0);
 lean_ctor_release(x_2, 1);
 lean_ctor_release(x_2, 2);
 lean_ctor_release(x_2, 3);
 lean_ctor_release(x_2, 4);
 x_281 = x_2;
} else {
 lean_dec_ref(x_2);
 x_281 = lean_box(0);
}
x_282 = l_Brainfuck_writeCell(x_5, x_6, x_273);
lean_dec(x_273);
x_283 = lean_unsigned_to_nat(1u);
x_284 = lean_nat_add(x_7, x_283);
lean_dec(x_7);
if (lean_is_scalar(x_281)) {
 x_285 = lean_alloc_ctor(0, 5, 0);
} else {
 x_285 = x_281;
}
lean_ctor_set(x_285, 0, x_282);
lean_ctor_set(x_285, 1, x_6);
lean_ctor_set(x_285, 2, x_284);
lean_ctor_set(x_285, 3, x_274);
lean_ctor_set(x_285, 4, x_9);
x_286 = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(x_286, 0, x_285);
return x_286;
}
}
}
case 6:
{
lean_object* x_287; uint8_t x_288; 
x_287 = l_Brainfuck_TAPE__LEN;
x_288 = lean_nat_dec_lt(x_6, x_287);
if (x_288 == 0)
{
lean_object* x_289; lean_object* x_290; lean_object* x_291; 
lean_dec(x_9);
lean_dec(x_8);
lean_dec(x_7);
lean_dec(x_5);
x_289 = lean_nat_to_int(x_6);
x_290 = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(x_290, 0, x_289);
x_291 = lean_alloc_ctor(2, 2, 0);
lean_ctor_set(x_291, 0, x_2);
lean_ctor_set(x_291, 1, x_290);
return x_291;
}
else
{
lean_object* x_292; lean_object* x_293; lean_object* x_294; uint8_t x_295; 
if (lean_is_exclusive(x_2)) {
 lean_ctor_release(x_2, 0);
 lean_ctor_release(x_2, 1);
 lean_ctor_release(x_2, 2);
 lean_ctor_release(x_2, 3);
 lean_ctor_release(x_2, 4);
 x_292 = x_2;
} else {
 lean_dec_ref(x_2);
 x_292 = lean_box(0);
}
x_293 = lean_array_fget(x_5, x_6);
x_294 = lean_unsigned_to_nat(0u);
x_295 = lean_nat_dec_eq(x_293, x_294);
lean_dec(x_293);
if (x_295 == 0)
{
lean_object* x_296; lean_object* x_297; lean_object* x_298; lean_object* x_299; 
x_296 = lean_unsigned_to_nat(1u);
x_297 = lean_nat_add(x_7, x_296);
lean_dec(x_7);
if (lean_is_scalar(x_292)) {
 x_298 = lean_alloc_ctor(0, 5, 0);
} else {
 x_298 = x_292;
}
lean_ctor_set(x_298, 0, x_5);
lean_ctor_set(x_298, 1, x_6);
lean_ctor_set(x_298, 2, x_297);
lean_ctor_set(x_298, 3, x_8);
lean_ctor_set(x_298, 4, x_9);
x_299 = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(x_299, 0, x_298);
return x_299;
}
else
{
lean_object* x_300; lean_object* x_301; lean_object* x_302; lean_object* x_303; 
x_300 = lean_ctor_get(x_1, 1);
x_301 = l___private_Brainfuck_Step_0__Brainfuck_jumpAfterPartner(x_300, x_7);
lean_dec(x_7);
if (lean_is_scalar(x_292)) {
 x_302 = lean_alloc_ctor(0, 5, 0);
} else {
 x_302 = x_292;
}
lean_ctor_set(x_302, 0, x_5);
lean_ctor_set(x_302, 1, x_6);
lean_ctor_set(x_302, 2, x_301);
lean_ctor_set(x_302, 3, x_8);
lean_ctor_set(x_302, 4, x_9);
x_303 = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(x_303, 0, x_302);
return x_303;
}
}
}
default: 
{
lean_object* x_304; uint8_t x_305; 
x_304 = l_Brainfuck_TAPE__LEN;
x_305 = lean_nat_dec_lt(x_6, x_304);
if (x_305 == 0)
{
lean_object* x_306; lean_object* x_307; lean_object* x_308; 
lean_dec(x_9);
lean_dec(x_8);
lean_dec(x_7);
lean_dec(x_5);
x_306 = lean_nat_to_int(x_6);
x_307 = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(x_307, 0, x_306);
x_308 = lean_alloc_ctor(2, 2, 0);
lean_ctor_set(x_308, 0, x_2);
lean_ctor_set(x_308, 1, x_307);
return x_308;
}
else
{
lean_object* x_309; lean_object* x_310; lean_object* x_311; uint8_t x_312; uint8_t x_313; 
if (lean_is_exclusive(x_2)) {
 lean_ctor_release(x_2, 0);
 lean_ctor_release(x_2, 1);
 lean_ctor_release(x_2, 2);
 lean_ctor_release(x_2, 3);
 lean_ctor_release(x_2, 4);
 x_309 = x_2;
} else {
 lean_dec_ref(x_2);
 x_309 = lean_box(0);
}
x_310 = lean_array_fget(x_5, x_6);
x_311 = lean_unsigned_to_nat(0u);
x_312 = lean_nat_dec_eq(x_310, x_311);
lean_dec(x_310);
x_313 = l_instDecidableNot___rarg(x_312);
if (x_313 == 0)
{
lean_object* x_314; lean_object* x_315; lean_object* x_316; lean_object* x_317; 
x_314 = lean_unsigned_to_nat(1u);
x_315 = lean_nat_add(x_7, x_314);
lean_dec(x_7);
if (lean_is_scalar(x_309)) {
 x_316 = lean_alloc_ctor(0, 5, 0);
} else {
 x_316 = x_309;
}
lean_ctor_set(x_316, 0, x_5);
lean_ctor_set(x_316, 1, x_6);
lean_ctor_set(x_316, 2, x_315);
lean_ctor_set(x_316, 3, x_8);
lean_ctor_set(x_316, 4, x_9);
x_317 = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(x_317, 0, x_316);
return x_317;
}
else
{
lean_object* x_318; lean_object* x_319; lean_object* x_320; lean_object* x_321; 
x_318 = lean_ctor_get(x_1, 1);
x_319 = l___private_Brainfuck_Step_0__Brainfuck_jumpAfterPartner(x_318, x_7);
lean_dec(x_7);
if (lean_is_scalar(x_309)) {
 x_320 = lean_alloc_ctor(0, 5, 0);
} else {
 x_320 = x_309;
}
lean_ctor_set(x_320, 0, x_5);
lean_ctor_set(x_320, 1, x_6);
lean_ctor_set(x_320, 2, x_319);
lean_ctor_set(x_320, 3, x_8);
lean_ctor_set(x_320, 4, x_9);
x_321 = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(x_321, 0, x_320);
return x_321;
}
}
}
}
}
}
}
else
{
lean_object* x_322; 
lean_dec(x_9);
lean_dec(x_8);
lean_dec(x_7);
lean_dec(x_6);
lean_dec(x_5);
x_322 = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(x_322, 0, x_2);
return x_322;
}
}
}
LEAN_EXPORT lean_object* l_Brainfuck_step___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = l_Brainfuck_step(x_1, x_2);
lean_dec(x_1);
return x_3;
}
}
lean_object* initialize_Init(uint8_t builtin, lean_object*);
lean_object* initialize_Brainfuck_Constants(uint8_t builtin, lean_object*);
lean_object* initialize_Brainfuck_Errors(uint8_t builtin, lean_object*);
lean_object* initialize_Brainfuck_Program(uint8_t builtin, lean_object*);
lean_object* initialize_Brainfuck_State(uint8_t builtin, lean_object*);
lean_object* initialize_Brainfuck_Tape(uint8_t builtin, lean_object*);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_Brainfuck_Step(uint8_t builtin, lean_object* w) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
res = initialize_Init(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Brainfuck_Constants(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Brainfuck_Errors(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Brainfuck_Program(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Brainfuck_State(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Brainfuck_Tape(builtin, lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
l___private_Brainfuck_Step_0__Brainfuck_jumpAfterPartner___closed__1 = _init_l___private_Brainfuck_Step_0__Brainfuck_jumpAfterPartner___closed__1();
lean_mark_persistent(l___private_Brainfuck_Step_0__Brainfuck_jumpAfterPartner___closed__1);
l_Brainfuck_step___closed__1 = _init_l_Brainfuck_step___closed__1();
lean_mark_persistent(l_Brainfuck_step___closed__1);
l_Brainfuck_step___closed__2 = _init_l_Brainfuck_step___closed__2();
lean_mark_persistent(l_Brainfuck_step___closed__2);
l_Brainfuck_step___closed__3 = _init_l_Brainfuck_step___closed__3();
lean_mark_persistent(l_Brainfuck_step___closed__3);
l_Brainfuck_step___closed__4 = _init_l_Brainfuck_step___closed__4();
lean_mark_persistent(l_Brainfuck_step___closed__4);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
