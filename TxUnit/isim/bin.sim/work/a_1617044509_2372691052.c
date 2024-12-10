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
static const char *ng0 = "/home/ccy6321/Documents/S7/Archi/UART_VHDL/TxUnit/testTxUnit.vhd";



static void work_a_1617044509_2372691052_p_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    int64 t7;
    int64 t8;

LAB0:    t1 = (t0 + 3584U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(103, ng0);
    t2 = (t0 + 4248);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(104, ng0);
    t2 = (t0 + 2608U);
    t3 = *((char **)t2);
    t7 = *((int64 *)t3);
    t8 = (t7 / 2);
    t2 = (t0 + 3392);
    xsi_process_wait(t2, t8);

LAB6:    *((char **)t1) = &&LAB7;

LAB1:    return;
LAB4:    xsi_set_current_line(105, ng0);
    t2 = (t0 + 4248);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(106, ng0);
    t2 = (t0 + 2608U);
    t3 = *((char **)t2);
    t7 = *((int64 *)t3);
    t8 = (t7 / 2);
    t2 = (t0 + 3392);
    xsi_process_wait(t2, t8);

LAB10:    *((char **)t1) = &&LAB11;
    goto LAB1;

LAB5:    goto LAB4;

LAB7:    goto LAB5;

LAB8:    goto LAB2;

LAB9:    goto LAB8;

LAB11:    goto LAB9;

}

static void work_a_1617044509_2372691052_p_1(char *t0)
{
    char *t1;
    char *t2;
    int64 t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned char t8;
    unsigned char t9;
    unsigned char t10;
    unsigned char t11;
    unsigned char t12;
    unsigned char t13;
    unsigned char t14;
    unsigned char t15;
    unsigned char t16;
    char *t17;
    unsigned char t18;
    unsigned char t19;
    char *t20;

LAB0:    t1 = (t0 + 3832U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(114, ng0);
    t3 = (100 * 1000LL);
    t2 = (t0 + 3640);
    xsi_process_wait(t2, t3);

LAB6:    *((char **)t1) = &&LAB7;

LAB1:    return;
LAB4:    xsi_set_current_line(115, ng0);
    t2 = (t0 + 4312);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(117, ng0);
    t3 = (200 * 1000LL);
    t2 = (t0 + 3640);
    xsi_process_wait(t2, t3);

LAB10:    *((char **)t1) = &&LAB11;
    goto LAB1;

LAB5:    goto LAB4;

LAB7:    goto LAB5;

LAB8:    xsi_set_current_line(120, ng0);
    t2 = (t0 + 2152U);
    t4 = *((char **)t2);
    t9 = *((unsigned char *)t4);
    t10 = (t9 == (unsigned char)3);
    if (t10 == 1)
        goto LAB15;

LAB16:    t8 = (unsigned char)0;

LAB17:    t13 = (!(t8));
    if (t13 != 0)
        goto LAB12;

LAB14:
LAB13:    xsi_set_current_line(125, ng0);
    t2 = (t0 + 2608U);
    t4 = *((char **)t2);
    t3 = *((int64 *)t4);
    t2 = (t0 + 3640);
    xsi_process_wait(t2, t3);

LAB27:    *((char **)t1) = &&LAB28;
    goto LAB1;

LAB9:    goto LAB8;

LAB11:    goto LAB9;

LAB12:    xsi_set_current_line(121, ng0);

LAB20:    t2 = (t0 + 4152);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB21;
    goto LAB1;

LAB15:    t2 = (t0 + 2312U);
    t5 = *((char **)t2);
    t11 = *((unsigned char *)t5);
    t12 = (t11 == (unsigned char)3);
    t8 = t12;
    goto LAB17;

LAB18:    t6 = (t0 + 4152);
    *((int *)t6) = 0;
    goto LAB13;

LAB19:    t6 = (t0 + 2152U);
    t7 = *((char **)t6);
    t15 = *((unsigned char *)t7);
    t16 = (t15 == (unsigned char)3);
    if (t16 == 1)
        goto LAB22;

LAB23:    t14 = (unsigned char)0;

LAB24:    if (t14 == 1)
        goto LAB18;
    else
        goto LAB20;

LAB21:    goto LAB19;

LAB22:    t6 = (t0 + 2312U);
    t17 = *((char **)t6);
    t18 = *((unsigned char *)t17);
    t19 = (t18 == (unsigned char)3);
    t14 = t19;
    goto LAB24;

LAB25:    xsi_set_current_line(127, ng0);
    t2 = (t0 + 7056);
    t5 = (t0 + 4376);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t17 = (t7 + 56U);
    t20 = *((char **)t17);
    memcpy(t20, t2, 8U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(128, ng0);
    t2 = (t0 + 4440);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(133, ng0);
    t2 = (t0 + 2152U);
    t4 = *((char **)t2);
    t9 = *((unsigned char *)t4);
    t10 = (t9 == (unsigned char)3);
    if (t10 == 1)
        goto LAB32;

LAB33:    t8 = (unsigned char)0;

LAB34:    t13 = (!(t8));
    if (t13 != 0)
        goto LAB29;

LAB31:
LAB30:    xsi_set_current_line(136, ng0);
    t2 = (t0 + 2608U);
    t4 = *((char **)t2);
    t3 = *((int64 *)t4);
    t2 = (t0 + 3640);
    xsi_process_wait(t2, t3);

LAB44:    *((char **)t1) = &&LAB45;
    goto LAB1;

LAB26:    goto LAB25;

LAB28:    goto LAB26;

LAB29:    xsi_set_current_line(134, ng0);

LAB37:    t2 = (t0 + 4168);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB38;
    goto LAB1;

LAB32:    t2 = (t0 + 2312U);
    t5 = *((char **)t2);
    t11 = *((unsigned char *)t5);
    t12 = (t11 == (unsigned char)2);
    t8 = t12;
    goto LAB34;

LAB35:    t6 = (t0 + 4168);
    *((int *)t6) = 0;
    goto LAB30;

LAB36:    t6 = (t0 + 2152U);
    t7 = *((char **)t6);
    t15 = *((unsigned char *)t7);
    t16 = (t15 == (unsigned char)3);
    if (t16 == 1)
        goto LAB39;

LAB40:    t14 = (unsigned char)0;

LAB41:    if (t14 == 1)
        goto LAB35;
    else
        goto LAB37;

LAB38:    goto LAB36;

LAB39:    t6 = (t0 + 2312U);
    t17 = *((char **)t6);
    t18 = *((unsigned char *)t17);
    t19 = (t18 == (unsigned char)2);
    t14 = t19;
    goto LAB41;

LAB42:    xsi_set_current_line(137, ng0);
    t2 = (t0 + 4440);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(146, ng0);

LAB48:    *((char **)t1) = &&LAB49;
    goto LAB1;

LAB43:    goto LAB42;

LAB45:    goto LAB43;

LAB46:    goto LAB2;

LAB47:    goto LAB46;

LAB49:    goto LAB47;

}


extern void work_a_1617044509_2372691052_init()
{
	static char *pe[] = {(void *)work_a_1617044509_2372691052_p_0,(void *)work_a_1617044509_2372691052_p_1};
	xsi_register_didat("work_a_1617044509_2372691052", "isim/bin.sim/work/a_1617044509_2372691052.didat");
	xsi_register_executes(pe);
}
