#include <iostream>
#include <vector>
using namespace std;

#include "TH1D.h"
#include "TFile.h"
#include "TGraphAsymmErrors.h"

#include "CommandLine.h"
#include "CustomAssert.h"

int main(int argc, char *argv[]);

int main(int argc, char *argv[])
{
   CommandLine CL(argc, argv);

   vector<string> FileNames   = CL.GetStringVector("Input");
   vector<string> Numerator   = CL.GetStringVector("Numerator");
   vector<string> Denominator = CL.GetStringVector("Denominator");
   vector<string> Names       = CL.GetStringVector("Name");
   vector<int> Rebins         = CL.GetIntVector("Rebin");

   string OutputFileName      = CL.Get("Output");

   int N = FileNames.size();

   Assert(N == FileNames.size(),   "Number of files do not match!");
   Assert(N == Numerator.size(),   "Number of numerators do not match!");
   Assert(N == Denominator.size(), "Number of denominators do not match!");
   Assert(N == Names.size(),       "Number of names do not match!");
   Assert(N == Rebins.size(),      "Number of rebins do not match!");

   TFile OutputFile(OutputFileName.c_str(), "RECREATE");

   for(int i = 0; i < N; i++)
   {
      TFile InputFile(FileNames[i].c_str());

      TH1D *H1 = (TH1D *)InputFile.Get(Numerator[i].c_str());
      TH1D *H2 = (TH1D *)InputFile.Get(Denominator[i].c_str());

      if(H1 != nullptr && H2 != nullptr)
      {
         H1->Rebin(Rebins[i]);
         H2->Rebin(Rebins[i]);

         OutputFile.cd();

         TGraphAsymmErrors G;
         G.Divide(H1, H2);
         G.SetName(Names[i].c_str());
         G.Write();
      }

      InputFile.Close();
   }

   OutputFile.Close();

   return 0;
}


