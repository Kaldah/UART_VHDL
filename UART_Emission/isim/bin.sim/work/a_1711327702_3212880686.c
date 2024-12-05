/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0xfbc00daa */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "/home/gaut/Documents/GitHub/UART_VHDL/UART_Emission/EltEtat.vhd";
extern char *IEEE_P_2592010699;
extern char *STD_STANDARD;

unsigned char ieee_p_2592010699_sub_2763492388968962707_503743352(char *, char *, unsigned int , unsigned int );


static void work_a_1711327702_3212880686_p_0(char *t0)
{
    char t21[16];
    char t22[16];
    char t23[16];
    char t27[16];
    char t29[16];
    char t32[16];
    char t37[16];
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    int t11;
    unsigned char t12;
    unsigned char t13;
    int t14;
    int t15;
    int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    char *t20;
    char *t24;
    char *t25;
    char *t26;
    char *t28;
    char *t30;
    char *t31;
    char *t33;
    char *t34;
    char *t35;
    char *t36;
    char *t38;
    char *t39;
    char *t40;
    unsigned int t41;
    unsigned int t42;
    static char *nl0[] = {&&LAB8, &&LAB9, &&LAB10, &&LAB11};

LAB0:    xsi_set_current_line(58, ng0);
    t1 = (t0 + 1032U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)2);
    if (t4 != 0)
        goto LAB2;

LAB4:    t1 = (t0 + 1152U);
    t3 = ieee_p_2592010699_sub_2763492388968962707_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t3 != 0)
        goto LAB5;

LAB6:
LAB3:    t1 = (t0 + 4344);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(59, ng0);
    t1 = (t0 + 4424);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(60, ng0);
    t1 = xsi_get_transient_memory(8U);
    memset(t1, 0, 8U);
    t2 = t1;
    memset(t2, (unsigned char)2, 8U);
    t5 = (t0 + 4488);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t1, 8U);
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(61, ng0);
    t1 = (t0 + 4552);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(62, ng0);
    t1 = (t0 + 4616);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(63, ng0);
    t1 = (t0 + 4680);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(64, ng0);
    t1 = (t0 + 3048U);
    t2 = *((char **)t1);
    t1 = (t2 + 0);
    *((int *)t1) = 0;
    goto LAB3;

LAB5:    xsi_set_current_line(67, ng0);
    t2 = (t0 + 2472U);
    t5 = *((char **)t2);
    t4 = *((unsigned char *)t5);
    t2 = (char *)((nl0) + t4);
    goto **((char **)t2);

LAB7:    goto LAB3;

LAB8:    xsi_set_current_line(70, ng0);
    t6 = (t0 + 4552);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((unsigned char *)t10) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t6);
    xsi_set_current_line(71, ng0);
    t1 = (t0 + 4616);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(72, ng0);
    t1 = (t0 + 3048U);
    t2 = *((char **)t1);
    t1 = (t2 + 0);
    *((int *)t1) = 0;
    xsi_set_current_line(76, ng0);
    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB12;

LAB14:
LAB13:    goto LAB7;

LAB9:    xsi_set_current_line(85, ng0);
    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB15;

LAB17:
LAB16:    goto LAB7;

LAB10:    xsi_set_current_line(104, ng0);
    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB21;

LAB23:
LAB22:    goto LAB7;

LAB11:    xsi_set_current_line(124, ng0);
    t1 = (t0 + 3048U);
    t2 = *((char **)t1);
    t11 = *((int *)t2);
    t3 = (t11 == 2);
    if (t3 != 0)
        goto LAB27;

LAB29:
LAB28:    xsi_set_current_line(134, ng0);
    t1 = (t0 + 3048U);
    t2 = *((char **)t1);
    t11 = *((int *)t2);
    t14 = (t11 + 1);
    t1 = (t0 + 3048U);
    t5 = *((char **)t1);
    t1 = (t5 + 0);
    *((int *)t1) = t14;
    goto LAB7;

LAB12:    xsi_set_current_line(77, ng0);
    t1 = xsi_get_transient_memory(8U);
    memset(t1, 0, 8U);
    t5 = t1;
    memset(t5, (unsigned char)0, 8U);
    t6 = (t0 + 4744);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 8U);
    xsi_driver_first_trans_fast(t6);
    xsi_set_current_line(78, ng0);
    t1 = (t0 + 4680);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(79, ng0);
    t1 = (t0 + 4424);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)1;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(80, ng0);
    t1 = (t0 + 2928U);
    t2 = *((char **)t1);
    t1 = (t2 + 0);
    *((int *)t1) = 0;
    goto LAB13;

LAB15:    xsi_set_current_line(87, ng0);
    t1 = (t0 + 2928U);
    t5 = *((char **)t1);
    t11 = *((int *)t5);
    t12 = (t11 == 7);
    if (t12 != 0)
        goto LAB18;

LAB20:    xsi_set_current_line(94, ng0);
    t1 = (t0 + 1512U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 2928U);
    t5 = *((char **)t1);
    t11 = *((int *)t5);
    t14 = (7 - t11);
    t15 = (t14 - 7);
    t17 = (t15 * -1);
    t18 = (1 * t17);
    t19 = (0U + t18);
    t1 = (t0 + 4744);
    t6 = (t1 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = t3;
    xsi_driver_first_trans_delta(t1, t19, 1, 0LL);
    xsi_set_current_line(95, ng0);
    t1 = (t0 + 7657);
    t5 = ((STD_STANDARD) + 384);
    t6 = (t0 + 2928U);
    t7 = *((char **)t6);
    t11 = *((int *)t7);
    t6 = xsi_int_to_mem(t11);
    t8 = xsi_string_variable_get_image(t21, t5, t6);
    t10 = ((STD_STANDARD) + 984);
    t20 = (t23 + 0U);
    t24 = (t20 + 0U);
    *((int *)t24) = 1;
    t24 = (t20 + 4U);
    *((int *)t24) = 17;
    t24 = (t20 + 8U);
    *((int *)t24) = 1;
    t14 = (17 - 1);
    t17 = (t14 * 1);
    t17 = (t17 + 1);
    t24 = (t20 + 12U);
    *((unsigned int *)t24) = t17;
    t9 = xsi_base_array_concat(t9, t22, t10, (char)97, t1, t23, (char)97, t8, t21, (char)101);
    t24 = (t0 + 7674);
    t28 = ((STD_STANDARD) + 984);
    t30 = (t29 + 0U);
    t31 = (t30 + 0U);
    *((int *)t31) = 1;
    t31 = (t30 + 4U);
    *((int *)t31) = 16;
    t31 = (t30 + 8U);
    *((int *)t31) = 1;
    t15 = (16 - 1);
    t17 = (t15 * 1);
    t17 = (t17 + 1);
    t31 = (t30 + 12U);
    *((unsigned int *)t31) = t17;
    t26 = xsi_base_array_concat(t26, t27, t28, (char)97, t9, t22, (char)97, t24, t29, (char)101);
    t31 = ((IEEE_P_2592010699) + 3216);
    t33 = (t0 + 1512U);
    t34 = *((char **)t33);
    t3 = *((unsigned char *)t34);
    t33 = xsi_char_to_mem(t3);
    t35 = xsi_string_variable_get_image(t32, t31, t33);
    t38 = ((STD_STANDARD) + 984);
    t36 = xsi_base_array_concat(t36, t37, t38, (char)97, t26, t27, (char)97, t35, t32, (char)101);
    t39 = (t21 + 12U);
    t17 = *((unsigned int *)t39);
    t18 = (17U + t17);
    t19 = (t18 + 16U);
    t40 = (t32 + 12U);
    t41 = *((unsigned int *)t40);
    t42 = (t19 + t41);
    xsi_report(t36, t42, 0);
    xsi_set_current_line(96, ng0);
    t1 = (t0 + 2928U);
    t2 = *((char **)t1);
    t11 = *((int *)t2);
    t14 = (t11 + 1);
    t1 = (t0 + 2928U);
    t5 = *((char **)t1);
    t1 = (t5 + 0);
    *((int *)t1) = t14;

LAB19:    goto LAB16;

LAB18:    xsi_set_current_line(88, ng0);
    t1 = (t0 + 1512U);
    t6 = *((char **)t1);
    t13 = *((unsigned char *)t6);
    t1 = (t0 + 2928U);
    t7 = *((char **)t1);
    t14 = *((int *)t7);
    t15 = (7 - t14);
    t16 = (t15 - 7);
    t17 = (t16 * -1);
    t18 = (1 * t17);
    t19 = (0U + t18);
    t1 = (t0 + 4744);
    t8 = (t1 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t20 = *((char **)t10);
    *((unsigned char *)t20) = t13;
    xsi_driver_first_trans_delta(t1, t19, 1, 0LL);
    xsi_set_current_line(89, ng0);
    t1 = (t0 + 7624);
    t5 = ((STD_STANDARD) + 384);
    t6 = (t0 + 2928U);
    t7 = *((char **)t6);
    t11 = *((int *)t7);
    t6 = xsi_int_to_mem(t11);
    t8 = xsi_string_variable_get_image(t21, t5, t6);
    t10 = ((STD_STANDARD) + 984);
    t20 = (t23 + 0U);
    t24 = (t20 + 0U);
    *((int *)t24) = 1;
    t24 = (t20 + 4U);
    *((int *)t24) = 17;
    t24 = (t20 + 8U);
    *((int *)t24) = 1;
    t14 = (17 - 1);
    t17 = (t14 * 1);
    t17 = (t17 + 1);
    t24 = (t20 + 12U);
    *((unsigned int *)t24) = t17;
    t9 = xsi_base_array_concat(t9, t22, t10, (char)97, t1, t23, (char)97, t8, t21, (char)101);
    t24 = (t0 + 7641);
    t28 = ((STD_STANDARD) + 984);
    t30 = (t29 + 0U);
    t31 = (t30 + 0U);
    *((int *)t31) = 1;
    t31 = (t30 + 4U);
    *((int *)t31) = 16;
    t31 = (t30 + 8U);
    *((int *)t31) = 1;
    t15 = (16 - 1);
    t17 = (t15 * 1);
    t17 = (t17 + 1);
    t31 = (t30 + 12U);
    *((unsigned int *)t31) = t17;
    t26 = xsi_base_array_concat(t26, t27, t28, (char)97, t9, t22, (char)97, t24, t29, (char)101);
    t31 = ((IEEE_P_2592010699) + 3216);
    t33 = (t0 + 1512U);
    t34 = *((char **)t33);
    t3 = *((unsigned char *)t34);
    t33 = xsi_char_to_mem(t3);
    t35 = xsi_string_variable_get_image(t32, t31, t33);
    t38 = ((STD_STANDARD) + 984);
    t36 = xsi_base_array_concat(t36, t37, t38, (char)97, t26, t27, (char)97, t35, t32, (char)101);
    t39 = (t21 + 12U);
    t17 = *((unsigned int *)t39);
    t18 = (17U + t17);
    t19 = (t18 + 16U);
    t40 = (t32 + 12U);
    t41 = *((unsigned int *)t40);
    t42 = (t19 + t41);
    xsi_report(t36, t42, 0);
    xsi_set_current_line(90, ng0);
    t1 = (t0 + 2928U);
    t2 = *((char **)t1);
    t1 = (t2 + 0);
    *((int *)t1) = 0;
    xsi_set_current_line(91, ng0);
    t1 = (t0 + 4424);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    goto LAB19;

LAB21:    xsi_set_current_line(105, ng0);
    t1 = (t0 + 7690);
    t6 = ((IEEE_P_2592010699) + 3216);
    t7 = (t0 + 1512U);
    t8 = *((char **)t7);
    t12 = *((unsigned char *)t8);
    t7 = xsi_char_to_mem(t12);
    t9 = xsi_string_variable_get_image(t21, t6, t7);
    t20 = ((STD_STANDARD) + 984);
    t24 = (t23 + 0U);
    t25 = (t24 + 0U);
    *((int *)t25) = 1;
    t25 = (t24 + 4U);
    *((int *)t25) = 36;
    t25 = (t24 + 8U);
    *((int *)t25) = 1;
    t11 = (36 - 1);
    t17 = (t11 * 1);
    t17 = (t17 + 1);
    t25 = (t24 + 12U);
    *((unsigned int *)t25) = t17;
    t10 = xsi_base_array_concat(t10, t22, t20, (char)97, t1, t23, (char)97, t9, t21, (char)101);
    t25 = (t21 + 12U);
    t17 = *((unsigned int *)t25);
    t18 = (36U + t17);
    xsi_report(t10, t18, 0);
    xsi_set_current_line(107, ng0);
    t1 = (t0 + 1512U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)2);
    if (t4 != 0)
        goto LAB24;

LAB26:    xsi_set_current_line(112, ng0);
    t1 = (t0 + 4680);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(113, ng0);
    t1 = (t0 + 2632U);
    t2 = *((char **)t1);
    t1 = (t0 + 4488);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 8U);
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(116, ng0);
    t1 = (t0 + 4424);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);

LAB25:    goto LAB22;

LAB24:    xsi_set_current_line(108, ng0);
    t1 = (t0 + 4552);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(109, ng0);
    t1 = (t0 + 4680);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(110, ng0);
    t1 = (t0 + 4424);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);
    goto LAB25;

LAB27:    xsi_set_current_line(125, ng0);
    t1 = (t0 + 3048U);
    t5 = *((char **)t1);
    t1 = (t5 + 0);
    *((int *)t1) = 0;
    xsi_set_current_line(127, ng0);
    t1 = (t0 + 1672U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)2);
    if (t4 != 0)
        goto LAB30;

LAB32:
LAB31:    xsi_set_current_line(130, ng0);
    t1 = (t0 + 4680);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(131, ng0);
    t1 = (t0 + 4424);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);
    goto LAB28;

LAB30:    xsi_set_current_line(128, ng0);
    t1 = (t0 + 4616);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB31;

}


extern void work_a_1711327702_3212880686_init()
{
	static char *pe[] = {(void *)work_a_1711327702_3212880686_p_0};
	xsi_register_didat("work_a_1711327702_3212880686", "isim/bin.sim/work/a_1711327702_3212880686.didat");
	xsi_register_executes(pe);
}
