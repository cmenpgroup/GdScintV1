//
/// \file GdScintActionInitialization.hh
/// \brief Definition of the GdScintActionInitialization class

#ifndef GdScintActionInitialization_h
#define GdScintActionInitialization_h 1

#include "G4VUserActionInitialization.hh"

/// Action initialization class.

class GdScintActionInitialization : public G4VUserActionInitialization
{
  public:
    GdScintActionInitialization();
    virtual ~GdScintActionInitialization();

    virtual void BuildForMaster() const;
    virtual void Build() const;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
