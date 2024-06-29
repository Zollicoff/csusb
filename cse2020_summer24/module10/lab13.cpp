#include <fstream>
#include <iostream>
#include "MergeSort.hpp"

using namespace std;

int main()
{
    vector<int> v;
    
    // Read values from sort.txt
    ifstream input("sort.txt");
    int number;
    while (input >> number)
    {
        v.push_back(number);
    }
    input.close();

    // Call merge sort function
    mergeSort(v);

    // Print the sorted items
    cout << "The merge sort: ";
    for (const auto& num : v)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
