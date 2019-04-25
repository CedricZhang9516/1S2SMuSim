#include "/Users/zhangce/WorkArea/CZhang/CZhang.cxx"

using namespace std;

TH1D * h[5];
TH2D * hxy;
TH2D * hxxp;
TH2D * hyyp;

void SimDiffusion_rho(){

	std::string hname = "FinalRho";

  std::string hname2[5] = {"1s1/2", "2p1/2", "2s1/2", "2p3/2", "ion"};
	
  int i = 0;

  static constexpr int nRhos = 17;
  const int fNPoints = 201;

	h[i] = new TH1D(Form("%s_%s",hname.c_str(),hname2[i].c_str()),Form("%s_%s",hname.c_str(),hname2[i].c_str()),100,0,2);
	for(i = 1; i<5; i++){
		h[i] = new TH1D(Form("%s_%s",hname.c_str(),hname2[i].c_str()),Form("%s_%s",hname.c_str(),hname2[i].c_str()),2000,-1e-5,1e-5);
	}

	hxy = new TH2D("hxy","beam size XY;X(mm);Y(mm)",200,-100,100,200,-100,100);
	hxxp = new TH2D("hxxp","XXp;X(mm);X'",100,-100,100,100,-2,2);
	hyyp = new TH2D("hyyp","YYp;Y(mm);Y'",100,-100,100,100,-2,2);

	//TFile * f = new TFile("./test.root");
	//TFile * f = new TFile("./Detail_output_0.root");
	//TFile * f = new TFile("./output_0.root");

	//TFile * f = new TFile("./Detail_output_0410_0.root");
	
  //TFile * f = new TFile("../output0424_0.root");
  TFile * f = new TFile("../output_hline_repro_0.root");

	//TFile * f = new TFile("./No_Tsf/Detail_output_0.root");
	//TFile * f = new TFile("output_0410_0.root");
	//TFile * f = new TFile("./output0410_0.root");
	//TFile * f = new TFile("./test_900.root");
	TTree * t = (TTree*) f->Get("MuTree");

	//TCanvas *c2 = new TCanvas("c2","c2",800,800);
	//t->Draw( "FinalRho[][0]+FinalRho[][3]+FinalRho[][4]:FinalTime", "", "L");
	//t->Draw( "FinalRho[][4]:FinalTime", "", "");
	//t->Draw( "Rho[][0]+Rho[][3]+Rho[][4]:Time", "", "L");
	//t->Draw( "Rho[][0]:Time", "", "");


	//std::array<double,5> Rho;
	//std::array<double,nRhos> FinalRho;
	
  double *fTime;     // (t) array
  double (*fRho)[nRhos];

  double fFinalTime;
  double fFinalPos[3];
  double fFinalVelocity[3];
  double fFinalAbsVelocity;
  double fFinalRho[nRhos];

  fTime = new double[fNPoints]();
  fRho = new double[fNPoints][nRhos]();

	t->SetBranchAddress("FinalRho",&fFinalRho);
	t->SetBranchAddress("FinalTime",&fFinalTime);
	t->SetBranchAddress( "FinalPosition", fFinalPos );
	//t->SetBranchAddress( "FinalTime", &fFinalTime );
	t->SetBranchAddress( "FinalVelocity", fFinalVelocity );
	
  //t->SetBranchAddress("Time",fTime);
	//t->SetBranchAddress("Rho",fRho);
	
  //fTree->Branch( "FinalRho", fFinalRho, "FinalRho[5]/D" );

	TProfile * tp_3 = new TProfile("","N_tot population_2S_rho[3]; time (us); N",220,0,2.2e-6,0,1);
	TProfile * tp_4 = new TProfile("","N_tot population_ion_rho[4]; time (us); N",220,0,2.2e-6,0,1);

	double min1 = 1, max1 = 0;
	double min2 = 0, max2 = 0;
  double Rho1s, Rho2s, Rho2p1, Rho2p2, RhoIon;


	const int nEntries = t->GetEntries();
  	for( int entry=0; entry<nEntries; entry++ ){
  		t->GetEntry( entry );

      Rho1s = fFinalRho[0];
      Rho2s = fFinalRho[2];
      Rho2p1 = fFinalRho[1];
      Rho2p2 = fFinalRho[3];
      RhoIon = fFinalRho[16];

  		//cout<<Rho[3]<<Rho[4]<<" "<<FinalTime<<endl;
  		
      if(RhoIon>max1)max1=RhoIon;
  		if(RhoIon>0 && RhoIon<min1)min1=RhoIon;

  		if(Rho1s>max2)max2=Rho1s;
  		if(Rho1s>0 && Rho1s<min2)min2=Rho1s;
  		
      //cout<<Rho[0]<<" "<<Rho[1]<<" "<<Rho[2]<<" "<<Rho[3]<<" "<<Rho[4]<<endl;
  		h[0]->Fill(Rho1s);
      h[1]->Fill(Rho2p1);
      h[2]->Fill(Rho2s);
      h[3]->Fill(Rho2p2);
      //if(RhoIon>1.0e-9)
        h[4]->Fill(RhoIon);

      double totRho = 0;
      totRho += fFinalRho[0] + fFinalRho[1] + fFinalRho[2] + fFinalRho[3] + fFinalRho[16];
      for(int j = 4; j<nRhos-1; j=j+2){
        totRho += sqrt(fFinalRho[j]*fFinalRho[j]+fFinalRho[j+1]*fFinalRho[j+1]);
      }
      //cout<<"tot Rho "<< Rho1s + Rho2s + Rho2p1 + Rho2p2 + RhoIon<<" "<<totRho<<endl;

      /*
      for(int j = 0; j<5; j++){
    		if(fFinalRho[j]>=4.94066e-324)
    	}
      */

    	for(int j = 0; j<fNPoints; j++){
    		//tp->Fill(fTime[j],fRho[j][0]);
    		//tp->Fill(fTime[j],fRho[j][0]+fRho[j][1]+fRho[j][2]+fRho[j][3]+fRho[j][4]);
    		//tp_3->Fill(fTime[j],fRho[j][3]);
    		//tp_4->Fill(fTime[j],fRho[j][4]);
    		//cout<<fTime[j]<<" "<<fRho[j][0]<<endl;
    	}

    	hxy->Fill(fFinalPos[0],fFinalPos[1]);
    	hxxp->Fill(fFinalPos[0],fFinalVelocity[0]/fFinalVelocity[2]);
    	hyyp->Fill(fFinalPos[1],fFinalVelocity[1]/fFinalVelocity[2]);

      cout<<"tot cal "<<totRho<<endl;
    }

    cout<<max1<<" "<<min1<<endl;
    cout<<max2<<" "<<min2<<endl;
    cout<<h[4]->GetMean()<<endl;
    
	
	TCanvas *c = new TCanvas("c","c",2000,400);
  	c->Divide(5,1);
  	//c->Divide(3,1);
  	for (int i = 1; i<6; i++){c->cd(i);SetstyleHist1(h[i-1]);h[i-1]->Draw();}
  	//c->cd(1);h[0]->Draw();
  	//c->cd(2);h[3]->Draw();
  	//c->cd(3);h[4]->Draw();
  	TCanvas *c3 = new TCanvas("c3","c3",800,400);
  	c3->Divide(2,1);
  	c3->cd(1);
  	tp_3->Draw();
  	c3->cd(2);
  	tp_4->Draw();

  	TCanvas *c4 = new TCanvas("c4","c4",1200,400);
  	c4->Divide(3,1);
  	c4->cd(1);
  	hxy->Draw("colz");

  	c4->cd(2);
  	hxxp->Draw("colz");

  	c4->cd(3);
  	hyyp->Draw("colz");



}



