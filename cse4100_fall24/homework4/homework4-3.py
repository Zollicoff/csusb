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

# --- Distance Vector Algorithm Initialization (t=0) ---

# Initial Distance Vector at t=0 for each router
distance_vectors = {
    'a': {'a': 0, 'b': 4, 'c': np.inf, 'd': np.inf, 'e': 2, 'f': np.inf, 'g': 8, 'h': np.inf},
    'b': {'a': 4, 'b': 0, 'c': 2, 'd': np.inf, 'e': 2, 'f': np.inf, 'g': np.inf, 'h': np.inf},
    'c': {'a': np.inf, 'b': 2, 'c': 0, 'd': 4, 'e': 4, 'f': np.inf, 'g': np.inf, 'h': np.inf},
    'd': {'a': np.inf, 'b': np.inf, 'c': 4, 'd': 0, 'e': np.inf, 'f': 2, 'g': np.inf, 'h': 6},
    'e': {'a': 2, 'b': 2, 'c': 4, 'd': np.inf, 'e': 0, 'f': 5, 'g': np.inf, 'h': np.inf},
    'f': {'a': np.inf, 'b': np.inf, 'c': np.inf, 'd': 2, 'e': 5, 'f': 0, 'g': np.inf, 'h': 5},
    'g': {'a': 8, 'b': np.inf, 'c': np.inf, 'd': np.inf, 'e': np.inf, 'f': np.inf, 'g': 0, 'h': 4},
    'h': {'a': np.inf, 'b': np.inf, 'c': np.inf, 'd': 6, 'e': np.inf, 'f': 5, 'g': 4, 'h': 0}
}

# Create a DataFrame for the initial Distance Vector table at t=0 for all routers
dv_table_t0 = pd.DataFrame(distance_vectors).transpose().replace(np.inf, '∞')
dv_table_t0.index.name = 'Router'
dv_table_t0.columns = [f"DV to {col}" for col in dv_table_t0.columns]

# --- Distance Vector Update for Router 'd' at t=1 ---

# Update Distance Vector for router 'd' based on neighbors 'c' and 'f'
neighbors_d = ['c', 'f']
for dest in distance_vectors['d'].keys():
    new_distances = [distance_vectors['d'][neighbor] + distance_vectors[neighbor][dest]
                     for neighbor in neighbors_d if distance_vectors[neighbor][dest] != np.inf]
    if new_distances:
        distance_vectors['d'][dest] = min([distance_vectors['d'][dest]] + new_distances)

# Create a DataFrame for the updated Distance Vector table for router 'd' at t=1
dv_table_d_t1 = pd.DataFrame([distance_vectors['d']], index=['Router d at t=1']).replace(np.inf, '∞')
dv_table_d_t1.columns = [f"DV to {col}" for col in dv_table_d_t1.columns]

# Plot both graph and tables side by side
fig, axs = plt.subplots(1, 3, figsize=(18, 8))
fig.suptitle("Network Topology, Initial Distance Vectors at t=0, and Distance Vector for Router d at t=1")

# Draw the network graph
nx.draw(G, pos, with_labels=True, ax=axs[0], node_size=700, font_size=14, font_weight='bold')
edge_labels = nx.get_edge_attributes(G, 'weight')
nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels, font_size=12, ax=axs[0])
axs[0].set_title("Network Topology Graph")

# Display the Distance Vector table for all routers at t=0
axs[1].axis('off')
table1 = axs[1].table(cellText=dv_table_t0.values, colLabels=dv_table_t0.columns, rowLabels=dv_table_t0.index, cellLoc='center', loc='center')
table1.auto_set_font_size(False)
table1.set_fontsize(8)
table1.auto_set_column_width(col=list(range(len(dv_table_t0.columns))))
axs[1].set_title("Distance Vectors for All Routers at t=0")

# Display the Distance Vector table for router 'd' at t=1
axs[2].axis('off')
table2 = axs[2].table(cellText=dv_table_d_t1.values, colLabels=dv_table_d_t1.columns, rowLabels=dv_table_d_t1.index, cellLoc='center', loc='center')
table2.auto_set_font_size(False)
table2.set_fontsize(8)
table2.auto_set_column_width(col=list(range(len(dv_table_d_t1.columns))))
axs[2].set_title("Distance Vector for Router d at t=1")

plt.show()
