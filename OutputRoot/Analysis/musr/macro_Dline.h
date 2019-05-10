#include "/Users/zhangce/WorkArea/CZhang/CZhang.cxx"


  //const int Ndet = 22;
  const int N = 280;// number of array for save_par
  double prev_x =-9999;
  double prev_z =-9999;

  const int DET_ID = 918;//958;//Best focus poit : z =-300
  
  const int PID  = -13;//muon

  void macro_Dline_(string fname_);
  void macro_Dline_2(string fname_, int i );
  TGraph * gx;// = new TGraph(Form("%s_x.txt",fname_.c_str()));
  TGraph * gy;// = new TGraph(Form("%s_y.txt",fname_.c_str()));
  TLegend * tl;

  TLine * linex;// = new TLine(tmp,0,tmp,gx->GetYaxis()->GetXmax());
  TLine * liney;// = new TLine(tmp,0,tmp,gy->GetYaxis()->GetXmax());


  TCanvas* c1;//

  TH1F*    fHx;//   = new TH1F("fHx",   "x",   3000, 600, 900);
  TH1F*    fHy;//   = new TH1F("fHy",   "y",   50000, -10000, 10000);
  TH1F*    fHz;//   = new TH1F("fHz",   "z",   500000, -10000, 100000);

  TTree          *fChain;

  Int_t           eventID;
  Double_t        muIniTime;
  Double_t        muIniPosX;
  Double_t        muIniPosY;
  Double_t        muIniPosZ;
  Double_t        muIniMomX;
  Double_t        muIniMomY;
  Double_t        muIniMomZ;
  Double_t        muDecayPosX;
  Double_t        muDecayPosY;
  Double_t        muDecayPosZ;
  Double_t        muDecayTime;
  Int_t           det_n;
  Int_t           det_ID[50];   //[det_n]
  Double_t        det_time_start[20];   //[det_n]
  Double_t        det_x[50];   //[det_n]
  Double_t        det_y[50];   //[det_n]
  Double_t        det_z[50];   //[det_n]
  Double_t        det_kine[50];   //[det_n]
  Int_t           det_VrtxParticleID[50];   //[det_n]
  Int_t           save_n;
  Int_t           save_detID[500];   //[save_n]
  Int_t           save_particleID[500];   //[save_n]
  Double_t        save_ke[500];   //[save_n]
  Double_t        save_x[500];   //[save_n]
  Double_t        save_y[500];   //[save_n]
  Double_t        save_z[500];   //[save_n]
  Double_t        save_px[500];   //[save_n]
  Double_t        save_py[500];   //[save_n]
  Double_t        save_pz[500];   //[save_n]

  // List of branches
  TBranch        *b_eventID;   //!
  TBranch        *b_muIniTime;   //!
  TBranch        *b_muIniPosX;   //!
  TBranch        *b_muIniPosY;   //!
  TBranch        *b_muIniPosZ;   //!
  TBranch        *b_muIniMomX;   //!
  TBranch        *b_muIniMomY;   //!
  TBranch        *b_muIniMomZ;   //!
  TBranch        *b_muDecayPosX;   //!
  TBranch        *b_muDecayPosY;   //!
  TBranch        *b_muDecayPosZ;   //!
  TBranch        *b_muDecayTime;   //!
  TBranch        *b_det_n;   //!
  TBranch        *b_det_ID;   //!
  TBranch        *b_det_time_start;   //!
  TBranch        *b_det_x;   //!
  TBranch        *b_det_y;   //!
  TBranch        *b_det_z;   //!
  TBranch        *b_det_kine;   //!
  TBranch        *b_det_VrtxParticleID;   //!
  TBranch        *b_save_n;   //!
  TBranch        *b_save_detID;   //!
  TBranch        *b_save_particleID;   //!
  TBranch        *b_save_ke;   //!
  TBranch        *b_save_x;   //!
  TBranch        *b_save_y;   //!
  TBranch        *b_save_z;   //!
  TBranch        *b_save_px;   //!
  TBranch        *b_save_py;   //!
  TBranch        *b_save_pz;   //!

const int Ndet = 26;//15;
int DetectorSet[Ndet]={
900,//Gen
901,//SOA1 center
902,//SOA2 center
903,//SOA3 center

904,//SOA exit
906,//entrance of Q1
907,//entrance of Q2
908,//Q2 exit

909,//entrance of ED
800,
801,
802,
910,
911,

912,//entrance of Q3
913,//entrance of Q4
914,//exit Q4

915,
916,
917,
1018,
1019,
918,//BM out


1020,
919,//Q5 out

920//MCP
//919//31,
};
/*

string DetectorSet[Ndet]={
"VirtualDetector/dettarget0",
"VirtualDetector/dettarget",
"VirtualDetector/detdq1",
"VirtualDetector/detdq2",
"VirtualDetector/detdq3",
"VirtualDetector/det1",
"VirtualDetector/det2",
"VirtualDetector/detsc",
"VirtualDetector/det_sc_entrance",
"VirtualDetector/det3",
"VirtualDetector/det4",
//"VirtualDetector/det4_1",
"VirtualDetector/det5",
"VirtualDetector/det6",
"VirtualDetector/det6b",
"VirtualDetector/det7",
"VirtualDetector/det8",//15
"VirtualDetector/det9",
"VirtualDetector/det10",
"VirtualDetector/det11",
"VirtualDetector/det12",
"VirtualDetector/det13",
"VirtualDetector/det14"//31
};
*/

void DrawPlots(TTree* , string , int, TGraph*,TGraph*);






//TH1F* Hx,Hy,Hz;

//TList *hlist = new TList;
//TH1F * H1F[Nhis] = {Hx,Hy,Hz};

const int Nhis = 5;
//string name[Nhis]={"x-100","y","z"};

string name[Nhis]={
    "x-100",
    "y",
    "z",
    "t",
    "Pz"
  };
  string title[Nhis]={
    "x;X(mm);N",
    "y;Y(mm);N",
    "z;Z(mm);N",
    "t;t(ns);N",
    "Pz;Pz(MeV/c);N"
  };
  Int_t nbin[Nhis]={
  	200,
  	200,
  	5000,
  	100,
  	100
  };
  Int_t xmin[Nhis]={
  	-100,
  	-101,
  	0,
  	-200,
  	0
  };
  Int_t xmax[Nhis]={
  	100,
  	100,
  	//50000,
  	50000,
  	2000,
  	35
  };

    




