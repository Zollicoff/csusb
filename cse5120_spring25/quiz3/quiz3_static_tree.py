import networkx as nx
import matplotlib.pyplot as plt

# Define the tree structure directly
# This represents the search tree created by UCS with no repeated state checking
def create_ucs_search_tree():
    # Create a new directed graph for the tree
    tree = nx.DiGraph()
    
    # Add nodes and edges to represent the UCS search tree
    # The tree structure follows the order of node expansion in UCS
    
    # First level: Root node A
    tree.add_node("A", level=0)
    
    # Second level: A's children (B, C, D)
    tree.add_edge("A", "B", weight=3)
    tree.add_edge("A", "C", weight=3)
    tree.add_edge("A", "D", weight=7)
    
    # Third level: B's and D's children
    tree.add_edge("B", "C_1", weight=3)  # C from B (C_1 to distinguish from direct C)
    tree.add_edge("D", "E", weight=1)    # E from D
    
    # Assign levels to all nodes for positioning
    for node in ["B", "C", "D"]:
        tree.nodes[node]["level"] = 1
    for node in ["C_1", "E"]:
        tree.nodes[node]["level"] = 2
    
    return tree

def plot_static_search_tree():
    # Create the tree
    tree = create_ucs_search_tree()
    
    # Set up figure
    plt.figure(figsize=(10, 8))
    
    # Create a hierarchical layout
    pos = {
        "A": (0, 0),       # Root
        "B": (-3, -2),     # First level, left
        "C": (0, -2),      # First level, middle
        "D": (3, -2),      # First level, right
        "C_1": (-3, -4),   # Second level, under B
        "E": (3, -4)       # Second level, under D
    }
    
    # Node colors
    node_colors = {
        "A": "lightblue",
        "B": "lightblue", 
        "C": "lightblue",
        "D": "lightblue",
        "C_1": "lightblue",
        "E": "yellow"      # Goal node
    }
    
    # Draw the tree
    nx.draw(tree, pos, 
            with_labels=True,
            node_color=[node_colors[node] for node in tree.nodes()],
            node_size=2000, 
            font_size=12,
            font_weight="bold",
            arrows=True)
    
    # Add edge labels (weights)
    edge_labels = {(u, v): f"cost: {d['weight']}" for u, v, d in tree.edges(data=True)}
    nx.draw_networkx_edge_labels(tree, pos, edge_labels=edge_labels, font_size=10)
    
    # Add expansion order
    # For UCS with these weights, the expansion order would be: A, B, C, C_1, D, E
    expansion_order = ["A", "B", "C", "C_1", "D", "E"]
    for i, node in enumerate(expansion_order):
        if node == "C_1":
            node_label = "C"  # Display as C in the node but track as C_1 internally
        else:
            node_label = node
        plt.annotate(f"{i+1}", 
                    xy=pos[node], 
                    xytext=(-20, -20),
                    textcoords="offset points",
                    bbox=dict(boxstyle="circle,pad=0.3", fc="white", ec="black"),
                    fontsize=10)
    
    plt.title("UCS Search Tree with Expansion Order (1-6)", fontsize=14)
    plt.axis("off")
    plt.tight_layout()
    
    # Add a legend explaining the numbers
    plt.figtext(0.5, 0.01, "Numbers indicate the expansion order of nodes in UCS", 
                ha="center", fontsize=12)
    
    plt.savefig("ucs_search_tree.png", dpi=300, bbox_inches="tight")
    plt.show()

# Generate and show the static search tree
plot_static_search_tree()

# Also show the original problem graph for reference
def plot_original_graph():
    # Define the original graph
    graph = {
        'A': [('B', 3), ('C', 3), ('D', 7)],
        'B': [('C', 3)],
        'C': [],
        'D': [('E', 1)],
        'E': []
    }
    
    G = nx.DiGraph()
    for node, neighbors in graph.items():
        for neighbor_info in neighbors:
            neighbor, weight = neighbor_info
            G.add_edge(node, neighbor, weight=weight)

    pos = {
        'A': (2, 3),
        'E': (4, 3),
        'B': (1, 1),
        'C': (2, 1),
        'D': (3, 1),
    }

    plt.figure(figsize=(8, 5))
    nx.draw(G, pos, with_labels=True, node_color="lightblue", edge_color="red",
            node_size=2000, font_size=12, font_weight="bold", arrows=True)
    
    edge_labels = {(u, v): d['weight'] for u, v, d in G.edges(data=True)}
    nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels)
    
    plt.title("Original Problem Graph")
    plt.savefig("original_graph.png", dpi=300, bbox_inches="tight")
    plt.show()

plot_original_graph() 