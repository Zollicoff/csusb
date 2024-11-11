import networkx as nx
import matplotlib.pyplot as plt

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

# Initialize the graph
G = nx.Graph()

# Add edges to the graph
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

# Display the graph
plt.title("Centered Symmetrical Network Topology Graph")
plt.show()
