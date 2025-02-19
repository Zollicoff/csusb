Starting Breadth-first Search from A to reach E...

Expand A
Dequeue A
Enqueue B, C, D
Queue after enqueueing ['B', 'C', 'D']

Expand B
Dequeue B
Enqueue C
Queue after enqueueing: ['C', 'D', 'C']

Expand C
Dequeue C
Queue after enqueueing: ['D', 'C']

Expand D
Dequeue D
Enqueue E
Queue after enqueueing: ['C', 'E']

Expand C
Dequeue: C
Queue after enqueueing: ['E']

Expand E
Dequeued: E
Queue after enqueueing: []

Goal E reached!

Final Expansion Order: ['A', 'B', 'C', 'D', 'C', 'E']