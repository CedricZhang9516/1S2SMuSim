//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Jul 14 17:24:07 2016 by ROOT version 5.34/09
// from TTree t1/a simple Tree with simple variables
// found on file: musr_AccTest_rev_20160629.root
//////////////////////////////////////////////////////////

#ifndef AccTest_Input_h
#define AccTest_Input_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

const string output = "AccTest.d";
//const string input = "musr_Mum_proposal_merge.root";
//const string input = "./data/170124_acctest_short.root";
//const string input = "./data/170124_acctest_rkita.root";
//const string input = "./data/slowmu_170208_4.root";
//const string input = "./data/musr_paper_Mum_171029.root";
//const string input = "./data/murfq_171108.root";
//const string input = "./data/murfq_mup_171121.root";
//const string input = "./data/murfq_mup_171121_2.root";
//const string input = "./data/musr_0.root";
//const string input_ = 
//"./data/musr_0_78_DG500.root";
//"./data/musr_0_78_DG525.root";
//"./data/musr_0_78_DG500_dqd0.9_den0.3.root";
//"./data/musr_0_78_DG500_dqd0.95_1e7.root";
//"./data/musr_0_78_DG500_dqd0.95_tot.root";
//"./data/musr_0_78_DG500_dqd0.95_7.1e8.root";
//"musr_0";

//"musr_0_2.0";
//"musr_fuck_20_eq2_0";

//"../../0507_point_11";

//"./musr_fuck_20_eq2_0_9080X_shift";
//"musr_fuck_20_eq2_0_eq3_-1.088_ed_2.5";

//"musr_0_2.0";
//"musr_0418_eq2_2.0";
//"./musr_fuck_20";
//"./musr_fuck_20_eq2_0";

//"musr_0_0.56";
// = input_ + ".root";


#define NSAVE 500
// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class AccTest_Input {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   string input;
   string input2;
   // Declaration of leaf types
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
   Int_t           save_detID[NSAVE];   //[save_n]
   Int_t           save_particleID[NSAVE];   //[save_n]
   Double_t        save_ke[NSAVE];   //[save_n]
   Double_t        save_x[NSAVE];   //[save_n]
   Double_t        save_y[NSAVE];   //[save_n]
   Double_t        save_z[NSAVE];   //[save_n]
   Double_t        save_px[NSAVE];   //[save_n]
   Double_t        save_py[NSAVE];   //[save_n]
   Double_t        save_pz[NSAVE];   //[save_n]

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

   AccTest_Input( string input_, TTree *tree=0);
   virtual ~AccTest_Input();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop(int I);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef AccTest_Input_cxx
AccTest_Input::AccTest_Input(string input_, TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   input = input_ + ".root";
   input2 = input_ ;//+ ".root";


   if (tree == 0) {



	  TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject(input.c_str());
      //      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("musr_AccTest_rev_20160629.root");
      if (!f || !f->IsOpen()) {
	f = new TFile(input.c_str());
	 //         f = new TFile("musr_AccTest_rev_20160629.root");
      }
      f->GetObject("t1",tree);

   }
   Init(tree);
}

AccTest_Input::~AccTest_Input()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t AccTest_Input::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t AccTest_Input::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void AccTest_Input::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

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
   Notify();
}

Bool_t AccTest_Input::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void AccTest_Input::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t AccTest_Input::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef AccTest_Input_cxx
