# Zachary Hampton 008339494 09-08-2024
# This program creates a network graph of a hypothetical computer network at California State University, San Bernardino (CSUSB).
# The network consists of four departments: Computer Science, Electrical Engineering, Physics, and Mathematics.
# Each department has five computers connected to a departmental network, and each department's network is connected to the university's router.
# The university's router is connected to AT&T's router, which is connected to the Internet modem.
# Additionally, there are inter-departmental connections between the computers of different departments.
# The graph is visualized using NetworkX and Matplotlib libraries in Python.

import matplotlib.pyplot as plt
import networkx as nx

# Initialize the graph
G = nx.Graph()

# Define nodes for departments and computers within each department
departments = {
    "Computer Science": ["CS1", "CS2", "CS3", "CS4", "CS5"],
    "Electrical Engineering": ["EE1", "EE2", "EE3", "EE4", "EE5"],
    "Physics": ["PH1", "PH2", "PH3", "PH4", "PH5"],
    "Mathematics": ["MA1", "MA2", "MA3", "MA4", "MA5"]
}

# Add department nodes and internal edges within each department
for department, computers in departments.items():
    # Add nodes for each computer
    for computer in computers:
        G.add_node(computer, group=department)
    # Connect each computer within the department to each other
    for i in range(len(computers)):
        for j in range(i + 1, len(computers)):
            G.add_edge(computers[i], computers[j])

# Add routers and internet nodes
routers = ["University Router", "AT&T Router", "Internet Modem"]
for router in routers:
    G.add_node(router)

# Connect each department's network to the University Router
for department, computers in departments.items():
    G.add_edge(computers[0], "University Router")  # Connect one representative computer from each department to the university router

# Connect the University Router to AT&T Router and the AT&T Router to the Internet Modem
G.add_edge("University Router", "AT&T Router")
G.add_edge("AT&T Router", "Internet Modem")

# Connect departments' networks to each other
for dep1, computers1 in departments.items():
    for dep2, computers2 in departments.items():
        if dep1 != dep2:
            G.add_edge(computers1[0], computers2[0])  # Inter-departmental connections

# Use a planar layout (Kamada-Kawai) for a cleaner and more organized structure
pos = nx.kamada_kawai_layout(G)

# Draw the graph with the Kamada-Kawai layout and updated title
plt.figure(figsize=(14, 10))
nx.draw_networkx_nodes(G, pos, node_color='skyblue', node_size=500, alpha=0.8)
nx.draw_networkx_edges(G, pos, width=1.0, alpha=0.6)
nx.draw_networkx_labels(G, pos, font_size=10, font_family="sans-serif")
plt.title("CSUSB Network for CS, EE, PHYS, MATH")
plt.axis('off')

plt.show()
