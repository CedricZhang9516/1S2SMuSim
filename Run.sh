#! /bin/sh

WorkDir=$PWD
Lib_boost=/home/had/zhangce/lib_boost/include

#### SimG4BeamLine (with ROOT 534)

#if [ $1 -eq 1 ]; then
if [[ $1 =~ 1 ]]; then
source ~/.bashrc534
cd ${WorkDir}/SimBeamLine/
if [ -z $2 ];then
g4bl mlf_d2_190406_dqdscale_0.95_ns_0.in
mv mlf_d2_190406_dqdscale_0.95_ns_0.root ${WorkDir}/OutputRoot/SimBeamLine_0.root
else
g4bl mlf_d2_190406_dqdscale_0.95_ns_$2.in
mv mlf_d2_190406_dqdscale_0.95_ns_$2.root ${WorkDir}/OutputRoot/SimBeamLine_$2.root
fi

#### SimBeamStop
if [[ $1 =~ 2 ]]; then
cd ${WorkDir}/SimBeamStop/
${WorkDir}/SimBeamStop/build/Application_Main 19 run0221.mac
mv ${WorkDir}/SimBeamStop/SimBeamStop.root ${WorkDir}/OutputRoot/SimBeamStop.root
#mv ${WorkDir}/SimBeamStop/SimBeamStop.root ${WorkDir}/SimDiffusionLaser/Root/SimBeamStop.root
fi

#### SimDiffusionLaser (with ROOT 641)
if [[ $1 =~ 3 ]]; then
cd ${WorkDir}/SimDiffusionLaser/
${WorkDir}/SimDiffusionLaser/SimLaser $2 $3
mv ${WorkDir}/SimDiffusionLaser/Root/${2} ${WorkDir}/OutputRoot/SimDiffusionLaser_${2}
#mv ${WorkDir}/SimDiffusionLaser/Root/FromDline_musr.dat ${WorkDir}/SimThermalMuonTran/run/FromDline_musr.dat
fi

#### SimThermalMuonTransmission (with ROOT 534)
if [[ $1 =~ 4 ]]; then
cd ${WorkDir}/SimThermalMuonTran/run/
../bin/Linux-g++/musrSim musr_simple.mac
mv ${WorkDir}/SimThermalMuonTran/run/data/musr_0.root ${WorkDir}/OutputRoot/SimThermalMuonTran.root
fi

#mv ${WorkDir}/SimDiffusionLaser/Root/SimBeamStop.root ${WorkDir}/OutputRoot/SimBeamStop.root
#mv ${WorkDir}/SimDiffusionLaser/Root/output_0.root ${WorkDir}/OutputRoot/SimDiffusionLaser.root
#mv ${WorkDir}/SimThermalMuonTran/run/data/musr_0.root ${WorkDir}/OutputRoot/SimThermalMuonTran.root

cd ${WorkDir}
