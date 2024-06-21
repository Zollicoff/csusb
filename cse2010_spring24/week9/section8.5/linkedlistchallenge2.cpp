#include <iostream>
using namespace std;
  
class BlackbirdNode {
   public:
      BlackbirdNode(int chicksInit = 0, BlackbirdNode* nextLoc = nullptr);
      void InsertAfter(BlackbirdNode* nodeLoc);
      BlackbirdNode* GetNext();
      void PrintNodeData();
   private:
      int chicksVal;
      BlackbirdNode* nextNodePtr;
};

BlackbirdNode::BlackbirdNode(int chicksInit, BlackbirdNode* nextLoc) {
   this->chicksVal = chicksInit;
   this->nextNodePtr = nextLoc;
}

void BlackbirdNode::InsertAfter(BlackbirdNode* nodeLoc) {
   BlackbirdNode* tmpNext = nullptr;

   tmpNext = this->nextNodePtr;
   this->nextNodePtr = nodeLoc;
   nodeLoc->nextNodePtr = tmpNext;
}

BlackbirdNode* BlackbirdNode::GetNext() {
   return this->nextNodePtr;
}

void BlackbirdNode::PrintNodeData() {
   cout << this->chicksVal << endl;
}

int main() {
   BlackbirdNode* headBlackbird = nullptr;
   BlackbirdNode* currBlackbird = nullptr;
   BlackbirdNode* lastBlackbird = nullptr;
   int blackbirdCount;
   int inputValue;
   int i;

   cin >> blackbirdCount;
   
   headBlackbird = new BlackbirdNode(blackbirdCount);
   lastBlackbird = headBlackbird;
   
   /* Your code goes here */
   for (int i = 1; i <= blackbirdCount; i++) {
      cin >> inputValue;
      currBlackbird = new BlackbirdNode(inputValue);
      lastBlackbird->InsertAfter(currBlackbird);
      lastBlackbird = currBlackbird;
   }
   
   currBlackbird = headBlackbird;
   while (currBlackbird != nullptr) {
      currBlackbird->PrintNodeData();
      currBlackbird = currBlackbird->GetNext();
   }

   return 0;
}
