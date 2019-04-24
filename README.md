
# 1S2SMuSim

This program is for Muonium 1S2S Spectroscopy Experiment proposed at J-PARC MUSE D2

The entire program is consist of four parts:

- J-PARC Dline (D2) simulation
- Stopping simulation at aerogel target
- Diffusion model and cw & pulsed Laser ionization
- Thermal muon transmission

It has been builded and tested on KEKCC. Parts of it could be run offline.


## Prerequisites

To run the entire simulation, following are needed:

- ROOT 6.14.06
- PYTHON 2.7
- gcc 4.8.5 (Linux)
- Geant4 10.3.3
	- CMake 3.3 or higher
	- CLHEP 2.1.1.0
- odeint-v2
- G4Beamline-3.02 (http://www.muonsinternal.com/muons3/G4beamline#Download)

In order to run G4Beamline and make musrSim in the thermal muon transmission, extras needed:

- ROOT 5.34.36
- Geant4 4.9.5
- (vis) view3dscene or wrl

If only parts of the simulaitons are used, the prerequisite for each part are:

### D-line transmission (SimBeamLine)

- gcc 4.8.5
- Geant4-10.3.3
- G4Beamline-3.02
- ROOT 534


### Stopping simulation (SimBeamStop)

- gcc 4.8.5
- Geant4-10.3.3
- ROOT 6.14.06

### Diffusion Model with laser simulation (SimDiffusionLaser)

- gcc 4.8.5
- ROOT 6.14.06
- Python 2.7 or higher
- odeint-v2

### Thermal Muon transmission, muSRsim (SimThermalMuonTran)

- gcc 4.8.5
- Geant4-4.9.5
- ROOT 5.34
- (visual, optional) view3dscene or wrl

## Quick start

using the Build.sh and Run.sh one can easily build and run the entire simulation (assuming prerequisites above installed).

Run.sh provides an easy way to run the simulaiton. using

```
./Run.sh $n
```

one can run each simulation, here $n corresponds to each simulaiton.

For example, to run the Diffusion model with the laser, in the ./1S2SMuSim, type

```
./Run.sh 3 output_0.root 0
```

and for other simulation:

```
./Run.sh 1  # Run D-line transmission (SimBeamLine)
./Run.sh 2  # Run Stopping simulation (SimBeamStop)
./Run.sh 4  # Run Thermal Muon transmission (SimThermalMuonTran)
```

The result .root file will be moved and saved in the ./1S2SMuSim/OutputRoot

## Building and Installing

### 1.SimBeamLine

This simulation starts from the entrance of D-line (pion target) to the end of D-line. The G4Beamline-3.02 package is needed. It can be downloaded from [official website](http://www.muonsinternal.com/muons3/G4beamline#Download) or in the KEKCC account. In short, after unzip the file, using g4bldata to install extra data in the home path.

After G4Beamline installed, in the directory, type

```
g4bl mlf_d2_190406_dqdscale_0.95_ns_70.in
```

 (Or refer to ./1S2SMuSim/Run.sh)

Currently, Genat4.9 and ROOR 5.34 should be used in this part.

### 2.SimBeamStop

This simulation starts from the end of D-line (entrance of D2 area) to the aerogel target, the detials of the target holder and the Mu chamber would be attached in the reference. The number of events read by the program are in the run0221.mac

ROOT6 and Geant4.10 should be used in this part.

In the directory ./1S2SMuSim/SimBeamStop, build the program simply by 

```
./buildnClear.sh
```

Then run the simulation by

```
./build/Application_Main 19 run0221.mac
```

Here 19 is the label of aerogel sample, the number of events can be set in the run0221.mac. Also one can refer to ./src/Geometry.cc, ./include/P00SteppingAction.hh, ./include/PrimaryGeneratorAction1.hh for more details.

### 3.SimDiffusionLaser

This simulation includes the diffusion model and the laser simulation (CW laser and Pulsed laser, credit to Okayama Univ.). The Muonium inside the aerogel target will diffuse and possibly emitted out to be ionized by the laser.

GCC and ROOT6.14 are needed, along with odeint-v2 library. After compile with g++, directly run with

```
./Sim output_N.root N
```

here N is the detuning frequency.

output_N.root file will contain the final infomation of ionized population, and Target_output_N.root will contain the spatial and angular information of Muonium events who reach the surface of the aerogel.

### 4.SimThermalMuonTran

This simulation starts from the thermal muon (Ionized muon) at the defined laser region, who will be transmitted along the transmission line (SOA, EQ1-2, ED, EQ3-4, BM, EQ5) to the MCP detector.

musrSim package is applied in this simulaiton. Details of musrSim could be found at ./SimThermalMuonTran/doc

For this part, old version Geant4-4.9.5 and ROOT 5.34 are needed. In the .1S2SMuSim/SimThermalMuonTran, directly type "make", then if successful, one should goto .1S2SMuSim/SimThermalMuonTran/run and run by

```
../bin/Linux-g++/musrSim musr_simple.mac
```

or of course "./Run.sh 4" in the ./1S2SMuSim, the result musr_0.root will be saved at /run/data.






