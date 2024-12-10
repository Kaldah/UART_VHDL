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
static const char *ng0 = "/home/ccy6321/Documents/S7/Archi/UART_VHDL/TxUnit/TxUnit.vhd";
extern char *IEEE_P_2592010699;

unsigned char ieee_p_2592010699_sub_2763492388968962707_503743352(char *, char *, unsigned int , unsigned int );


static void work_a_0342691397_2193661277_p_0(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    unsigned char t9;
    unsigned char t10;
    char *t11;
    unsigned char t12;
    int t13;
    int t14;
    int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    char *t19;
    char *t20;
    char *t21;
    static char *nl0[] = {&&LAB8, &&LAB9, &&LAB10, &&LAB11, &&LAB12};

LAB0:    xsi_set_current_line(31, ng0);
    t1 = (t0 + 1192U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)2);
    if (t4 != 0)
        goto LAB2;

LAB4:    t1 = (t0 + 992U);
    t3 = ieee_p_2592010699_sub_2763492388968962707_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t3 != 0)
        goto LAB5;

LAB6:
LAB3:    xsi_set_current_line(91, ng0);
    t1 = (t0 + 3128U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 4696);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = t3;
    xsi_driver_first_trans_fast_port(t1);
    t1 = (t0 + 4424);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(32, ng0);
    t1 = (t0 + 4504);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(33, ng0);
    t1 = (t0 + 4568);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(34, ng0);
    t1 = (t0 + 3128U);
    t2 = *((char **)t1);
    t1 = (t2 + 0);
    *((unsigned char *)t1) = (unsigned char)3;
    xsi_set_current_line(35, ng0);
    t1 = (t0 + 3008U);
    t2 = *((char **)t1);
    t1 = (t2 + 0);
    *((int *)t1) = 0;
    xsi_set_current_line(36, ng0);
    t1 = (t0 + 4632);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);
    goto LAB3;

LAB5:    xsi_set_current_line(38, ng0);
    t2 = (t0 + 2472U);
    t5 = *((char **)t2);
    t4 = *((unsigned char *)t5);
    t2 = (char *)((nl0) + t4);
    goto **((char **)t2);

LAB7:    goto LAB3;

LAB8:    xsi_set_current_line(40, ng0);
    t6 = (t0 + 1512U);
    t7 = *((char **)t6);
    t9 = *((unsigned char *)t7);
    t10 = (t9 == (unsigned char)3);
    if (t10 != 0)
        goto LAB13;

LAB15:
LAB14:    goto LAB7;

LAB9:    xsi_set_current_line(48, ng0);
    t1 = (t0 + 2768U);
    t2 = *((char **)t1);
    t1 = (t0 + 2888U);
    t5 = *((char **)t1);
    t1 = (t5 + 0);
    memcpy(t1, t2, 8U);
    xsi_set_current_line(49, ng0);
    t1 = (t0 + 4568);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(50, ng0);
    t1 = (t0 + 3128U);
    t2 = *((char **)t1);
    t1 = (t2 + 0);
    *((unsigned char *)t1) = (unsigned char)3;
    xsi_set_current_line(51, ng0);
    t1 = (t0 + 4632);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    goto LAB7;

LAB10:    xsi_set_current_line(54, ng0);
    t1 = (t0 + 1512U);
    t2 = *((char **)t1);
    t4 = *((unsigned char *)t2);
    t9 = (t4 == (unsigned char)3);
    if (t9 == 1)
        goto LAB19;

LAB20:    t3 = (unsigned char)0;

LAB21:    if (t3 != 0)
        goto LAB16;

LAB18:
LAB17:    xsi_set_current_line(58, ng0);
    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB22;

LAB24:
LAB23:    goto LAB7;

LAB11:    xsi_set_current_line(65, ng0);
    t1 = (t0 + 1512U);
    t2 = *((char **)t1);
    t4 = *((unsigned char *)t2);
    t9 = (t4 == (unsigned char)3);
    if (t9 == 1)
        goto LAB28;

LAB29:    t3 = (unsigned char)0;

LAB30:    if (t3 != 0)
        goto LAB25;

LAB27:
LAB26:    xsi_set_current_line(69, ng0);
    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t4 = *((unsigned char *)t2);
    t9 = (t4 == (unsigned char)3);
    if (t9 == 1)
        goto LAB34;

LAB35:    t3 = (unsigned char)0;

LAB36:    if (t3 != 0)
        goto LAB31;

LAB33:    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t4 = *((unsigned char *)t2);
    t9 = (t4 == (unsigned char)3);
    if (t9 == 1)
        goto LAB39;

LAB40:    t3 = (unsigned char)0;

LAB41:    if (t3 != 0)
        goto LAB37;

LAB38:
LAB32:    goto LAB7;

LAB12:    xsi_set_current_line(78, ng0);
    t1 = (t0 + 1512U);
    t2 = *((char **)t1);
    t4 = *((unsigned char *)t2);
    t9 = (t4 == (unsigned char)3);
    if (t9 == 1)
        goto LAB45;

LAB46:    t3 = (unsigned char)0;

LAB47:    if (t3 != 0)
        goto LAB42;

LAB44:
LAB43:    xsi_set_current_line(82, ng0);
    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t4 = *((unsigned char *)t2);
    t9 = (t4 == (unsigned char)3);
    if (t9 == 1)
        goto LAB51;

LAB52:    t3 = (unsigned char)0;

LAB53:    if (t3 != 0)
        goto LAB48;

LAB50:    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t4 = *((unsigned char *)t2);
    t9 = (t4 == (unsigned char)3);
    if (t9 == 1)
        goto LAB56;

LAB57:    t3 = (unsigned char)0;

LAB58:    if (t3 != 0)
        goto LAB54;

LAB55:
LAB49:    goto LAB7;

LAB13:    xsi_set_current_line(41, ng0);
    t6 = (t0 + 2152U);
    t8 = *((char **)t6);
    t6 = (t0 + 2768U);
    t11 = *((char **)t6);
    t6 = (t11 + 0);
    memcpy(t6, t8, 8U);
    xsi_set_current_line(42, ng0);
    t1 = (t0 + 3128U);
    t2 = *((char **)t1);
    t1 = (t2 + 0);
    *((unsigned char *)t1) = (unsigned char)2;
    xsi_set_current_line(44, ng0);
    t1 = (t0 + 4632);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)1;
    xsi_driver_first_trans_fast(t1);
    goto LAB14;

LAB16:    xsi_set_current_line(55, ng0);
    t1 = (t0 + 2152U);
    t6 = *((char **)t1);
    t1 = (t0 + 2768U);
    t7 = *((char **)t1);
    t1 = (t7 + 0);
    memcpy(t1, t6, 8U);
    xsi_set_current_line(56, ng0);
    t1 = (t0 + 3128U);
    t2 = *((char **)t1);
    t1 = (t2 + 0);
    *((unsigned char *)t1) = (unsigned char)2;
    goto LAB17;

LAB19:    t1 = (t0 + 3128U);
    t5 = *((char **)t1);
    t10 = *((unsigned char *)t5);
    t12 = (t10 == (unsigned char)3);
    t3 = t12;
    goto LAB21;

LAB22:    xsi_set_current_line(59, ng0);
    t1 = (t0 + 4504);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(60, ng0);
    t1 = (t0 + 3008U);
    t2 = *((char **)t1);
    t1 = (t2 + 0);
    *((int *)t1) = 7;
    xsi_set_current_line(61, ng0);
    t1 = (t0 + 4632);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    goto LAB23;

LAB25:    xsi_set_current_line(66, ng0);
    t1 = (t0 + 2152U);
    t6 = *((char **)t1);
    t1 = (t0 + 2768U);
    t7 = *((char **)t1);
    t1 = (t7 + 0);
    memcpy(t1, t6, 8U);
    xsi_set_current_line(67, ng0);
    t1 = (t0 + 3128U);
    t2 = *((char **)t1);
    t1 = (t2 + 0);
    *((unsigned char *)t1) = (unsigned char)2;
    goto LAB26;

LAB28:    t1 = (t0 + 3128U);
    t5 = *((char **)t1);
    t10 = *((unsigned char *)t5);
    t12 = (t10 == (unsigned char)3);
    t3 = t12;
    goto LAB30;

LAB31:    xsi_set_current_line(70, ng0);
    t1 = (t0 + 2888U);
    t6 = *((char **)t1);
    t1 = (t0 + 3008U);
    t7 = *((char **)t1);
    t14 = *((int *)t7);
    t15 = (t14 - 7);
    t16 = (t15 * -1);
    xsi_vhdl_check_range_of_index(7, 0, -1, t14);
    t17 = (1U * t16);
    t18 = (0 + t17);
    t1 = (t6 + t18);
    t12 = *((unsigned char *)t1);
    t8 = (t0 + 4504);
    t11 = (t8 + 56U);
    t19 = *((char **)t11);
    t20 = (t19 + 56U);
    t21 = *((char **)t20);
    *((unsigned char *)t21) = t12;
    xsi_driver_first_trans_fast_port(t8);
    xsi_set_current_line(71, ng0);
    t1 = (t0 + 3008U);
    t2 = *((char **)t1);
    t13 = *((int *)t2);
    t14 = (t13 - 1);
    t1 = (t0 + 3008U);
    t5 = *((char **)t1);
    t1 = (t5 + 0);
    *((int *)t1) = t14;
    goto LAB32;

LAB34:    t1 = (t0 + 3008U);
    t5 = *((char **)t1);
    t13 = *((int *)t5);
    t10 = (t13 > 0);
    t3 = t10;
    goto LAB36;

LAB37:    xsi_set_current_line(73, ng0);
    t1 = (t0 + 2888U);
    t6 = *((char **)t1);
    t1 = (t0 + 3008U);
    t7 = *((char **)t1);
    t14 = *((int *)t7);
    t15 = (t14 - 7);
    t16 = (t15 * -1);
    xsi_vhdl_check_range_of_index(7, 0, -1, t14);
    t17 = (1U * t16);
    t18 = (0 + t17);
    t1 = (t6 + t18);
    t12 = *((unsigned char *)t1);
    t8 = (t0 + 4504);
    t11 = (t8 + 56U);
    t19 = *((char **)t11);
    t20 = (t19 + 56U);
    t21 = *((char **)t20);
    *((unsigned char *)t21) = t12;
    xsi_driver_first_trans_fast_port(t8);
    xsi_set_current_line(74, ng0);
    t1 = (t0 + 4632);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)4;
    xsi_driver_first_trans_fast(t1);
    goto LAB32;

LAB39:    t1 = (t0 + 3008U);
    t5 = *((char **)t1);
    t13 = *((int *)t5);
    t10 = (t13 == 0);
    t3 = t10;
    goto LAB41;

LAB42:    xsi_set_current_line(79, ng0);
    t1 = (t0 + 2152U);
    t6 = *((char **)t1);
    t1 = (t0 + 2768U);
    t7 = *((char **)t1);
    t1 = (t7 + 0);
    memcpy(t1, t6, 8U);
    xsi_set_current_line(80, ng0);
    t1 = (t0 + 3128U);
    t2 = *((char **)t1);
    t1 = (t2 + 0);
    *((unsigned char *)t1) = (unsigned char)2;
    goto LAB43;

LAB45:    t1 = (t0 + 3128U);
    t5 = *((char **)t1);
    t10 = *((unsigned char *)t5);
    t12 = (t10 == (unsigned char)3);
    t3 = t12;
    goto LAB47;

LAB48:    xsi_set_current_line(83, ng0);
    t1 = (t0 + 4632);
    t6 = (t1 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t11 = *((char **)t8);
    *((unsigned char *)t11) = (unsigned char)1;
    xsi_driver_first_trans_fast(t1);
    goto LAB49;

LAB51:    t1 = (t0 + 3128U);
    t5 = *((char **)t1);
    t10 = *((unsigned char *)t5);
    t12 = (t10 == (unsigned char)2);
    t3 = t12;
    goto LAB53;

LAB54:    xsi_set_current_line(85, ng0);
    t1 = (t0 + 4504);
    t6 = (t1 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t11 = *((char **)t8);
    *((unsigned char *)t11) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(86, ng0);
    t1 = (t0 + 4632);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);
    goto LAB49;

LAB56:    t1 = (t0 + 3128U);
    t5 = *((char **)t1);
    t10 = *((unsigned char *)t5);
    t12 = (t10 == (unsigned char)3);
    t3 = t12;
    goto LAB58;

}


extern void work_a_0342691397_2193661277_init()
{
	static char *pe[] = {(void *)work_a_0342691397_2193661277_p_0};
	xsi_register_didat("work_a_0342691397_2193661277", "isim/bin.sim/work/a_0342691397_2193661277.didat");
	xsi_register_executes(pe);
}
