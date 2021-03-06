# LaserMuYield

This program uses ODEint (http://headmyshoulder.github.io/odeint-v2/) and the ROOT library.

Diffusion model is also applied in the aerogel target.

(For the old version of diffusion model, see MuYield)


Usage:

 [] ./LaserSim outputFileName detuning  (./Mu1S2S 1kHz.root 1000)

 - Mu1S2SSim.C
   It contains the main function. The numerical calculation of the differential equations is done in this code.
   The equations are originaly published in PRA73,052501,2006 Eqs.(10) for 1s-2s two-photon spectroscopy of hydrogen.
   Masuda modified the equations for the muonium spectroscopy.
   In the pulse excitation simulation, optical Bloch equations based on Laser Physics, Vol. 12, No. 7, 2002, pp. 1–8. are used.
   T.Hiraki updated the equations for the muonium spectroscopy.

 - CWLaser.h
   This class represents the 244 nm CW laser. An instance of this class is created with the three dimensional position, the waist size, and the power.
   It also stores the detuning from the resonance. Once it is created, it returns intensity at any position.
   So far, this class assumes the cw laser is a perfect gaussian beam (the raylength length is implemented) and it propagates along the x-axis.

 - PulseLaser.h
   This class represents the 355 nm pulsed laser. An instance of this class is created with the three dimensional position, the timing at the center, the pulse duration, the waist size, and the pulse energy.
   Once it is created, it returns intensity at any position and time.
   So far, this class assumes the pulsed laser is a perfect gaussian beam (the raylength length is implemented) and it propagates along the x-axis as well as the CWLaser.

- Muonium0.h
   This class represents each muonium in the target. 
   Diffusion model is applied in this class.

 - TreeManager0.h
   This class is used to save the calculation results in a TTree and a TFile for only Mu emission process.
   
 - Muonium.h
   This class represents each muonium for laser ionization process. This class has physical parameters of muonium such as two-photon Rabi frequency coefficient, doppler shift, and stark shifts.
   It is also used for the muonium tracking based on its initial position and velocity information.

 - TreeManager.h
   This class is used to save the calculation results in a TTree and a TFile for ionized Mu.
   When the saveFlag is true, all the values during the calculation are stored; the output file size becomes large.
   When the saveFlag is false, only the initial and final values will be stored.


   
   The important output parameters "Rho[]" are modified (now 17 parameters)
   In this simulation 4-level optical Bloch equations are solved.
   (The levels considered are L1:1s1/2, L2:2p1/2, L3:2s1/2, L4:2p3/2)
       Rho[0]-Rho[3]: the population of L1, L2, L3, L4 state
       Rho[4]-Rho[15] coherence parameters (Real part (even) and Imaginary part (odd)): 4,5:L1-L2, 6,7:L1-L3 (1s-2s), 8,9:L1-L4, 10,11:L2-L3, 12,13:L2-L4, 14,15:L3-L4  
       Rho[16]: the population of the ionized state

   (original version, you can use this two-level (5 paremeter) simulation by modify "nRhos" in Muonium.h and Mu1S2SSim.C (commented out now) )
   The important output parameters:
       Rho[0] : the population of the 1S state
       Rho[1] : the real part of the coherenece between 1S-2S states
       Rho[2] : the imaginary part of the coherenece between 1S-2S states
       Rho[3] : the population of the 2S state
       Rho[4] : the population of the ionized state
 
 //(rho_gg, Re(rho_ge), Im(rho_ge), rho_ee, rho_ion) array