#include "macro_MCP.h"



void macro_MCP(){

	for (int i = 1; i<2;i++){
	//	t = new AccTest_Input(Form("../../0508_totpoint/musr_0508_%i",id[i]));
		//t = new AccTest_Input(Form("../../0508_totpoint_x/musr_0508_%i",i));
		t = new AccTest_Input(Form("../../0510_point/musr_0510_1"));
		
		t->Loop(i);
	}
	
	
		


}