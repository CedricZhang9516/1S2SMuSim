//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Geometry.cc
/*
BC scintillator replacement:
 The replacement BC is being constructed by Steve Chan in our scintillator
 shop now. They have requested a small change in dimension and will perhaps
 add a step in the "fishtail" rectangular-to-round conversion piece in order
 to make the rectangular face glue joint stronger and easier to align. Steve
 has the drawings of the holder from Sirui's talk at our last meeting and is
 aware of the constraints. He has selected a sample of BC408 scintillator
 that is "measured" to be 0.013" (0.33 mm) with variation in thickness of
 <0.0002" (<0.005 mm). I have asked him to weigh and measure the scintillator
 carefully before gluing it in so that we have the best possible estimate of
 thickness in g/cm^2.
*/
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "Geometry.hh"

#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4SubtractionSolid.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4PVReplica.hh"
#include "G4VPhysicalVolume.hh"

#include "G4GeometryManager.hh"
#include "G4PhysicalVolumeStore.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4SolidStore.hh"

#include "G4Isotope.hh"
#include "G4Element.hh"
#include "G4Material.hh"
#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4UnitsTable.hh"
#include "G4Colour.hh"
#include "G4PhysicalConstants.hh"
#include "G4VisAttributes.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........

std::map<G4String,G4int> Geometry::volumeID;

Geometry::Geometry() : G4VUserDetectorConstruction()
{ 
  lengthXworld    = 200.*mm;
  lengthYworld    = 200.*mm;
  lengthZworld    = 400.*mm;  //z is the mu+ beam direction
  
  posZPb          = -90*mm;
  diaPb           = 60.0*mm;
  diaPbHole       = 16.0*mm;
  lengthZPb       = 50.0*mm; 
  lengthZPbHole   = lengthZPb;
  
  posZmylar       = -60*mm;
  diaMylar        = 40.0*mm;
  thickMylar      = 0.034*mm;
  
  posZAlPipe      = -60*mm;
  diaAlPipe       = 70.0*mm;
  diaAlPipeInner  = diaMylar;
  thickAlPipe     = 10.0*mm;
  
  posZVC          = -53*mm;
  lengthVC        = 50*mm;
  diaVCInner      = 10.0*mm;
  thickVC         = 3.0*mm;
  
  posZBC          = -13.75*mm;
  lengthBC        = 18.0*mm;
  thickBC         = 0.33*mm;
  
  posZAerogel     = -4.5*mm;
  lengthXAerogel  = 50.0*mm;
  lengthYAerogel  = 50.0*mm;
  lengthZAerogel  = 9.0*mm;
  fPerfLyrDn      = 0.0235*CLHEP::g/CLHEP::cm3;

  DefineMaterials();
}


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........
Geometry::~Geometry() { }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........
G4VPhysicalVolume* Geometry::Construct()
{
  // Clean old geometry, if any
  G4GeometryManager::GetInstance()->OpenGeometry();
  G4PhysicalVolumeStore::GetInstance()->Clean();
  G4LogicalVolumeStore::GetInstance()->Clean();
  G4SolidStore::GetInstance()->Clean();


  //============ World Volume (VolID= 0) =============
  solidWorld
    = new G4Box("World", lengthXworld/2.0, lengthYworld/2.0, lengthZworld/2.0);
  logicalWorld
    = new G4LogicalVolume(solidWorld, fDefaultMaterial, "World");
  physWorld
    = new G4PVPlacement(G4Transform3D(), "World", logicalWorld, 0, false, 0);

  volumeID["World"]= 0;
  
  //=============== Pb Collimator (VolID= 1) ===============
  solidPb
    = new G4Tubs("Pb", 0., diaPb/2.0, lengthZPb/2.0, 0., 360.*deg);
  solidPbHole
    = new G4Tubs("PbHole", 0., diaPbHole/2.0, lengthZPbHole/2.0, 0., 360.*deg);
  G4VSolid* solidPbCollimator
    = new G4SubtractionSolid("PbCollimator", solidPb, solidPbHole);
  logicalPbCollimator
    = new G4LogicalVolume(solidPbCollimator, fPbMaterial, "PbCollimator");
  physPbCollimator
    = new G4PVPlacement(0, G4ThreeVector(0,0,posZPb), "PbCollimator",
			logicalPbCollimator, physWorld, false, 0);

  volumeID["PbCollimator"]= 1;
  
  //=============== Mylar Window (VolID= 2) ===============
  // Define 1 piece of 'mylar windows' (thickness = 50 um)
  solidMylar
    = new G4Tubs("MylarWindow", 0., diaMylar/2.0, thickMylar/2.0, 0., 360.*deg);
  logicalMylar
    = new G4LogicalVolume(solidMylar, fMylarMaterial, "MylarWindow");
  physMylar
    = new G4PVPlacement(0, G4ThreeVector(0,0,posZmylar), "MylarWindow",
			logicalMylar, physWorld, false, 0);

  volumeID["MylarWindow"]= 2;
  
  //=============== Al Pipe (VolID= 3) ===============
  solidAl
    = new G4Tubs("AlPipe", 0., diaAlPipe/2.0, thickAlPipe/2.0, 0., 360.*deg);
  solidAlPipeHole
    = new G4Tubs("AlPipeHole", 0., diaAlPipeInner/2.0, thickAlPipe/2.0, 0.,
		 360.*deg);
  G4VSolid* solidAlPipe
    = new G4SubtractionSolid("AlPipe", solidAl, solidAlPipeHole);
  logicalAlPipe
    = new G4LogicalVolume(solidAlPipe, fPipeMaterial, "AlPipe");
  physAlPipe
    = new G4PVPlacement(0, G4ThreeVector(0,0,posZAlPipe), "AlPipe",
			logicalAlPipe, physWorld, false, 0);

  volumeID["AlPipe"]= 3;
  
  //=============== Veto Counter (VC) (VolID= 4) ===============
  solidVCBox
    = new G4Box("VCBox", lengthVC/2, lengthVC/2, thickVC/2);
  solidVCHole
    = new G4Tubs("VCHole", 0., diaVCInner/2.0, thickVC/2.0, 0., 360.*deg);
  G4VSolid* solidVC
    = new G4SubtractionSolid("VC", solidVCBox, solidVCHole);
  logicalVC
    = new G4LogicalVolume(solidVC, fScintillatorMaterial, "VC");
  physVC
    = new G4PVPlacement(0, G4ThreeVector(0,0,posZVC), "VC",
			logicalVC, physWorld, false, 0);

  volumeID["VC"]= 4;

  //=============== Mylar Wrap (VolID= 5, 6) ===============
  // Define 2 piece of 'mylars wrapped around BC' (thickness = 0.006 um)
  solidMylarWrap
    = new G4Box("MylarWrap", lengthBC/2, lengthBC/2,  0.006*mm/2);
  logicalMylarWrap
    = new G4LogicalVolume(solidMylarWrap, fMylarMaterial, "MylarWrap");
  physMylarWrap1 // ID= 5
    = new G4PVPlacement(0, G4ThreeVector(0,0,posZBC-thickBC/2-thickMylar/2),
			"MylarWrap1", logicalMylarWrap, physWorld, false, 1);
  physMylarWrap2 // ID= 6
    = new G4PVPlacement(0, G4ThreeVector(0,0,posZBC+thickBC/2+thickMylar/2),
			"MylarWrap2", logicalMylarWrap, physWorld, false, 2);

  volumeID["MylarWrap"]= 5;
  volumeID["MylarWrap1"]= 5;
  volumeID["MylarWrap2"]= 6;
    
  //=============== Beam Counter (BC) (VolID= 7) ===============
  solidBC
    = new G4Box("BCBox", lengthBC/2, lengthBC/2, thickBC/2);
  logicalBC
    = new G4LogicalVolume(solidBC, fScintillatorMaterial, "BC");
  physBC
    = new G4PVPlacement(0, G4ThreeVector(0,0,posZBC), "BC",
			logicalBC, physWorld, false, 0);

  volumeID["BC"]= 7;
    
  //=============== Silica Aerogel (VolID= 8) ===============
  solidAerogel
    = new G4Box("Aerogel", lengthXAerogel/2.0,
		lengthYAerogel/2.0, lengthZAerogel/2.0);
  logicalAerogel
    = new G4LogicalVolume(solidAerogel, fPerfLyrMaterial, "Aerogel");
  physAerogel
    = new G4PVPlacement(0, G4ThreeVector(0,0,posZAerogel), "Aerogel",
			logicalAerogel, physWorld, false, 0);

  volumeID["Aerogel"]= 8;
  
  return physWorld;
}



// M A T E R I A L    D E F I N E
void Geometry::DefineMaterials()
{ 
  // use G4-NIST materials data base
  G4NistManager* materialMan = G4NistManager::Instance();
  fDefaultMaterial = materialMan->FindOrBuildMaterial("G4_Galactic");
  
  G4Element* Si = materialMan->FindOrBuildElement("Si");
  G4Element* O  = materialMan->FindOrBuildElement("O");
  fPerfLyrMaterial = new G4Material("Aerogel1", density= fPerfLyrDn, nel=2);
  fPerfLyrMaterial->AddElement(Si, natoms=1);
  fPerfLyrMaterial->AddElement(O, natoms=2);
  
  fPbMaterial     = materialMan->FindOrBuildMaterial("G4_Pb");
  fMylarMaterial  = materialMan->FindOrBuildMaterial("G4_MYLAR");
  fKaptonMaterial = materialMan->FindOrBuildMaterial("G4_KAPTON");
  fPipeMaterial   = materialMan->FindOrBuildMaterial("G4_Al");
  fScintillatorMaterial
        = materialMan->FindOrBuildMaterial("G4_PLASTIC_SC_VINYLTOLUENE");;
  fSiO2 = materialMan->FindOrBuildMaterial("G4_SILICON_DIOXIDE");

  //=============== G4_vacuum =================
  // From PhysicalConstants.h
  // G4double density, massfraction, nComponents, temperature, pressure;  
  //  density     = 2.376e-15*g/cm3;
  //  pressure    = 1.e-19*pascal;
  //  temperature = 300*kelvin;
  //  G4Material* vacuum = new G4Material( "Galactic", density, nComponents=1,
  //				       kStateGas, temperature, pressure );
  //  vacuum-> AddMaterial( materialMan->FindOrBuildMaterial("G4_AIR"),
  //		        massfraction=1.0 );
  //  G4cout << *(G4Material::GetMaterialTable()) << G4endl;
}

