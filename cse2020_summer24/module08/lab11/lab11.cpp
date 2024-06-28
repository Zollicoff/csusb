// TestMap.cpp
#include <iostream>
#include <string>   
#include "Map.cpp"
using namespace std;

int main()
{
  Map<string,int> basket;
  int howmany, count;
  string name;

  cout << "How many types of fruits in basket? ";
  cin >> howmany;

  for (int i = 1; i <= howmany; i++)
    {
      cout << "Fruit? ";
      cin >> name;
      cout << endl << "How many? ";
      cin >> count;
      basket[name] = count;
    }
  cout << "Content of my basket:" << endl;
  basket.printMap();
  cout << endl ;

  cout << "Change which fruit? ";
  cin >> name;
  cout << "... to what? ";
  cin >> count;
  cout << endl;

  basket[name] = count;

  basket.printMap();
  cout << endl;
  
  cout << "Check which fruit? ";
  cin >> name;
  cout << "there are " << basket[name] << " " << name << endl << endl;

  cout << "Remove which one? ";
  cin >> name;
  cout << endl ;

  basket.remove(name);

  basket.printMap();
  
  return 0;
}
