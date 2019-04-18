#! /bin/sh

#source bashrc with ROOT 614
source /home/had/zhangce/.bashrc614
cd /home/had/zhangce/1S2SMuSim/SimBeamStop
./buildnClear.sh

#dont need to change anything
cd /home/had/zhangce/1S2SMuSim/SimDiffusionLaser/
g++ -I/home/had/zhangce/lib_boost/include /home/had/zhangce/1S2SMuSim/SimDiffusionLaser/Mu1S2SSim.cpp -o /home/had/zhangce/1S2SMuSim/SimDiffusionLaser/Mu1S2SSim `root-config --cflags --glibs`

#source bashrc with ROOT 534
#source /home/had/zhangce/.bashrc534
export ROOTSYS=/sw/packages/root/5.34.36
export G4INSTALL=/home/had/masashio/OldG4package/geant4.9.5
cd /home/had/zhangce/1S2SMuSim/SimThermalMuonTran
make

#source /home/had/zhangce/.bashrc614
export ROOTSYS=/sw/packages/root/6.14.06
cd /home/had/zhangce/1S2SMuSim
