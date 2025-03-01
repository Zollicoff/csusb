**CSE 5120 Introduction to Artificial Intelligence**
**Quiz 02**

---

### **Question 1: Breadth-first search**

Given a state space (a search graph) and the corresponding transition model of a route planning problem as shown in Figure 1, starting from the original city **A** as the initial state to reach the goal city  **E** , please list the order to expand the nodes (nodes can be labeled by the state/city of the node data structure) **in the derived search tree** (not the graph representation of the state space shown in Figure 1), using the tree search algorithm (i.e., with **no check on repeated states** and visiting the same city multiple times is allowed) by a  **breadth-first search (BFS)** .

---

#### **A hint:**

Please be reminded that **BFS** performs the goal condition check of a node to conclude the search process **when a node is pushed into the fringe** (**FIFO** queue), but **not** when a node is expanded ( **removed from the fringe** ).
