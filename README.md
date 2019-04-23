
# 1S2SMuSim

This program is for Muonium 1S2S Spectroscopy Experiment proposed at J-PARC MUSE D2

The entire program is consist of four parts:

- Dline (D2) simulation
- Stopping simulation at aerogel target
- Diffusion model and cw & pulsed Laser ionization
- Thermal muon transmission

It could be builded and run on KEKCC. Parts of it could be run offline.

More details should be added in the future.

## PREREQUISITE

- ROOT 61406
- PYTHON 2.7
- gcc 4.8.5
- Geant4 10.3.3
- CLHEP 2.1.1.0
- odeint-v2 library
- G4Beamline-3.02 (http://www.muonsinternal.com/muons3/G4beamline#Download)

In order to run G4Beamline and make musr, extras needed:

- ROOT 53436
- Geant4 4.9.5
- (vis) view3dscene or wrl

## To Build the entire simulation packages
### 1.SimBeamLine, the G4Beamline-3.02 is needed. 

### 1.SimBeamLine:

- qdq_scale = 0.95
- Momentum = 28.4 MeV/c

- .in
- ROOT file:

