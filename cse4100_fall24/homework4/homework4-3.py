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

# --- Dijkstra's Algorithm for Step-by-Step Table ---

nodes = list(network_topology.keys())
distances = {node: np.inf for node in nodes}
previous_nodes = {node: None for node in nodes}
distances['a'] = 0  # Starting from node 'a'
visited = set()
steps = []

# Dijkstra's Algorithm with steps recorded
step_number = 0
while len(visited) < len(nodes):
    # Find the unvisited node with the smallest distance
    current_node = min((node for node in distances if node not in visited), key=distances.get)
    visited.add(current_node)

    # Record the step with format: Step | N' | D(node),P(node) for each node
    step = {'Step': step_number, 'N\'': ''.join(visited)}
    for node in nodes:
        distance = distances[node] if distances[node] != np.inf else '∞'
        predecessor = previous_nodes[node] if previous_nodes[node] else ''
        step[f"D({node}),P({node})"] = f"{distance},{predecessor}"
    steps.append(step)

    # Update the distances for neighbors of the current node
    for neighbor, weight in network_topology[current_node].items():
        if neighbor not in visited:
            new_distance = distances[current_node] + weight
            if new_distance < distances[neighbor]:
                distances[neighbor] = new_distance
                previous_nodes[neighbor] = current_node

    # Move to the next step
    step_number += 1

# Convert steps to a DataFrame for easier visualization
dijkstra_df = pd.DataFrame(steps)

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

# Plot with a 2x2 layout
fig, axs = plt.subplots(2, 2, figsize=(18, 16))
fig.suptitle("Network Topology, Dijkstra's Algorithm Steps, and Distance Vector Tables", fontweight='bold')

# Draw the network graph (Top Left)
nx.draw(G, pos, with_labels=True, ax=axs[0, 0], node_size=700, font_size=14, font_weight='bold')
edge_labels = nx.get_edge_attributes(G, 'weight')
nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels, font_size=12, ax=axs[0, 0])
axs[0, 0].set_title("Network Topology Graph", fontweight='bold')

# Display the Dijkstra's Algorithm table (Top Right)
axs[0, 1].axis('off')
table1 = axs[0, 1].table(cellText=dijkstra_df.values, colLabels=dijkstra_df.columns, cellLoc='center', loc='center')
table1.auto_set_font_size(False)
table1.set_fontsize(8)
table1.auto_set_column_width(col=list(range(len(dijkstra_df.columns))))
axs[0, 1].set_title("Dijkstra's Algorithm Steps", fontweight='bold')

# Display the Distance Vector table for all routers at t=0 (Bottom Left)
axs[1, 0].axis('off')
table2 = axs[1, 0].table(cellText=dv_table_t0.values, colLabels=dv_table_t0.columns, rowLabels=dv_table_t0.index, cellLoc='center', loc='center')
table2.auto_set_font_size(False)
table2.set_fontsize(8)
table2.auto_set_column_width(col=list(range(len(dv_table_t0.columns))))
axs[1, 0].set_title("Distance Vectors for All Routers at t=0", fontweight='bold')

# Display the Distance Vector table for router 'd' at t=1 (Bottom Right)
axs[1, 1].axis('off')
table3 = axs[1, 1].table(cellText=dv_table_d_t1.values, colLabels=dv_table_d_t1.columns, rowLabels=dv_table_d_t1.index, cellLoc='center', loc='center')
table3.auto_set_font_size(False)
table3.set_fontsize(8)
table3.auto_set_column_width(col=list(range(len(dv_table_d_t1.columns))))
axs[1, 1].set_title("Distance Vector for Router d at t=1", fontweight='bold')

plt.tight_layout(rect=[0, 0, 1, 0.95])  # Adjust layout to make room for the main title
plt.show()
