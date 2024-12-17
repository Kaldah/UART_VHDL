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
unsigned char ieee_p_2592010699_sub_3488768497506413324_503743352(char *, unsigned char , unsigned char );


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
    unsigned char t13;
    unsigned char t14;
    unsigned char t15;
    int t16;
    int t17;
    int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    char *t22;
    char *t23;
    char *t24;
    static char *nl0[] = {&&LAB8, &&LAB9, &&LAB10, &&LAB11, &&LAB12, &&LAB13};

LAB0:    xsi_set_current_line(33, ng0);
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
LAB3:    xsi_set_current_line(112, ng0);
    t1 = (t0 + 3288U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 4920);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = t3;
    xsi_driver_first_trans_fast_port(t1);
    t1 = (t0 + 4584);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(34, ng0);
    t1 = (t0 + 4664);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(35, ng0);
    t1 = (t0 + 4728);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(36, ng0);
    t1 = (t0 + 3288U);
    t2 = *((char **)t1);
    t1 = (t2 + 0);
    *((unsigned char *)t1) = (unsigned char)3;
    xsi_set_current_line(37, ng0);
    t1 = (t0 + 3168U);
    t2 = *((char **)t1);
    t1 = (t2 + 0);
    *((int *)t1) = 0;
    xsi_set_current_line(38, ng0);
    t1 = xsi_get_transient_memory(8U);
    memset(t1, 0, 8U);
    t2 = t1;
    memset(t2, (unsigned char)2, 8U);
    t5 = (t0 + 2928U);
    t6 = *((char **)t5);
    t5 = (t6 + 0);
    memcpy(t5, t1, 8U);
    xsi_set_current_line(39, ng0);
    t1 = xsi_get_transient_memory(8U);
    memset(t1, 0, 8U);
    t2 = t1;
    memset(t2, (unsigned char)2, 8U);
    t5 = (t0 + 3048U);
    t6 = *((char **)t5);
    t5 = (t6 + 0);
    memcpy(t5, t1, 8U);
    xsi_set_current_line(40, ng0);
    t1 = (t0 + 4792);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(41, ng0);
    t1 = (t0 + 4856);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);
    goto LAB3;

LAB5:    xsi_set_current_line(43, ng0);
    t2 = (t0 + 2632U);
    t5 = *((char **)t2);
    t4 = *((unsigned char *)t5);
    t2 = (char *)((nl0) + t4);
    goto **((char **)t2);

LAB7:    goto LAB3;

LAB8:    xsi_set_current_line(45, ng0);
    t6 = (t0 + 1512U);
    t7 = *((char **)t6);
    t9 = *((unsigned char *)t7);
    t10 = (t9 == (unsigned char)3);
    if (t10 != 0)
        goto LAB14;

LAB16:
LAB15:    goto LAB7;

LAB9:    xsi_set_current_line(53, ng0);
    t1 = (t0 + 2928U);
    t2 = *((char **)t1);
    t1 = (t0 + 3048U);
    t5 = *((char **)t1);
    t1 = (t5 + 0);
    memcpy(t1, t2, 8U);
    xsi_set_current_line(54, ng0);
    t1 = (t0 + 4728);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(55, ng0);
    t1 = (t0 + 3288U);
    t2 = *((char **)t1);
    t1 = (t2 + 0);
    *((unsigned char *)t1) = (unsigned char)3;
    xsi_set_current_line(56, ng0);
    t1 = (t0 + 4856);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    goto LAB7;

LAB10:    xsi_set_current_line(59, ng0);
    t1 = (t0 + 1512U);
    t2 = *((char **)t1);
    t4 = *((unsigned char *)t2);
    t9 = (t4 == (unsigned char)3);
    if (t9 == 1)
        goto LAB20;

LAB21:    t3 = (unsigned char)0;

LAB22:    if (t3 != 0)
        goto LAB17;

LAB19:
LAB18:    xsi_set_current_line(63, ng0);
    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB23;

LAB25:
LAB24:    goto LAB7;

LAB11:    xsi_set_current_line(70, ng0);
    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t9 = *((unsigned char *)t2);
    t10 = (t9 == (unsigned char)3);
    if (t10 == 1)
        goto LAB32;

LAB33:    t4 = (unsigned char)0;

LAB34:    if (t4 == 1)
        goto LAB29;

LAB30:    t3 = (unsigned char)0;

LAB31:    if (t3 != 0)
        goto LAB26;

LAB28:
LAB27:    xsi_set_current_line(74, ng0);
    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t4 = *((unsigned char *)t2);
    t9 = (t4 == (unsigned char)3);
    if (t9 == 1)
        goto LAB38;

LAB39:    t3 = (unsigned char)0;

LAB40:    if (t3 != 0)
        goto LAB35;

LAB37:    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t4 = *((unsigned char *)t2);
    t9 = (t4 == (unsigned char)3);
    if (t9 == 1)
        goto LAB43;

LAB44:    t3 = (unsigned char)0;

LAB45:    if (t3 != 0)
        goto LAB41;

LAB42:
LAB36:    goto LAB7;

LAB12:    xsi_set_current_line(85, ng0);
    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB46;

LAB48:
LAB47:    goto LAB7;

LAB13:    xsi_set_current_line(99, ng0);
    t1 = (t0 + 1512U);
    t2 = *((char **)t1);
    t4 = *((unsigned char *)t2);
    t9 = (t4 == (unsigned char)3);
    if (t9 == 1)
        goto LAB58;

LAB59:    t3 = (unsigned char)0;

LAB60:    if (t3 != 0)
        goto LAB55;

LAB57:
LAB56:    xsi_set_current_line(103, ng0);
    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t4 = *((unsigned char *)t2);
    t9 = (t4 == (unsigned char)3);
    if (t9 == 1)
        goto LAB64;

LAB65:    t3 = (unsigned char)0;

LAB66:    if (t3 != 0)
        goto LAB61;

LAB63:    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t4 = *((unsigned char *)t2);
    t9 = (t4 == (unsigned char)3);
    if (t9 == 1)
        goto LAB69;

LAB70:    t3 = (unsigned char)0;

LAB71:    if (t3 != 0)
        goto LAB67;

LAB68:
LAB62:    goto LAB7;

LAB14:    xsi_set_current_line(46, ng0);
    t6 = (t0 + 2152U);
    t8 = *((char **)t6);
    t6 = (t0 + 2928U);
    t11 = *((char **)t6);
    t6 = (t11 + 0);
    memcpy(t6, t8, 8U);
    xsi_set_current_line(47, ng0);
    t1 = (t0 + 3288U);
    t2 = *((char **)t1);
    t1 = (t2 + 0);
    *((unsigned char *)t1) = (unsigned char)2;
    xsi_set_current_line(48, ng0);
    t1 = (t0 + 4792);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(49, ng0);
    t1 = (t0 + 4856);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)1;
    xsi_driver_first_trans_fast(t1);
    goto LAB15;

LAB17:    xsi_set_current_line(60, ng0);
    t1 = (t0 + 2152U);
    t6 = *((char **)t1);
    t1 = (t0 + 2928U);
    t7 = *((char **)t1);
    t1 = (t7 + 0);
    memcpy(t1, t6, 8U);
    xsi_set_current_line(61, ng0);
    t1 = (t0 + 3288U);
    t2 = *((char **)t1);
    t1 = (t2 + 0);
    *((unsigned char *)t1) = (unsigned char)2;
    goto LAB18;

LAB20:    t1 = (t0 + 3288U);
    t5 = *((char **)t1);
    t10 = *((unsigned char *)t5);
    t12 = (t10 == (unsigned char)3);
    t3 = t12;
    goto LAB22;

LAB23:    xsi_set_current_line(64, ng0);
    t1 = (t0 + 4664);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(65, ng0);
    t1 = (t0 + 3168U);
    t2 = *((char **)t1);
    t1 = (t2 + 0);
    *((int *)t1) = 7;
    xsi_set_current_line(66, ng0);
    t1 = (t0 + 4856);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    goto LAB24;

LAB26:    xsi_set_current_line(71, ng0);
    t1 = (t0 + 2152U);
    t7 = *((char **)t1);
    t1 = (t0 + 2928U);
    t8 = *((char **)t1);
    t1 = (t8 + 0);
    memcpy(t1, t7, 8U);
    xsi_set_current_line(72, ng0);
    t1 = (t0 + 3288U);
    t2 = *((char **)t1);
    t1 = (t2 + 0);
    *((unsigned char *)t1) = (unsigned char)2;
    goto LAB27;

LAB29:    t1 = (t0 + 3288U);
    t6 = *((char **)t1);
    t14 = *((unsigned char *)t6);
    t15 = (t14 == (unsigned char)3);
    t3 = t15;
    goto LAB31;

LAB32:    t1 = (t0 + 1512U);
    t5 = *((char **)t1);
    t12 = *((unsigned char *)t5);
    t13 = (t12 == (unsigned char)3);
    t4 = t13;
    goto LAB34;

LAB35:    xsi_set_current_line(75, ng0);
    t1 = (t0 + 3048U);
    t6 = *((char **)t1);
    t1 = (t0 + 3168U);
    t7 = *((char **)t1);
    t17 = *((int *)t7);
    t18 = (t17 - 7);
    t19 = (t18 * -1);
    xsi_vhdl_check_range_of_index(7, 0, -1, t17);
    t20 = (1U * t19);
    t21 = (0 + t20);
    t1 = (t6 + t21);
    t12 = *((unsigned char *)t1);
    t8 = (t0 + 4664);
    t11 = (t8 + 56U);
    t22 = *((char **)t11);
    t23 = (t22 + 56U);
    t24 = *((char **)t23);
    *((unsigned char *)t24) = t12;
    xsi_driver_first_trans_fast_port(t8);
    xsi_set_current_line(76, ng0);
    t1 = (t0 + 2472U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 3048U);
    t5 = *((char **)t1);
    t1 = (t0 + 3168U);
    t6 = *((char **)t1);
    t16 = *((int *)t6);
    t17 = (t16 - 7);
    t19 = (t17 * -1);
    xsi_vhdl_check_range_of_index(7, 0, -1, t16);
    t20 = (1U * t19);
    t21 = (0 + t20);
    t1 = (t5 + t21);
    t4 = *((unsigned char *)t1);
    t9 = ieee_p_2592010699_sub_3488768497506413324_503743352(IEEE_P_2592010699, t3, t4);
    t7 = (t0 + 4792);
    t8 = (t7 + 56U);
    t11 = *((char **)t8);
    t22 = (t11 + 56U);
    t23 = *((char **)t22);
    *((unsigned char *)t23) = t9;
    xsi_driver_first_trans_fast(t7);
    xsi_set_current_line(77, ng0);
    t1 = (t0 + 3168U);
    t2 = *((char **)t1);
    t16 = *((int *)t2);
    t17 = (t16 - 1);
    t1 = (t0 + 3168U);
    t5 = *((char **)t1);
    t1 = (t5 + 0);
    *((int *)t1) = t17;
    goto LAB36;

LAB38:    t1 = (t0 + 3168U);
    t5 = *((char **)t1);
    t16 = *((int *)t5);
    t10 = (t16 > 0);
    t3 = t10;
    goto LAB40;

LAB41:    xsi_set_current_line(79, ng0);
    t1 = (t0 + 3048U);
    t6 = *((char **)t1);
    t1 = (t0 + 3168U);
    t7 = *((char **)t1);
    t17 = *((int *)t7);
    t18 = (t17 - 7);
    t19 = (t18 * -1);
    xsi_vhdl_check_range_of_index(7, 0, -1, t17);
    t20 = (1U * t19);
    t21 = (0 + t20);
    t1 = (t6 + t21);
    t12 = *((unsigned char *)t1);
    t8 = (t0 + 4664);
    t11 = (t8 + 56U);
    t22 = *((char **)t11);
    t23 = (t22 + 56U);
    t24 = *((char **)t23);
    *((unsigned char *)t24) = t12;
    xsi_driver_first_trans_fast_port(t8);
    xsi_set_current_line(80, ng0);
    t1 = (t0 + 2472U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 3048U);
    t5 = *((char **)t1);
    t1 = (t0 + 3168U);
    t6 = *((char **)t1);
    t16 = *((int *)t6);
    t17 = (t16 - 7);
    t19 = (t17 * -1);
    xsi_vhdl_check_range_of_index(7, 0, -1, t16);
    t20 = (1U * t19);
    t21 = (0 + t20);
    t1 = (t5 + t21);
    t4 = *((unsigned char *)t1);
    t9 = ieee_p_2592010699_sub_3488768497506413324_503743352(IEEE_P_2592010699, t3, t4);
    t7 = (t0 + 4792);
    t8 = (t7 + 56U);
    t11 = *((char **)t8);
    t22 = (t11 + 56U);
    t23 = *((char **)t22);
    *((unsigned char *)t23) = t9;
    xsi_driver_first_trans_fast(t7);
    xsi_set_current_line(81, ng0);
    t1 = (t0 + 4856);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)4;
    xsi_driver_first_trans_fast(t1);
    goto LAB36;

LAB43:    t1 = (t0 + 3168U);
    t5 = *((char **)t1);
    t16 = *((int *)t5);
    t10 = (t16 == 0);
    t3 = t10;
    goto LAB45;

LAB46:    xsi_set_current_line(86, ng0);
    t1 = xsi_get_transient_memory(8U);
    memset(t1, 0, 8U);
    t5 = t1;
    memset(t5, (unsigned char)2, 8U);
    t6 = (t0 + 3048U);
    t7 = *((char **)t6);
    t6 = (t7 + 0);
    memcpy(t6, t1, 8U);
    xsi_set_current_line(87, ng0);
    t1 = (t0 + 4728);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(88, ng0);
    t1 = (t0 + 2472U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 4664);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = t3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(89, ng0);
    t1 = (t0 + 4856);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)5;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(90, ng0);
    t1 = (t0 + 1512U);
    t2 = *((char **)t1);
    t4 = *((unsigned char *)t2);
    t9 = (t4 == (unsigned char)3);
    if (t9 == 1)
        goto LAB52;

LAB53:    t3 = (unsigned char)0;

LAB54:    if (t3 != 0)
        goto LAB49;

LAB51:
LAB50:    goto LAB47;

LAB49:    xsi_set_current_line(91, ng0);
    t1 = (t0 + 2152U);
    t6 = *((char **)t1);
    t1 = (t0 + 2928U);
    t7 = *((char **)t1);
    t1 = (t7 + 0);
    memcpy(t1, t6, 8U);
    xsi_set_current_line(92, ng0);
    t1 = (t0 + 3288U);
    t2 = *((char **)t1);
    t1 = (t2 + 0);
    *((unsigned char *)t1) = (unsigned char)2;
    goto LAB50;

LAB52:    t1 = (t0 + 3288U);
    t5 = *((char **)t1);
    t10 = *((unsigned char *)t5);
    t12 = (t10 == (unsigned char)3);
    t3 = t12;
    goto LAB54;

LAB55:    xsi_set_current_line(100, ng0);
    t1 = (t0 + 2152U);
    t6 = *((char **)t1);
    t1 = (t0 + 2928U);
    t7 = *((char **)t1);
    t1 = (t7 + 0);
    memcpy(t1, t6, 8U);
    xsi_set_current_line(101, ng0);
    t1 = (t0 + 3288U);
    t2 = *((char **)t1);
    t1 = (t2 + 0);
    *((unsigned char *)t1) = (unsigned char)2;
    goto LAB56;

LAB58:    t1 = (t0 + 3288U);
    t5 = *((char **)t1);
    t10 = *((unsigned char *)t5);
    t12 = (t10 == (unsigned char)3);
    t3 = t12;
    goto LAB60;

LAB61:    xsi_set_current_line(104, ng0);
    t1 = (t0 + 4856);
    t6 = (t1 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t11 = *((char **)t8);
    *((unsigned char *)t11) = (unsigned char)1;
    xsi_driver_first_trans_fast(t1);
    goto LAB62;

LAB64:    t1 = (t0 + 3288U);
    t5 = *((char **)t1);
    t10 = *((unsigned char *)t5);
    t12 = (t10 == (unsigned char)2);
    t3 = t12;
    goto LAB66;

LAB67:    xsi_set_current_line(106, ng0);
    t1 = (t0 + 4664);
    t6 = (t1 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t11 = *((char **)t8);
    *((unsigned char *)t11) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(107, ng0);
    t1 = (t0 + 4856);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);
    goto LAB62;

LAB69:    t1 = (t0 + 3288U);
    t5 = *((char **)t1);
    t10 = *((unsigned char *)t5);
    t12 = (t10 == (unsigned char)3);
    t3 = t12;
    goto LAB71;

}


extern void work_a_0342691397_2193661277_init()
{
	static char *pe[] = {(void *)work_a_0342691397_2193661277_p_0};
	xsi_register_didat("work_a_0342691397_2193661277", "isim/bin.sim/work/a_0342691397_2193661277.didat");
	xsi_register_executes(pe);
}
