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
df_dijkstra = pd.DataFrame(steps)

# Distance Vector Algorithm Initialization at t=0
distance_vectors = {node: {n: np.inf for n in nodes} for node in nodes}
for node in nodes:
    distance_vectors[node][node] = 0  # Distance to itself is 0
    for neighbor, weight in network_topology[node].items():
        distance_vectors[node][neighbor] = weight  # Direct neighbor distances

# Capture DV at t=0 for all nodes
df_dv_t0 = pd.DataFrame(distance_vectors).sort_index(axis=0).sort_index(axis=1)

# Update distance vector for router d at t=1
for neighbor, weight in network_topology['d'].items():
    for node in nodes:
        new_distance = distance_vectors['d'][neighbor] + distance_vectors[neighbor][node]
        if new_distance < distance_vectors['d'][node]:
            distance_vectors['d'][node] = new_distance

# Capture DV for router d at t=1
df_dv_d_t1 = pd.DataFrame(distance_vectors).loc[['d']]

# Plot both graph, Dijkstra table, and Distance Vector tables side by side
fig, axs = plt.subplots(1, 3, figsize=(18, 6))
fig.suptitle("Network Topology, Dijkstra's Algorithm Steps, and Distance Vector Table")

# Draw the graph on the first subplot
nx.draw(G, pos, with_labels=True, ax=axs[0], node_size=700, font_size=14, font_weight='bold')
edge_labels = nx.get_edge_attributes(G, 'weight')
nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels, font_size=12, ax=axs[0])
axs[0].set_title("Network Topology Graph")

# Display the Dijkstra table on the second subplot
axs[1].axis('off')  # Hide axes for the table display
table = axs[1].table(cellText=df_dijkstra.values, colLabels=df_dijkstra.columns, cellLoc='center', loc='center')
table.auto_set_font_size(False)
table.set_fontsize(10)
table.auto_set_column_width(col=list(range(len(df_dijkstra.columns))))
axs[1].set_title("Dijkstra's Algorithm Steps")

# Display the Distance Vector table on the third subplot
# Showing both t=0 for all nodes and t=1 for router d
axs[2].axis('off')
table_dv_t0 = axs[2].table(cellText=df_dv_t0.values, colLabels=df_dv_t0.columns, rowLabels=df_dv_t0.index, cellLoc='center', loc='upper center')
table_dv_t0.auto_set_font_size(False)
table_dv_t0.set_fontsize(10)
table_dv_t0.auto_set_column_width(col=list(range(len(df_dv_t0.columns))))
axs[2].set_title("Distance Vector at t=0 (All Routers)")

# Display router d's distance vector at t=1 below t=0 for clarity
table_dv_d_t1 = axs[2].table(cellText=df_dv_d_t1.values, colLabels=df_dv_d_t1.columns, rowLabels=['d (t=1)'], cellLoc='center', loc='lower center')
table_dv_d_t1.auto_set_font_size(False)
table_dv_d_t1.set_fontsize(10)
table_dv_d_t1.auto_set_column_width(col=list(range(len(df_dv_d_t1.columns))))

plt.show()
