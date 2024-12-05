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
static const char *ng0 = "/home/gaut/Documents/GitHub/UART_VHDL/UART_Emission/RxTester.vhd";



static void work_a_2944787698_2372691052_p_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    int64 t7;
    int64 t8;

LAB0:    t1 = (t0 + 4024U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(113, ng0);
    t2 = (t0 + 4848);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(114, ng0);
    t2 = (t0 + 2928U);
    t3 = *((char **)t2);
    t7 = *((int64 *)t3);
    t8 = (t7 / 2);
    t2 = (t0 + 3832);
    xsi_process_wait(t2, t8);

LAB6:    *((char **)t1) = &&LAB7;

LAB1:    return;
LAB4:    xsi_set_current_line(115, ng0);
    t2 = (t0 + 4848);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(116, ng0);
    t2 = (t0 + 2928U);
    t3 = *((char **)t2);
    t7 = *((int64 *)t3);
    t8 = (t7 / 2);
    t2 = (t0 + 3832);
    xsi_process_wait(t2, t8);

LAB10:    *((char **)t1) = &&LAB11;
    goto LAB1;

LAB5:    goto LAB4;

LAB7:    goto LAB5;

LAB8:    goto LAB2;

LAB9:    goto LAB8;

LAB11:    goto LAB9;

}

static void work_a_2944787698_2372691052_p_1(char *t0)
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
    int t10;
    int t11;
    int t12;
    int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    char *t17;
    char *t18;
    char *t19;
    int64 t20;

LAB0:    t1 = (t0 + 4272U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(128, ng0);
    t3 = (100 * 1000LL);
    t2 = (t0 + 4080);
    xsi_process_wait(t2, t3);

LAB6:    *((char **)t1) = &&LAB7;

LAB1:    return;
LAB4:    xsi_set_current_line(130, ng0);
    t2 = (t0 + 4912);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(135, ng0);
    t2 = (t0 + 4976);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(136, ng0);

LAB10:    t2 = (t0 + 4592);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB11;
    goto LAB1;

LAB5:    goto LAB4;

LAB7:    goto LAB5;

LAB8:    t4 = (t0 + 4592);
    *((int *)t4) = 0;
    xsi_set_current_line(139, ng0);
    t2 = (t0 + 4976);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(140, ng0);

LAB14:    t2 = (t0 + 4608);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB15;
    goto LAB1;

LAB9:    t4 = (t0 + 1032U);
    t5 = *((char **)t4);
    t8 = *((unsigned char *)t5);
    t9 = (t8 == (unsigned char)3);
    if (t9 == 1)
        goto LAB8;
    else
        goto LAB10;

LAB11:    goto LAB9;

LAB12:    t4 = (t0 + 4608);
    *((int *)t4) = 0;
    xsi_set_current_line(143, ng0);
    t2 = (t0 + 7912);
    t5 = (t0 + 3048U);
    t6 = *((char **)t5);
    t5 = (t6 + 0);
    memcpy(t5, t2, 8U);
    xsi_set_current_line(144, ng0);
    t2 = (t0 + 7920);
    *((int *)t2) = 7;
    t4 = (t0 + 7924);
    *((int *)t4) = 0;
    t10 = 7;
    t11 = 0;

LAB16:    if (t10 >= t11)
        goto LAB17;

LAB19:    xsi_set_current_line(149, ng0);

LAB31:    t2 = (t0 + 4656);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB32;
    goto LAB1;

LAB13:    t4 = (t0 + 1032U);
    t5 = *((char **)t4);
    t8 = *((unsigned char *)t5);
    t9 = (t8 == (unsigned char)2);
    if (t9 == 1)
        goto LAB12;
    else
        goto LAB14;

LAB15:    goto LAB13;

LAB17:    xsi_set_current_line(145, ng0);

LAB22:    t5 = (t0 + 4624);
    *((int *)t5) = 1;
    *((char **)t1) = &&LAB23;
    goto LAB1;

LAB18:    t2 = (t0 + 7920);
    t10 = *((int *)t2);
    t4 = (t0 + 7924);
    t11 = *((int *)t4);
    if (t10 == t11)
        goto LAB19;

LAB28:    t12 = (t10 + -1);
    t10 = t12;
    t5 = (t0 + 7920);
    *((int *)t5) = t10;
    goto LAB16;

LAB20:    t6 = (t0 + 4624);
    *((int *)t6) = 0;
    xsi_set_current_line(146, ng0);
    t2 = (t0 + 3048U);
    t4 = *((char **)t2);
    t2 = (t0 + 7920);
    t12 = *((int *)t2);
    t13 = (t12 - 7);
    t14 = (t13 * -1);
    xsi_vhdl_check_range_of_index(7, 0, -1, *((int *)t2));
    t15 = (1U * t14);
    t16 = (0 + t15);
    t5 = (t4 + t16);
    t8 = *((unsigned char *)t5);
    t6 = (t0 + 4976);
    t7 = (t6 + 56U);
    t17 = *((char **)t7);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    *((unsigned char *)t19) = t8;
    xsi_driver_first_trans_fast(t6);
    xsi_set_current_line(147, ng0);

LAB26:    t2 = (t0 + 4640);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB27;
    goto LAB1;

LAB21:    t6 = (t0 + 1032U);
    t7 = *((char **)t6);
    t8 = *((unsigned char *)t7);
    t9 = (t8 == (unsigned char)3);
    if (t9 == 1)
        goto LAB20;
    else
        goto LAB22;

LAB23:    goto LAB21;

LAB24:    t4 = (t0 + 4640);
    *((int *)t4) = 0;
    goto LAB18;

LAB25:    t4 = (t0 + 1032U);
    t5 = *((char **)t4);
    t8 = *((unsigned char *)t5);
    t9 = (t8 == (unsigned char)2);
    if (t9 == 1)
        goto LAB24;
    else
        goto LAB26;

LAB27:    goto LAB25;

LAB29:    t4 = (t0 + 4656);
    *((int *)t4) = 0;
    xsi_set_current_line(152, ng0);
    t2 = (t0 + 4976);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(153, ng0);

LAB35:    t2 = (t0 + 4672);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB36;
    goto LAB1;

LAB30:    t4 = (t0 + 1032U);
    t5 = *((char **)t4);
    t8 = *((unsigned char *)t5);
    t9 = (t8 == (unsigned char)3);
    if (t9 == 1)
        goto LAB29;
    else
        goto LAB31;

LAB32:    goto LAB30;

LAB33:    t4 = (t0 + 4672);
    *((int *)t4) = 0;
    xsi_set_current_line(157, ng0);
    t2 = (t0 + 2928U);
    t4 = *((char **)t2);
    t3 = *((int64 *)t4);
    t20 = (t3 * 10);
    t2 = (t0 + 4080);
    xsi_process_wait(t2, t20);

LAB39:    *((char **)t1) = &&LAB40;
    goto LAB1;

LAB34:    t4 = (t0 + 1032U);
    t5 = *((char **)t4);
    t8 = *((unsigned char *)t5);
    t9 = (t8 == (unsigned char)2);
    if (t9 == 1)
        goto LAB33;
    else
        goto LAB35;

LAB36:    goto LAB34;

LAB37:    xsi_set_current_line(161, ng0);
    t2 = (t0 + 4976);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(162, ng0);

LAB43:    t2 = (t0 + 4688);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB44;
    goto LAB1;

LAB38:    goto LAB37;

LAB40:    goto LAB38;

LAB41:    t4 = (t0 + 4688);
    *((int *)t4) = 0;
    xsi_set_current_line(166, ng0);
    t2 = (t0 + 4976);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(167, ng0);

LAB47:    t2 = (t0 + 4704);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB48;
    goto LAB1;

LAB42:    t4 = (t0 + 1032U);
    t5 = *((char **)t4);
    t8 = *((unsigned char *)t5);
    t9 = (t8 == (unsigned char)3);
    if (t9 == 1)
        goto LAB41;
    else
        goto LAB43;

LAB44:    goto LAB42;

LAB45:    t4 = (t0 + 4704);
    *((int *)t4) = 0;
    xsi_set_current_line(171, ng0);
    t2 = (t0 + 7928);
    t5 = (t0 + 3048U);
    t6 = *((char **)t5);
    t5 = (t6 + 0);
    memcpy(t5, t2, 8U);
    xsi_set_current_line(172, ng0);
    t2 = (t0 + 7936);
    *((int *)t2) = 0;
    t4 = (t0 + 7940);
    *((int *)t4) = 7;
    t10 = 0;
    t11 = 7;

LAB49:    if (t10 <= t11)
        goto LAB50;

LAB52:    xsi_set_current_line(178, ng0);

LAB64:    t2 = (t0 + 4752);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB65;
    goto LAB1;

LAB46:    t4 = (t0 + 1032U);
    t5 = *((char **)t4);
    t8 = *((unsigned char *)t5);
    t9 = (t8 == (unsigned char)2);
    if (t9 == 1)
        goto LAB45;
    else
        goto LAB47;

LAB48:    goto LAB46;

LAB50:    xsi_set_current_line(173, ng0);

LAB55:    t5 = (t0 + 4720);
    *((int *)t5) = 1;
    *((char **)t1) = &&LAB56;
    goto LAB1;

LAB51:    t2 = (t0 + 7936);
    t10 = *((int *)t2);
    t4 = (t0 + 7940);
    t11 = *((int *)t4);
    if (t10 == t11)
        goto LAB52;

LAB61:    t12 = (t10 + 1);
    t10 = t12;
    t5 = (t0 + 7936);
    *((int *)t5) = t10;
    goto LAB49;

LAB53:    t6 = (t0 + 4720);
    *((int *)t6) = 0;
    xsi_set_current_line(174, ng0);
    t2 = (t0 + 3048U);
    t4 = *((char **)t2);
    t2 = (t0 + 7936);
    t12 = *((int *)t2);
    t13 = (t12 - 7);
    t14 = (t13 * -1);
    xsi_vhdl_check_range_of_index(7, 0, -1, *((int *)t2));
    t15 = (1U * t14);
    t16 = (0 + t15);
    t5 = (t4 + t16);
    t8 = *((unsigned char *)t5);
    t6 = (t0 + 4976);
    t7 = (t6 + 56U);
    t17 = *((char **)t7);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    *((unsigned char *)t19) = t8;
    xsi_driver_first_trans_fast(t6);
    xsi_set_current_line(175, ng0);

LAB59:    t2 = (t0 + 4736);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB60;
    goto LAB1;

LAB54:    t6 = (t0 + 1032U);
    t7 = *((char **)t6);
    t8 = *((unsigned char *)t7);
    t9 = (t8 == (unsigned char)3);
    if (t9 == 1)
        goto LAB53;
    else
        goto LAB55;

LAB56:    goto LAB54;

LAB57:    t4 = (t0 + 4736);
    *((int *)t4) = 0;
    goto LAB51;

LAB58:    t4 = (t0 + 1032U);
    t5 = *((char **)t4);
    t8 = *((unsigned char *)t5);
    t9 = (t8 == (unsigned char)2);
    if (t9 == 1)
        goto LAB57;
    else
        goto LAB59;

LAB60:    goto LAB58;

LAB62:    t4 = (t0 + 4752);
    *((int *)t4) = 0;
    xsi_set_current_line(182, ng0);
    t2 = (t0 + 4976);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(183, ng0);

LAB68:    t2 = (t0 + 4768);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB69;
    goto LAB1;

LAB63:    t4 = (t0 + 1032U);
    t5 = *((char **)t4);
    t8 = *((unsigned char *)t5);
    t9 = (t8 == (unsigned char)3);
    if (t9 == 1)
        goto LAB62;
    else
        goto LAB64;

LAB65:    goto LAB63;

LAB66:    t4 = (t0 + 4768);
    *((int *)t4) = 0;
    xsi_set_current_line(187, ng0);

LAB72:    *((char **)t1) = &&LAB73;
    goto LAB1;

LAB67:    t4 = (t0 + 1032U);
    t5 = *((char **)t4);
    t8 = *((unsigned char *)t5);
    t9 = (t8 == (unsigned char)2);
    if (t9 == 1)
        goto LAB66;
    else
        goto LAB68;

LAB69:    goto LAB67;

LAB70:    goto LAB2;

LAB71:    goto LAB70;

LAB73:    goto LAB71;

}


extern void work_a_2944787698_2372691052_init()
{
	static char *pe[] = {(void *)work_a_2944787698_2372691052_p_0,(void *)work_a_2944787698_2372691052_p_1};
	xsi_register_didat("work_a_2944787698_2372691052", "isim/bin.sim/work/a_2944787698_2372691052.didat");
	xsi_register_executes(pe);
}
