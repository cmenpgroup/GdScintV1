//Mostly relic from Scint Sim.  Easily changed for interactive commands for DRIFT Sim if reqd.

#include "DriftEventMessenger.hh"
#include "DriftEventAction.hh"
#include "G4UIdirectory.hh"
#include "G4UIcmdWithAString.hh"
#include "G4UIcmdWithADouble.hh"
#include "G4UIcmdWithAnInteger.hh"

DriftEventMessenger::DriftEventMessenger(DriftEventAction * DriftEA)
:DriftEvAct(DriftEA)
{ 
  DriftEADir = new G4UIdirectory("/DriftEA/");
  DriftEADir->SetGuidance("Drift event action control.");

  SetThresholdCmd = new G4UIcmdWithAnInteger("/DriftEA/setThreshold",this);
  SetThresholdCmd->SetGuidance("Set the threshold of the pmts");
  SetThresholdCmd->SetParameterName("Threshold",false);
  SetThresholdCmd->AvailableForStates(G4State_Idle);

  //output to a root file, set its filename  
  SetFileCmd = new G4UIcmdWithAString("/DriftEA/setFile",this);
  SetFileCmd->SetGuidance("Set the output root filename");
  SetFileCmd->SetParameterName("filename",false);
  SetFileCmd->AvailableForStates(G4State_Idle);
}

DriftEventMessenger::~DriftEventMessenger()
{
  delete SetThresholdCmd;
  delete SetFileCmd;
  delete DriftEADir;
}

void DriftEventMessenger::SetNewValue(G4UIcommand* command,G4String newValue)
{ 
//Set the threshold of pmts
  if( command == SetThresholdCmd )
    {
    G4int th;
    if(SetThresholdCmd->GetNewIntValue(newValue)) th=(SetThresholdCmd->GetNewIntValue(newValue));
      DriftEvAct->SetThreshold(th);
   }
  
  //Set filename for root output
  else if (command == SetFileCmd) {
     DriftEvAct->SetFileName(newValue.data());
     }
  }
