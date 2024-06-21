#include <iostream>
using namespace std;
  
class SeahorseNode {
   public:
      SeahorseNode(int babiesInit = 0, SeahorseNode* nextLoc = nullptr);
      void InsertAfter(SeahorseNode* nodeLoc);
      SeahorseNode* GetNext();
      int GetNodeData();
   private:
      int babiesVal;
      SeahorseNode* nextNodePtr;
};

SeahorseNode::SeahorseNode(int babiesInit, SeahorseNode* nextLoc) {
   this->babiesVal = babiesInit;
   this->nextNodePtr = nextLoc;
}

void SeahorseNode::InsertAfter(SeahorseNode* nodeLoc) {
   SeahorseNode* tmpNext = nullptr;

   tmpNext = this->nextNodePtr;
   this->nextNodePtr = nodeLoc;
   nodeLoc->nextNodePtr = tmpNext;
}

SeahorseNode* SeahorseNode::GetNext() {
   return this->nextNodePtr;
}

int SeahorseNode::GetNodeData() {
   return this->babiesVal;
}

int main() {
   SeahorseNode* headSeahorse = nullptr;
   SeahorseNode* currSeahorse = nullptr;
   SeahorseNode* lastSeahorse = nullptr;
   int count;
   int inputValue;
   int i;
   
   cin >> count;
   
   headSeahorse = new SeahorseNode(count);
   lastSeahorse = headSeahorse;

   for (i = 0; i < count; ++i) {
      cin >> inputValue;
      
      currSeahorse = new SeahorseNode(inputValue);
      
      lastSeahorse->InsertAfter(currSeahorse);
      lastSeahorse = currSeahorse;
   }

   /* Your code goes here */
   currSeahorse = headSeahorse;
   while (currSeahorse != nullptr) {
      if (currSeahorse->GetNodeData() == 0) {
         cout << "Found a seahorse without babies." << endl;
      }
      currSeahorse = currSeahorse->GetNext();
   }

   
   return 0;
}
