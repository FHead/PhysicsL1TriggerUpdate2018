#include "Messenger.h"

L1NTupleMessenger::L1NTupleMessenger(TFile &File, string TreeName)
{
   Tree = (TTree *)File.Get(TreeName.c_str());
   
   Event = NULL;
   GCT = NULL;
   Generator = NULL;
   Simulation = NULL;
   GMT = NULL;
   GT = NULL;
   RCT = NULL;
   DTTF = NULL;
   CALO = NULL;

   SetBranchAddress();
}

L1NTupleMessenger::~L1NTupleMessenger()
{
}

void L1NTupleMessenger::SetBranchAddress()
{
   if(Tree == NULL)
      return;

   Tree->SetBranchAddress("Event", &Event);
   Tree->SetBranchAddress("GCT", &GCT);
   Tree->SetBranchAddress("Generator", &Generator);
   Tree->SetBranchAddress("Simulation", &Simulation);
   Tree->SetBranchAddress("GMT", &GMT);
   Tree->SetBranchAddress("GT", &GT);
   Tree->SetBranchAddress("RCT", &RCT);
   Tree->SetBranchAddress("DTTF", &DTTF);
   Tree->SetBranchAddress("CALO", &CALO);
}

bool L1NTupleMessenger::GetEntry(int Entry)
{
   if(Tree == NULL)
      return false;

   Tree->GetEntry(Entry);

   GenP.clear();
   GenID.clear();
   GenStatus.clear();

   if(Generator != NULL)
   {
      for(int i = 0; i < (int)Generator->partId.size(); i++)
      {
         FourVector P;
         P.SetPtEtaPhi(Generator->partPt[i], Generator->partEta[i], Generator->partPhi[i]);
         P[0] = Generator->partE[i];
         GenP.push_back(P);

         GenID.push_back(Generator->partId[i]);

         GenStatus.push_back(Generator->partStat[i]);
      }
   }

   return true;
}

L1ExtraUpgradeTreeMessenger::L1ExtraUpgradeTreeMessenger(TFile &File, string TreeName)
{
   Tree = (TTree *)File.Get(TreeName.c_str());

   L1ExtraUpgrade = NULL;

   SetBranchAddress();
}

L1ExtraUpgradeTreeMessenger::~L1ExtraUpgradeTreeMessenger()
{
}
   
void L1ExtraUpgradeTreeMessenger::SetBranchAddress()
{
   if(Tree == NULL)
      return;

   Tree->SetBranchAddress("L1ExtraUpgrade", &L1ExtraUpgrade);
}

bool L1ExtraUpgradeTreeMessenger::GetEntry(int Entry)
{
   if(Tree == NULL)
      return false;

   Tree->GetEntry(Entry);

   vector<double> D0;
   vector<int> I0;

   FillObject(EG, L1ExtraUpgrade->nEG, &L1ExtraUpgrade->egEt, &L1ExtraUpgrade->egEta, &L1ExtraUpgrade->egPhi, &L1ExtraUpgrade->egBx, &D0, &D0, &D0);
   FillObject(IsoEG, L1ExtraUpgrade->nIsoEG, &L1ExtraUpgrade->isoEGEt, &L1ExtraUpgrade->isoEGEta, &L1ExtraUpgrade->isoEGPhi, &L1ExtraUpgrade->isoEGBx, &D0, &D0, &D0);
   FillObject(TkEG, L1ExtraUpgrade->nTkEG, &L1ExtraUpgrade->tkEGEt, &L1ExtraUpgrade->tkEGEta, &L1ExtraUpgrade->tkEGPhi, &L1ExtraUpgrade->tkEGBx, &L1ExtraUpgrade->tkEGTrkIso, &L1ExtraUpgrade->tkEGzVtx, &D0);
   FillObject(TkEG2, L1ExtraUpgrade->nTkEG2, &L1ExtraUpgrade->tkEG2Et, &L1ExtraUpgrade->tkEG2Eta, &L1ExtraUpgrade->tkEG2Phi, &L1ExtraUpgrade->tkEG2Bx, &L1ExtraUpgrade->tkEG2TrkIso, &L1ExtraUpgrade->tkEG2zVtx, &D0);
   FillObject(TkIsoEG, L1ExtraUpgrade->nTkIsoEG, &L1ExtraUpgrade->tkIsoEGEt, &L1ExtraUpgrade->tkIsoEGEta, &L1ExtraUpgrade->tkIsoEGPhi, &L1ExtraUpgrade->tkIsoEGBx, &L1ExtraUpgrade->tkIsoEGTrkIso, &L1ExtraUpgrade->tkIsoEGzVtx, &D0);
   FillObject(TkEM, L1ExtraUpgrade->nTkEM, &L1ExtraUpgrade->tkEMEt, &L1ExtraUpgrade->tkEMEta, &L1ExtraUpgrade->tkEMPhi, &L1ExtraUpgrade->tkEMBx, &L1ExtraUpgrade->tkEMTrkIso, &D0, &D0);
   FillObject(Tau, L1ExtraUpgrade->nTau, &L1ExtraUpgrade->tauEt, &L1ExtraUpgrade->tauEta, &L1ExtraUpgrade->tauPhi, &L1ExtraUpgrade->tauBx, &D0, &D0, &D0);
   FillObject(IsoTau, L1ExtraUpgrade->nIsoTau, &L1ExtraUpgrade->isoTauEt, &L1ExtraUpgrade->isoTauEta, &L1ExtraUpgrade->isoTauPhi, &L1ExtraUpgrade->isoTauBx, &D0, &D0, &D0);
   FillObject(TkTau, L1ExtraUpgrade->nTkTau, &L1ExtraUpgrade->tkTauEt, &L1ExtraUpgrade->tkTauEta, &L1ExtraUpgrade->tkTauPhi, &L1ExtraUpgrade->tkTauBx, &L1ExtraUpgrade->tkTauTrkIso, &L1ExtraUpgrade->tkTauzVtx, &D0);
   FillObject(Jet, L1ExtraUpgrade->nJets, &L1ExtraUpgrade->jetEt, &L1ExtraUpgrade->jetEta, &L1ExtraUpgrade->jetPhi, &L1ExtraUpgrade->jetBx, &D0, &D0, &D0);
   FillObject(TkJet, L1ExtraUpgrade->nTkJets, &L1ExtraUpgrade->tkJetEt, &L1ExtraUpgrade->tkJetEta, &L1ExtraUpgrade->tkJetPhi, &L1ExtraUpgrade->tkJetBx, &D0, &L1ExtraUpgrade->tkJetzVtx, &D0);
   FillObject(FwdJet, L1ExtraUpgrade->nFwdJets, &L1ExtraUpgrade->fwdJetEt, &L1ExtraUpgrade->fwdJetEta, &L1ExtraUpgrade->fwdJetPhi, &L1ExtraUpgrade->fwdJetBx, &D0, &D0, &D0);

   FillObject(Muon, L1ExtraUpgrade->nMuons, &L1ExtraUpgrade->muonEt, &L1ExtraUpgrade->muonEta, &L1ExtraUpgrade->muonPhi, &L1ExtraUpgrade->muonBx, &D0, &D0, &D0);
   // vector<int>     muonChg;
   // vector<unsigned int> muonIso;
   // vector<unsigned int> muonFwd;
   // vector<unsigned int> muonMip;
   // vector<unsigned int> muonRPC;
   // vector<int>     muonQuality;
   
   FillObject(TkMuon, L1ExtraUpgrade->nTkMuons, &L1ExtraUpgrade->tkMuonEt, &L1ExtraUpgrade->tkMuonEta, &L1ExtraUpgrade->tkMuonPhi, &L1ExtraUpgrade->tkMuonBx, &L1ExtraUpgrade->tkMuonTrkIso, &L1ExtraUpgrade->tkMuonzVtx, &D0);
   // vector<int>     tkMuonChg;
   // vector<unsigned int> tkMuonIso;
   // vector<unsigned int> tkMuonFwd;
   // vector<unsigned int> tkMuonMip;
   // vector<unsigned int> tkMuonRPC;
   // vector<unsigned int> tkMuonQuality;

   FillObject(MET, L1ExtraUpgrade->nMet, &L1ExtraUpgrade->met, &D0, &L1ExtraUpgrade->metPhi, &L1ExtraUpgrade->metBx, &D0, &D0, &L1ExtraUpgrade->et);
   FillObject(TkMET, L1ExtraUpgrade->nTkMet, &L1ExtraUpgrade->tkMet, &D0, &L1ExtraUpgrade->tkMetPhi, &L1ExtraUpgrade->tkMetBx, &D0, &D0, &L1ExtraUpgrade->tkEt);
   FillObject(MHT, L1ExtraUpgrade->nMht, &L1ExtraUpgrade->mht, &D0, &L1ExtraUpgrade->mhtPhi, &L1ExtraUpgrade->mhtBx, &D0, &D0, &L1ExtraUpgrade->et);
   FillObject(TkMHT, L1ExtraUpgrade->nTkMht, &L1ExtraUpgrade->tkMht, &D0, &L1ExtraUpgrade->tkMhtPhi, &L1ExtraUpgrade->tkMhtBx, &D0, &D0, &L1ExtraUpgrade->tkEt);

   return true;
}

void L1ExtraUpgradeTreeMessenger::FillObject(vector<GenericObject> &V, int N,
   vector<double> *ET, vector<double> *Eta, vector<double> *Phi, vector<int> *Bx,
   vector<double> *Iso, vector<double> *VZ, vector<double> *PET)
{
   V.clear();

   for(int i = 0; i < N; i++)
   {
      GenericObject O;

      double TempET = (ET->size() > i) ? (*ET)[i] : -1;
      double TempEta = (Eta->size() > i) ? (*Eta)[i] : -1;
      double TempPhi = (Phi->size() > i) ? (*Phi)[i] : -1;

      O.P.SetPtEtaPhi(TempET, TempEta, TempPhi);
      O.Bx = (Bx->size() > i) ? (*Bx)[i] : -1;
      O.Iso = (Iso->size() > i) ? (*Iso)[i] : -1;
      O.VZ = (VZ->size() > i) ? (*VZ)[i] : -1;
      O.PET = (PET->size() > i) ? (*PET)[i] : -1;

      V.push_back(O);
   }
}

void L1ExtraUpgradeTreeMessenger::FillObject(vector<GenericObject> &V, int N,
   vector<double> *ET, vector<double> *Eta, vector<double> *Phi, vector<double> *Bx,
   vector<double> *Iso, vector<double> *VZ, vector<double> *PET)
{
   V.clear();

   for(int i = 0; i < N; i++)
   {
      GenericObject O;

      double TempET = (ET->size() > i) ? (*ET)[i] : -1;
      double TempEta = (Eta->size() > i) ? (*Eta)[i] : -1;
      double TempPhi = (Phi->size() > i) ? (*Phi)[i] : -1;
      
      O.P.SetPtEtaPhi(TempET, TempEta, TempPhi);
      O.Bx = (Bx->size() > i) ? (*Bx)[i] : -1;
      O.Iso = (Iso->size() > i) ? (*Iso)[i] : -1;
      O.VZ = (VZ->size() > i) ? (*VZ)[i] : -1;
      O.PET = (PET->size() > i) ? (*PET)[i] : -1;

      V.push_back(O);
   }
}
L1PhaseIITreeV11p1Messenger::L1PhaseIITreeV11p1Messenger(TFile &File, string TreeName)
{
   Tree = (TTree *)File.Get(TreeName.c_str());

   L1PhaseII = NULL;

   SetBranchAddress();
}

L1PhaseIITreeV11p1Messenger::~L1PhaseIITreeV11p1Messenger()
{
}
   
void L1PhaseIITreeV11p1Messenger::SetBranchAddress()
{
   if(Tree == NULL)
      return;

   Tree->SetBranchAddress("L1PhaseII", &L1PhaseII);
}

bool L1PhaseIITreeV11p1Messenger::GetEntry(int Entry)
{
   if(Tree == NULL)
      return false;

   Tree->GetEntry(Entry);

   L1Analysis::L1AnalysisPhaseIIStep1DataFormat *P = L1PhaseII;

   vector<double> D0;
      
   // CaloTau: IEt, IEta, IPhi, TowerIPhi, TowerIEta, RawEt, IsoEt, NTT, HasEM, IsMerged
   vector<double> CaloTauRegion = GetRegionFromEta(P->caloTauEta);
   FillObject(CaloTau, P->nCaloTaus,
      &P->caloTauEt, &P->caloTauEta, &P->caloTauPhi,
      &P->caloTauBx, &P->caloTauIso, &D0, &D0,
      &P->caloTauHwQual, &CaloTauRegion, &D0, &D0,
      &D0);

   // PFPhase1Jets
   vector<double> PFPhase1JetRegion = GetRegionFromEta(P->pfPhase1L1JetEta);
   FillObject(PFPhase1Jet, P->nPfPhase1L1Jets,
      &P->pfPhase1L1JetEt, &P->pfPhase1L1JetEta, &P->pfPhase1L1JetPhi,
      &D0, &D0, &D0, &D0,
      &D0, &PFPhase1JetRegion, &D0, &D0,
      &D0);

   // PFPhase1HT, PFPhase1MHT
   FillObject(PFPhase1HT, P->nPfPhase1L1MHT,
      &P->pfPhase1L1HT, &D0, &D0,
      &D0, &D0, &D0, &D0,
      &D0, &D0, &D0, &P->pfPhase1L1HT,
      &D0);
   FillObject(PFPhase1MHT, P->nPfPhase1L1MHT,
      &P->pfPhase1L1MHTEt, &D0, &P->pfPhase1L1MHTPhi,
      &D0, &D0, &D0, &P->pfPhase1L1HT,
      &D0, &D0, &D0, &D0,
      &D0);

   // EG
   FillObject(EG, P->nEG,
      &P->EGEt, &P->EGEta, &P->EGPhi,
      &P->EGBx, &P->EGIso, &P->EGzVtx, &D0,
      &P->EGHwQual, &P->EGHGC, &P->EGPassesPhotonID, &D0,
      &D0);
   FillObject(EGTrackID, P->nEG,
      &P->EGEt, &P->EGEta, &P->EGPhi,
      &P->EGBx, &P->EGIso, &P->EGzVtx, &D0,
      &P->EGHwQual, &P->EGHGC, &P->EGPassesLooseTrackID, &D0,
      &D0);

   // TkElectron: EGRefPt, EGRefEta, EGRefPhi
   FillObject(TkElectron, P->nTkElectrons,
      &P->tkElectronEt, &P->tkElectronEta, &P->tkElectronPhi,
      &P->tkElectronBx, &P->tkElectronTrkIso, &P->tkElectronzVtx, &D0,
      &P->tkElectronHwQual, &P->tkElectronHGC, &P->tkElectronPassesPhotonID, &P->tkElectronChg,
      &D0);
   FillObject(TkElectronTrackID, P->nTkElectrons,
      &P->tkElectronEt, &P->tkElectronEta, &P->tkElectronPhi,
      &P->tkElectronBx, &P->tkElectronTrkIso, &P->tkElectronzVtx, &D0,
      &P->tkElectronHwQual, &P->tkElectronHGC, &P->tkElectronPassesLooseTrackID, &P->tkElectronChg,
      &D0);

   // TkPhoton: EGRefPt, EGRefEta, EGRefPhi
   FillObject(TkPhoton, P->nTkPhotons,
      &P->tkPhotonEt, &P->tkPhotonEta, &P->tkPhotonPhi,
      &P->tkPhotonBx, &P->tkPhotonTrkIso, &P->tkPhotonzVtx, &D0,
      &P->tkPhotonHwQual, &P->tkPhotonHGC, &P->tkPhotonPassesPhotonID, &D0,
      &D0);
   FillObject(TkPhotonTrackID, P->nTkPhotons,
      &P->tkPhotonEt, &P->tkPhotonEta, &P->tkPhotonPhi,
      &P->tkPhotonBx, &P->tkPhotonTrkIso, &P->tkPhotonzVtx, &D0,
      &P->tkPhotonHwQual, &P->tkPhotonHGC, &P->tkPhotonPassesLooseTrackID, &D0,
      &D0);
   FillObject(TkPhotonPVTrackID, P->nTkPhotons,
      &P->tkPhotonEt, &P->tkPhotonEta, &P->tkPhotonPhi,
      &P->tkPhotonBx, &P->tkPhotonTrkIsoPV, &P->tkPhotonzVtx, &D0,
      &P->tkPhotonHwQual, &P->tkPhotonHGC, &P->tkPhotonPassesLooseTrackID, &D0,
      &D0);

   // StandaloneMuon: Pt2
   vector<unsigned short int> StandaloneMuonNewQual = P->standaloneMuonQual;
   for(int i = 0; i < P->nStandaloneMuons; i++)
      if(P->standaloneMuonRegion[i] == 3)
         StandaloneMuonNewQual[i] = P->standaloneMuonEMTFQual[i];
   FillObject(StandaloneMuon, P->nStandaloneMuons,
      &P->standaloneMuonPt, &P->standaloneMuonEta, &P->standaloneMuonPhi,
      &P->standaloneMuonBx, &D0, &D0, &D0,
      &StandaloneMuonNewQual, &P->standaloneMuonRegion, &D0, &P->standaloneMuonChg,
      &D0);

   // TkMuon: MuRefPt, TrkRefPt, MuRefPhi, MuRefEta, DRMuTrack, NMatchedTracks, MuRefChg
   vector<unsigned int> TkMuonNewQual = P->tkMuonQual;
   for(int i = 0; i < P->nTkMuons; i++)
      if(P->tkMuonRegion[i] == 3)
         TkMuonNewQual[i] = P->tkMuonEMTFQual[i];
   FillObject(TkMuon, P->nTkMuons,
      &P->tkMuonPt, &P->tkMuonEta, &P->tkMuonPhi,
      &P->tkMuonBx, &P->tkMuonTrkIso, &P->tkMuonzVtx, &D0,
      &TkMuonNewQual, &P->tkMuonRegion, &D0, &P->tkMuonChg,
      &D0);

   // PuppiMET
   vector<double> PuppiMETEt = {P->puppiMETEt};
   vector<double> PuppiMETPhi = {P->puppiMETPhi};
   FillObject(PuppiMET, 1,
      &PuppiMETEt, &D0, &PuppiMETPhi,
      &D0, &D0, &D0, &D0,
      &D0, &D0, &D0, &D0,
      &D0);

   // NNTau: ChargedIso, PassLoosePF, PassTightPF, ID
   vector<double> NNTauRegion = GetRegionFromEta(P->nnTauEta);
   FillObject(NNTau, P->nNNTaus,
      &P->nnTauEt, &P->nnTauEta, &P->nnTauPhi,
      &D0, &P->nnTauFullIso, &D0, &D0,
      &D0, &NNTauRegion, &P->nnTauPassTightNN, &P->nnTauChg,
      &D0);
   FillObject(NNTauLoose, P->nNNTaus,
      &P->nnTauEt, &P->nnTauEta, &P->nnTauPhi,
      &D0, &P->nnTauFullIso, &D0, &D0,
      &D0, &NNTauRegion, &P->nnTauPassLooseNN, &P->nnTauChg,
      &D0);
   FillObject(NNTauPF, P->nNNTaus,
      &P->nnTauEt, &P->nnTauEta, &P->nnTauPhi,
      &D0, &P->nnTauFullIso, &D0, &D0,
      &D0, &NNTauRegion, &P->nnTauPassTightPF, &P->nnTauChg,
      &D0);
   FillObject(NNTauLoosePF, P->nNNTaus,
      &P->nnTauEt, &P->nnTauEta, &P->nnTauPhi,
      &D0, &P->nnTauFullIso, &D0, &D0,
      &D0, &NNTauRegion, &P->nnTauPassLoosePF, &P->nnTauChg,
      &D0);

   return true;
}
   
vector<double> L1PhaseIITreeV11p1Messenger::GetRegionFromEta(vector<double> &Eta)
{
   vector<double> Result(Eta.size());

   for(int i = 0; i < (int)Eta.size(); i++)
   {
      if(abs(Eta[i]) < 1.5)
         Result[i] = 0;
      else
         Result[i] = 1;
   }

   return Result;
}
   
L1GenMessenger::L1GenMessenger(TFile &File, string TreeName)
{
   Tree = (TTree *)File.Get(TreeName.c_str());
   
   Generator = NULL;

   SetBranchAddress();
}

L1GenMessenger::~L1GenMessenger()
{
}

void L1GenMessenger::SetBranchAddress()
{
   if(Tree == NULL)
      return;

   Tree->SetBranchAddress("Generator", &Generator);
}

bool L1GenMessenger::GetEntry(int Entry)
{
   if(Tree == NULL)
      return false;

   Tree->GetEntry(Entry);

   GenP.clear();
   GenID.clear();
   GenStatus.clear();
   GenCharge.clear();
   GenParent.clear();
   GenDaughter.clear();
   GenDxy.clear();
   GenLxy.clear();
   GenJet.clear();
   GenMETTrue = FourVector(0, 0, 0, 0);
   GenMETCalo = FourVector(0, 0, 0, 0);

   if(Generator != NULL)
   {
      for(int i = 0; i < (int)Generator->partId.size(); i++)
      {
         FourVector P;
         P.SetPtEtaPhi(Generator->partPt[i], Generator->partEta[i], Generator->partPhi[i]);
         P[0] = Generator->partE[i];
         GenP.push_back(P);

         GenID.push_back(Generator->partId[i]);
         GenStatus.push_back(Generator->partStat[i]);
         GenCharge.push_back(Generator->partCh[i]);
         GenParent.push_back(Generator->partParent[i]);
         // GenDxy.push_back(Generator->partDxy[i]);
         // GenLxy.push_back(Generator->partLxy[i]);
         GenDxy.push_back(-1);
         GenLxy.push_back(-1);
         GenDaughter.push_back(vector<int>());
      }

      int N = Generator->partId.size();
      for(int i = 0; i < (int)Generator->partId.size(); i++)
      {
         int Parent = GenParent[i];
         if(Parent >= 0 && Parent < N)
            GenDaughter[Parent].push_back(i);
      }

      for(int i = 0; i < Generator->nJet; i++)
      {
         FourVector J;
         double PT =   ((Generator->jetPt.size() > i) ?  Generator->jetPt[i] :  0);
         double Eta =  ((Generator->jetEta.size() > i) ? Generator->jetEta[i] : 0);
         double Phi =  ((Generator->jetPhi.size() > i) ? Generator->jetPhi[i] : 0);
         double Mass = ((Generator->jetM.size() > i) ?   Generator->jetM[i] :   0);
         J.SetPtEtaPhiMass(PT, Eta, Phi, Mass);
         GenJet.push_back(J);
      }

      GenMETTrue.SetPtEtaPhi(Generator->genMetTrue, 0, 0);
      GenMETCalo.SetPtEtaPhi(Generator->genMetCalo, 0, 0);
   }

   return true;
}


