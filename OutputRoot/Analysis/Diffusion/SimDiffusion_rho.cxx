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

double PI = 3.1415926;
double light = 299792458; // m/s
double massMu = 106.16/light/light; // MeV/c2, 1.1811893e-15;
const double mmu = 105.658;

static constexpr int nRhos = 17;
const int fNPoints = 201;
int i = 0;

TH1D * hcount = new TH1D("hcount","hcount",200,0,200);
TH1D * hxdev = new TH1D("hcount","hcount",200,0,100);

TRandom3 *r = new TRandom3();

double GenerateUniform(double ti,double tf,int seed = 0){

    
    //double r = gRandom->Uniform(ti,tf);
    //cout<<"seed "<<r->GetSeed()<<" "<<r<<endl;
    return r->Uniform(ti,tf);
}

void SimDiffusion_rho2(int seed){


	h[i] = new TH1D(Form("%s_%s",hname.c_str(),hname2[i].c_str()),Form("%s_%s",hname.c_str(),hname2[i].c_str()),100,0,2);
	for(i = 1; i<4; i++){
		//h[i] = new TH1D(Form("%s_%s",hname.c_str(),hname2[i].c_str()),Form("%s_%s",hname.c_str(),hname2[i].c_str()),2000,-1e-5,1e-5);
    h[i] = new TH1D(Form("%s_%s",hname.c_str(),hname2[i].c_str()),Form("%s_%s",hname.c_str(),hname2[i].c_str()),200,-0.05,0.45);
	}
  //h[4] = new TH1D(Form("%s_%s",hname.c_str(),hname2[4].c_str()),Form("%s_%s",hname.c_str(),hname2[4].c_str()),400,-0.0004,0.004);
  h[4] = new TH1D(Form("%s_%s",hname.c_str(),hname2[4].c_str()),Form("%s_%s",hname.c_str(),hname2[4].c_str()),400,-0.0004,1.0);

	//hyz = new TH2D("hyz","ZY_distribution;Z[mm];Y[mm]",100,0,60,200,-60,60);
  //hxy = new TH2D("hxy","XY_distribution;X[mm];Y[mm]",200,-60,60,200,-60,60);
  hyz = new TH2D("hyz","ZY_distribution;Z[mm];Y[mm]",50,0,10,100,-10,10);
  hxy = new TH2D("hxy","XY_distribution;X[mm];Y[mm]",200,-60,60,100,-10,10);
	
  hxxp = new TH2D("hxxp","XXp;X(mm);X'",100,-100,100,100,-2,2);
	hyyp = new TH2D("hyyp","YYp;Y(mm);Y'",100,-100,100,100,-2,2);

  tp_3 = new TProfile("tp_3","N_tot population_2S_rho[3]; time (us); N",220,0,2.2e-6,0,1);
  tp_4 = new TProfile("tp_4","N_tot population_ion_rho[4]; time (us); N",220,0,2.2e-6,0,1);

  //tp2d_yz = new TProfile2D("tp2d_yz","Weighted_ZY_distribution {>1e-10}; z[mm]; y[mm]",100,0,60,200,-60,60,0,1);
  //tp2d_xy = new TProfile2D("tp2d_xy","Weighted_XY_distribution {>1e-10}; x[mm]; y[mm]",200,-60,60,200,-60,60,0,1);

  tp2d_yz = new TProfile2D("tp2d_yz","Weighted_ZY_distribution {>1e-10}; z[mm]; y[mm]",50,0,10,100,-10,10,0,1);
  //tp2d_yz = new TProfile2D("tp2d_yz","Weighted_ZY_distribution ; z[mm]; y[mm]",50,0,10,100,-10,10,0,1);
  tp2d_xy = new TProfile2D("tp2d_xy","Weighted_XY_distribution {>1e-10}; x[mm]; y[mm]",100,-10,10,100,-10,10,0,1);
  //tp2d_xy = new TProfile2D("tp2d_xy","Weighted_XY_distribution ; x[mm]; y[mm]",100,-10,10,100,-10,10,0,1);

  //tp_yz = new TProfile("tp_yz","Weighted; z[mm]; y[mm]",200,-100,100,200,-100,100);
  //tp_xy = new TProfile("tp_xy","Weighted; y[mm]; x[mm]",200,-100,100,200,-100,100);

	
  //TFile * f = new TFile("../../test0_1.1.root");
  

  //TFile * f = new TFile("../../0511_test_1.3_0.root");string name = "../../0511_test_1.3_0";//88
  //TFile * f = new TFile("../../0522_1.3_0.01J.root");string name = "../../0522_1.3_0.01J";//101
  //TFile * f = new TFile("../../0522_1.3_0.05J.root");string name = "../../0522_1.3_0.05J";//164
  //TFile * f = new TFile("../../0522_1.3_0.1J.root");string name = "../../0522_1.3_0.1J";//320
  //TFile * f = new TFile("../../0514_1.3_0.5J.root");string name = "../../0514_1.3_0.5J";//1392
  //TFile * f = new TFile("../../0522_1.3_0.8J.root");string name = "../../0522_1.3_0.8J";//1392
  //TFile * f = new TFile("../../0522_1.3_1.0J.root");string name = "../../0522_1.3_1.0J";//1392
  TFile * f = new TFile("../../0522_1.3_1.0J.root");string name = "../../0717_1.3_1.0J_Source_straight_CUT38mm";//1392
  //TFile * f = new TFile("../../0522_1.3_5.0J.root");string name = "../../0522_1.3_5.0J";//1392
  //TFile * f = new TFile("../../0522_1.3_5.0J.root");string name = "../../0522_1.3_10.0J";//1392
  //TFile * f = new TFile("../../0522_1.3_20.0J.root");string name = "../../0522_1.3_20.0J";//1392
  //TFile * f = new TFile("../../0522_1.3_50.0J.root");string name = "../../0522_1.3_50.0J";//1392

  //TFile * f = new TFile("../../0612_1.4_0.005J_000V.root");string name = "../../0612_1.4_0.005J_000V";//88
  //TFile * f = new TFile("../../0613_1.4_0.005J_060V.root");string name = "../../0613_1.4_0.005J_060V";//88
  
  
  
  
  //TFile * f = new TFile("../../test0_1.1.root");
  //TFile * f = new TFile("../../test0_1.1.root");
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
  t->SetBranchAddress( "FinalAbsVelocity", &fFinalAbsVelocity );
	
  //t->SetBranchAddress("Time",fTime);
	//t->SetBranchAddress("Rho",fRho);
	
  //fTree->Branch( "FinalRho", fFinalRho, "FinalRho[5]/D" );


  TFile newfile("Ion.root", "recreate");
  auto newtree = t->CloneTree(0);
	
	double min1 = 1, max1 = 0;
	double min2 = 0, max2 = 0;
  double Rho1s, Rho2s, Rho2p1, Rho2p2, RhoIon;

  double RanProb = 0;
  int Ncount = 0;
  //string output = "0523_test0_1.3_20.0J.dat";
  string output = name+".dat";
  //string output = "0523_test0_1.3_0.005J.dat";
  //string tmp2= seed;
  //string output = "0528CUT_0.005J_"+std::to_string(seed)+".dat";
  ofstream wf(output.c_str());

  //r->SetSeed(i);
  //cout<<"seed "<<r->GetSeed()<<endl;
  //gRandom->SetSeed();

	const int nEntries = t->GetEntries();

	for( int entry=0; entry<nEntries; entry++ ){
		t->GetEntry( entry );

    Rho1s = fFinalRho[0];
    Rho2s = fFinalRho[2];
    Rho2p1 = fFinalRho[1];
    Rho2p2 = fFinalRho[3];
    RhoIon = fFinalRho[16];

    double LaserE = 0.5 * massMu * 1e-6 * fFinalAbsVelocity*fFinalAbsVelocity;// (VX_sf*VX_sf + VY_sf*VY_sf + VZ_sf*VZ_sf);//v:mm/s, Ek: MeV
    //LaserE = 20.0e-3;//MeV, = 20 keV
    double g = 1.0*(mmu+LaserE)/mmu;
    double b = 1.0*sqrt(2.0*LaserE*mmu+LaserE*LaserE)/(mmu+LaserE);

    //debug
    /*
    cout<<"fFinalAbsVelocity "<<fFinalAbsVelocity<<endl //mm/s
    <<"LaserE "<<LaserE<<endl
    <<"fFinalTime "<<fFinalTime<<endl //s // actual: s
    <<"fFinalPos[0] "<<fFinalPos[0]<<endl // mm
    <<"xp "<<fFinalVelocity[0]/fFinalVelocity[2]<<endl; //
		*/

    if(RhoIon>max1)max1=RhoIon;
		if(RhoIon>0 && RhoIon<min1)min1=RhoIon;

		if(Rho1s>max2)max2=Rho1s;
		if(Rho1s>0 && Rho1s<min2)min2=Rho1s;
		
		h[0]->Fill(Rho1s);
    h[1]->Fill(Rho2p1);
    h[2]->Fill(Rho2s);
    h[3]->Fill(Rho2p2);
    //h[4]->Fill(RhoIon);

    if(RhoIon >= -1){ 
    //if(RhoIon >= 1e-10){
      
/*
      tp2d_xy->Fill(fFinalPos[0],fFinalPos[1],RhoIon);
      tp2d_yz->Fill(fFinalPos[2],fFinalPos[1],RhoIon);
      h[4]->Fill(RhoIon);
*/

      //RanProb = GenerateUniform(0.0,0.00371048);//0.005J, 1000V
      //RanProb = GenerateUniform(0.0,0.0191688);//0.01J
      //RanProb = GenerateUniform(0.0,0.528871);//0.05J
      //RanProb = GenerateUniform(0.0,0.828992);//0.1J
      //RanProb = GenerateUniform(0.0,0.916161);//0.5J
      //RanProb = GenerateUniform(0.0,0.916593);//0.8J
      RanProb = GenerateUniform(0.0,0.91662);//1.0J
      //RanProb = GenerateUniform(0.0,0.93179);//5.0J
      //RanProb = GenerateUniform(0.0,0.938579);//10.0J
      //RanProb = GenerateUniform(0.0,0.940025);//20.0J
      //RanProb = r->Uniform(0.0,0.948469);//GenerateUniform(0.0,0.948469);//50.0J
      //cout<<"seed "<<r->GetSeed()<<endl;

      //RanProb = GenerateUniform(0.0,0.00616306);//0.005J, 300V
      //RanProb = GenerateUniform(0.0,0.00681045);//0.005J, 250V
      //RanProb = GenerateUniform(0.0,0.00760452);//0.005J, 200V
      //RanProb = GenerateUniform(0.0,0.0085198);//0.005J, 150V
      //RanProb = GenerateUniform(0.0,0.0094492);//0.005J, 100V
      //RanProb = GenerateUniform(0.0,0.0101801);//0.005J, 050V
      //RanProb = GenerateUniform(0.0,0.0104627);//0.005J, 000V

      
      
      if( RhoIon < RanProb)continue;

      if (abs(fFinalPos[0])>19)continue;

        newtree->Fill();
        Ncount++;
        
        //if(fFinalPos[0]>0){
        /*
        wf << fFinalPos[0]*0.1 << " "
        << fFinalVelocity[0]/fFinalVelocity[2]*1000 << " "
        << fFinalPos[1]*0.1 << " "
        << fFinalVelocity[1]/fFinalVelocity[2]*1000 << " "
        << mmu/1000*g*b << " "
        << fFinalPos[2] << " "
        << fFinalTime*1e9 << " "
        << "-1 -1" << endl;
        */
        //}
        
        wf << fFinalPos[0]*0.1 << " "
        << 0 << " "
        << fFinalPos[1]*0.1 << " "
        << 0 << " "
        << mmu/1000*g*b << " "
        << fFinalPos[2] << " "
        << fFinalTime*1e9 << " "
        << "-1 -1" << endl;
        
        tp2d_xy->Fill(fFinalPos[0],fFinalPos[1],RhoIon);
        tp2d_yz->Fill(fFinalPos[2],fFinalPos[1],RhoIon);

        //hxy->Fill(fFinalPos[0],fFinalPos[1],RhoIon);
        hxy->Fill(fFinalPos[0],fFinalPos[1]);
        //hyz->Fill(fFinalPos[2],fFinalPos[1],RhoIon);
        hyz->Fill(fFinalPos[2],fFinalPos[1]);

        //hxxp->Fill(fFinalPos[0],fFinalVelocity[0]/fFinalVelocity[2],RhoIon);
        hxxp->Fill(fFinalPos[0],fFinalVelocity[0]/fFinalVelocity[2]);
        //hyyp->Fill(fFinalPos[1],fFinalVelocity[1]/fFinalVelocity[2],RhoIon);
        hyyp->Fill(fFinalPos[1],fFinalVelocity[1]/fFinalVelocity[2]);

        h[4]->Fill(RhoIon);
      //}

    }


    double totRho = 0;
    totRho += fFinalRho[0] + fFinalRho[1] + fFinalRho[2] + fFinalRho[3] + fFinalRho[16];
    /*
    for(int j = 4; j<nRhos-1; j=j+2){
      totRho += sqrt(fFinalRho[j]*fFinalRho[j]+fFinalRho[j+1]*fFinalRho[j+1]);
    }
    */


  	//for(int j = 0; j<fNPoints; j++){
  		//tp->Fill(fTime[j],fRho[j][0]);
  		//tp->Fill(fTime[j],fRho[j][0]+fRho[j][1]+fRho[j][2]+fRho[j][3]+fRho[j][4]);
  		//tp_3->Fill(fTime[j],fRho[j][3]);
  		//tp_4->Fill(fTime[j],fRho[j][4]);
  		//cout<<fTime[j]<<" "<<fRho[j][0]<<endl;
  	//}

  	//hxy->Fill(fFinalPos[0],fFinalPos[1]);
  	

  }

  cout<<"Ion max "<<max1<<" "<<min1<<endl;
  cout<<"RanProb_Ncount "<<Ncount<<endl;
  hcount->Fill(Ncount);
  hxdev->Fill(hxy->GetStdDev());
  //cout<<max2<<" "<<min2<<endl;
  //cout<<h[4]->GetMean()<<endl;

  //newtree->Print();
  newfile.Write();
  cout<<"mean ion "<<h[4]->GetMean()<<endl;
  cout<<"x dev "<<hxy->GetStdDev()<<endl;
  //cout<<"seed "<<gRandom->GetSeed()<<endl;
 


  gStyle->SetPalette(56);

  TCanvas *c5 = new TCanvas("c5","c5",1200,600);
  c5->Divide(2,1);
  c5->cd(1);
  hxy->SetTitle("XY_distribution_weighted");
  hxy->Draw("colz");
  c5->cd(2);
  hyz->SetTitle("ZY_distribution_weighted");
  hyz->Draw("colz");
  TEllipse *ee = new TEllipse(3,0,1);
  ee->SetFillColorAlpha(0,0);
  ee->SetLineColor(3);
  ee->Draw();
  TLine *ll;
  c5->cd(1);
  ll = new TLine(-60,1,60,1);
  ll->SetLineColor(3);
  ll->Draw();
  ll = new TLine(-60,-1,60,-1);
  ll->SetLineColor(3);
  ll->Draw();

  c5->SaveAs(Form("%s_1.pdf",name.c_str()));


  TCanvas *c3 = new TCanvas("c3","c3",1200,1000);
  
  TPad *pad1 = new TPad("pad1", "The pad 40 of the height",0.0,0.6,1.0,1.0);
  TPad *pad2 = new TPad("pad2", "The pad 60 of the height",0.0,0.0,1.0,0.6);

  pad1->Divide(3,1);
  pad1->SetLogy();
  pad2->Divide(3,3);


  //TCanvas *c5 = new TCanvas("c5","c5",1200,600);
	//c5->Divide(3,2);
  pad1->cd(1);
	//h[4]->SetTitle("Ionization probability_selected {>1e-10}; probability; N");
  h[4]->SetTitle("Ionization probability; probability; N");
  //gStyle->SetOptLogy(1);
  h[4]->Draw();
  
  //gStyle->SetOptLogy(0);
  //h[4]->GetYaxis()->SetTitleOffset(0.5);
  SetStyleHist1(h[4]);

  pad1->cd(2);
  hxy->SetTitle("XY_distribution_weighted");
  //hxy->SetTitle("XY_distribution");
  //SetStyleHist2(hxy);
  hxy->Draw("colz");

  //tp2d_xy->Draw("colz");
  pad1->cd(3);
  hyz->SetTitle("ZY_distribution_weighted");
  //hyz->SetTitle("ZY_distribution");
  //SetStyleHist2(hyz);
  hyz->Draw("colz");
  //tp2d_yz->Draw("colz");
  //hxxp->Draw("colz");
  //c4->cd(3);
  //hyyp->Draw("colz");
  pad1->cd(3);

  TEllipse *e = new TEllipse(3,0,1);
  e->SetFillColorAlpha(0,0);
  e->SetLineColor(3);
  e->Draw();
  TLine *l;
  pad1->cd(2);
  l = new TLine(-60,1,60,1);
  l->SetLineColor(3);
  l->Draw();
  l = new TLine(-60,-1,60,-1);
  l->SetLineColor(3);
  l->Draw();


  const TCut selection = "FinalRho[16]>1e-10";
  //const TCut selection = "";

  pad2->cd(1);
  SetStyleHist2(hxxp);
  hxxp->Draw("colz");
  //t->Draw("FinalPosition[0]:FinalVelocity[0]/FinalVelocity[2]",selection);
  //SetTitleTreeDraw("X-X';mm;rad");
  pad2->cd(2);
  SetStyleHist2(hyyp);
  hyyp->Draw("colz");
  //t->Draw("FinalPosition[1]:FinalVelocity[1]/FinalVelocity[2]",selection);
  //SetTitleTreeDraw("Y-Y';mm;rad");
  pad2->cd(3);
  //t->Draw("0.5 * 106.16 * 1e-6 * FinalAbsVelocity*FinalAbsVelocity/299792458/299792458",selection);
  newtree->Draw("0.5 * 106.16 * 1e-6 * FinalAbsVelocity*FinalAbsVelocity/299792458/299792458",selection);
  //newtree->Draw("0.5 * 106.16 * 1e-6 * FinalAbsVelocity*FinalAbsVelocity",selection);
  SetTitleTreeDraw("Ek;MeV/c2;N");  

  pad2->cd(3+1);
//	t->Draw("FinalVelocity[0]",selection);
  newtree->Draw("FinalVelocity[0]",selection);
  SetTitleTreeDraw("Vx_laser;mm/s;N");
  pad2->cd(3+2);
  //t->Draw("FinalVelocity[1]",selection);
  newtree->Draw("FinalVelocity[1]",selection);
  SetTitleTreeDraw("Vy_laser;mm/s;N");
  pad2->cd(3+3);
  //t->Draw("FinalVelocity[2]",selection);
  newtree->Draw("FinalVelocity[2]",selection);
  SetTitleTreeDraw("Vz_laser;mm/s;N");
  //tp_3->Draw();
	pad2->cd(3+4);
	//tp_4->Draw();
  //t->Draw("FinalPosition[0]",selection);
  newtree->Draw("FinalPosition[0]",selection);
  SetTitleTreeDraw("X_laser;mm;N");
  pad2->cd(3+5);
  //tp_4->Draw();
  //t->Draw("FinalPosition[1]",selection);
  newtree->Draw("FinalPosition[1]",selection);
  SetTitleTreeDraw("Y_laser;mm;N");
  pad2->cd(3+6);
  //tp_4->Draw();
  //t->Draw("FinalPosition[2]",selection);
  newtree->Draw("FinalPosition[2]",selection);
  SetTitleTreeDraw("Z_laser;mm;N");




	//TCanvas *c4 = new TCanvas("c4","c4",1200,1200);
	//c4->Divide(2,1);


  c3->cd();
  pad1->Draw();
  pad2->Draw();

  c3->SaveAs(Form("%s_2.pdf",name.c_str()));


}

void SimDiffusion_rho(){
  for(int i = 10; i<11;  i++)SimDiffusion_rho2(i);
  //SimDiffusion_rho2(0);
    //hcount->Draw();
    //hxdev->Draw();

  
}
