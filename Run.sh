#! /bin/sh

WorkDir=$PWD
Lib_boost=/home/had/zhangce/lib_boost/include

#### SimG4BeamLine (with ROOT 534)
#source ~/.bashrc534
#cd ${WorkDir}/SimBeamLine/
#g4bl mlf_d2_190406_dqdscale_0.95_ns_70.in

#### SimBeamStop
cd ${WorkDir}/SimBeamStop/
${WorkDir}/SimBeamStop/build/Application_Main 19 run0221.mac

mv ${WorkDir}/SimBeamStop/SimBeamStop.root ${WorkDir}/SimDiffusionLaser/Root/

#### SimDiffusionLaser (with ROOT 641)
cd ${WorkDir}/SimDiffusionLaser/
${WorkDir}/SimDiffusionLaser/SimLaser output_0.root 0
#mv ${WorkDir}/SimDiffusionLaser/Root/FromDline_musr.dat ${WorkDir}/SimThermalMuonTran/run/FromDline_musr.dat

#### SimThermalMuonTransmission (with ROOT 534)
cd ${WorkDir}/SimThermalMuonTran/run/
../bin/Linux-g++/musrSim musr_simple.mac


mv ${WorkDir}/SimDiffusionLaser/Root/SimBeamStop.root ${WorkDir}/OutputRoot/SimBeamStop.root
mv ${WorkDir}/SimDiffusionLaser/Root/output_0.root ${WorkDir}/OutputRoot/SimDiffusionLaser.root
mv ${WorkDir}/SimThermalMuonTran/run/data/musr_0.root ${WorkDir}/OutputRoot/SimThermalMuonTran.root

cd ${WorkDir}