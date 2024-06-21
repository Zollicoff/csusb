#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string fileName;
    cin >> fileName;

    ifstream inputFile(fileName);
    if (!inputFile) {
        cout << "Unable to open file " << fileName << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        size_t pos = line.find("_photo.jpg");
        if (pos != string::npos) {
            line.replace(pos, 10, "_info.txt");
            cout << line << endl;
        }
    }

    inputFile.close();
    return 0;
}