//
/// \file GdScintDetectorConstruction.hh
/// \brief Definition of the GdScintDetectorConstruction class

#ifndef GdScintDetectorConstruction_h
#define GdScintDetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"

class G4VPhysicalVolume;
class G4LogicalVolume;

/// Detector construction class to define materials and geometry.

class GdScintDetectorConstruction : public G4VUserDetectorConstruction
{
  public:
    GdScintDetectorConstruction();
    virtual ~GdScintDetectorConstruction();

    virtual G4VPhysicalVolume* Construct();

    G4LogicalVolume* GetScoringVolume() const { return fScoringVolume; }

  protected:
    G4LogicalVolume*  fScoringVolume;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
