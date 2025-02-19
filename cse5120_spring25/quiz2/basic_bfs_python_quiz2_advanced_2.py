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

def plot_graph_state(graph, queue, transitions=None, pause_time=1):
    """
    Draw the graph.
    transitions: a dict mapping node -> color override.
      This is used to temporarily show:
        - green for an item about to be enqueued (transitioning)
        - red for an item being dequeued.
    Default colors:
      - if in transitions, its color is from the dict
      - if in queue, yellow
      - otherwise, lightblue
    """
    if transitions is None:
        transitions = {}
    G = nx.DiGraph()
    # Add all nodes so even ones with no edges are included.
    G.add_nodes_from(pos.keys())
    for node, neighbors in graph.items():
        for neighbor in neighbors:
            G.add_edge(node, neighbor)
    
    node_colors = []
    for node in pos.keys():
        if node in transitions:
            node_colors.append(transitions[node])
        elif node in queue:
            node_colors.append("yellow")
        else:
            node_colors.append("lightblue")
    
    plt.clf()
    nx.draw(G, pos, with_labels=True, node_color=node_colors, edge_color="red",
            node_size=2000, font_size=12, font_weight="bold", arrows=True)
    
    title = "BFS Step-by-Step Visualization"
    if transitions.get("current"):
        title += f" (Processing: {transitions['current']})"
    plt.title(title)
    plt.draw()
    plt.pause(pause_time)

def bfs(graph, start, goal):
    expansion_order = []
    queue = deque([start])
    print(f"Starting BFS from {start} to reach {goal}...\n")
    
    # Initial visualization: show start node in queue (yellow).
    plot_graph_state(graph, list(queue))
    
    while queue:
        node = queue.popleft()
        expansion_order.append(node)
        transitions = {node: "red", "current": node}
        # Show dequeued node as red.
        plot_graph_state(graph, list(queue) + [node], transitions=transitions)
        print(f"Dequeued: {node}")
        
        # Update visualization without the node.
        plot_graph_state(graph, list(queue))
        
        if node == goal:
            print(f"Goal {goal} reached!\n")
            break
        
        for neighbor in graph[node]:
            queue.append(neighbor)
            transitions = {neighbor: "green"}
            # Show neighbor being enqueued.
            plot_graph_state(graph, list(queue), transitions=transitions)
            # Finalize neighbor visualization.
            plot_graph_state(graph, list(queue))
            print(f"Enqueued: {neighbor}")
            print(f"Current Queue: {list(queue)}\n")
    
    print("Final Expansion Order:", expansion_order)
    return expansion_order

bfs(graph, 'A', 'E')

plt.ioff()

def close_plots():
    plt.close('all')
    print("Plot window closed due to timer.")

# Start a timer that will close the plot window after 10 seconds
timer = threading.Timer(10.0, close_plots)
timer.start()

plt.show()
