import networkx as nx
import matplotlib.pyplot as plt
import heapq  # For priority queue
import threading  # added for timer

plt.ion()

# Graph with weighted edges (city connections with distances)
graph = {
    'A': [('B', 3), ('C', 3), ('D', 7)],
    'B': [('C', 3)],
    'C': [],
    'D': [('E', 1)],
    'E': []
}

# Node positions for visualization
pos = {
    'A': (2, 3),  # Top row (center)
    'E': (4, 3),  # Top row (aligned with A but to the right)
    'B': (1, 1),  # Second row (left)
    'C': (2, 1),  # Second row (center)
    'D': (3, 1),  # Second row (right)
}

def ucs(graph, start, goal):
    expansion_order = []
    # Priority queue entries are (cumulative_cost, node, [path])
    priority_queue = [(0, start, [])]
    heapq.heapify(priority_queue)
    visited = set()
    
    while priority_queue:
        # Get node with lowest cumulative cost
        cost, node, path = heapq.heappop(priority_queue)
        path = path + [node]
        
        print(f"Dequeued: {node} with cost {cost}")
        print(f"Current Priority Queue: {[(c, n) for c, n, _ in priority_queue]}")

        # Goal test when node is expanded
        if node == goal:
            expansion_order.append(node)
            print(f"Goal {goal} reached!")
            print(f"Final path: {' -> '.join(path)}")
            print(f"Total cost: {cost}")
            return expansion_order
        
        # Skip already expanded nodes
        if node in visited:
            print(f"Skipping already expanded node: {node}")
            continue
        
        # Otherwise, expand the node
        visited.add(node)
        expansion_order.append(node)
        print(f"Expanded: {node}, Cost so far: {cost}")
        
        # Add neighbors to the priority queue
        for neighbor, edge_cost in graph[node]:
            if neighbor not in visited:
                new_cost = cost + edge_cost
                heapq.heappush(priority_queue, (new_cost, neighbor, path))
                print(f"Enqueued: {neighbor} with cost {new_cost}")
                print(f"Current Priority Queue: {[(c, n) for c, n, _ in priority_queue]}")
    
    print("No path found.")
    return expansion_order

# Run UCS and capture the expansion order
print("\nRunning Uniform-Cost Search (UCS) from A to E:")
order = ucs(graph, 'A', 'E')

# Print the final expansion order
print("\nFinal Expansion Order:", order)

plt.ioff()
