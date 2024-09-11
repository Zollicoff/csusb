# Zachary Hampton 008339494 09-08-2024
# This program creates a network graph of a hypothetical computer network at California State University, San Bernardino (CSUSB).
# The network consists of four departments: Computer Science, Electrical Engineering, Physics, and Mathematics.
# Each department has five computers connected to a departmental network, and each department's network is connected to the university's router.
# The university's router is connected to AT&T's router, which is connected to the Internet modem.
# Additionally, there are inter-departmental connections between the computers of different departments.
# The graph is visualized using NetworkX and Matplotlib libraries in Python.

import matplotlib.pyplot as plt
import networkx as nx
import scipy as sp

# Initialize the graph
G = nx.Graph()

# Define nodes for departments, switches, and computers
departments = {
    "Computer Science": ["CS1", "CS2", "CS3", "CS4", "CS5"],
    "Electrical Engineering": ["EE1", "EE2", "EE3", "EE4", "EE5"],
    "Physics": ["PH1", "PH2", "PH3", "PH4", "PH5"],
    "Mathematics": ["MA1", "MA2", "MA3", "MA4", "MA5"]
}

# Add switches for each department
switches = {
    "Computer Science Switch": departments["Computer Science"],
    "Electrical Engineering Switch": departments["Electrical Engineering"],
    "Physics Switch": departments["Physics"],
    "Mathematics Switch": departments["Mathematics"]
}

# Add routers and internet modem
routers = ["University Router", "AT&T Router", "Internet Modem"]

# Add department switches and connect them to their respective computers
for switch, computers in switches.items():
    G.add_node(switch)  # Add switch node
    for computer in computers:
        G.add_node(computer)  # Add computer node
        G.add_edge(switch, computer)  # Connect switch to each computer

# Add routers and internet modem nodes
for router in routers:
    G.add_node(router)

# Connect each department switch to the University Router
for switch in switches.keys():
    G.add_edge(switch, "University Router")

# Connect the University Router to AT&T Router and the AT&T Router to the Internet Modem
G.add_edge("University Router", "AT&T Router")
G.add_edge("AT&T Router", "Internet Modem")

# Define positions using a spring layout for better visualization
pos = nx.spring_layout(G, seed=42)

# Draw the graph with the new layout
plt.figure(figsize=(14, 10))
nx.draw_networkx_nodes(G, pos, node_color='skyblue', node_size=500, alpha=0.8)
nx.draw_networkx_edges(G, pos, width=1.0, alpha=0.6)
nx.draw_networkx_labels(G, pos, font_size=10, font_family="sans-serif")
plt.title("CSUSB Network for CS, EE, PHYS, MATH using Python (Zachary A. Hampton 008339494)")
plt.axis('off')

plt.show()
