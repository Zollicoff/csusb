import networkx as nx
import matplotlib.pyplot as plt
from collections import deque
import threading  # added for timer

plt.ion()

graph = {
    'A': ['B', 'C', 'D'],
    'B': ['C'],
    'C': [],
    'D': ['E'],
    'E': []
}

pos = {
    'A': (2, 3),  # Top row (center)
    'E': (4, 3),  # Top row (aligned with A but to the right)
    'B': (1, 1),  # Second row (left)
    'C': (2, 1),  # Second row (center)
    'D': (3, 1),  # Second row (right)
}

def plot_graph_state(graph, queue, transitions=None, pause_time=1, info=""):
    """
    Draw the graph alongside a text panel.
    transitions: dict mapping node -> color override.
    The text panel (right side) shows info matching console output.
    """
    if transitions is None:
        transitions = {}
    
    # Set figure size to be wider.
    plt.gcf().set_size_inches(16, 6)
    plt.clf()
    
    # Create two subplots; left for graph, right for text info.
    ax_graph = plt.subplot(1, 2, 1)
    ax_text = plt.subplot(1, 2, 2)
    
    # Build the network graph.
    G = nx.DiGraph()
    G.add_nodes_from(pos.keys())
    for node, neighbors in graph.items():
        for neighbor in neighbors:
            G.add_edge(node, neighbor)
    
    # Determine colors for nodes.
    node_colors = []
    for node in pos.keys():
        if node in transitions:
            node_colors.append(transitions[node])
        elif node in queue:
            node_colors.append("yellow")
        else:
            node_colors.append("lightblue")
    
    ax_graph.clear()
    nx.draw(G, pos, with_labels=True, node_color=node_colors, edge_color="red",
            node_size=2000, font_size=12, font_weight="bold", arrows=True, ax=ax_graph)
    
    # Set a constant title.
    ax_graph.set_title("BFS Tree Search Visualization (NO check on repeated states)")
    
    # Prepare the text info in the right panel.
    ax_text.clear()
    ax_text.axis("off")
    ax_text.text(0.05, 0.8, info, fontsize=12, fontfamily="monospace")
    plt.draw()
    plt.pause(pause_time)

def bfs_tree_search(graph, start, goal):
    expansion_order = []
    queue = deque([start])
    
    info = f"Starting BFS Tree Search from {start} to reach {goal}...\nNO check on repeated states - can visit same city multiple times.\nChecking for goal when nodes are ADDED to queue."
    plot_graph_state(graph, list(queue), info=info)
    print(info)
    
    # Check if start is the goal
    if start == goal:
        info = f"Start node {start} is the goal!"
        plot_graph_state(graph, list(queue), info=info)
        print(info)
        return [start]
    
    while queue:
        node = queue.popleft()
        expansion_order.append(node)
        info = f"Dequeued: {node}"
        transitions = {node: "red"}
        plot_graph_state(graph, list(queue) + [node], transitions=transitions, info=info)
        print(info)
        plot_graph_state(graph, list(queue), info=info)
        
        for neighbor in graph[node]:
            # Check for goal when node is added to queue (not when expanded)
            if neighbor == goal:
                queue.append(neighbor)
                info = f"Enqueued: {neighbor} (Goal found!)\nCurrent Queue: {list(queue)}"
                transitions = {neighbor: "green"}
                plot_graph_state(graph, list(queue), transitions=transitions, info=info)
                print(info)
                
                # Goal is reached when we add it to queue, so stop adding more nodes
                # Expansion order stops here - we don't expand the goal
                return expansion_order
            
            # Add neighbor to queue - NO check for repeated states
            queue.append(neighbor)
            info = f"Enqueued: {neighbor}\nCurrent Queue: {list(queue)}"
            transitions = {neighbor: "orange"}
            plot_graph_state(graph, list(queue), transitions=transitions, info=info)
            print(info)
            plot_graph_state(graph, list(queue), info=info)
    
    final_info = f"No path found to goal {goal}.\nFinal Expansion Order: {expansion_order}"
    plot_graph_state(graph, list(queue), info=final_info)
    print(final_info)
    return expansion_order

# Run BFS and capture the expansion order
print("\nRunning Breadth-First Search (BFS) Tree Search from A to E:")
order = bfs_tree_search(graph, 'A', 'E')

# Print the final expansion order
print("\nFinal Expansion Order:", order)

plt.ioff()

def close_plots():
    plt.close('all')
    print("Plot window closed due to timer.")

# Start a timer that will close the plot window after 10 seconds
timer = threading.Timer(10.0, close_plots)
timer.start()

plt.show() 