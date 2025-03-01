import networkx as nx
import matplotlib.pyplot as plt
from collections import deque
import threading  # added for timer

plt.ion()

graph = {
    'A': ['B', 'C', 'D'],
    'B': ['C'],
    'C': [],
    'D': ['E'],
    'E': []
}

pos = {
    'A': (2, 3),  # Top row (center)
    'E': (4, 3),  # Top row (aligned with A but to the right)
    'B': (1, 1),  # Second row (left)
    'C': (2, 1),  # Second row (center)
    'D': (3, 1),  # Second row (right)
}

def bfs(graph, start, goal):
    expansion_order = []
    queue = deque([start])
    visited = {start}  # Track nodes already enqueued/visited
    
    while queue:
        node = queue.popleft()
        expansion_order.append(node)
        print(f"Dequeued: {node}")
        print(f"Current Queue: {list(queue)}")
        
        if node == goal:
            print(f"Goal {goal} reached!")
            return expansion_order

        for neighbor in graph[node]:
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)
                print(f"Enqueued: {neighbor}")
                print(f"Current Queue: {list(queue)}")
    
    print("No path found.")
    return expansion_order

# Run BFS and capture the expansion order
print("\nRunning Breadth-First Search (BFS) from A to E:")
order = bfs(graph, 'A', 'E')

# Print the final expansion order
print("\nFinal Expansion Order:", order)

plt.ioff()
