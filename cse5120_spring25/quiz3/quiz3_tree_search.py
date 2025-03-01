import networkx as nx
import matplotlib.pyplot as plt
import heapq  # For priority queue
import threading  # added for timer

plt.ion()

# Graph with weighted edges (city connections with distances)
graph = {
    'A': [('B', 3), ('C', 3), ('D', 7)],
    'B': [('C', 3)],
    'C': [],
    'D': [('E', 1)],
    'E': []
}

# Node positions for visualization
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
    
    # Add weighted edges
    for node, neighbors in graph.items():
        for neighbor_info in neighbors:
            neighbor, weight = neighbor_info
            G.add_edge(node, neighbor, weight=weight)
    
    # Determine colors for nodes.
    node_colors = []
    for node in pos.keys():
        if node in transitions:
            node_colors.append(transitions[node])
        elif node in [n for _, n, _ in queue]:
            node_colors.append("yellow")
        else:
            node_colors.append("lightblue")
    
    ax_graph.clear()
    nx.draw(G, pos, with_labels=True, node_color=node_colors, edge_color="red",
            node_size=2000, font_size=12, font_weight="bold", arrows=True, ax=ax_graph)
    
    # Draw edge labels (weights)
    edge_labels = {(u, v): d['weight'] for u, v, d in G.edges(data=True)}
    nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels)
    
    # Set a constant title.
    ax_graph.set_title("UCS Tree Search Visualization (NO check on repeated states)")
    
    # Prepare the text info in the right panel.
    ax_text.clear()
    ax_text.axis("off")
    ax_text.text(0.05, 0.8, info, fontsize=12, fontfamily="monospace")
    plt.draw()
    plt.pause(pause_time)

def ucs_tree_search(graph, start, goal):
    expansion_order = []
    # Priority queue entries are (cumulative_cost, node, [path])
    priority_queue = [(0, start, [])]
    heapq.heapify(priority_queue)
    
    info = f"Starting UCS Tree Search from {start} to reach {goal}...\nNO check on repeated states - can visit same city multiple times."
    plot_graph_state(graph, priority_queue, info=info)
    print(info)
    
    while priority_queue:
        # Get node with lowest cumulative cost
        cost, node, path = heapq.heappop(priority_queue)
        path = path + [node]
        
        # Goal test when node is expanded (popped from queue)
        if node == goal:
            expansion_order.append(node)
            info = f"Expanded: {node} (GOAL!)\nCost: {cost}"
            transitions = {node: "green"}
            plot_graph_state(graph, priority_queue, transitions=transitions, info=info)
            print(info)
            
            final_info = f"Goal {goal} reached!\nFinal path: {' -> '.join(path)}\nTotal cost: {cost}"
            plot_graph_state(graph, priority_queue, info=final_info)
            print(final_info)
            return expansion_order
        
        # Expand the node - NO check for repeated states as per quiz requirements
        expansion_order.append(node)
        info = f"Expanded: {node}\nCost so far: {cost}\nCurrent path: {' -> '.join(path)}"
        transitions = {node: "red"}
        plot_graph_state(graph, priority_queue, transitions=transitions, info=info)
        print(info)
        
        # Add neighbors to the priority queue - NO check for repeated states
        for neighbor, edge_cost in graph[node]:
            new_cost = cost + edge_cost
            new_path = path.copy()
            
            # Enqueue the neighbor with the cumulative cost
            heapq.heappush(priority_queue, (new_cost, neighbor, new_path))
            info = f"Enqueued: {neighbor} with cost {new_cost}"
            transitions = {neighbor: "orange"}
            plot_graph_state(graph, priority_queue, transitions=transitions, info=info)
            print(info)
        
        # Display current queue state
        queue_info = f"Current Priority Queue: {[(c, n) for c, n, _ in priority_queue]}"
        plot_graph_state(graph, priority_queue, info=queue_info)
        print(queue_info)
    
    # If no path is found
    final_info = f"No path found to goal {goal}.\nFinal Expansion Order: {expansion_order}"
    plot_graph_state(graph, priority_queue, info=final_info)
    print(final_info)
    return expansion_order

# Run UCS and capture the expansion order
print("\nRunning Uniform-Cost Search (UCS) Tree Search from A to E:")
order = ucs_tree_search(graph, 'A', 'E')

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