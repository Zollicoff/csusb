import networkx as nx
import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

# Define the network topology as an adjacency list
network_topology = {
    'a': {'b': 4, 'e': 2, 'g': 8},
    'b': {'a': 4, 'e': 2, 'c': 2},
    'c': {'b': 2, 'e': 4, 'd': 4},
    'd': {'c': 4, 'f': 2, 'h': 6},
    'e': {'a': 2, 'b': 2, 'c': 4, 'f': 5},
    'f': {'e': 5, 'd': 2, 'h': 5},
    'g': {'a': 8, 'h': 4},
    'h': {'d': 6, 'f': 5, 'g': 4}
}

# Initialize the graph for visualization
G = nx.Graph()
for node, neighbors in network_topology.items():
    for neighbor, weight in neighbors.items():
        G.add_edge(node, neighbor, weight=weight)

# Custom positions for each node with centered alignment for each row
pos = {
    'b': (1, 2), 'c': (2, 2), 'd': (3, 2),             # Top row, centered
    'a': (0.5, 1), 'e': (1.5, 1), 'f': (2.5, 1), 'h': (3.5, 1),  # Middle row, centered
    'g': (2, 0)  # Bottom row, centered
}

# Draw the graph with custom node positions
plt.figure(figsize=(8, 6))
nx.draw(G, pos, with_labels=True, node_size=700, font_size=14, font_weight='bold')
edge_labels = nx.get_edge_attributes(G, 'weight')
nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels, font_size=12)
plt.title("Centered Symmetrical Network Topology Graph")
plt.show()

# Dijkstra's Algorithm for step-by-step table creation
nodes = list(network_topology.keys())
distances = {node: np.inf for node in nodes}
previous_nodes = {node: None for node in nodes}
distances['a'] = 0  # Starting from node 'a'
visited = set()
steps = []

# Dijkstra's Algorithm with steps recorded
while len(visited) < len(nodes):
    # Find the unvisited node with the smallest distance
    current_node = min((node for node in distances if node not in visited), key=distances.get)
    visited.add(current_node)

    # Record the step
    steps.append({
        'N\'': ''.join(visited),
        **{f"D({node})": distances[node] if distances[node] != np.inf else '∞' for node in nodes},
        **{f"P({node})": previous_nodes[node] if previous_nodes[node] else '' for node in nodes}
    })

    # Update the distances for neighbors of the current node
    for neighbor, weight in network_topology[current_node].items():
        if neighbor not in visited:
            new_distance = distances[current_node] + weight
            if new_distance < distances[neighbor]:
                distances[neighbor] = new_distance
                previous_nodes[neighbor] = current_node

# Convert steps to a DataFrame for easier visualization
df = pd.DataFrame(steps)

# Display the DataFrame as a table
print(df)
