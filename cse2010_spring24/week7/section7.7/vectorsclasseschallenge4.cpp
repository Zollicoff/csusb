#include <iostream>
#include <vector>
using namespace std;

class Recording {
   public:
      void SetTopicAndDuration(string newTopic, int newDuration);
		void Print() const;
   private:
      string topic;
      int duration;
};

void Recording::SetTopicAndDuration(string newTopic, int newDuration) {
   topic = newTopic;
   duration = newDuration;
}

void Recording::Print() const {
	cout << "Recording: " << topic << ", Duration: " << duration << endl;
}

int main() {
   vector<Recording> recordingList;
   Recording currRecording;
   string currTopic;
   int currDuration;
   int recordingCount;
   unsigned int i;

   cin >> recordingCount;
   for (i = 0; i < recordingCount; ++i) {
      cin >> currTopic;
      cin >> currDuration;
      
      currRecording.SetTopicAndDuration(currTopic, currDuration);
      recordingList.push_back(currRecording);
   }

   for (i = 0; i < recordingList.size(); ++i) {
      currRecording = recordingList.at(i);
      currRecording.Print();
   }

   return 0;
}
