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

# Initialize an empty graph
G = nx.Graph()

# Add edges to the graph
for node, neighbors in network_topology.items():
    for neighbor, weight in neighbors.items():
        G.add_edge(node, neighbor, weight=weight)

# Draw the graph
pos = nx.spring_layout(G)  # Positioning the nodes

# Draw nodes and edges with weights
nx.draw(G, pos, with_labels=True, node_size=700, font_size=14, font_weight='bold')
edge_labels = nx.get_edge_attributes(G, 'weight')
nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels, font_size=12)

# Save the graph as an image file
plt.title("Network Topology Graph")
plt.savefig("network_topology_graph.png")
plt.show()
