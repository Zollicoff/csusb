#include "StringInstrument.h"

void StringInstrument::SetNumOfStrings(int numStrings) {
   this->numStrings = numStrings;
}

int StringInstrument::GetNumOfStrings() {
   return this->numStrings;
}

void StringInstrument::SetNumOfFrets(int numFrets) {
   this->numFrets = numFrets;
}

int StringInstrument::GetNumOfFrets() {
   return this->numFrets;
}

void  StringInstrument::SetIsBowed(bool isBowed) {
   this->isBowed = isBowed;
}

bool StringInstrument::GetIsBowed() {
   return this->isBowed;
}
