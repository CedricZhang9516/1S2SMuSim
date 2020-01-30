void ns_opticxx()
{
//=========Macro generated from canvas: c1/c1
//=========  (Tue Mar  5 17:57:58 2019) by ROOT version 6.14/06
   TCanvas *c1 = new TCanvas("c1", "c1",10,45,700,500);
   c1->Range(481.25,188,593.75,1532);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   Double_t _fx1[6] = {
   1.1,1.2,1.3,1.4,1.5,1.6};
   Double_t _efx1[6] = {
   0,
   0,
   0,
   0,
0,
0};
   Double_t _fy1[6] = {
   50,
 70,
88,
81,
78,
67};
   Double_t _efy1[6] = {
   sqrt(50),
   sqrt(70),
   sqrt(88),
   sqrt(81),
      sqrt(78),
         sqrt(67)
};

Double_t _fy2[6] = {
   6.33,
7.26,7.73,
8.04,
7.27,
7.03};
   TGraphErrors *graph = new TGraphErrors(6,_fx1,_fy1,_efx1,_efy1);
   graph->SetName("");
   graph->SetTitle("Pulse_optimization;shooting time(ns);N_selected");
   graph->SetFillStyle(1000);
   //graph->SetLineStyle(4);
   graph->SetLineWidth(1);
   graph->SetMarkerStyle(3);
   /*
   TH1F *Graph_Graph1 = new TH1F("Graph_Graph1","DG_optimization",100,492.5,582.5);
   Graph_Graph1->SetMinimum(322.4);
   Graph_Graph1->SetMaximum(1397.6);
   Graph_Graph1->SetDirectory(0);
   Graph_Graph1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_Graph1->SetLineColor(ci);
   Graph_Graph1->GetXaxis()->SetTitle("thickness(um)");
   Graph_Graph1->GetXaxis()->SetLabelFont(42);
   Graph_Graph1->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1->GetXaxis()->SetTitleFont(42);
   Graph_Graph1->GetYaxis()->SetTitle("Ntot");
   Graph_Graph1->GetYaxis()->SetLabelFont(42);
   Graph_Graph1->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1->GetYaxis()->SetTitleOffset(0);
   Graph_Graph1->GetYaxis()->SetTitleFont(42);
   Graph_Graph1->GetZaxis()->SetLabelFont(42);
   Graph_Graph1->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1->GetZaxis()->SetTitleFont(42);
   //graph->SetHistogram(Graph_Graph1);
   */
   graph->Draw("alp");
   /*
   TPaveText *pt = new TPaveText(0.3538968,0.9368947,0.6461032,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *pt_LaTex = pt->AddText("DG_optimization");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
   */
}
