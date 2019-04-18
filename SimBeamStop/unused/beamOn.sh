#!/bin/sh

if [ ! -d output ]; then
    mkdir output
fi
if [ ! -d log ]; then
    mkdir log
fi

# pwd
echo "momentum value (in MeV/c) >"
#read momentum
echo "sigma of kinE Gaus distribution (in MeV) >"
#read kinESigma
echo "width of the flat top of kinE distribution (in MeV) >"
#read kinEWidthFlatTop
echo "event number >"
#read eventNum

targetnum=0
momentum=23.3
kinESigma=0.04
kinEWidthFlatTop=0.02
eventNum=10000
#eventNum=10
muonMass=105.6583715

intensity1=1
intensity2=`echo "scale=4; $intensity1*$kinEWidthFlatTop/($kinESigma*2.5066)*2" | bc`
kinE0=`echo "scale=8; sqrt($muonMass^2+$momentum^2)-$muonMass" | bc`
kinE1=`echo "scale=8; $kinE0 - $kinEWidthFlatTop/2" | bc`
kinE2=`echo "scale=8; $kinE0 + $kinEWidthFlatTop/2" | bc`
if [ -f run.mac ] ; then
    rm run.mac
fi
echo  "
/run/initialize
# P A R T I C L E   S O U R C E
# beam #1 (Gaussian: lowE side)
# default intensity is 1
/gps/source/intensity $intensity1
/gps/particle mu+
/gps/pos/type Volume
/gps/pos/shape Ellipsoid
/gps/pos/centre 0.0  0.0  -20.0 cm
/gps/pos/halfx 6 mm
/gps/pos/halfy 6 mm
/gps/pos/halfz 3 mm

/gps/ang/type beam2d
/gps/ang/sigma_x 30. mrad
/gps/ang/sigma_y 30. mrad
/gps/direction 0.0  0.0  +1.0

/gps/ene/type Gauss
/gps/ene/mono $kinE1 MeV
/gps/ene/sigma $kinESigma MeV
/gps/ene/max $kinE1 MeV

# beam #2 (flat top)
/gps/source/add $intensity2
/gps/particle mu+
/gps/pos/type Volume
/gps/pos/shape Ellipsoid
/gps/pos/centre 0.0  0.0  -20.0 cm
/gps/pos/halfx 6 mm
/gps/pos/halfy 6 mm
/gps/pos/halfz 3 mm

/gps/ang/type beam2d
/gps/ang/sigma_x 30. mrad
/gps/ang/sigma_y 30. mrad
/gps/direction 0.0  0.0  +1.0

/gps/ene/type Lin
/gps/ene/gradient 0
/gps/ene/intercept 1
/gps/ene/min $kinE1 MeV
/gps/ene/max $kinE2 MeV

# beam #3 (Gaussian: highE side)
/gps/source/add $intensity1
/gps/particle mu+
/gps/pos/type Volume
/gps/pos/shape Ellipsoid
/gps/pos/centre 0.0  0.0  -20.0 cm
/gps/pos/halfx 6 mm
/gps/pos/halfy 6 mm
/gps/pos/halfz 3 mm

/gps/ang/type beam2d
/gps/ang/sigma_x 30. mrad
/gps/ang/sigma_y 30. mrad
/gps/direction 0.0  0.0  +1.0

/gps/ene/type Gauss
/gps/ene/mono $kinE2 MeV
/gps/ene/sigma $kinESigma MeV
/gps/ene/min $kinE2 MeV

/control/verbose 1
/process/verbose 1
/tracking/verbose 1
/material/verbose 0
/run/verbose 1
/event/verbose 1
/vis/verbose 0

/run/beamOn $eventNum" > beamOn.mac



#===== Run G4 binary --->.root file ---> root macro 
./build/Application_Main $targetnum beamOn.mac > ./log/log$momentum.txt

if [ -f P00RawData.root ] ; then
	cp P00RawData.root ./output/rawData$momentum.root
fi

#rm beamOn.mac

echo "
=============================
>> Run completed!
             momentum = $momentum MeV/c 
    sigma of Gaussian = $kinESigma MeV
       flat top width = $kinEWidthFlatTop MeV
>> rawData$momentum.root generated!
=============================
"
