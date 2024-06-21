#include <iostream>
using namespace std;

class Computer {
public:
   void SetComputerStatus(string cpuStatus, string internetStatus) {
      cpuUsage = cpuStatus;
      internet = internetStatus;
   };

   void PrintStatus() {
      cout << "Internet: " << internet << endl;
      cout << "CPU: " << cpuUsage << endl;
   };

protected:
   string cpuUsage;
   string internet;
};

class Laptop : public Computer {
public:
   void SetWiFiStatus(string wifiStatus) {
      wifiQuality = wifiStatus;
   };

   void PrintStatus() {
      cout << "CPU: " << cpuUsage << endl;
      cout << "WiFi: " << wifiQuality << endl;
   };

private:
   string wifiQuality;
};

int main() {
   Laptop myLaptop;

   myLaptop.SetComputerStatus("20%", "connected");
   myLaptop.SetWiFiStatus("bad");

   myLaptop.PrintStatus();

   return 0;
}
