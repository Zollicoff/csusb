#ifndef STR_INSTRUMENTH
#define STR_INSTRUMENTH

#include "Instrument.h"

class StringInstrument : public Instrument {
private:
   int numStrings;
   int numFrets;
   bool isBowed;

	// TODO: Declare mutator functions - 
	//      SetNumOfStrings(), SetNumOfFrets(), SetIsBowed()

public:
   void SetNumOfStrings(int numStrings);
   int GetNumOfStrings();
   
   void SetNumOfFrets(int numFrets);
   int GetNumOfFrets();
   
   void SetIsBowed(bool isBowed);
   bool GetIsBowed();

};

#endif
