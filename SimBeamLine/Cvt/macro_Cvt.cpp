//#include "/Users/zhangce/WorkArea/CZhang/CZhang.cxx"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

double light = 299792458; // m/s
double massMu = 106.16; // MeV/c2

void macro_Cvt_single(TString,TString);



void macro_Cvt(){

  TString name = "mlf_d2_190406_dqdscale_0.95_ns_";
  TString name2;

  for(int i = 70; i<71; i++){
    stringstream ss; ss << i;
    
    TString name1 = name + ss.str() + ".root";
    name2 = ss.str();
    
    macro_Cvt_single(name1 , name2);    
  }

}


void macro_Cvt_single(TString name1 = "", TString name2 = ""){

  Float_t rX,rY,rZ,rPx,rPy,rPz,rEk,rT;

  TFile*   fF2  = new TFile(Form("../%s",name1.Data()));

  TTree* fT2  = (TTree*)fF2->Get("VirtualDetector/det8");

  
  fT2->SetBranchAddress("x",&rX);
  fT2->SetBranchAddress("y",&rY);
  fT2->SetBranchAddress("z",&rZ);
  fT2->SetBranchAddress("Px",&rPx);
  fT2->SetBranchAddress("Py",&rPy);
  fT2->SetBranchAddress("Pz",&rPz);
  //fT2->SetBranchAddress("rEk",&rEk);
  fT2->SetBranchAddress("t",&rT);
  //fT2->Draw("Px/Pz:(x-100)");
  //fT2->Draw("Py/Pz:(y-100)");

  ofstream outFile;
  outFile.open(Form("../FromDline_dqdscale_0.95_0406_ns_%s.txt",name2.Data()));



  int N = fT2->GetEntries();
  for (int i = 0; i < N; i++){
    fT2->GetEntry(i);

    double P = sqrt(rPx*rPx + rPy*rPy + rPz*rPz);
    rPx /= P;
    rPy /= P;
    rPz /= P;

    rEk = sqrt(massMu*massMu + P*P ) - massMu;

    outFile<< rX-100<<" "<<rY<<" "<<-393<<" "<<rPx<<" "<<rPy<<" "<<rPz<<" "<<rEk<<" "<<rT<<endl;

  }
  
  outFile.close();

}
