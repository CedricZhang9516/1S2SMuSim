//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Geometry.hh
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef Geometry_h
#define Geometry_h 1

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"
#include <map>

class G4VPhysicalVolume;
class G4Box;
class G4Tubs;
class G4SubtractionSolid;
class G4LogicalVolume;
class G4VPhysicalVolume;
class G4Material;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........
class Geometry : public G4VUserDetectorConstruction
{
  public:
    Geometry();
   ~Geometry();

  static std::map<G4String,G4int> volumeID;
  
  private:
    G4int              nel;  // nel=number of elements;
    G4int              natoms; // natoms=number of atoms
    G4double           density; 

    G4Material*        fDefaultMaterial;
    G4double           lengthXworld;
    G4double           lengthYworld;
    G4double           lengthZworld;

    G4Material*        fPbMaterial;
    G4double           diaPb;
    G4double           lengthZPb; 
    G4double           posZPb;
    G4double           diaPbHole;
    G4double           lengthZPbHole;

    G4Material*        fMylarMaterial;
    G4Material*        fKaptonMaterial;
    G4double           diaMylar;
    G4double           thickMylar;
    G4double           posZmylar;

    G4Material*        fPipeMaterial;
    G4double           posZAlPipe;
    G4double           diaAlPipe;
    G4double           diaAlPipeInner;
    G4double           thickAlPipe;

    G4Material*        fScintillatorMaterial;
    G4double           posZVC;
    G4double           lengthVC;
    G4double           diaVCInner;
    G4double           thickVC;
    G4double           posZBC;
    G4double           lengthBC;
    G4double           thickBC;

    G4Material*        fPerfLyrMaterial;
    G4double           lengthXAerogel;
    G4double           lengthYAerogel;
    G4double           lengthZAerogel;
    G4double           posZAerogel;
    G4double           fPerfLyrDn;
    G4Material*        fSiO2;


    G4Box*             solidWorld;                  
    G4LogicalVolume*   logicalWorld; 
    G4VPhysicalVolume* physWorld;

    G4Tubs*            solidPb;
    G4Tubs*            solidPbHole;
    G4LogicalVolume*   logicalPbCollimator;
    G4VPhysicalVolume* physPbCollimator;

    G4Tubs*            solidMylar;
    G4LogicalVolume*   logicalMylar;
    G4VPhysicalVolume* physMylar;
    G4Tubs*            solidAl;
    G4Tubs*            solidAlPipeHole;
    G4LogicalVolume*   logicalAlPipe;
    G4VPhysicalVolume* physAlPipe;

    G4Box*             solidVCBox;
    G4Tubs*            solidVCHole;
    G4LogicalVolume*   logicalVC;
    G4VPhysicalVolume* physVC;

    G4Box* solidMylarWrap;
    G4LogicalVolume* logicalMylarWrap; 
    G4VPhysicalVolume* physMylarWrap1;
    G4VPhysicalVolume* physMylarWrap2; 
    G4Box*             solidBC;
    G4LogicalVolume*   logicalBC;
    G4VPhysicalVolume* physBC;

    G4Box*             solidAerogel;
    G4LogicalVolume*   logicalAerogel;
    G4VPhysicalVolume* physAerogel;

    void DefineMaterials();
    G4VPhysicalVolume* Construct();
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........
#endif
