Zachary Hampton

Dr. Xiangyu Li

CSE 5120 Intro to AI

28 February 2025

Quiz 3

UCS Tree Search from A to reach E...
NO check on repeated states - can visit same city multiple times.
Checking for goal when nodes are EXPANDED (removed from queue).

Dequeued: A with cost 0
Expanded: A, Cost so far: 0
Enqueued: B with cost 3
Enqueued: C with cost 3
Enqueued: D with cost 7
Current Priority Queue: [(3, 'B'), (3, 'C'), (7, 'D')]

Dequeued: B with cost 3
Expanded: B, Cost so far: 3
Enqueued: C with cost 6
Current Priority Queue: [(3, 'C'), (7, 'D'), (6, 'C')]

Dequeued: C with cost 3
Expanded: C, Cost so far: 3
Current Priority Queue: [(6, 'C'), (7, 'D')]

Dequeued: C with cost 6
Expanded: C, Cost so far: 6
Current Priority Queue: [(7, 'D')]

Dequeued: D with cost 7
Expanded: D, Cost so far: 7
Enqueued: E with cost 8
Current Priority Queue: [(8, 'E')]

Dequeued: E with cost 8
Goal E reached!
Final path: A -> D -> E
Total cost: 8
