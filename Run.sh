#! /bin/sh

# with ROOT 614
/home/had/zhangce/1S2SMuSim/SimBeamStop/build/Application_Main 19 run0221.mac

mv /home/had/zhangce/1S2SMuSim/SimBeamStop/SimBeamStop.root /home/had/zhangce/1S2SMuSim/SimDiffusionLaser/Root/

/home/had/zhangce/1S2SMuSim/SimDiffusionLaser/Mu1S2SSim output_0.root 0
/home/had/zhangce/1S2SMuSim/SimDiffusionLaser/Root/GenerateTXT/GenerateTXT.sh

mv /home/had/zhangce/1S2SMuSim/SimDiffusionLaser/Root/FromDline_musr.txt /home/had/zhangce/1S2SMuSim/SimThermalMuonTran/run

# with ROOT 534 (once finish build however, dont need ROOT534 anymore)
cd /home/had/zhangce/1S2SMuSim/SimThermalMuonTran/run
../bin/Linux-g++/musrSim test190326_simple.mac


mv /home/had/zhangce/1S2SMuSim/SimDiffusionLaser/Root/SimBeamStop.root /home/had/zhangce/1S2SMuSim/Root
mv /home/had/zhangce/1S2SMuSim/SimDiffusionLaser/Root/output_0.root /home/had/zhangce/1S2SMuSim/Root
mv /home/had/zhangce/1S2SMuSim/SimThermalMuonTran/run/musr_0.root /home/had/zhangce/1S2SMuSim/Root
