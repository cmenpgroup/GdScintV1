//
/// \file GdScintActionInitialization.cc
/// \brief Implementation of the GdScintActionInitialization class

#include "GdScintActionInitialization.hh"
#include "GdScintPrimaryGeneratorAction.hh"
#include "GdScintRunAction.hh"
#include "GdScintEventAction.hh"
#include "GdScintSteppingAction.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

GdScintActionInitialization::GdScintActionInitialization()
 : G4VUserActionInitialization()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

GdScintActionInitialization::~GdScintActionInitialization()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void GdScintActionInitialization::BuildForMaster() const
{
  GdScintRunAction* runAction = new GdScintRunAction;
  SetUserAction(runAction);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void GdScintActionInitialization::Build() const
{
  SetUserAction(new GdScintPrimaryGeneratorAction);

  GdScintRunAction* runAction = new GdScintRunAction;
  SetUserAction(runAction);

  GdScintEventAction* eventAction = new GdScintEventAction(runAction);
  SetUserAction(eventAction);

  SetUserAction(new GdScintSteppingAction(eventAction));
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
