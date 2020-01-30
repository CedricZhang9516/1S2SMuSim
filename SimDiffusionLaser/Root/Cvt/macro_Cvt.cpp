#include "macro_Cvt.h"

void macro_Cvt(){

	t = new CvtMusr();
	/*
	t->Loop(15, 0, 3,"./FromDline_musr_0508_11.dat");
	t->Loop(-20, 0, 3,"./FromDline_musr_0508_12.dat");
	t->Loop(-15, 0, 3,"./FromDline_musr_0508_13.dat");
	t->Loop(-10, 0, 3,"./FromDline_musr_0508_14.dat");
	t->Loop(-5, 0, 3,"./FromDline_musr_0508_15.dat");

	t->Loop(0, 15, 3,"./FromDline_musr_0508_21.dat");
	t->Loop(0, 10, 3,"./FromDline_musr_0508_22.dat");
	t->Loop(0, 7, 3,"./FromDline_musr_0508_23.dat");
	t->Loop(0, 3, 3,"./FromDline_musr_0508_24.dat");
	t->Loop(0, 2, 3,"./FromDline_musr_0508_25.dat");
	t->Loop(0, 1.5, 3,"./FromDline_musr_0508_26.dat");
	t->Loop(0, 1, 3,"./FromDline_musr_0508_27.dat");
	t->Loop(0, 0.5, 3,"./FromDline_musr_0508_28.dat");
	t->Loop(0, 0, 3,"./FromDline_musr_0508_29.dat");

	t->Loop(0, -15, 3,"./FromDline_musr_0508_30.dat");
	t->Loop(0, -10, 3,"./FromDline_musr_0508_31.dat");
	t->Loop(0, -7, 3,"./FromDline_musr_0508_32.dat");
	t->Loop(0, -3, 3,"./FromDline_musr_0508_33.dat");
	t->Loop(0, -2, 3,"./FromDline_musr_0508_34.dat");
	t->Loop(0, -1.5, 3,"./FromDline_musr_0508_35.dat");
	t->Loop(0, -1, 3,"./FromDline_musr_0508_36.dat");
	t->Loop(0, -0.5, 3,"./FromDline_musr_0508_37.dat");

	t->Loop(0, 0, 1,"./FromDline_musr_0508_41.dat");
	t->Loop(0, 0, 3,"./FromDline_musr_0508_42.dat");
	t->Loop(0, 0, 4,"./FromDline_musr_0508_43.dat");
	t->Loop(0, 0, 5,"./FromDline_musr_0508_44.dat");
	*/
	//t->Loop(0, 0, 0,"./FromDline_musr_0508_50.dat");
/*
	t->Loop(-20	,0,	3,"./FromDline_musr_0521_1.dat");
	t->Loop(-18	,0,	3,"./FromDline_musr_0521_2.dat");
	t->Loop(-16	,0,	3,"./FromDline_musr_0521_3.dat");
	t->Loop(-14	,0,	3,"./FromDline_musr_0521_4.dat");
	t->Loop(-12	,0,	3,"./FromDline_musr_0521_5.dat");
	t->Loop(-10	,0,	3,"./FromDline_musr_0521_6.dat");
	t->Loop(-8	,0,	3,"./FromDline_musr_0521_7.dat");
	t->Loop(-6	,0,	3,"./FromDline_musr_0521_8.dat");
	t->Loop(-4	,0,	3,"./FromDline_musr_0521_9.dat");
	t->Loop(-2	,0,	3,"./FromDline_musr_0521_10.dat");
	t->Loop(-1	,0,	3,"./FromDline_musr_0521_11.dat");
	t->Loop(0	,0,	3,"./FromDline_musr_0521_12.dat");
	t->Loop(1	,0,	3,"./FromDline_musr_0521_13.dat");
	t->Loop(2	,0,	3,"./FromDline_musr_0521_14.dat");
	t->Loop(4	,0,	3,"./FromDline_musr_0521_15.dat");
	t->Loop(6	,0,	3,"./FromDline_musr_0521_16.dat");
	t->Loop(8	,0,	3,"./FromDline_musr_0521_17.dat");
	t->Loop(10	,0,	3,"./FromDline_musr_0521_18.dat");
	t->Loop(12	,0,	3,"./FromDline_musr_0521_19.dat");
	t->Loop(14	,0,	3,"./FromDline_musr_0521_20.dat");
	t->Loop(16	,0,	3,"./FromDline_musr_0521_21.dat");
	t->Loop(18	,0,	3,"./FromDline_musr_0521_22.dat");
	t->Loop(20	,0,	3,"./FromDline_musr_0521_23.dat");
*/

/*
t->Loop(0,	-10	,3,"./FromDline_musr_0521_24.dat");
t->Loop(0,	-8	,3,"./FromDline_musr_0521_25.dat");
t->Loop(0,	-6	,3,"./FromDline_musr_0521_26.dat");
t->Loop(0,	-4	,3,"./FromDline_musr_0521_27.dat");
t->Loop(0,	-3	,3,"./FromDline_musr_0521_28.dat");
t->Loop(0,	-2.5	,3,"./FromDline_musr_0521_29.dat");
t->Loop(0,	-2.0	,3,"./FromDline_musr_0521_30.dat");
t->Loop(0,	-1.6	,3,"./FromDline_musr_0521_31.dat");
t->Loop(0,	-1.4	,3,"./FromDline_musr_0521_32.dat");
t->Loop(0,	-1.2	,3,"./FromDline_musr_0521_33.dat");
t->Loop(0,	-1	,3,"./FromDline_musr_0521_34.dat");
t->Loop(0,	-0.8	,3,"./FromDline_musr_0521_35.dat");
t->Loop(0,	-0.6	,3,"./FromDline_musr_0521_36.dat");
t->Loop(0,	-0.4	,3,"./FromDline_musr_0521_37.dat");
t->Loop(0,	-0.2	,3,"./FromDline_musr_0521_38.dat");
t->Loop(0,	0	,3,"./FromDline_musr_0521_39.dat");
t->Loop(0,	0.2	,3,"./FromDline_musr_0521_40.dat");
t->Loop(0,	0.4	,3,"./FromDline_musr_0521_41.dat");
t->Loop(0,	0.6	,3,"./FromDline_musr_0521_42.dat");
t->Loop(0,	0.8	,3,"./FromDline_musr_0521_43.dat");
t->Loop(0,	1	,3,"./FromDline_musr_0521_44.dat");
t->Loop(0,	1.2	,3,"./FromDline_musr_0521_45.dat");
t->Loop(0,	1.4	,3,"./FromDline_musr_0521_46.dat");
t->Loop(0,	1.6	,3,"./FromDline_musr_0521_47.dat");
t->Loop(0,	2.0	,3,"./FromDline_musr_0521_48.dat");
t->Loop(0,	2.5	,3,"./FromDline_musr_0521_49.dat");
t->Loop(0,	3	,3,"./FromDline_musr_0521_50.dat");
t->Loop(0,	4	,3,"./FromDline_musr_0521_51.dat");
t->Loop(0,	6	,3,"./FromDline_musr_0521_52.dat");
t->Loop(0,	8	,3,"./FromDline_musr_0521_53.dat");
t->Loop(0,	10	,3,"./FromDline_musr_0521_54.dat");
t->Loop(0,	0	,1,"./FromDline_musr_0521_55.dat");
t->Loop(0,	0	,2,"./FromDline_musr_0521_56.dat");
t->Loop(0,	0	,3,"./FromDline_musr_0521_57.dat");
t->Loop(0,	0	,4,"./FromDline_musr_0521_58.dat");
t->Loop(0,	0	,5,"./FromDline_musr_0521_59.dat");
*/

t->Loop(-10,	0	,3,"./FromDline_musr_0618_00.dat");
t->Loop(-6,	0	,3,"./FromDline_musr_0618_01.dat");

t->Loop(-4,	0	,3,"./FromDline_musr_0618_02.dat");
t->Loop(-2,	0	,3,"./FromDline_musr_0618_03.dat");
t->Loop(0,	0	,3,"./FromDline_musr_0618_04.dat");
t->Loop(2,	0	,3,"./FromDline_musr_0618_05.dat");
t->Loop(4,	0	,3,"./FromDline_musr_0618_06.dat");
t->Loop(6,	0	,3,"./FromDline_musr_0618_07.dat");
t->Loop(10,	0	,3,"./FromDline_musr_0618_08.dat");

}

