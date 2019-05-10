#include "/Users/zhangce/WorkArea/CZhang/CZhang.cxx"
#define AccTest_Input_cxx
#define DEBUG

#include "AccTest_Input.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>


//const double det_pos_z = -266.6;

void AccTest_Input::Loop(int I)
{
//   In a ROOT session, you can do:
//      Root > .L AccTest_Input.C
//      Root > AccTest_Input t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   //Set parameters start
   const int N = 280;// number of array for save_par
   double prev_x =-9999;
   double prev_z =-9999;
   
   //Open an output file
   //ofstream outfile(output.c_str());
   
   // constants
   //const int DET_ID       = 958;//Best focus poit : z =-300
   //const int DET_ID       = 918;//958;//Best focus poit : z =-300
   
 
 
   const int PID          = -13;//muon
   const double RFQbore   = 3.7;//mm
   
   //histogarms for the check
   const int Nhist = 6;
   
   const double xmin = -1000;
   const double xmax =  1000;
   const double xbin =  1000;

   const double amin = -0.08;
   const double amax =  0.08;
   const double abin =  20;
   const string XTitle[Nhist] = {"X[mm]", "X[mm]", "Y[mm]", "X[mm]","X[mm]","Y[mm]"};
   //const string YTitle[Nhist] = {"Y[mm]", "p_{x}/p_{z}", "p_{y}/p_{z}", "Y[mm]","p_{x}/p_{z}","p_{y}/p_{z}"}; 
   const string YTitle[Nhist] = {"Y[mm]", "X'", "Y'", "Y[mm]","X'","Y'"}; 
   
   const string fH_Name[Nhist] = {
    "X-Y",
    "X-pxpz",
    "Y-pypz",
    "X-Y cut",
    "X-pxpz cut",
    "Y-pypz cut"
    };

  TH1F * hT = new TH1F("ht",Form("Kinetic E_%i; MeV; Events",I),100,0.000001,0.025);

  TH2F*  hist[Nhist];
  
  for( int i = 0 ; i < Nhist ; i++ ){

    if(i==3){
      hist[i] = new TH2F(fH_Name[i].c_str(),fH_Name[i].c_str(),
			 30, -2000, 1000,
			 40, -2000, 2000);      
    }
    if(i==5){
      hist[i] = new TH2F(fH_Name[i].c_str(),fH_Name[i].c_str(),
       200, -100, 100,
       abin*2, amin*2, amax*2);      
    }

  }//for Nhist

   hist[0] = new TH2F(fH_Name[0].c_str(),fH_Name[0].c_str(),200, -100, 100, 200, -100, 100);      
    //hist[0] = new TH2F(fH_Name[0].c_str(),fH_Name[0].c_str(),100, -30, 30, 100, -10, 10);      
    hist[1] = new TH2F(fH_Name[1].c_str(),fH_Name[1].c_str(),800, -100, 100,abin*2, amin*2, amax*2);      
    //hist[1] = new TH2F(fH_Name[1].c_str(),fH_Name[1].c_str(),100, -30, 30,abin*2, amin*2, amax*2);      
    //hist[2] = new TH2F(fH_Name[2].c_str(),fH_Name[2].c_str(),800, -20, 20, 100, -0.01,0.01);
    hist[2] = new TH2F(fH_Name[2].c_str(),fH_Name[2].c_str(),800, -20, 20, 100, -1.0,1.0);
    //hist[2] = new TH2F(fH_Name[2].c_str(),fH_Name[2].c_str(),100, -10, 10, 100, -0.01,0.01);
    hist[4] = new TH2F(fH_Name[4].c_str(),fH_Name[4].c_str(),40, -10, 10,100, -1,1);  


    const int DET_ID       = 920;//914;//920;//918;//958;//Best focus poit : z =-300
    //920: MCP
    //914: EQ4 exit
    const double det_pos_x = -475;//MCP
    //const double det_pos_x = 780;//Initial X
    const double det_pos_z = 622;
    //const double det_pos_z = 0;





    //Set parameters end

    Long64_t nentries = fChain->GetEntriesFast();
    cout<<"nentries "<<nentries<<endl;

    Long64_t nbytes = 0, nb = 0;
    for (Long64_t jentry=0; jentry<nentries;jentry++) {
    //for (Long64_t jentry=0; jentry<100000;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
       
       nb = fChain->GetEntry(jentry);   nbytes += nb;
       // if (Cut(ientry) < 0) continue;

       //counter
	 if( jentry%10 == 0 ){
	   //cout<<"jentry : "<<jentry<<endl;
	 }


       //Initialization
       double T  = -9999;
       double px = -9999;
       double py = -9999;
       double pz = -9999;
       double x  = -9999;
       double y  = -9999;
       double z  = -9999;

       ///routine start
       for( int i = 0 ; i < N ; i++ ){       

	 if( save_detID[i]==DET_ID && save_particleID[i]==PID ){//DET_ID & PID
	   //	     cout<<"test2 : "<<save_z[i]<<"\t"<<i<<endl;
	   //if( save_z[i] < (det_pos_z + 1.) && save_z[i] > (det_pos_z - 1.) ){//focus point ID

	     //	    if( (save_z[i]-878)**2+save_y[i]**2<441 ){//MCPreal size cut

	       if(prev_x==save_x[i]&&prev_z==save_z[i])continue;//Identify a new event

	       //	       cout<<"jentry : "<<jentry<<" save_x : "<<save_x[i]<<" i : "<<i<<endl;
	       //	    cout<<save_x[i]<<"\t"<<save_z[i]<<endl;
	       //	    cin.get();
	       
	       //Get parameters
	       //	       T  = 7.5*1E-3;//MeV
	       T  = save_ke[i];//MeV

         px = save_px[i];
         py = save_py[i];
         pz = save_pz[i];
         x  = save_x[i]-det_pos_x;
         
         y  = save_y[i];
         z  = save_z[i]-det_pos_z;
	       //cout<<z<<endl;
         //cout<<x<<endl;



	       //Fill hist for checking
	       hist[0]   -> Fill( x, y     );//cout<<1<<endl;
         //hist[0]   -> Fill( z, y     );//cout<<1<<endl;
	       
         hist[1]   -> Fill( x, px/pz );
         //hist[1]   -> Fill( z, pz/px );
	       hist[2]   -> Fill( y, py/pz );
         //hist[2]   -> Fill( y, py/px );
         hT->Fill(T);

	       if( x*x+y*y < RFQbore*RFQbore*2){//bore cut
		 hist[3]   -> Fill( x, y     );
		 hist[4]   -> Fill( x, px/pz );
		 hist[5]   -> Fill( y, py/pz );
	       }
	       
	       //Record previous value	      
	       prev_x = save_x[i];
	       prev_z = save_z[i];

	       //	    cout<<save_n<<endl;
	       //	    end = true;
	       break;
	       //	  }//if	

	   //cnt++;	  

	   //}//if : focus point ID
	 }//if : DET_ID && PID
       }//for : i

       //      if(end)break;

       //routine end

    }//jentry

    //Close a file
   //outfile.close();

#ifdef DEBUG
   //gStyle->SetOptStat(0);
  TCanvas* c1 = new TCanvas("c1","c_check",800,800);
  c1->Divide(2,2);
  for( int i = 1 ; i < 4 ; i++ ){
    c1->cd(i+1);
    c1->cd(i+1)->SetGrid();
    hist[i-1]   -> GetYaxis()->SetTitleOffset(1.2);
    hist[i-1]   -> SetXTitle(XTitle[i-1].c_str());
    hist[i-1]   -> SetYTitle(YTitle[i-1].c_str());
    hist[i-1]   -> Draw("COLZ");    
  }//for //Nhist
  gStyle->SetPalette(1);
  c1->cd(1);SetstyleHist1(hT);hT->Draw();

  c1->SaveAs(Form("%s.png",input2.c_str()));
#endif


}
