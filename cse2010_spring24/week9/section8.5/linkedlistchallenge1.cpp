#include <iostream>
using namespace std;

class RabbitNode {
   public:
      RabbitNode(int babiesInit = 0, RabbitNode* nextLoc = nullptr);
      void InsertAfter(RabbitNode* nodeLoc);
      RabbitNode* GetNext();
      void PrintNodeData();
   private:
      int babiesVal;
      RabbitNode* nextNodePtr;
};

RabbitNode::RabbitNode(int babiesInit, RabbitNode* nextLoc) {
   this->babiesVal = babiesInit;
   this->nextNodePtr = nextLoc;
}

void RabbitNode::InsertAfter(RabbitNode* nodeLoc) {
   RabbitNode* tmpNext = nullptr;

   tmpNext = this->nextNodePtr;
   this->nextNodePtr = nodeLoc;
   nodeLoc->nextNodePtr = tmpNext;
}

RabbitNode* RabbitNode::GetNext() {
   return this->nextNodePtr;
}

void RabbitNode::PrintNodeData() {
   cout << this->babiesVal << endl;
}

int main() {
   RabbitNode* headObj = nullptr;
   RabbitNode* firstRabbit = nullptr;
   RabbitNode* secondRabbit = nullptr;
   RabbitNode* currRabbit = nullptr;
   int babies1;
   int babies2;

   cin >> babies1;
   cin >> babies2;

   headObj = new RabbitNode(-1);
   
   /* Your code goes here */
   headObj = new RabbitNode(-1);
   
   firstRabbit = new RabbitNode(babies1);
   headObj->InsertAfter(firstRabbit);
   
   secondRabbit = new RabbitNode(babies2);
   firstRabbit->InsertAfter(secondRabbit);

   currRabbit = headObj;
   while (currRabbit != nullptr) {
      currRabbit->PrintNodeData();
      currRabbit = currRabbit->GetNext();
   }

   return 0;
}