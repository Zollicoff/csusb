#include <iostream>
#include <string>

using namespace std;

int GetMonthAsInt(string month) {
	int monthInt = 0;
	
	if (month == "January")
		monthInt = 1;
	else if (month == "February")
		monthInt = 2;
	else if (month == "March")
		monthInt = 3;
	else if (month == "April")
		monthInt = 4;
	else if (month == "May")
		monthInt = 5;
	else if (month == "June")
		monthInt = 6;
	else if (month == "July")
		monthInt = 7;
	else if (month == "August")
		monthInt = 8;
	else if (month == "September")
		monthInt = 9;
	else if (month == "October")
		monthInt = 10;
	else if (month == "November")
		monthInt = 11;
	else if (month == "December")
		monthInt = 12;
	return monthInt;
}

int main () {
    string date;
    string month;
    string day;
    string year;
    int monthInt;
    int dayInt;
    int yearInt;
    
    while(getline(cin, date) && date != "-1") {
       size_t firstSpace = date.find(" ");
       size_t comma = date.find(",");
       if (firstSpace != string::npos && comma != string::npos) {
          month = date.substr(0, firstSpace);
          day = date.substr(firstSpace + 1, comma - firstSpace - 1);
          year = date.substr(comma + 1);
          monthInt = GetMonthAsInt(month);
          try {
             dayInt = stoi(day);
             yearInt = stoi(year);
             if (monthInt != 0 && dayInt > 0 && dayInt <= 31 && yearInt > 0) {
                cout << monthInt << "-" << dayInt << "-" << yearInt << endl;
             }
          } catch (invalid_argument&) {
             // Ignore invalid day or year
          }
       }
    }
}

