#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main() {
    int numWords;
    cin >> numWords;

    vector<string> words(numWords);
    map<string, int> totalFrequencies;

    for (int i = 0; i < numWords; ++i) {
        cin >> words[i];
        totalFrequencies[words[i]]++;
    }

    for (const auto& word : words) {
        cout << word << " - " << totalFrequencies[word] << endl;
    }

    return 0;
}
