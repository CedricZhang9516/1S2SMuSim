//#include "/Users/zhangce/WorkArea/CZhang/CZhang.cxx"
//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Aug 23 14:21:25 2018 by ROOT version 5.34/36
// from TTree tree/MuYield event
// found on file: Otanisan0823_tree_Type1_D87000_T322_Nrepeat1000000_Xfree1_Thick7.12_NewGeo0_.root
//////////////////////////////////////////////////////////

#ifndef CvtMusr_h
#define CvtMusr_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
//const string filename = "OtanisanNewGeo0824_tree_Type1_D87000_T322_Nrepeat2000000_Xfree1_Thick7.12_NewGeo0_.root";

//const string filename = "OtanisanNewGeo0824_tree_Type1_D87000_T322_Nrepeat840000_Xfree1_Thick2.00_NewGeo1_.root";
//const string filename = "OtanisanNewGeo0827_tree_Type1_D87000_T322_Nrepeat2000000_Xfree1_Thick7.12_NewGeo0_.root";
//const string filename = "OtanisanNewGeo0827_tree_Type1_D87000_T322_Nrepeat840000_Xfree1_Thick2.00_NewGeo1_.root";
const string filename = //"Otanisan0823_tree_Type1_D87000_T322_Nrepeat1000000_Xfree1_Thick7.12_NewGeo0_.root";
//"/home/had/zhangce/1S2SMuSim/SimDiffusionLaser/Root/Target_output_0.root";
"./0324_tlaser_1.2.root";

const string output = 
"/Users/zhangce/WorkArea/1S2SMuSim/SimThermalMuonTran/run/FromDline_musr.dat";

double PI = 3.1415926;

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class CvtMusr {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Double_t        TBeam;
   Double_t        decayT;
   Double_t        X0;
   Double_t        Y0;
   Double_t        Z0;
   Double_t        vel0;
   Double_t        theta0;
   Double_t        phi0;
   Double_t        Vz0;
   Double_t        Vx0;
   Double_t        Vy0;
   Double_t        Lmfp;
   Double_t        X_sf;
   Double_t        Y_sf;
   Double_t        Z_sf;
   Double_t        VX_sf;
   Double_t        VY_sf;
   Double_t        VZ_sf;
   Double_t        theta_sf;
   Double_t        phi_sf;
   Double_t        t0;
   Double_t        DecayX;
   Double_t        DecayY;
   Double_t        DecayZ;
   Double_t        LaserX;
   Double_t        LaserY;
   Double_t        LaserZ;
   Double_t        LaserE;
   Double_t        LaserXp;
   Double_t        LaserYp;
   Double_t        MeshEk;
   Double_t        MeshE;
   Double_t        MeshT;
   Double_t        MeshT_ab;
   Double_t        MeshX;
   Double_t        MeshY;
   Double_t        MeshZ;
   Double_t        MeshXp;
   Double_t        MeshYp;
   Double_t        MeshBeta;
   Double_t        MeshVY;
   Double_t        MeshVX;
   Double_t        MeshVZ;
   Double_t        DriftT;
   Double_t        DriftT_ab;
   Double_t        DriftX;
   Double_t        DriftY;
   Double_t        DriftZ;

   // List of branches
   TBranch        *b_TBeam;   //!
   TBranch        *b_decayT;   //!
   TBranch        *b_X0;   //!
   TBranch        *b_Y0;   //!
   TBranch        *b_Z0;   //!
   TBranch        *b_vel0;   //!
   TBranch        *b_theta0;   //!
   TBranch        *b_phi0;   //!
   TBranch        *b_Vz0;   //!
   TBranch        *b_Vx0;   //!
   TBranch        *b_Vy0;   //!
   TBranch        *b_Lmfp;   //!
   TBranch        *b_X_sf;   //!
   TBranch        *b_Y_sf;   //!
   TBranch        *b_Z_sf;   //!
   TBranch        *b_VX_sf;   //!
   TBranch        *b_VY_sf;   //!
   TBranch        *b_VZ_sf;   //!
   TBranch        *b_theta_sf;   //!
   TBranch        *b_phi_sf;   //!
   TBranch        *b_t0;   //!
   TBranch        *b_DecayX;   //!
   TBranch        *b_DecayY;   //!
   TBranch        *b_DecayZ;   //!
   TBranch        *b_LaserX;   //!
   TBranch        *b_LaserY;   //!
   TBranch        *b_LaserZ;   //!
   TBranch        *b_LaserE;   //!
   TBranch        *b_LaserXp;   //!
   TBranch        *b_LaserYp;   //!
   TBranch        *b_MeshEk;   //!
   TBranch        *b_MeshE;   //!
   TBranch        *b_MeshT;   //!
   TBranch        *b_MeshT_ab;   //!
   TBranch        *b_MeshX;   //!
   TBranch        *b_MeshY;   //!
   TBranch        *b_MeshZ;   //!
   TBranch        *b_MeshXp;   //!
   TBranch        *b_MeshYp;   //!
   TBranch        *b_MeshBeta;   //!
   TBranch        *b_MeshVY;   //!
   TBranch        *b_MeshVX;   //!
   TBranch        *b_MeshVZ;   //!
   TBranch        *b_DriftT;   //!
   TBranch        *b_DriftT_ab;   //!
   TBranch        *b_DriftX;   //!
   TBranch        *b_DriftY;   //!
   TBranch        *b_DriftZ;   //!

   CvtMusr(TTree *tree=0);
   virtual ~CvtMusr();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef CvtMusr_cxx
CvtMusr::CvtMusr(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
     //TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("Otanisan0823_tree_Type1_D87000_T322_Nrepeat1000000_Xfree1_Thick7.12_NewGeo0_.root");
     TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject(Form("%s",filename.c_str()));
      if (!f || !f->IsOpen()) {
	//f = new TFile("Otanisan0823_tree_Type1_D87000_T322_Nrepeat1000000_Xfree1_Thick7.12_NewGeo0_.root");
	f = new TFile(Form("%s",filename.c_str()));
      }
      f->GetObject("tree",tree);

   }
   Init(tree);
}

CvtMusr::~CvtMusr()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t CvtMusr::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t CvtMusr::LoadTree(Long64_t entry)
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

void CvtMusr::Init(TTree *tree)
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

   fChain->SetBranchAddress("TBeam", &TBeam, &b_TBeam);
   fChain->SetBranchAddress("decayT", &decayT, &b_decayT);
   fChain->SetBranchAddress("X0", &X0, &b_X0);
   fChain->SetBranchAddress("Y0", &Y0, &b_Y0);
   fChain->SetBranchAddress("Z0", &Z0, &b_Z0);
   fChain->SetBranchAddress("vel0", &vel0, &b_vel0);
   fChain->SetBranchAddress("theta0", &theta0, &b_theta0);
   fChain->SetBranchAddress("phi0", &phi0, &b_phi0);
   fChain->SetBranchAddress("Vz0", &Vz0, &b_Vz0);
   fChain->SetBranchAddress("Vx0", &Vx0, &b_Vx0);
   fChain->SetBranchAddress("Vy0", &Vy0, &b_Vy0);
   fChain->SetBranchAddress("Lmfp", &Lmfp, &b_Lmfp);
   fChain->SetBranchAddress("X_sf", &X_sf, &b_X_sf);
   fChain->SetBranchAddress("Y_sf", &Y_sf, &b_Y_sf);
   fChain->SetBranchAddress("Z_sf", &Z_sf, &b_Z_sf);
   fChain->SetBranchAddress("VX_sf", &VX_sf, &b_VX_sf);
   fChain->SetBranchAddress("VY_sf", &VY_sf, &b_VY_sf);
   fChain->SetBranchAddress("VZ_sf", &VZ_sf, &b_VZ_sf);
   fChain->SetBranchAddress("theta_sf", &theta_sf, &b_theta_sf);
   fChain->SetBranchAddress("phi_sf", &phi_sf, &b_phi_sf);
   fChain->SetBranchAddress("t0", &t0, &b_t0);
   fChain->SetBranchAddress("DecayX", &DecayX, &b_DecayX);
   fChain->SetBranchAddress("DecayY", &DecayY, &b_DecayY);
   fChain->SetBranchAddress("DecayZ", &DecayZ, &b_DecayZ);
   fChain->SetBranchAddress("LaserX", &LaserX, &b_LaserX);
   fChain->SetBranchAddress("LaserY", &LaserY, &b_LaserY);
   fChain->SetBranchAddress("LaserZ", &LaserZ, &b_LaserZ);
   fChain->SetBranchAddress("LaserE", &LaserE, &b_LaserE);
   fChain->SetBranchAddress("LaserXp", &LaserXp, &b_LaserXp);
   fChain->SetBranchAddress("LaserYp", &LaserYp, &b_LaserYp);
   fChain->SetBranchAddress("MeshEk", &MeshEk, &b_MeshEk);
   fChain->SetBranchAddress("MeshE", &MeshE, &b_MeshE);
   fChain->SetBranchAddress("MeshT", &MeshT, &b_MeshT);
   fChain->SetBranchAddress("MeshT_ab", &MeshT_ab, &b_MeshT_ab);
   fChain->SetBranchAddress("MeshX", &MeshX, &b_MeshX);
   fChain->SetBranchAddress("MeshY", &MeshY, &b_MeshY);
   fChain->SetBranchAddress("MeshZ", &MeshZ, &b_MeshZ);
   fChain->SetBranchAddress("MeshXp", &MeshXp, &b_MeshXp);
   fChain->SetBranchAddress("MeshYp", &MeshYp, &b_MeshYp);
   fChain->SetBranchAddress("MeshBeta", &MeshBeta, &b_MeshBeta);
   fChain->SetBranchAddress("MeshVY", &MeshVY, &b_MeshVY);
   fChain->SetBranchAddress("MeshVX", &MeshVX, &b_MeshVX);
   fChain->SetBranchAddress("MeshVZ", &MeshVZ, &b_MeshVZ);
   fChain->SetBranchAddress("DriftT", &DriftT, &b_DriftT);
   fChain->SetBranchAddress("DriftT_ab", &DriftT_ab, &b_DriftT_ab);
   fChain->SetBranchAddress("DriftX", &DriftX, &b_DriftX);
   fChain->SetBranchAddress("DriftY", &DriftY, &b_DriftY);
   fChain->SetBranchAddress("DriftZ", &DriftZ, &b_DriftZ);
   Notify();
}

Bool_t CvtMusr::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void CvtMusr::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t CvtMusr::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef CvtMusr_cxx
