Config     = 20220202.config

default: RunTest 

Execute: FillHistograms.cpp Histograms.o HelperFunctions.o
	CompileRootMacro FillHistograms.cpp Execute \
		-I../../CommonCode/include ../../CommonCode/library/*.o \
		`fastjet-config --cxxflags --libs` \
		Histograms.o HelperFunctions.o

Histograms.o: Histograms.cpp Histograms.h
	CompileRootMacro Histograms.cpp Histograms.o -c

HelperFunctions.o: HelperFunctions.cpp HelperFunctions.h
	CompileRootMacro HelperFunctions.cpp HelperFunctions.o -c \
		-I../../CommonCode/include `fastjet-config --cxxflags`

RunTest: Execute
	./Execute --input `ls SamplesDYLL/* | head -n 5 | tr '\n' ',' | sed "s/,$$//g"` \
		--output TestRun.root --StoredGen true --config $(Config)

RunLDR: Execute
	# ./Execute --input `ls SamplesDYLL/* | head -n 40 | tr '\n' ',' | sed "s/,$$//g"` \
	# 	--output DYLLLDR.root --StoredGen true --config $(Config) --LDROnly true
	./Execute --input `ls SamplesTTbarV14p1/* | head -n 40 | tr '\n' ',' | sed "s/,$$//g"` \
		--output TTbarLDR.root --StoredGen true --config $(Config) --LDROnly true
	./Execute --input `ls SamplesVBFHTauTauV14p1/* | head -n 40 | tr '\n' ',' | sed "s/,$$//g"` \
		--output VBFHTauTauLDR.root --StoredGen true --config $(Config) --LDROnly true

RunDYLL: Execute
	./Execute --input `ls SamplesDYLL/* | head -n 99999 | tr '\n' ',' | sed "s/,$$//g"` \
		--output /tmp/chenyi/DYLL.root --StoredGen true --config $(Config)

RunDYLLPartial: Execute
	./Execute --input `ls SamplesDYLL/* | head -n 40 | tr '\n' ',' | sed "s/,$$//g"` \
		--output /tmp/chenyi/DYLLPartial.root --StoredGen true --config $(Config)

RunHGG: Execute
	./Execute --input `ls SamplesHGG/* | head -n 99999 | tr '\n' ',' | sed "s/,$$//g"` \
		--output /tmp/chenyi/HGG.root --StoredGen true --config $(Config)

RunTTbar: Execute
	# ./Execute --input `ls SamplesTTbar/* | head -n 99999 | tr '\n' ',' | sed "s/,$$//g"` \
	# 	--output /tmp/chenyi/TTbar.root --StoredGen true --config $(Config)
	# ./Execute --input `ls SamplesTTbarV12p1/* | head -n 99999 | tr '\n' ',' | sed "s/,$$//g"` \
	# 	--output /tmp/chenyi/TTbar.root --StoredGen true --config $(Config)
	./Execute --input `ls SamplesTTbarV14p1/* | head -n 99999 | tr '\n' ',' | sed "s/,$$//g"` \
		--output /tmp/chenyi/TTbar.root --StoredGen true --config $(Config)

RunTTbarHT: Execute
	# ./Execute --input `ls SamplesTTbar/* | head -n 99999 | tr '\n' ',' | sed "s/,$$//g"` \
	# 	--output /tmp/chenyi/TTbar.root --StoredGen true --config $(HTConfig)
	# ./Execute --input `ls SamplesTTbarV12p1/* | head -n 99999 | tr '\n' ',' | sed "s/,$$//g"` \
	# 	--output /tmp/chenyi/TTbar.root --StoredGen true --config $(HTConfig)
	# ./Execute --input `ls SamplesTTbarV14/* | head -n 99999 | tr '\n' ',' | sed "s/,$$//g"` \
	# 	--output /tmp/chenyi/TTbarHT.root --StoredGen true --config $(HTConfig)
	
RunVBFHTauTau: Execute
	./Execute --input `ls SamplesVBFHTauTauV14p1/* | head -n 99999 | tr '\n' ',' | sed "s/,$$//g"` \
		--output /tmp/chenyi/VBFHTauTau.root --StoredGen true --config $(Config)


