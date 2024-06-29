#include <fstream>
#include <iostream>
#include "MergeSort.hpp"

using namespace std;

int main()
{
	vector <int> v;
    
    // add your code
    ifstream input("sort.txt");
    int number;
    while (input >> number) {
        v.push_back(number);
    }
    input.close();
    
    return 0;
}
