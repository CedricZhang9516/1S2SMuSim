#include <iostream>
using namespace std;

void readdatax(string t);
void readdatay(string t);
void readdataz(string t);
void readdata2(string t);

void readdata(){



	//readdatax("point_source;shift_x [mm];MeanX [mm]");
	//readdatax("point_source;shift_x [mm];MeanY [mm]");
	readdatay("point_source;shift_y [mm];MeanX [mm]");
	//readdatay("point_source;shift_y [mm];MeanY [mm]");
	//readdataz("point_source;shift_z [mm];MeanX [mm]");
	//readdataz("point_source;shift_z [mm];MeanY [mm]");
	//readdata2("point_source;shift_z [mm];MeanY [mm]");
	//gPad->SetGrid();

}

void readdatax(string t){
	//ifstream k("data_z.txt");//4
	//ifstream k("data_x2.txt");//9
	ifstream k("data_nocut.txt");//9
	//ifstream k("data_y.txt");//17
	string  x,	y,	z, EX, EY, EZ;
	double  x_, y_,	z_, EX_, EY_, EZ_;
	double E_, Ep_;
	
	int i = 0;
	
	//TH3F * h3 = new TH3F("h","z",68,-34,34,68,-34,34,48,-12,12);
	TH3F * h3 = new TH3F("h","z",34,-34,34,34,-34,34,24,-12,12);
	TProfile2D *p1 = new TProfile2D("p1","p1",68,-34,34,68,-34,34,-12,12);
	TProfile2D *p2 = new TProfile2D("p2","p2",68,-34,34,68,-34,34,-12,12);
	TProfile2D *p3 = new TProfile2D("p3","p3",68,-34,34,68,-34,34,-12,12);
	TProfile2D *p4 = new TProfile2D("p4","p4",68,-34,34,68,-34,34,-12,12);
	
	TH2D *h4 = new TH2D("h4","h4,abs",68,-34,34,68,-34,34);
	TH2D *h5 = new TH2D("h5","h5",68,-34,34,68,-34,34);
	TH2D *h6 = new TH2D("h6","h6,>0",68,-34,34,68,-34,34);
	TH2D *h7 = new TH2D("h7","h7,<0",68,-34,34,68,-34,34);
	
	TH1D *h8 = new TH1D("h8","h8,abs",100,0,1);

	//TH1F * h = new TH1F("h","z",10,0,1);
	TGraph * g = new TGraph();
	TGraph * g2 = new TGraph();
	
	while(i<20){

		k>>x;//>>y>>z>>EX>>EY>>EZ;//refer;
		//z>>z_;
		x_ = std::atof(x.c_str());
		

		//MeanX_ = std::atof(MeanX.c_str());
		//MeanY_ = std::atof(MeanY.c_str());
		//MeanX>>MeanX_;
		//g->SetPoint(i,x_,MeanX_);
		//g->SetPoint(i,x_,MeanY_);
		//g->SetPoint(i,x_,y_);
		//g2->SetPoint(i,MeanX_,MeanY_);
		//E_ = sqrt(EX_*EX_ + EY_*EY_ + EZ_*EZ_);
		//Ep_ = sqrt(EX_*EX_ + EY_*EY_);
		//h3->Fill(x_,y_,z_,abs(EZ_));
		
		//p1->Fill(x_,y_,z_,EZ_);
		//p2->Fill(x_,y_,z_,abs(EZ_));
		
		//if(z_>0)h6->Fill(x_,y_,EZ_);
		//if(z_<0)h7->Fill(x_,y_,EZ_);
		h8->Fill(x_);
		//if(z_ == 0.0)p4->Fill(x_,y_,z_);//p4->Fill(x_,y_,z_,EZ_);
		
		

		i++;
	}

	TCanvas *c = new TCanvas("c","c",600,600);
	h8->Draw("");
	//c->Divide(2,1);
	//c->cd(1);
	//h3->DrawNormalized("lego");
	//g->SetTitle(t.c_str());
	//g->Draw("AP*L");
	//c->cd(2);

}

void readdatay(string t){
	//ifstream k("data_z.txt");//4
	//ifstream k("data_x.txt");//9
	//ifstream k("data_y2.txt");//17
	ifstream k("eventN.txt");//17
	string  x,	y,	z, Bx, By, Bz;// MeanY, refer;
	double  x_,	y_,	z_, Bx_, By_, Bz_;

	TH2D *h4 = new TH2D("h4","h4,abs",100,-200,200,200,-400,400);
	TH2D *h5 = new TH2D("h5","h5,abs",100,-200,200,200,-400,400);
	TH2D *h6 = new TH2D("h6","h6,abs",200,-400,400,25,-50,50);

	int i = 0;
	//TH1F * h = new TH1F("h","z",10,0,1);
	TGraph * g = new TGraph();
	TGraph * g2 = new TGraph();

	TF1 *f1 = new TF1("f1","[0]*TMath::Log(x)+[1]",0,50);
	TF1 *f2 = new TF1("f2","[0]*TMath::Log(x)+[1]",0,50);
   	
	
	while(i<11){

		k>>x>>y>>z;//>>EX>>EY>>EZ;//refer;
		//z>>z_;
		x_ = std::atof(x.c_str());
		y_ = std::atof(y.c_str());
		z_ = std::atof(z.c_str());
		

		//MeanX_ = std::atof(MeanX.c_str());
		//MeanY_ = std::atof(MeanY.c_str());
		//MeanX>>MeanX_;
		g->SetPoint(i,x_,y_);
		//g->SetPoint(i,x_,MeanY_);
		g2->SetPoint(i,x_,z_);
		//g2->SetPoint(i,MeanX_,MeanY_);
		//E_ = sqrt(EX_*EX_ + EY_*EY_ + EZ_*EZ_);
		//Ep_ = sqrt(EX_*EX_ + EY_*EY_);
		//h3->Fill(x_,y_,z_,abs(EZ_));
		
		//p1->Fill(x_,y_,z_,EZ_);
		//p2->Fill(x_,y_,z_,abs(EZ_));
		
		//if(z_>0)h6->Fill(x_,y_,EZ_);
		//if(z_<0)h7->Fill(x_,y_,EZ_);
		//h8->Fill(x_);
		//if(z_ == 0.0)p4->Fill(x_,y_,z_);//p4->Fill(x_,y_,z_,EZ_);
		
		

		i++;
	}

	TCanvas *c = new TCanvas("c","c",1000,500);
	c->Divide(2,1);
	c->cd(1);
	g->SetTitle("events selected using dice; Intensity [J]; N");
	g->Draw("AP*L");
	g->Fit("f1","L");
	f1->Draw("same");
	//h6->Draw("colz");
	c->cd(2);
	g2->SetTitle("events transported to MCP; Intensity [J]; N");
	g2->Draw("AP*L");
	g2->Fit("f2","L");
	f2->Draw("same");
	//h5->Draw("colz");

}

void readdataz(string t){
	ifstream k("eventN.txt");//4
	//ifstream k("data_x.txt");//9
	//ifstream k("data_y.txt");//17
	string  x,	y,	z, MeanX, MeanY, refer;
	double  x_,	y_,	z_, MeanX_, MeanY_, refer_;
	
	int i = 0;
	TH1F * h = new TH1F("h","z",10,0,1);
	TGraph * g = new TGraph();
	
	while(i<5){
		k>>x>>y>>z>>MeanX>>MeanY>>refer;
		//z>>z_;
		z_ = std::atof(z.c_str());
		MeanX_ = std::atof(MeanX.c_str());
		MeanY_ = std::atof(MeanY.c_str());
		//MeanX>>MeanX_;
		//g->SetPoint(i,z_,MeanX_);
		g->SetPoint(i,z_,MeanY_);
		//cout<<z_<<MeanY_<<endl;
		i++;
	}

	g->SetTitle(t.c_str());
	g->Draw("AP*L");

}

void readdata2(string t){
	//ifstream k("data_z.txt");//4
	ifstream k2("data2.txt");//9
	ifstream k("data3.txt");//9
	//ifstream k("data_y.txt");//17
	string  x,	y,	z, MeanX, MeanY, refer;
	double  x_,y_,	z_, MeanX_, MeanY_, refer_;
	
	int i = 0;
	TH1F * h = new TH1F("h","z",10,0,1);
	TGraph * g = new TGraph();
	TGraph * g0 = new TGraph();
	TGraph * g2 = new TGraph();
	TGraph * g3 = new TGraph();
	
	while(i<9){
		k>>x>>y>>z>>MeanX>>MeanY>>refer;
		//z>>z_;
		x_ = std::atof(x.c_str());
		y_ = std::atof(y.c_str());
		MeanX_ = std::atof(MeanX.c_str());
		MeanY_ = std::atof(MeanY.c_str());
		//MeanX>>MeanX_;
		g->SetPoint(i,x_,y_);
		g2->SetPoint(i,MeanX_,MeanY_);
		g0->SetPoint(2*i,MeanX_,MeanY_);

		k2>>x>>y>>z>>MeanX>>MeanY>>refer;
		x_ = std::atof(x.c_str());
		y_ = std::atof(y.c_str());
		MeanX_ = std::atof(MeanX.c_str());
		MeanY_ = std::atof(MeanY.c_str());
		g3->SetPoint(i,MeanX_,MeanY_);		
		g0->SetPoint(2*i+1,MeanX_,MeanY_);

		i++;
	}
	//g->SetPoint(i,0,0);
	//g2->SetPoint(i,6.62248,-1.12181);
	TCanvas *c = new TCanvas("c","c",1000,500);
	c->Divide(2,1);
	//g->SetTitle(t.c_str());
	c->cd(1);
	g->Draw("AP*");
	//g->SetTitle(t.c_str());
	c->cd(2);
	//TAxis *axis = g2->GetXaxis();
	//g2->GetXaxis()->SetLimits(-12,20);

	//c->Update(); 
	//g2->GetHistogram()->SetMaximum(20);   // along          
   	//g2->GetHistogram()->SetMinimum(-12);
	//g2->GetXaxis()->SetLimits(-12,20);
	g0->Draw("AP*");
	g2->Draw("sameP*");
	//g3->SetMarkerColor(kRed);
	g3->Draw("sameP*");

}