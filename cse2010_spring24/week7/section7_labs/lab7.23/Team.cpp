#include <iostream>
#include <iomanip> 
#include "Team.h"
using namespace std;

void Team::SetName(string name) {
   this->name = name;
}

void Team::SetWins(int wins) {
   this->wins = wins;
}

void Team::SetLosses(int losses) {
   this->losses = losses;
}

string Team::GetName() {
   return name;
}

int Team::GetWins() {
   return wins;
}

int Team::GetLosses() {
   return losses;
}

double Team::GetWinPercentage() {
   return (double)wins / (wins + losses);
}

void Team::PrintStanding() {
   double winPercentage = GetWinPercentage();
   cout << "Win percentage: " << fixed << setprecision(2) << winPercentage << endl;
   if (winPercentage >= 0.5) {
      cout << "Congratulations, Team " << name << " has a winning average!" << endl;
   } else {
      cout << "Team " << name << " has a losing average." << endl;
   }
}