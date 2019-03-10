#include <iostream>
#include <vector>
using namespace std;

#include "TF1.h"
#include "TFile.h"
#include "TH1D.h"
#include "TGraphAsymmErrors.h"
#include "TH2D.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TLegend.h"
#include "TPaveStats.h"

#include "PlotHelper3.h"
#include "SetStyle.h"
#include "CommandLine.h"

#include "HelperFunctions.h"

int main(int argc, char *argv[]);
void ProcessFile(PdfFileHelper &PdfFile, string FileName,
   string Prefix, vector<double> Thresholds,
   double Target, string Tag, string Name = "PT", int Type = TYPE_SMOOTH_SUPERTIGHT);

int main(int argc, char *argv[])
{
   CommandLine CL(argc, argv);

   string InputFileName = CL.Get("input");
   string OutputFileName = CL.Get("output");
   string CurvesFileName = CL.Get("curves");

   SetThesisStyle();

   PdfFileHelper PdfFile(OutputFileName);
   PdfFile.AddTextPage("Scaling plots :D");
   
   TFile OutputFile(CurvesFileName.c_str(), "RECREATE");
   OutputFile.Close();

   vector<double> EGThresholds = {12, 15, 20, 25, 30};
   vector<double> MuonThresholds = {12, 15, 20, 25, 30};
   vector<double> JetThresholds = {25, 50, 75, 100, 150, 200, 250, 300};
   vector<double> HTThresholds = {50, 100, 150, 200, 250, 300, 350, 400, 450, 500};
   vector<double> MHTThresholds = {20, 40, 60, 80, 100, 125, 150};
   vector<double> METThresholds = {20, 40, 60, 80, 100, 125, 150};

   ProcessFile(PdfFile, InputFileName, "Jet/Jet",             JetThresholds,  0.95, "TTbarJet",       "PT", TYPE_FIT);
   ProcessFile(PdfFile, InputFileName, "Muon/Muon",           MuonThresholds, 0.95, "TTbarMuon",      "PT", TYPE_FIT);
   ProcessFile(PdfFile, InputFileName, "MuonKF/MuonKF",       MuonThresholds, 0.95, "TTbarMuonKF",    "PT", TYPE_SMOOTH_TIGHT);
   ProcessFile(PdfFile, InputFileName, "EG/EG",               EGThresholds,   0.95, "TTbarEG",        "PT");
   ProcessFile(PdfFile, InputFileName, "EG/EG",               EGThresholds,   0.95, "TTbarEG",        "PTEta15");
   ProcessFile(PdfFile, InputFileName, "EG/EG",               EGThresholds,   0.95, "TTbarEG",        "PTEtaLarge");
   ProcessFile(PdfFile, InputFileName, "TkEG/TkEG",           EGThresholds,   0.95, "TTbarTkEG",      "PT");
   ProcessFile(PdfFile, InputFileName, "TkEG/TkEG",           EGThresholds,   0.95, "TTbarTkEG",      "PTEta15");
   ProcessFile(PdfFile, InputFileName, "TkEG/TkEG",           EGThresholds,   0.95, "TTbarTkEG",      "PTEtaLarge");
   ProcessFile(PdfFile, InputFileName, "TkEM/TkEM",           EGThresholds,   0.95, "TTbarTkEM",      "PT");
   ProcessFile(PdfFile, InputFileName, "TkEM/TkEM",           EGThresholds,   0.95, "TTbarTkEM",      "PTEta15");
   ProcessFile(PdfFile, InputFileName, "TkEM/TkEM",           EGThresholds,   0.95, "TTbarTkEM",      "PTEtaLarge");
   ProcessFile(PdfFile, InputFileName, "TkJet/TkJet",         JetThresholds,  0.95, "TTbarTkJet",     "PT", TYPE_FIT);
   ProcessFile(PdfFile, InputFileName, "TkCaloJet/TkCaloJet", JetThresholds,  0.95, "TTbarTkCaloJet", "PT", TYPE_FIT);
   ProcessFile(PdfFile, InputFileName, "TkMuon/TkMuon",       MuonThresholds, 0.95, "TTbarTkMuon",    "PT", TYPE_SMOOTH_TIGHT);
   ProcessFile(PdfFile, InputFileName, "PuppiJet/PuppiJet",   JetThresholds,  0.95, "TTbarPuppiJet",  "PT", TYPE_FIT);
   ProcessFile(PdfFile, InputFileName, "TkHT/TkHT",           HTThresholds,   0.95, "TTbarTkHT",      "PT", TYPE_SMOOTH_TIGHT);
   ProcessFile(PdfFile, InputFileName, "TkMHT/TkMHT",         MHTThresholds,  0.95, "TTbarTkMHT",     "PT", TYPE_SMOOTH_TIGHT);
   ProcessFile(PdfFile, InputFileName, "TkMET/TkMET",         METThresholds,  0.95, "TTbarTkMET",     "PT", TYPE_SMOOTH_TIGHT);
   ProcessFile(PdfFile, InputFileName, "PuppiHT/PuppiHT",     HTThresholds,   0.95, "TTbarPuppiHT",   "PT", TYPE_SMOOTH_TIGHT);
   ProcessFile(PdfFile, InputFileName, "PuppiMHT/PuppiMHT",   MHTThresholds,  0.95, "TTbarPuppiMHT",  "PT", TYPE_FIT);
   ProcessFile(PdfFile, InputFileName, "PuppiMET/PuppiMET",   METThresholds,  0.95, "TTbarPuppiMET",  "PT", TYPE_FIT);
   
   PdfFile.AddTimeStampPage();
   PdfFile.Close();

   return 0;
}

void ProcessFile(PdfFileHelper &PdfFile, string FileName,
   string Prefix, vector<double> Thresholds,
   double Target, string Tag, string Name, int Type)
{
   string TypeString = "UNKNOWN";
   if(Type == TYPE_FIT)
      TypeString = "TYPE_FIT";
   if(Type == TYPE_SMOOTH_LOOSE)
      TypeString = "TYPE_SMOOTH_LOOSE";
   if(Type == TYPE_SMOOTH_TIGHT)
      TypeString = "TYPE_SMOOTH_TIGHT";
   if(Type == TYPE_SMOOTH_SUPERTIGHT)
      TypeString = "TYPE_SMOOTH_SUPERTIGHT";
   if(Type == TYPE_SMOOTH_ULTRATIGHT)
      TypeString = "TYPE_SMOOTH_ULTRATIGHT";

   vector<string> Text(11);
   Text[0] = "Plots for file";
   Text[1] = FileName;
   Text[2] = "";
   Text[3] = "...and object prefix";
   Text[4] = Prefix;
   Text[5] = "";
   Text[6] = "...and type";
   Text[7] = TypeString;
   Text[8] = "";
   Text[9] = "...and name";
   Text[10] = Name;
   PdfFile.AddTextPage(Text);

   TFile File(FileName.c_str());

   vector<double> CrossOver(Thresholds.size());

   for(int i = 0; i < (int)Thresholds.size(); i++)
   {
      PdfFile.AddTextPage(Form("Threshold = %.1f", Thresholds[i]));
      if(Type == TYPE_SMOOTH_LOOSE || Type == TYPE_SMOOTH_TIGHT
         || Type == TYPE_SMOOTH_SUPERTIGHT || Type == TYPE_SMOOTH_ULTRATIGHT)
         CrossOver[i] = SmoothTurnOn(PdfFile,
            (TH1D *)File.Get(Form("%s_%s_%06d", Prefix.c_str(), Name.c_str(), (int)Thresholds[i] * 100)),
            (TH1D *)File.Get(Form("%s_%s_000000", Prefix.c_str(), Name.c_str())), Target, Type);
      if(Type == TYPE_FIT)
         CrossOver[i] = FitTurnOn(PdfFile,
            (TH1D *)File.Get(Form("%s_%s_%06d", Prefix.c_str(), Name.c_str(), (int)Thresholds[i] * 100)),
            (TH1D *)File.Get(Form("%s_%s_000000", Prefix.c_str(), Name.c_str())), Target, false, false);
   }

   File.Close();
   
   PdfFile.AddTextPage("Scaling Curve");
   
   TFile OutputFile("ScalingCurves.root", "UPDATE");

   TGraph G;
   G.SetNameTitle(Tag.c_str(), "");
   G.GetXaxis()->SetTitle("Threshold");
   G.GetYaxis()->SetTitle("95\% location");

   for(int i = 0; i < (int)Thresholds.size(); i++)
   {
      cout << Thresholds[i] << " " << CrossOver[i] << endl;
      if(CrossOver[i] > 0)
         G.SetPoint(G.GetN(), Thresholds[i], CrossOver[i]);
   }
   PdfFile.AddPlot(G, "apl");

   G.Write();

   OutputFile.Close();
}


