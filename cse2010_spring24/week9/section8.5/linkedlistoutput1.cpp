#include <iostream>
using namespace std;

class PlaylistSong {
   public:
      PlaylistSong(string value = "noName", PlaylistSong* nextLoc = nullptr);
      void InsertAfter(PlaylistSong* nodePtr);
      PlaylistSong* GetNext();
      void PrintNodeData();
   private:
      string name;
      PlaylistSong* nextPlaylistSongPtr;
};

PlaylistSong::PlaylistSong(string name, PlaylistSong* nextLoc) {
   this->name = name;
   this->nextPlaylistSongPtr = nextLoc;
}

void PlaylistSong::InsertAfter(PlaylistSong* nodeLoc) {
   PlaylistSong* tmpNext = nullptr;

   tmpNext = this->nextPlaylistSongPtr;
   this->nextPlaylistSongPtr = nodeLoc;
   nodeLoc->nextPlaylistSongPtr = tmpNext;
}

PlaylistSong* PlaylistSong::GetNext() {
   return this->nextPlaylistSongPtr;
}

void PlaylistSong::PrintNodeData() {
   cout << this->name << endl;
}

int main() {
   PlaylistSong* headObj = nullptr;
   PlaylistSong* firstSong = nullptr;
   PlaylistSong* secondSong = nullptr;
   PlaylistSong* thirdSong = nullptr;
   PlaylistSong* currObj = nullptr;

   headObj = new PlaylistSong("head");

   firstSong = new PlaylistSong("Lacrimosa");
   headObj->InsertAfter(firstSong);

   secondSong = new PlaylistSong("Vocalise");
   firstSong->InsertAfter(secondSong);

   thirdSong = new PlaylistSong("Adagio");
   secondSong->InsertAfter(thirdSong);

   currObj = headObj;

   while (currObj != nullptr) {
      currObj->PrintNodeData();
      currObj = currObj->GetNext();
   }
   return 0;
}
