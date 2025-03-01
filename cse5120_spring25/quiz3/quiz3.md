**CSE 5120 Introduction to Artificial Intelligence**
**Quiz 03**

---

### **Question 1: Uniform-cost search**

Given a state space (a search graph) and the corresponding transition model of a route planning problem as shown in Figure 1, starting from the original city **A** as the initial state to reach the goal city  **E** , please list the order to expand the nodes (nodes can be labeled by the state/city of the node data structure) **in the derived search tree** (not the graph representation of the state space in Figure 1), using the tree search algorithm (with  **no check on repeated states** , i.e., visiting the same city multiple times is allowed) by a  **uniform-cost search (UCS)** .

---

#### **A hint:**

Please be reminded that **UCS** performs the goal condition check of a node to conclude the search process **when the node is expanded** (i.e., when the node is removed from the fringe of a priority queue), but **not** when the node is first generated (i.e., not when the node is inserted into the fringe list). This is one of the key differences between **UCS** and  **BFS** .
