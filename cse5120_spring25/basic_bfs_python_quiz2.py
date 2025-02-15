import networkx as nx
import matplotlib.pyplot as plt
from collections import deque

# Define the graph as an adjacency list
graph = {
    'A': ['B', 'C', 'D'],
    'B': ['C'],
    'C': [],
    'D': ['E'],
    'E': []
}

def bfs(graph, start, goal):
    queue = deque([start])  # Initialize queue with the start node
    expansion_order = []  # To store the order of node expansion

    print(f"Starting BFS from {start} to reach {goal}...\n")

    while queue:
        node = queue.popleft()  # Dequeue from front
        expansion_order.append(node)
        print(f"Dequeued: {node}")
        
        # Enqueue all neighbors (without checking for repeated states)
        for neighbor in graph[node]:
            queue.append(neighbor)
            print(f"Enqueued: {neighbor}")

        print(f"Queue after enqueueing: {list(queue)}\n")

        if node == goal:
            print(f"Goal {goal} reached!\n")
            break  # Stop BFS once goal is found

    return expansion_order

# Run BFS and get the expansion order
expansion_order = bfs(graph, 'A', 'E')

# Function to plot the graph with a specific layout
def plot_graph(graph):
    G = nx.DiGraph()  # Create a directed graph
    for node, neighbors in graph.items():
        for neighbor in neighbors:
            G.add_edge(node, neighbor)

    # Custom layout with A and E at the top, B, C, D in the second row
    pos = {
        'A': (2, 3),  # Top row (center)
        'E': (4, 3),  # Top row (aligned with A but to the right)
        'B': (1, 1),  # Second row (left)
        'C': (2, 1),  # Second row (center)
        'D': (3, 1),  # Second row (right)
    }

    plt.figure(figsize=(6, 4))
    nx.draw(G, pos, with_labels=True, node_color="lightblue", edge_color="red",
            node_size=2000, font_size=12, font_weight="bold", arrows=True)
    
    plt.title("Graph Representation with Custom Layout")
    plt.show()

# Plot the graph with the adjusted layout
plot_graph(graph)

print(f"\nFinal Expansion Order: {expansion_order}")
