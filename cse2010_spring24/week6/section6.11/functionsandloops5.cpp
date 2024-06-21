#include <iostream>
#include <vector>
using namespace std;

void ReverseVector(const vector<int>& inputVector, vector<int>& outputVector) {
   outputVector.clear();
   
   for (int i = inputVector.size() - 1; i >= 0; --i) {
      outputVector.push_back(inputVector.at(i));
   }
}

int main() {
   int i;
	vector<int> inputVector;
	vector<int> reversed;
	int size;
	int input;

	cin >> size;
	for (i = 0; i < size; ++i) {
		cin >> input;
		inputVector.push_back(input);
	}

   ReverseVector(inputVector, reversed);

	for (i = 0; i < reversed.size(); ++i) {
		cout << reversed.at(i) << endl;
	}

   return 0;
}
