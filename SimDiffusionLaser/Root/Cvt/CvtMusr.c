#define CvtMusr_cxx
#include "CvtMusr.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <stdlib.h>
#include <cmath>




void CvtMusr::Loop( double tmpa, double tmpb, double tmpc, string output_)
{
//   In a ROOT session, you can do:
//      Root > .L CvtMusr.C
//      Root > CvtMusr t
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

   const string output = 
   output_;//"./FromDline_musr_0507_10.dat";
   
   TH1D *hLaserX = new TH1D("hLaserX","hLaserX",200,-100,100); // mm
   TH1D *hLaserXp = new TH1D("hLaserXp","hLaserXp",200,-6,6); // mm
   TH1D *hLaserY = new TH1D("hLaserY","hLaserY",100,-5,5); // mm
   TH1D *hLaserYp = new TH1D("hLaserYp","hLaserYp",200,-8,8); // mm
   TH1D *hLaserZ = new TH1D("hLaserZ","hLaserZ",200,0,7); // mm
   TH1D *hLaserE = new TH1D("hLaserE","hLaserE",200,0,0.3e-6); // mm
   //TH1D *hLaserE = new TH1D("hLaserE","hLaserE",200,0,40e-6); // mm
   TH2D *hLaserXXp = new TH2D("hLaserXXp","hLaserXXp",100,-100,100,100,-6,6); // mm
   TH2D *hLaserYYp = new TH2D("hLaserYYp","hLaserYYp",100,-5,5,100,-8,8); // mm
   TCanvas *c = new TCanvas("c","c",1200,800);
   //TCanvas *c2 = new TCanvas("c2","c2",1000,800);
   c->Divide(3,2);


   TH1D* hX = new TH1D("hX","hX;mm",200,-60,60);
   TH1D* hY = new TH1D("hY","hY;mm",200,-25,25);
   TH1D* hZ = new TH1D("hZ","hZ;mm",100,-8.80,1);
   
   TH2D* TgtXY = new TH2D("TgtXY","TgtXY;X(mm);Y(mm)'",100,-50,50,50,-15,15); // mm;
   
   //TCanvas *c3 = new TCanvas("c3","c3",1200,400);
   //c3->Divide(4,1);


   if (fChain == 0) return;
   ofstream wf(output.c_str());
   Long64_t nentries = fChain->GetEntriesFast();//1e5
   const double mmu = 105.658;
   Long64_t nbytes = 0, nb = 0;

   
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;

      nb = fChain->GetEntry(jentry);   nbytes += nb;
      
      
      double p = 1.0*sqrt(2.0*LaserE*mmu+LaserE*LaserE);
      double g = 1.0*(mmu+LaserE)/mmu;
      double b = 1.0*sqrt(2.0*LaserE*mmu+LaserE*LaserE)/(mmu+LaserE);
      

      double tempX = TMath::ACos(  ((double)rand()/(RAND_MAX)) );
      double tempY = ((double) rand()/(RAND_MAX)) * 2 * PI;

      double theta = tempX;  // [0,+PI] radians
      double phi = tempY; //[0,+2PI] radians

      //LaserXp = sin(theta)*cos(phi)/cos(theta);
      //LaserYp = sin(theta)*sin(phi)/cos(theta);

      //cout << g << "\t" << b << endl;
      //LaserX = 10; LaserXp = 0; LaserY = 0; LaserYp = 0; LaserZ = 3;
      //LaserX = tmpa; 
      LaserXp = 0; 
      //LaserY = tmpb; 
      LaserYp = 0; 
      //LaserZ = tmpc;
      //if(abs(LaserY)<1 && abs(LaserX)<5){
         cout<<LaserX<<" "<<LaserY<<" "<<LaserZ<<endl;

         wf << LaserX*0.1 << " "
         << LaserXp*1000 << " "
         << LaserY*0.1 << " "
         << LaserYp*1000 << " "
         << mmu/1000*g*b << " "
         << LaserZ << " "
         << TBeam*1e9 << " "
         << "-1 -1" << endl;

         hLaserX->Fill(LaserX);// = new TH1D("hLaserX","hLaserX",200,-100,100); // mm
         hLaserXp->Fill(LaserXp);// = new TH1D("hLaserXp","hLaserXp",200,-6,6); // mm
         hLaserY->Fill(LaserY);// = new TH1D("hLaserY","hLaserY",200,-25,25); // mm
         hLaserYp->Fill(LaserYp);// = new TH1D("hLaserYp","hLaserYp",200,-8,8); // mm
         hLaserZ->Fill(LaserZ);// = new TH1D("hLaserZ","hLaserZ",200,0,7); // mm
         hLaserE->Fill(LaserE);// = new TH1D("hLaserE","hLaserE",200,0,0.3e-6); // mm
         TgtXY->Fill(LaserX,LaserY);

         hLaserXXp->Fill(LaserX,LaserXp);// = new TH1D("hLaserXp","hLaserXp",200,-6,6); // mm
         hLaserYYp->Fill(LaserY,LaserYp);// = new TH1D("hLaserXp","hLaserXp",200,-6,6); // mm
      //}
/*
      hX->Fill(X0);
      hY->Fill(Y0);
      hZ->Fill(Z0);
      TgtXY->Fill(X0,Y0);
*/
      if (Cut(ientry) < 0) continue;
   }


   wf.close();

      c->cd(1);
   SetstyleHist1(hLaserX);
   hLaserX->SetTitle("Mu X at the laser time 1.2 us; x(mm); N");
   hLaserX->Draw();
   
   c->cd(2);
   SetstyleHist1(hLaserY);
   hLaserY->SetTitle("Mu Y at the laser time 1.2 us; y(mm); N");
   hLaserY->Draw();
   c->cd(3);
   hLaserZ->SetTitle("Mu Z at the laser time 1.2 us; z(mm); N");
   SetstyleHist1(hLaserZ);
   hLaserZ  ->Draw();
   
   c->cd(4);
   //hLaserXp->Draw();
   hLaserXXp->SetTitle(";X(mm);Xp");
   hLaserXXp->Draw("colz");
   
   c->cd(5);
   //hLaserYp->Draw();
   hLaserYYp->SetTitle(";Y(mm);Yp");
   hLaserYYp->Draw("colz");
   
   c->cd(6);
   hLaserE->SetTitle("Mu kinetic E at the laser time 1.2 us; Ek(MeV); N");
   SetstyleHist1(hLaserE);
   //hLaserE->Draw();
   TgtXY->Draw("colz");

/*
   c2->Divide(2,1);
   c2->cd(1);
   hLaserXXp->Draw("colz");
   c2->cd(2);
   hLaserYYp->Draw("colz");

   c3->cd(1);SetstyleHist1(hX);hX->SetTitle("Initial X inside the target; x(mm); N");hX->Draw();
   c3->cd(2);SetstyleHist1(hY);hY->SetTitle("Initial X inside the target; y(mm); N");hY->Draw();
   c3->cd(3);SetstyleHist1(hZ);hZ->SetTitle("Initial Z inside the target; z(mm); N");hZ->Draw();
   
   c3->cd(4);TgtXY->SetTitle("Initial XY inside the target; X(mm); Y(mm)"); TgtXY->Draw("colz");
   */
}
