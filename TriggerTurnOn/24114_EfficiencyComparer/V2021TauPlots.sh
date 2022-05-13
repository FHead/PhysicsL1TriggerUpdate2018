#!/bin/bash

source Samples.sh

########################
# Tau plots HHBBTauTau #
########################

T="EtaPT40_000000"
./Execute \
   --label "NNPuppiTau","CaloTau" \
   --file $HHBBTauTauV20,$HHBBTauTauV20 \
   --numerator "NNTauLooseIso_${T}","CaloTauIso_${T}" \
   --denominator "auto","auto" \
   --title ";Gen. #eta;Matching efficiency (> 40 GeV)" --xmin -2.5 --xmax 2.5 --ymin 0.00 --ymax 1.10 --rebin 2 \
   --color -4,-6 \
   --Davignon ${Davignon} --output Plots/V20V21_Tau_001.pdf

T="EtaPT20to40_000000"
./Execute \
   --label "NNPuppiTau","CaloTau" \
   --file $HHBBTauTauV20,$HHBBTauTauV20 \
   --numerator "NNTauLooseIso_${T}","CaloTauIso_${T}" \
   --denominator "auto","auto" \
   --title ";Gen. #eta;Matching efficiency (20-40 GeV)" --xmin -2.5 --xmax 2.5 --ymin 0.00 --ymax 1.10 --rebin 2 \
   --color -4,-6 \
   --Davignon ${Davignon} --output Plots/V20V21_Tau_002.pdf

T="PTEta15_000000"
./Execute \
   --label "NNPuppiTau","CaloTau" \
   --file $HHBBTauTauV20,$HHBBTauTauV20 \
   --numerator "NNTauLooseIso_${T}","CaloTauIso_${T}" \
   --denominator "auto","auto" \
   --title ";Gen. p_{T};Matching efficiency (barrel)" --xmin 0 --xmax 150 --ymin 0.00 --ymax 1.10 --rebin 2 \
   --color -4,-6 \
   --Davignon ${Davignon} --output Plots/V20V21_Tau_003.pdf

T="PTEtaLarge_000000"
./Execute \
   --label "NNPuppiTau","CaloTau" \
   --file $HHBBTauTauV20,$HHBBTauTauV20 \
   --numerator "NNTauLooseIso_${T}","CaloTauIso_${T}" \
   --denominator "auto","auto" \
   --title ";Gen. p_{T};Matching efficiency (endcap)" --xmin 0 --xmax 150 --ymin 0.00 --ymax 1.10 --rebin 2 \
   --color -4,-6 \
   --Davignon ${Davignon} --output Plots/V20V21_Tau_004.pdf

T1="PTEta15_003000"
T2="PTEta15_000000"
./Execute \
   --label "NNPuppiTau","CaloTau" \
   --file $HHBBTauTauV20,$HHBBTauTauV20 \
   --numerator "NNTauLooseIso_${T1}","CaloTauIso_${T1}" \
   --denominator "NNTauLooseIso_${T2}","CaloTauIso_${T2}" \
   --title ";Gen. p_{T};Trigger efficiency (barrel, p_{T} > 30 GeV)" --xmin 0 --xmax 150 --ymin 0.00 --ymax 1.10 --rebin 2 \
   --color -4,-6 \
   --Davignon ${Davignon} --output Plots/V20V21_Tau_005.pdf

T1="PTEta15_007000"
T2="PTEta15_000000"
./Execute \
   --label "NNPuppiTau","CaloTau" \
   --file $HHBBTauTauV20,$HHBBTauTauV20 \
   --numerator "NNTauLooseIso_${T1}","CaloTauIso_${T1}" \
   --denominator "NNTauLooseIso_${T2}","CaloTauIso_${T2}" \
   --title ";Gen. p_{T};Trigger efficiency (barrel, p_{T} > 70 GeV)" --xmin 0 --xmax 150 --ymin 0.00 --ymax 1.10 --rebin 2 \
   --color -4,-6 \
   --Davignon ${Davignon} --output Plots/V20V21_Tau_006.pdf

T1="PTEtaLarge_003000"
T2="PTEtaLarge_000000"
./Execute \
   --label "NNPuppiTau","CaloTau" \
   --file $HHBBTauTauV20,$HHBBTauTauV20 \
   --numerator "NNTauLooseIso_${T1}","CaloTauIso_${T1}" \
   --denominator "NNTauLooseIso_${T2}","CaloTauIso_${T2}" \
   --title ";Gen. p_{T};Trigger efficiency (endcap, p_{T} > 30 GeV)" --xmin 0 --xmax 150 --ymin 0.00 --ymax 1.10 --rebin 2 \
   --color -4,-6 \
   --Davignon ${Davignon} --output Plots/V20V21_Tau_007.pdf

T1="PTEtaLarge_007000"
T2="PTEtaLarge_000000"
./Execute \
   --label "NNPuppiTau","CaloTau" \
   --file $HHBBTauTauV20,$HHBBTauTauV20 \
   --numerator "NNTauLooseIso_${T1}","CaloTauIso_${T1}" \
   --denominator "NNTauLooseIso_${T2}","CaloTauIso_${T2}" \
   --title ";Gen. p_{T};Trigger efficiency (endcap, p_{T} > 70 GeV)" --xmin 0 --xmax 150 --ymin 0.00 --ymax 1.10 --rebin 2 \
   --color -4,-6 \
   --Davignon ${Davignon} --output Plots/V20V21_Tau_008.pdf



###############
# NNTau plots #
###############

T="EtaPT40_000000"
./Execute \
   --label "NNPuppiTau (HH)","NNPuppiTau2Vtx (HH)","NNPuppiTau (H)","NNPuppiTau2Vtx (H)" \
   --file $HHBBTauTauV20,$HHBBTauTauV20,$VBFHTauTauV21,$VBFHTauTauV21 \
   --numerator "NNTauLooseIso_${T}","NNTau2VtxLooseIso_${T}","NNTauLooseIso_${T}","NNTau2VtxLooseIso_${T}" \
   --denominator "auto","auto","auto","auto" \
   --title ";Gen. #eta;Matching efficiency (> 40 GeV)" --xmin -2.5 --xmax 2.5 --ymin 0.00 --ymax 1.10 --rebin 2 \
   --color -4,-1,-2,-3 \
   --Davignon ${Davignon} --output Plots/V20V21_Tau_009.pdf

T="EtaPT20to40_000000"
./Execute \
   --label "NNPuppiTau (HH)","NNPuppiTau2Vtx (HH)","NNPuppiTau (H)","NNPuppiTau2Vtx (H)" \
   --file $HHBBTauTauV20,$HHBBTauTauV20,$VBFHTauTauV21,$VBFHTauTauV21 \
   --numerator "NNTauLooseIso_${T}","NNTau2VtxLooseIso_${T}","NNTauLooseIso_${T}","NNTau2VtxLooseIso_${T}" \
   --denominator "auto","auto","auto","auto" \
   --title ";Gen. #eta;Matching efficiency (20-40 GeV)" --xmin -2.5 --xmax 2.5 --ymin 0.00 --ymax 1.10 --rebin 2 \
   --color -4,-1,-2,-3 \
   --Davignon ${Davignon} --output Plots/V20V21_Tau_010.pdf

T="PTEta15_000000"
./Execute \
   --label "NNPuppiTau (HH)","NNPuppiTau2Vtx (HH)","NNPuppiTau (H)","NNPuppiTau2Vtx (H)" \
   --file $HHBBTauTauV20,$HHBBTauTauV20,$VBFHTauTauV21,$VBFHTauTauV21 \
   --numerator "NNTauLooseIso_${T}","NNTau2VtxLooseIso_${T}","NNTauLooseIso_${T}","NNTau2VtxLooseIso_${T}" \
   --denominator "auto","auto","auto","auto" \
   --title ";Gen. p_{T};Matching efficiency (barrel)" --xmin 0 --xmax 150 --ymin 0.00 --ymax 1.10 --rebin 2 \
   --color -4,-1,-2,-3 \
   --Davignon ${Davignon} --output Plots/V20V21_Tau_011.pdf

T="PTEtaLarge_000000"
./Execute \
   --label "NNPuppiTau (HH)","NNPuppiTau2Vtx (HH)","NNPuppiTau (H)","NNPuppiTau2Vtx (H)" \
   --file $HHBBTauTauV20,$HHBBTauTauV20,$VBFHTauTauV21,$VBFHTauTauV21 \
   --numerator "NNTauLooseIso_${T}","NNTau2VtxLooseIso_${T}","NNTauLooseIso_${T}","NNTau2VtxLooseIso_${T}" \
   --denominator "auto","auto","auto","auto" \
   --title ";Gen. p_{T};Matching efficiency (endcap)" --xmin 0 --xmax 150 --ymin 0.00 --ymax 1.10 --rebin 2 \
   --color -4,-1,-2,-3 \
   --Davignon ${Davignon} --output Plots/V20V21_Tau_012.pdf

T1="PTEta15_003000"
T2="PTEta15_000000"
./Execute \
   --label "NNPuppiTau (HH)","NNPuppiTau2Vtx (HH)","NNPuppiTau (H)","NNPuppiTau2Vtx (H)" \
   --file $HHBBTauTauV20,$HHBBTauTauV20,$VBFHTauTauV21,$VBFHTauTauV21 \
   --numerator "NNTauLooseIso_${T1}","NNTau2VtxLooseIso_${T1}","NNTauLooseIso_${T1}","NNTau2VtxLooseIso_${T1}" \
   --denominator "NNTauLooseIso_${T2}","NNTau2VtxLooseIso_${T2}","NNTauLooseIso_${T2}","NNTau2VtxLooseIso_${T2}" \
   --title ";Gen. p_{T};Trigger efficiency (barrel, p_{T} > 30 GeV)" --xmin 0 --xmax 150 --ymin 0.00 --ymax 1.10 --rebin 2 \
   --color -4,-1,-2,-3 \
   --Davignon ${Davignon} --output Plots/V20V21_Tau_013.pdf

T1="PTEta15_007000"
T2="PTEta15_000000"
./Execute \
   --label "NNPuppiTau (HH)","NNPuppiTau2Vtx (HH)","NNPuppiTau (H)","NNPuppiTau2Vtx (H)" \
   --file $HHBBTauTauV20,$HHBBTauTauV20,$VBFHTauTauV21,$VBFHTauTauV21 \
   --numerator "NNTauLooseIso_${T1}","NNTau2VtxLooseIso_${T1}","NNTauLooseIso_${T1}","NNTau2VtxLooseIso_${T1}" \
   --denominator "NNTauLooseIso_${T2}","NNTau2VtxLooseIso_${T2}","NNTauLooseIso_${T2}","NNTau2VtxLooseIso_${T2}" \
   --title ";Gen. p_{T};Trigger efficiency (barrel, p_{T} > 70 GeV)" --xmin 0 --xmax 150 --ymin 0.00 --ymax 1.10 --rebin 2 \
   --color -4,-1,-2,-3 \
   --Davignon ${Davignon} --output Plots/V20V21_Tau_014.pdf

T1="PTEtaLarge_003000"
T2="PTEtaLarge_000000"
./Execute \
   --label "NNPuppiTau (HH)","NNPuppiTau2Vtx (HH)","NNPuppiTau (H)","NNPuppiTau2Vtx (H)" \
   --file $HHBBTauTauV20,$HHBBTauTauV20,$VBFHTauTauV21,$VBFHTauTauV21 \
   --numerator "NNTauLooseIso_${T1}","NNTau2VtxLooseIso_${T1}","NNTauLooseIso_${T1}","NNTau2VtxLooseIso_${T1}" \
   --denominator "NNTauLooseIso_${T2}","NNTau2VtxLooseIso_${T2}","NNTauLooseIso_${T2}","NNTau2VtxLooseIso_${T2}" \
   --title ";Gen. p_{T};Trigger efficiency (endcap, p_{T} > 30 GeV)" --xmin 0 --xmax 150 --ymin 0.00 --ymax 1.10 --rebin 2 \
   --color -4,-1,-2,-3 \
   --Davignon ${Davignon} --output Plots/V20V21_Tau_015.pdf

T1="PTEtaLarge_007000"
T2="PTEtaLarge_000000"
./Execute \
   --label "NNPuppiTau (HH)","NNPuppiTau2Vtx (HH)","NNPuppiTau (H)","NNPuppiTau2Vtx (H)" \
   --file $HHBBTauTauV20,$HHBBTauTauV20,$VBFHTauTauV21,$VBFHTauTauV21 \
   --numerator "NNTauLooseIso_${T1}","NNTau2VtxLooseIso_${T1}","NNTauLooseIso_${T1}","NNTau2VtxLooseIso_${T1}" \
   --denominator "NNTauLooseIso_${T2}","NNTau2VtxLooseIso_${T2}","NNTauLooseIso_${T2}","NNTau2VtxLooseIso_${T2}" \
   --title ";Gen. p_{T};Trigger efficiency (endcap, p_{T} > 70 GeV)" --xmin 0 --xmax 150 --ymin 0.00 --ymax 1.10 --rebin 2 \
   --color -4,-1,-2,-3 \
   --Davignon ${Davignon} --output Plots/V20V21_Tau_016.pdf


#######################
# NNTau plots no 2Vtx #
#######################

T="EtaPT40_000000"
./Execute \
   --label "NNPuppiTau (HH)","NNPuppiTau (H)" \
   --file $HHBBTauTauV20,$VBFHTauTauV21 \
   --numerator "NNTauLooseIso_${T}","NNTauLooseIso_${T}" \
   --denominator auto,auto \
   --title ";Gen. #eta;Matching efficiency (> 40 GeV)" --xmin -2.5 --xmax 2.5 --ymin 0.00 --ymax 1.10 --rebin 2 \
   --color -4,-2 \
   --Davignon ${Davignon} --output Plots/V20V21_Tau_017.pdf

T="EtaPT20to40_000000"
./Execute \
   --label "NNPuppiTau (HH)","NNPuppiTau (H)" \
   --file $HHBBTauTauV20,$VBFHTauTauV21 \
   --numerator "NNTauLooseIso_${T}","NNTauLooseIso_${T}" \
   --denominator auto,auto \
   --title ";Gen. #eta;Matching efficiency (20-40 GeV)" --xmin -2.5 --xmax 2.5 --ymin 0.00 --ymax 1.10 --rebin 2 \
   --color -4,-2 \
   --Davignon ${Davignon} --output Plots/V20V21_Tau_018.pdf

T="PTEta15_000000"
./Execute \
   --label "NNPuppiTau (HH)","NNPuppiTau (H)" \
   --file $HHBBTauTauV20,$VBFHTauTauV21 \
   --numerator "NNTauLooseIso_${T}","NNTauLooseIso_${T}" \
   --denominator auto,auto \
   --title ";Gen. p_{T};Matching efficiency (barrel)" --xmin 0 --xmax 150 --ymin 0.00 --ymax 1.10 --rebin 2 \
   --color -4,-2 \
   --Davignon ${Davignon} --output Plots/V20V21_Tau_019.pdf

T="PTEtaLarge_000000"
./Execute \
   --label "NNPuppiTau (HH)","NNPuppiTau (H)" \
   --file $HHBBTauTauV20,$VBFHTauTauV21 \
   --numerator "NNTauLooseIso_${T}","NNTauLooseIso_${T}" \
   --denominator auto,auto \
   --title ";Gen. p_{T};Matching efficiency (endcap)" --xmin 0 --xmax 150 --ymin 0.00 --ymax 1.10 --rebin 2 \
   --color -4,-2 \
   --Davignon ${Davignon} --output Plots/V20V21_Tau_020.pdf

T1="PTEta15_003000"
T2="PTEta15_000000"
./Execute \
   --label "NNPuppiTau (HH)","NNPuppiTau (H)" \
   --file $HHBBTauTauV20,$VBFHTauTauV21 \
   --numerator "NNTauLooseIso_${T1}","NNTauLooseIso_${T1}" \
   --denominator "NNTauLooseIso_${T2}","NNTauLooseIso_${T2}" \
   --title ";Gen. p_{T};Trigger efficiency (barrel, p_{T} > 30 GeV)" --xmin 0 --xmax 150 --ymin 0.00 --ymax 1.10 --rebin 2 \
   --color -4,-2 \
   --Davignon ${Davignon} --output Plots/V20V21_Tau_021.pdf

T1="PTEta15_007000"
T2="PTEta15_000000"
./Execute \
   --label "NNPuppiTau (HH)","NNPuppiTau (H)" \
   --file $HHBBTauTauV20,$VBFHTauTauV21 \
   --numerator "NNTauLooseIso_${T1}","NNTauLooseIso_${T1}" \
   --denominator "NNTauLooseIso_${T2}","NNTauLooseIso_${T2}" \
   --title ";Gen. p_{T};Trigger efficiency (barrel, p_{T} > 70 GeV)" --xmin 0 --xmax 150 --ymin 0.00 --ymax 1.10 --rebin 2 \
   --color -4,-2 \
   --Davignon ${Davignon} --output Plots/V20V21_Tau_022.pdf

T1="PTEtaLarge_003000"
T2="PTEtaLarge_000000"
./Execute \
   --label "NNPuppiTau (HH)","NNPuppiTau (H)" \
   --file $HHBBTauTauV20,$VBFHTauTauV21 \
   --numerator "NNTauLooseIso_${T1}","NNTauLooseIso_${T1}" \
   --denominator "NNTauLooseIso_${T2}","NNTauLooseIso_${T2}" \
   --title ";Gen. p_{T};Trigger efficiency (endcap, p_{T} > 30 GeV)" --xmin 0 --xmax 150 --ymin 0.00 --ymax 1.10 --rebin 2 \
   --color -4,-2 \
   --Davignon ${Davignon} --output Plots/V20V21_Tau_023.pdf

T1="PTEtaLarge_007000"
T2="PTEtaLarge_000000"
./Execute \
   --label "NNPuppiTau (HH)","NNPuppiTau (H)" \
   --file $HHBBTauTauV20,$VBFHTauTauV21 \
   --numerator "NNTauLooseIso_${T1}","NNTauLooseIso_${T1}" \
   --denominator "NNTauLooseIso_${T2}","NNTauLooseIso_${T2}" \
   --title ";Gen. p_{T};Trigger efficiency (endcap, p_{T} > 70 GeV)" --xmin 0 --xmax 150 --ymin 0.00 --ymax 1.10 --rebin 2 \
   --color -4,-2 \
   --Davignon ${Davignon} --output Plots/V20V21_Tau_024.pdf



