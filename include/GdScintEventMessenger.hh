#ifndef DriftEventMessenger_h
#define DriftEventMessenger_h 1

#include "globals.hh"
#include "G4UImessenger.hh"

#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"

class DriftEventAction;
class G4UIdirectory;
class G4UIcmdWithAString;
class G4UIcmdWithAnInteger;

class DriftEventMessenger: public G4UImessenger
{
  public:
    DriftEventMessenger(DriftEventAction* );
   ~DriftEventMessenger();
    
    void SetNewValue(G4UIcommand*, G4String);
    
  private:
  DriftEventAction* DriftEvAct;
   
    G4UIdirectory*             DriftEADir;
    G4UIcmdWithAString*        SetFileCmd;
    G4UIcmdWithAnInteger*        SetThresholdCmd;
};

#endif
