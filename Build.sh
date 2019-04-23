#! /bin/sh

WorkDir=$PWD
Lib_boost=/home/had/zhangce/lib_boost/include

#echo "WorkDir "${WorkDir}
#######SimBeamLine

#After install G4BeamLine-3.02, directly run the SimBeamLine, with ROOT 534


#######SimBeamStop

#source bashrc with ROOT 614
#source /home/had/zhangce/.bashrc614
cd ${WorkDir}/SimBeamStop
#!!!!!!!!!!!!parameters imported here
./buildnClear.sh


#######SimDiffusion

#dont need to change anything
cd ${WorkDir}/SimDiffusionLaser/
#!!!!!!!!!!!!parameters imported here
g++ -I${Lib_boost} ${WorkDir}/SimDiffusionLaser/Mu1S2SSim.cpp -o ${WorkDir}/SimDiffusionLaser/SimLaser `root-config --cflags --glibs`


#######SimThermalTrans

#No parameter input needed here

#source bashrc with ROOT 534
#source /home/had/zhangce/.bashrc534
export ROOTSYS=/sw/packages/root/5.34.36
export G4INSTALL=/home/had/masashio/OldG4package/geant4.9.5

cd ${WorkDir}/SimThermalMuonTran
make

source /home/had/zhangce/.bashrc
#export ROOTSYS=/sw/packages/root/6.14.06
cd ${WorkDir}

