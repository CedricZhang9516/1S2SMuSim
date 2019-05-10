#include "macro_Dline.h"
//const double min_xy  = -300;
const double min_xy  = -100;
const double max_xy  =  300;
//const double max_xy  =  100;
//const double binw_xy =  2.0;
const double binw_xy =  2.0;
//const double binw_xy =  0.1;
const int    nbin_xy = (int)((max_xy-min_xy)/binw_xy);
//const double min_pt  = -0.2;
const double min_pt  = -0.3;
//const double max_pt  =  0.2;
const double max_pt  =  0.3;
const double binw_pt =  0.004;
const int    nbin_pt = (int)((max_pt-min_pt)/binw_pt);
//const double min_pt  = -0.2;
const double min_p  = 5;
//const double max_pt  =  0.2;
const double max_p  =  34;
const double binw_p =  0.2;
const int    nbin_p = (int)((max_pt-min_pt)/binw_pt);


void macro_Dline_(){

  c1 = new TCanvas("c1","c1",10,10,1200,1200);
  tl = new TLegend(0.6,0.6,0.76,0.85);

  c1->Divide(1,2);

  gx = new TGraph(Form("musr_dq2_0.56_x.txt"));gx->SetTitle("beam size evolution; z (mm); sigma_x(mm)");
  gy = new TGraph(Form("musr_dq2_0.56_y.txt"));gy->SetTitle("beam size evolution; z (mm); sigma_y(mm)");
  //tl->AddEntry(gx,Form("musr_dq2_0.56_dq4_1.056_dq5_0_default"));
  tl->AddEntry(gx,Form("musr_dq2_0.56_default"));

  
  //if(i == 0){
    c1->cd(1);
    gx->GetYaxis()->SetRangeUser(0,25);
    gx->Draw("apl*");
    //}
  //else {c1->cd(1);gx->Draw("l*");}
  c1->cd(2);
  gy->GetYaxis()->SetRangeUser(0,7);
  gy->Draw("apl*");
  
  


  const int size = 3;
  const int size2 = 4;
  
  string fname_[size]={
    //"musr_dq2_0.56",
    "musr_dq2_0.0",
    "musr_dq2_1.0",
    "musr_dq2_2.0"
  };

  string fname_2[size]={  
    "musr_dq2_0.0_0.0",
    "musr_dq2_0.0_0.056",
    "musr_dq2_0.0_1.556"
  };

  string fname_4[size2]={  
    "musr_dq2_0.0_0.0_1",
    "musr_dq2_0.0_1.056_1",
    "musr_dq2_0.56_1.056_1",
    "musr_dq2_2.0_1.056_1"
  };
    /*
    -rw-r--r--  1 zhangce  staff  409 Apr  1 15:37 musr_dq2_0.56_x.txt
-rw-r--r--  1 zhangce  staff  417 Apr  1 15:37 musr_dq2_0.56_y.txt
-rw-r--r--  1 zhangce  staff  406 Apr  1 15:51 musr_dq2_1.0_x.txt
-rw-r--r--  1 zhangce  staff  419 Apr  1 15:51 musr_dq2_1.0_y.txt
-rw-r--r--  1 zhangce  staff  407 Apr  2 12:13 musr_dq2_2.0_1.056_1_x.txt
-rw-r--r--  1 zhangce  staff  418 Apr  2 12:13 musr_dq2_2.0_1.056_1_y.txt
-rw-r--r--  1 zhangce  staff  412 Apr  1 15:57 musr_dq2_2.0_x.txt
-rw-r--r--  1 zhangce  staff  420 Apr  1 15:57 musr_dq2_2.0_y.txt
  };
  */

  for(int i = 0; i<size; i++){

    macro_Dline_2(fname_[i],i);
  }
  



  
  double zdet[6]={543.995,1164.11,2013.65,2403.72,3494.26,3657.22};
  for(int j = 0;j<6;j++){
    
    double tmp = zdet[j];
    linex = new TLine(tmp,0,tmp,gx->GetYaxis()->GetXmax());c1->cd(1); linex->Draw();
    liney = new TLine(tmp,0,tmp,gy->GetYaxis()->GetXmax());c1->cd(2); liney->Draw();
  }

  c1->cd(1);
    tl->Draw();


  c1->SaveAs("label_123.png");
  c1->SaveAs("label_123.pdf");
  c1->SaveAs("label_123.C");


}


void macro_Dline_2(string fname_, int i ){


  gx = new TGraph(Form("%s_x.txt",fname_.c_str()));
  gx->SetLineColor(ColorSet[i+1]);gx->SetMarkerColor(ColorSet[i+1]);
  gy = new TGraph(Form("%s_y.txt",fname_.c_str()));
  gy->SetLineColor(ColorSet[i+1]);gy->SetMarkerColor(ColorSet[i+1]);
  
  //if(i == 0){c1->cd(1);gx->Draw("apl*");}
  //else {
  c1->cd(1);gx->Draw("l*");
    //}
  c1->cd(2);gy->Draw("l*");
/*
  string fname_3[4]={  
    "musr_dq2_0.0_dq4_0.0_dq5_1",
    "musr_dq2_0.0_dq4_1.056_dq5_1",
    "musr_dq2_0.56_dq4_1.056_dq5_1",
    "musr_dq2_2.0_dq4_1.056_dq5_1"
  };
*/
    string fname_3[3]={  
    "musr_dq2_0.0_dq4_0.0",
    "musr_dq2_0.0_dq4_0.056",
    "musr_dq2_0.0_dq4_1.556"
  };


  //tl->AddEntry(gx,Form("%s",fname_3[i].c_str()));
  tl->AddEntry(gx,Form("%s",fname_.c_str()));


}


void macro_Dline(string fname_=""){

  string fname = //fname_; //"mlf_d2_10101401.root";
  //"mlf_d2_10101401_ns.root";
  //"mlf_d2_10101401_notime_e.root";
//"mlf_d2_190302_0_notime";                  
//"mlf_d2_190302_1_ns.root";                      
//"mlf_d2_190302_2_notime.root";                  
//"mlf_d2_190302_3_ns";                      
//"mlf_d2_190302_4_notime.root";                  
//"mlf_d2_190302_5_ns.root";                      
//"mlf_d2_190302_6_notime.root";   
//"mlf_d2_190302_7_ns";           
    //"mlf_d2_190303_notime";   
    //"mlf_d2_190303_ns";   
    //"mlf_d2_190305_notime";
    //"mlf_d2_190305_ns";
//"mlf_d2_190305_dqdscale_0.5_ns";
//"mlf_d2_190305_dqdscale_0.8_ns";
//"mlf_d2_190305_dqdscale_0.95_ns";
//"mlf_d2_190316_dqdscale_0.95_ns_46";
  //"mlf_d2_190316_dqdscale_0.95_ns_70";
  //"musr_0_2.0_1.056_1";
  //"./musr_fuck_20";
  //"./musr_fuck_20_eq2_0";
  //"../../0507_point_1";
  "../../0510_point/musr_0510_1";

//"musr_0_78_DG365_7.1e8";
//"mlf_d2_190305_dqdscale_1.1_ns";
//"mlf_d2_190305_dqdscale_1.2_ns";
//"mlf_d2_190305_dqdscale_0.5_ns";
    //"mlf_d2_mum_setup.root";
    //"mlf_d2_murfq_setup.root";

  string fname2 = fname;//"musr_dq2_2.0_1.056_1";
  ofstream output_filex(Form("%s_x.txt",fname2.c_str()));
  ofstream output_filey(Form("%s_y.txt",fname2.c_str()));

  TFile*   fF  = new TFile((fname+".root").c_str(), "read");

  c1 = new TCanvas("c1","c1",10,10,1200,1200);
  //tl = new TLegend(0.6,0.6,0.8,0.85);

  c1->Divide(1,2);


      //      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("musr_AccTest_rev_20160629.root");
  fF->GetObject("t1",fChain);


  fChain->SetBranchAddress("eventID", &eventID, &b_eventID);
  fChain->SetBranchAddress("muIniTime", &muIniTime, &b_muIniTime);
  fChain->SetBranchAddress("muIniPosX", &muIniPosX, &b_muIniPosX);
  fChain->SetBranchAddress("muIniPosY", &muIniPosY, &b_muIniPosY);
  fChain->SetBranchAddress("muIniPosZ", &muIniPosZ, &b_muIniPosZ);
  fChain->SetBranchAddress("muIniMomX", &muIniMomX, &b_muIniMomX);
  fChain->SetBranchAddress("muIniMomY", &muIniMomY, &b_muIniMomY);
  fChain->SetBranchAddress("muIniMomZ", &muIniMomZ, &b_muIniMomZ);
  fChain->SetBranchAddress("muDecayPosX", &muDecayPosX, &b_muDecayPosX);
  fChain->SetBranchAddress("muDecayPosY", &muDecayPosY, &b_muDecayPosY);
  fChain->SetBranchAddress("muDecayPosZ", &muDecayPosZ, &b_muDecayPosZ);
  fChain->SetBranchAddress("muDecayTime", &muDecayTime, &b_muDecayTime);
  fChain->SetBranchAddress("det_n", &det_n, &b_det_n);
  fChain->SetBranchAddress("det_ID", det_ID, &b_det_ID);
  fChain->SetBranchAddress("det_time_start", det_time_start, &b_det_time_start);
  fChain->SetBranchAddress("det_x", det_x, &b_det_x);
  fChain->SetBranchAddress("det_y", det_y, &b_det_y);
  fChain->SetBranchAddress("det_z", det_z, &b_det_z);
  fChain->SetBranchAddress("det_kine", det_kine, &b_det_kine);
  fChain->SetBranchAddress("det_VrtxParticleID", det_VrtxParticleID, &b_det_VrtxParticleID);
  fChain->SetBranchAddress("save_n", &save_n, &b_save_n);
  fChain->SetBranchAddress("save_detID", save_detID, &b_save_detID);
  fChain->SetBranchAddress("save_particleID", save_particleID, &b_save_particleID);
  fChain->SetBranchAddress("save_ke", save_ke, &b_save_ke);
  fChain->SetBranchAddress("save_x", save_x, &b_save_x);
  fChain->SetBranchAddress("save_y", save_y, &b_save_y);
  fChain->SetBranchAddress("save_z", save_z, &b_save_z);
  fChain->SetBranchAddress("save_px", save_px, &b_save_px);
  fChain->SetBranchAddress("save_py", save_py, &b_save_py);
  fChain->SetBranchAddress("save_pz", save_pz, &b_save_pz);

  //TFile*   fF  = new TFile("mlf_d2_10101401_ns.root");
  //TFile*   fF  = new TFile("mlf_d2_180219_notime.root");
  //TFile*   fF  = new TFile("mlf_d2_180219_ns.root");
  //TTree* fT  = (TTree*)fF->Get("VirtualDetector/focus_det_5");
  //TTree* fT  = (TTree*)fF->Get("VirtualDetector/dettarget0");
  //TTree* fT  = (TTree*)fF->Get("VirtualDetector/det8");
  //TTree* fT  = (TTree*)fF->Get("VirtualDetector/dettarget");
  //TTree* fT  = (TTree*)fF->Get("VirtualDetector/focus_det");

  ///////////////////////////////////////////////////

  //  Draw the sigma_xy flow

  ///////////////////////////////////////////////////  

  TGraph *gx = new TGraph();
  TGraph *gy = new TGraph();
  TH2F*    Hxy = new TH2F("HemiZ", "Z vs Z';Z(mm);z'", 500,540,660,100,-0.2,0.2);
  //TH2F*    Hxy = new TH2F("HemiY", "Y vs Y';Y(mm);y'", 100,-10,10,100,-0.01,0.01);
  TLine *linex[7];// = new TLine(24159.3,gx->GetYaxis()->GetXmin(),24159.3,gx->GetYaxis()->GetXmax());
  TLine *liney[7];// = new TLine(24159.3,gx->GetYaxis()->GetXmin(),24159.3,gx->GetYaxis()->GetXmax());

  Long64_t nentries = fChain->GetEntriesFast();
  cout<<"nentries "<<nentries<<endl;

  Long64_t nbytes = 0, nb = 0;



  for(int j = 0; j< Ndet; j++){
        fHx   = new TH1F("fHx",   "x",   3000, -1000, 900);
        fHy   = new TH1F("fHy",   "y",   3000, -1000, 1000);
        fHz   = new TH1F("fHz",   "z",   4000, -1000, 2000);
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
  
      //Long64_t ientry = LoadTree(jentry);
      //if (ientry < 0) break; 

      nb = fChain->GetEntry(jentry);   nbytes += nb;
      //Initialization
      double T  = -9999;
      double px = -9999;
      double py = -9999;
      double pz = -9999;
      double x  = -9999;
      double y  = -9999;
      double z  = -9999;
      
      //for(int j = 0; j< 1; j++){

        for( int i = 0 ; i < N ; i++ ){     

          if( save_detID[i]==DetectorSet[j] && save_particleID[i]==PID ){//DET_ID & PID
          //if( save_detID[i]==DetectorSet[0] && save_particleID[i]==PID ){//DET_ID & PID


            //if(prev_x==save_x[i]&&prev_z==save_z[i])continue;//Identify a new event

            T  = save_ke[i];//MeV

            px = save_px[i];
            py = save_py[i];
            pz = save_pz[i];
            x  = save_x[i];
            y  = save_y[i];
            z  = save_z[i];

            fHx->Fill(x);//cout<<x<<" fill"<<endl;
            fHy->Fill(y);
            fHz->Fill(z);
             
             
             //Record previous value        
            prev_x = save_x[i];
            prev_z = save_z[i];

            if(DetectorSet[j]==916)Hxy->Fill(z,pz/(-1*px));
            //if(DetectorSet[j]==917)Hxy->Fill(y,py/(-1*px));
            //if(DetectorSet[j]==1020)Hxy->Fill(y,py/(-1*pz));

            //break;
          
          }//if : DET_ID && PID
        }

        

      }//for : i
      //if(DetectorSet[j]<910 || DetectorSet[j]>914)gx->SetPoint(j,DetectorSet[j],fHx->GetStdDev());
      double detz = fHz->GetMean() +1004;
      double detx = fHx->GetMean() -780;
      double tmp = sqrt(detx*detx)+sqrt(detz*detz);
      
      if(DetectorSet[j]==801 || DetectorSet[j]==802|| DetectorSet[j]==800){
      //  double tmp = sqrt(detz*detz+detx*detx);
      //  gx->SetPoint(j,tmp,fHx->GetStdDev());
      //}
      //if(DetectorSet[j]>914){
        gx->SetPoint(j,tmp,sqrt(2)*fHx->GetMean());
        output_filex<<tmp<<" "<<sqrt(2)*fHx->GetMean()<<endl;
      }
      else if(DetectorSet[j]<910 || DetectorSet[j]>917){
      //  double tmp = sqrt(detz*detz+detx*detx);
      //  gx->SetPoint(j,tmp,fHx->GetMean());
      //}
      //if(DetectorSet[j]>914){
        gx->SetPoint(j,tmp,fHx->GetMean());
        output_filex<<tmp<<" "<<fHx->GetMean()<<endl;
      }
      //else gx->SetPoint(j,DetectorSet[j],fHz->GetMean());
      else {gx->SetPoint(j,tmp,fHz->GetMean());
        output_filex<<tmp<<" "<<fHz->GetMean()<<endl;
      }
        //gy->SetPoint(j,DetectorSet[j],fHy->GetMean());
      //if(DetectorSet[j]<910)gy->SetPoint(j,fHz->GetMean(),fHy->GetMean());
      //else 
      gy->SetPoint(j,tmp,fHy->GetMean());output_filey<<tmp<<" "<<fHy->GetMean()<<endl;

      if(DetectorSet[j]==904){cout<<tmp<<endl;linex[0] = new TLine(tmp,0,tmp,gx->GetYaxis()->GetXmax());}
      if(DetectorSet[j]==909){cout<<tmp<<endl;linex[1] = new TLine(tmp,0,tmp,gx->GetYaxis()->GetXmax());}
      if(DetectorSet[j]==911){cout<<tmp<<endl;linex[2] = new TLine(tmp,0,tmp,gx->GetYaxis()->GetXmax());}
      if(DetectorSet[j]==914){cout<<tmp<<endl;linex[3] = new TLine(tmp,0,tmp,gx->GetYaxis()->GetXmax());}
      if(DetectorSet[j]==918){cout<<tmp<<endl;linex[4] = new TLine(tmp,0,tmp,gx->GetYaxis()->GetXmax());}
      if(DetectorSet[j]==1020){cout<<tmp<<endl;linex[5] = new TLine(tmp,0,tmp,gx->GetYaxis()->GetXmax());}
      if(DetectorSet[j]==919){cout<<tmp<<endl;linex[6] = new TLine(tmp,0,tmp,gx->GetYaxis()->GetXmax());}

      if(DetectorSet[j]==904){cout<<tmp<<endl;liney[0] = new TLine(tmp,0,tmp,gx->GetYaxis()->GetXmax());}
      if(DetectorSet[j]==909){cout<<tmp<<endl;liney[1] = new TLine(tmp,0,tmp,gx->GetYaxis()->GetXmax());}
      if(DetectorSet[j]==911){cout<<tmp<<endl;liney[2] = new TLine(tmp,0,tmp,gx->GetYaxis()->GetXmax());}
      if(DetectorSet[j]==914){cout<<tmp<<endl;liney[3] = new TLine(tmp,0,tmp,gx->GetYaxis()->GetXmax());}
      if(DetectorSet[j]==918){cout<<tmp<<endl;liney[4] = new TLine(tmp,0,tmp,gx->GetYaxis()->GetXmax());}
      if(DetectorSet[j]==1020){cout<<tmp<<endl;liney[5] = new TLine(tmp,0,tmp,gx->GetYaxis()->GetXmax());}
      if(DetectorSet[j]==919){cout<<tmp<<endl;liney[6] = new TLine(tmp,0,tmp,gx->GetYaxis()->GetXmax());}


      
    }//jentry

    
    

    
    c1->cd(1);
    //gx->SetTitle("Sigma_x flow (horizonal); z(mm); #sigma_x (mm)");
    gx->SetTitle("Mean_x flow (horizonal); z(mm); #mean_x (mm)");
    gx->SetLineColor(kBlue);
    gx->Draw("APL*same");
    //fHy->Draw();
    //lineEndDQ15->Draw();
    //line8->Draw();
    //line9->Draw();
    for(int nl = 0; nl<7; nl++){linex[nl]->SetY1(gx->GetYaxis()->GetXmin());linex[nl]->SetY2(gx->GetYaxis()->GetXmax());linex[nl]->Draw();}
    c1->cd(2);
    //gy->SetTitle("Sigma_y flow (vertical); z(mm); #sigma_y (mm)");
    gy->SetTitle("Mean_y flow (vertical); z(mm); #mean_y (mm)");
    gy->SetLineColor(kBlue);
    gy->Draw("APL*same");
    for(int nl = 0; nl<7; nl++){liney[nl]->SetY1(gy->GetYaxis()->GetXmin());liney[nl]->SetY2(gy->GetYaxis()->GetXmax());liney[nl]->Draw();}
    //lineEndDQ15->Draw();
    //line8->Draw();
    //line9->Draw();
    //c1->SaveAs(Form("%s_SigmaFlow.png",fname2.c_str()));
      c1->SaveAs(Form("%s_MeanFlow.png",fname2.c_str()));

    TCanvas* c2 = new TCanvas("c2","c2",10,10,800,800);
    Hxy->Draw("colz");
/*

  for ( int i =0;i<Ndet;i++){
    string detname = DetectorSet[i];
    TTree* fT  = (TTree*)fF->Get(detname.c_str());
    DrawPlots(fT, detname,i,gx,gy);
  }

  SetstyleGraph1(gx);
  SetstyleGraph1(gy);

  TLine *lineEndDQ15 = new TLine(24159.3,gx->GetYaxis()->GetXmin(),24159.3,gx->GetYaxis()->GetXmax());
  TLine *line8 = new TLine(24558.6,gx->GetYaxis()->GetXmin(),24558.6,gx->GetYaxis()->GetXmax());
  TLine *line9 = new TLine(24837.8,gx->GetYaxis()->GetXmin(),24837.8,gx->GetYaxis()->GetXmax());
  

  TCanvas* c1 = new TCanvas("c1","c1",10,10,1200,1200);
  c1->Divide(1,2);
  c1->cd(1);
  gx->SetTitle("Sigma_x flow; z(mm); #sigma_x (mm)");
  gx->Draw("APL*");
  lineEndDQ15->Draw();
  line8->Draw();
  line9->Draw();
  c1->cd(2);
  gy->SetTitle("Sigma_y flow; z(mm); #sigma_y (mm)");
  gy->Draw("APL*");
  lineEndDQ15->Draw();
  line8->Draw();
  line9->Draw();
  c1->SaveAs(Form("%s_SigmaFlow.png",fname.c_str()));
*/
  ///////////////////////////////////////////////////

  //  Draw the histograms at particular detecting point
  
  ///////////////////////////////////////////////////  
/*
  string detname = DetectorSet[25];
  //string detname = DetectorSet[0];
  TTree* fT  = (TTree*)fF->Get(detname.c_str());

  std::vector<TH1F*> H1F = CreateVecH1F(Nhis,name,title,nbin,xmin,xmax);
  

  TCanvas* c2 = new TCanvas(("c2_"+detname).c_str(),("c2_"+detname).c_str(),10,10,1200,1200);
  c2->Divide(3,3);
  //SetStatus(0);
  for(int i = 0; i<Nhis; i++){
    fT -> Project(name[i].c_str(), name[i].c_str(), "PDGid==-13");
    c2->cd(i+1);
    //SetstyleHist1(H1F.at(i),kCyan+1);
    SetstyleHist1(H1F.at(i));
    //SetStatus(H1F.at(0));
    H1F.at(i)->Draw();
  }
  
  c2->cd(6);
  TH1F*    Hp = new TH1F("Hp", "P;P(MeV/c);N", 100, 0, 35);
  fT -> Draw("sqrt(Px*Px+Py*Py+Pz*Pz)>>Hp", "PDGid==-13");
  //fT -> Project("fHp", "sqrt(Px*Px+Py*Py+Pz*Pz)", "PDGid==-13");
  //SetStatus(0);
  SetstyleHist1(Hp);
  Hp ->Draw();  

  c2->cd(7);
  TH2F*    Hxy = new TH2F("Hxy", "Y vs X;X(mm);Y(mm)", 100,-200,200,100,-200,200);
  fT -> Draw("y:x-100>>Hxy", "PDGid==-13");
  //fT -> Draw("y:x>>Hxy", "PDGid==-13");
  //fT -> Draw("y:x-100>>Hxy", "PDGid==-13 && y*y+(x-100)*(x-100)<39*39");
  //SetStatus(0);
  Hxy ->Draw("colz");

  c2->cd(8);
  TH2F*    Hxdx = new TH2F("Hxdx", "X' vs X;X(mm);X'", 150,-150,150,100,-0.3,0.3);
  fT -> Draw("Px/Pz:x-100>>Hxdx", "PDGid==-13");
  //fT -> Draw("Px/Pz:x>>Hxdx", "PDGid==-13");
  Hxdx ->Draw("colz");
  c2->cd(9);
  TH2F*    Hydy = new TH2F("Hydy", "Y' vs Y;Y(mm);Y'", 150,-150,150,100,-0.3,0.3);
  fT -> Draw("Py/Pz:y>>Hydy", "PDGid==-13");
  Hydy ->Draw("colz");

  //c2->SaveAs(Form("%s_%s_Distributions.png",fname.c_str(),"det8"));//,detname.c_str()));

  //TCanvas* c3 = new TCanvas(("c3_"+detname).c_str(),("c3_"+detname).c_str(),10,10,400,400);

  //H1F.clear();
  //c2->Update();
  //delete fF;
  */
}

void DrawPlots(TTree* fT, string detname, int i, TGraph* gx, TGraph* gy ){

//  TGraph *gx = new TGraph();


  TH1F*    fHx   = new TH1F("fHx",   "x",   5000, -1000, 1000);
  //TH1F*    fHx   = new TH1F("fHx",   "x",   nbin_xy, 0, 200);
  fT -> Project("fHx", "x", "PDGid==-13");
  //cout<<fHx->GetStdDev()<<endl;
  TH1F*    fHy   = new TH1F("fHy",   "y",   5000, -1000, 1000);
  fT -> Project("fHy", "y", "PDGid==-13");
  TH1F*    fHz   = new TH1F("fHz",   "z",   500000, -10000, 100000);
  fT -> Project("fHz", "z", "PDGid==-13");
  
  //cout<<fHz->GetMean()<<" "<<fHx->GetStdDev()<<endl;
  gx->SetPoint(i,fHz->GetMean(),fHx->GetStdDev());
  gy->SetPoint(i,fHz->GetMean(),fHy->GetStdDev());
/*
  TH1F*    fHt   = new TH1F("fHt",   "t",   3000, -1000,2000);
  fT -> Project("fHt", "t", "PDGid==-13");
  TH1F*    fHptx = new TH1F("fHptx", "Px/Pz", nbin_pt, min_pt, max_pt);
  fT -> Project("fHptx", "Px/Pz", "PDGid==-13");
  TH1F*    fHpty = new TH1F("fHpty", "Py/Pz", nbin_pt, min_pt, max_pt);
  fT -> Project("fHpty", "Py/Pz", "PDGid==-13");
  TH2F*    fHxdx = new TH2F("fHxdx", "X vs Px/Pz",  (int)(nbin_xy/5), min_xy, max_xy, (int)(nbin_pt/10), min_pt, max_pt);
  //TH2F*    fHxdx = new TH2F("fHxdx", "X vs Px/Pz", (int)(nbin_pt/10), min_pt, max_pt, (int)(nbin_xy/5), 0, 200);
  //fT -> Draw("Px/Pz:x>>fHxdx", "PDGid==-13");
  

  //fHxdx -> GetYaxis() -> SetRangeUser(-50,50);
  fHxdx -> GetXaxis() -> SetRangeUser(50,350);
  fHxdx -> GetYaxis() -> SetRangeUser(-0.4,0.4);
  fHxdx -> GetYaxis() -> SetTitle("Px/Pz");
  fHxdx -> GetXaxis() -> SetTitle("X");
  TH2F*    fHydy = new TH2F("fHydy", "Y vs Py/Pz", (int)(nbin_xy/5), min_xy, max_xy, (int)(nbin_pt/10), min_pt, max_pt);
  //fT -> Draw("Py/Pz:y>>fHydy", "PDGid==-13");
  fHydy -> GetXaxis() -> SetRangeUser(-50,50);
  fHydy -> GetYaxis() -> SetRangeUser(-0.4,0.4);
  fHydy -> GetYaxis() -> SetTitle("Py/Pz");
  fHydy -> GetXaxis() -> SetTitle("Y");

  TH1F*    fHp = new TH1F("fHp", "P", nbin_p, min_p, max_p);
  fT -> Project("fHp", "sqrt(Px*Px+Py*Py+Pz*Pz)", "PDGid==-13");
  */
/*
  fHx->SetStats(0);
  fHy->SetStats(0);
  fHptx->SetStats(0);
  fHpty->SetStats(0);
  fHxdx->SetStats(0);
  fHydy->SetStats(0);
  fHp->SetStats(0);
*/
  /*
  cout <<"region cut: "<< fT -> GetEntries("abs(x)<20&&abs(y)<20&&PDGid==-13") << endl;
  cout <<"region cut: "<< fT -> GetEntries("abs(x)<35&&abs(y)<20") << endl;
  cout <<"region cut: "<< fT -> GetEntries("abs(x)<sqrt(20.0)/2&&abs(y)<sqrt(20.0)/2") << endl;
*/
  /*
  fHx   -> SetMaximum(fHx  ->GetMaximum()*1.2);  
  fHy   -> SetMaximum(fHy  ->GetMaximum()*1.2);
  fHptx -> SetMaximum(fHptx->GetMaximum()*1.2);
  fHpty -> SetMaximum(fHpty->GetMaximum()*1.2);
  fHp   -> SetMaximum(fHp  ->GetMaximum()*1.2);

  fHx   -> SetFillColor(3);
  fHy   -> SetFillColor(3);
  fHptx -> SetFillColor(3);
  fHpty -> SetFillColor(3);
  fHp   -> SetFillColor(3);
  fHt   -> SetFillColor(3);
  fHt   -> SetXTitle("ns");
  fHx   -> SetXTitle("mm");
  fHy   -> SetXTitle("mm");
  fHptx -> SetXTitle("Px/Pz");
  fHpty -> SetXTitle("Py/Pz");
  fHp   -> SetXTitle("P (MeV/c)");
*/

  //TCanvas* c1 = new TCanvas("c1","c1",10,10,1200,1200);
  /*
  TCanvas* c1 = new TCanvas(("c1_"+detname).c_str(),("c1_"+detname).c_str(),10,10,1800,1200);
  c1 -> Divide(4,2);
  //c1 -> Divide(2,2);

  c1 -> cd(1);
  fHx-> Draw();
  c1 -> cd(2);
  fHptx-> Draw();
  c1 -> cd(3);
  //fT -> Draw("Px/Pz:x", "PDGid==-13");
  fHxdx-> Draw("colz");

  c1 -> cd(5);
  fHy-> Draw();
  c1 -> cd(6);
  fHpty-> Draw();
  c1 -> cd(7);
  //fT -> Draw("Py/Pz:y", "PDGid==-13");
  fHydy-> Draw("colz");

  c1 -> cd(4);
  fHp-> Draw();
  c1 -> cd(8);
  //fHt->Draw();
  
  //fT -> Draw("x:y", "PDGid==-13");
  */
  //TCanvas* c1 = new TCanvas(("c1_"+detname).c_str(),("c1_"+detname).c_str(),10,10,1800,1200);
  
  delete fHx;
  delete fHy;
  delete fHz;

}
