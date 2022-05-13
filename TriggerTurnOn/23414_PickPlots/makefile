
V10DYLL = DYLL_V10p7.root
# V10DYLL = DYLL_V10p7_20200213.root

default: TestRun

TestRun: Execute
	./Execute \
		--Input $(V10DYLL),$(V10DYLL),$(V10DYLL),$(V10DYLL),$(V10DYLL) \
		--Numerator "TkMuonStubWideIso/TkMuonStubWideIso_EtaPT15_000000","TkMuonStubWideIso/TkMuonStubWideIso_EtaPT2to5_000000","TkMuonStubIsoBEta/TkMuonStubIsoBEta_PT_000000","TkMuonStubIsoOEta/TkMuonStubIsoOEta_PT_000000","TkMuonStubIsoEEta/TkMuonStubIsoEEta_PT_000000" \
		--Denominator "TkMuonStubWideIso/TkMuonStubWideIsoNoMatch_EtaPT15_000000","TkMuonStubWideIso/TkMuonStubWideIsoNoMatch_EtaPT2to5_000000","TkMuonStubIsoBEta/TkMuonStubIsoBEtaNoMatch_PT_000000","TkMuonStubIsoOEta/TkMuonStubIsoOEtaNoMatch_PT_000000","TkMuonStubIsoEEta/TkMuonStubIsoEEtaNoMatch_PT_000000" \
		--Name "TkMuonStub_EtaPT15","TkMuonStub_EtaPT2to5","TkMuonStub_PTBarrel","TkMuonStub_PTOverlap","TkMuonStub_PTEndcap" \
		--Rebin 1,1,2,2,2 \
		--Output V10Muon.root

Execute: PickCurves.cpp
	CompileRootMacro PickCurves.cpp Execute
