#include "/Users/zhangce/WorkArea/CZhang/CZhang.cxx"

using namespace std;

TH1D * h[5];
TH2D * hxy;
TH2D * hyz;
TH2D * hxxp;
TH2D * hyyp;

TProfile * tp_3;// = new TProfile("","N_tot population_2S_rho[3]; time (us); N",220,0,2.2e-6,0,1);
TProfile * tp_4;// = new TProfile("","N_tot population_ion_rho[4]; time (us); N",220,0,2.2e-6,0,1);

TProfile2D * tp2d_xy;
TProfile2D * tp2d_yz;

TProfile * tp_xy;
TProfile * tp_yz;

std::string hname = "FinalRho";
std::string hname2[5] = {"1s1/2", "2p1/2", "2s1/2", "2p3/2", "ion"};

static constexpr int nRhos = 17;
const int fNPoints = 201;
int i = 0;

void SimDiffusion_rho(){


	h[i] = new TH1D(Form("%s_%s",hname.c_str(),hname2[i].c_str()),Form("%s_%s",hname.c_str(),hname2[i].c_str()),100,0,2);
	for(i = 1; i<4; i++){
		//h[i] = new TH1D(Form("%s_%s",hname.c_str(),hname2[i].c_str()),Form("%s_%s",hname.c_str(),hname2[i].c_str()),2000,-1e-5,1e-5);
    h[i] = new TH1D(Form("%s_%s",hname.c_str(),hname2[i].c_str()),Form("%s_%s",hname.c_str(),hname2[i].c_str()),200,-0.05,0.45);
	}
  h[4] = new TH1D(Form("%s_%s",hname.c_str(),hname2[4].c_str()),Form("%s_%s",hname.c_str(),hname2[4].c_str()),400,-0.0004,0.004);

	hyz = new TH2D("hyz","ZY_distribution;Z[mm];Y[mm]",100,0,60,200,-60,60);
  hxy = new TH2D("hxy","XY_distribution;X[mm];Y[mm]",200,-60,60,200,-60,60);
	hxxp = new TH2D("hxxp","XXp;X(mm);X'",100,-100,100,100,-2,2);
	hyyp = new TH2D("hyyp","YYp;Y(mm);Y'",100,-100,100,100,-2,2);

  tp_3 = new TProfile("tp_3","N_tot population_2S_rho[3]; time (us); N",220,0,2.2e-6,0,1);
  tp_4 = new TProfile("tp_4","N_tot population_ion_rho[4]; time (us); N",220,0,2.2e-6,0,1);

  tp2d_yz = new TProfile2D("tp2d_yz","Weighted_ZY_distribution; z[mm]; y[mm]",100,0,60,200,-60,60,0,1);
  tp2d_xy = new TProfile2D("tp2d_xy","Weighted_XY_distribution; x[mm]; y[mm]",200,-60,60,200,-60,60,0,1);

  //tp_yz = new TProfile("tp_yz","Weighted; z[mm]; y[mm]",200,-100,100,200,-100,100);
  //tp_xy = new TProfile("tp_xy","Weighted; y[mm]; x[mm]",200,-100,100,200,-100,100);

	
  TFile * f = new TFile("../../test0.root");
	TTree * t = (TTree*) f->Get("MuTree");
	
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
	t->SetBranchAddress( "FinalVelocity", fFinalVelocity );
	
  //t->SetBranchAddress("Time",fTime);
	//t->SetBranchAddress("Rho",fRho);
	
  //fTree->Branch( "FinalRho", fFinalRho, "FinalRho[5]/D" );

	
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
  		
      if(RhoIon>max1)max1=RhoIon;
  		if(RhoIon>0 && RhoIon<min1)min1=RhoIon;

  		if(Rho1s>max2)max2=Rho1s;
  		if(Rho1s>0 && Rho1s<min2)min2=Rho1s;
  		
  		h[0]->Fill(Rho1s);
      h[1]->Fill(Rho2p1);
      h[2]->Fill(Rho2s);
      h[3]->Fill(Rho2p2);
      //h[4]->Fill(RhoIon);

      //cout<<fFinalPos[1]<<" "<<fFinalPos[2]<<endl;
      if(sqrt((fFinalPos[2]-3)*(fFinalPos[2]-3)+fFinalPos[1]*fFinalPos[1])<1){
        hxy->Fill(fFinalPos[0],fFinalPos[1]);
        hyz->Fill(fFinalPos[2],fFinalPos[1]);

        tp2d_xy->Fill(fFinalPos[0],fFinalPos[1],RhoIon);
        tp2d_yz->Fill(fFinalPos[2],fFinalPos[1],RhoIon);

        h[4]->Fill(RhoIon);
      }


      double totRho = 0;
      totRho += fFinalRho[0] + fFinalRho[1] + fFinalRho[2] + fFinalRho[3] + fFinalRho[16];
      /*
      for(int j = 4; j<nRhos-1; j=j+2){
        totRho += sqrt(fFinalRho[j]*fFinalRho[j]+fFinalRho[j+1]*fFinalRho[j+1]);
      }
      */


    	for(int j = 0; j<fNPoints; j++){
    		//tp->Fill(fTime[j],fRho[j][0]);
    		//tp->Fill(fTime[j],fRho[j][0]+fRho[j][1]+fRho[j][2]+fRho[j][3]+fRho[j][4]);
    		//tp_3->Fill(fTime[j],fRho[j][3]);
    		//tp_4->Fill(fTime[j],fRho[j][4]);
    		//cout<<fTime[j]<<" "<<fRho[j][0]<<endl;
    	}

    	//hxy->Fill(fFinalPos[0],fFinalPos[1]);
    	hxxp->Fill(fFinalPos[0],fFinalVelocity[0]/fFinalVelocity[2]);
    	hyyp->Fill(fFinalPos[1],fFinalVelocity[1]/fFinalVelocity[2]);

    }

    cout<<max1<<" "<<min1<<endl;
    cout<<max2<<" "<<min2<<endl;
    cout<<h[4]->GetMean()<<endl;


  cout<<h[4]->GetMean()<<endl;
    
	
	TCanvas *c = new TCanvas("c","c",2000,400);
	c->Divide(5,1);
	for (int i = 1; i<6; i++){
    c->cd(i);
    //SetstyleHist1(h[i-1]);
    h[i-1]->Draw();
  }

  TCanvas *c3 = new TCanvas("c3","c3",800,800);
  c3->SetLogy();
  h[4]->SetTitle("Ionization probability_selected; probability; N");
  h[4]->Draw();

/*
  TCanvas *c3 = new TCanvas("c3","c3",800,400);
	c3->Divide(2,1);
	c3->cd(1);
	tp_3->Draw();
	c3->cd(2);
	tp_4->Draw();
*/
	TCanvas *c4 = new TCanvas("c4","c4",1200,1200);
	c4->Divide(2,1);
	c4->cd(1);
	//hxy->Draw("colz");
  tp2d_xy->DrawNormalized("colz");
	c4->cd(2);
  //hyz->Draw("colz");
  tp2d_yz->DrawNormalized("colz");
	//hxxp->Draw("colz");
	//c4->cd(3);
	//hyyp->Draw("colz");
  TEllipse *e = new TEllipse(3,0,1);
  e->SetFillColorAlpha(0,0);
  e->SetLineColor(2);
  e->Draw();

  TLine *l;
  /*
  l = new TLine(2,-100,2,100);
  l->Draw();
  l = new TLine(4,-100,4,100);
  l->Draw();
  */
  c4->cd(1);

  l = new TLine(-60,1,60,1);
  l->SetLineColor(2);
  l->Draw();
  l = new TLine(-60,-1,60,-1);
  l->SetLineColor(2);
  l->Draw();




}



