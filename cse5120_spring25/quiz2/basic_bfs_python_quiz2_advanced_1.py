import networkx as nx
import matplotlib.pyplot as plt
from collections import deque

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

def plot_graph_state(graph, queue, current=None):
    """
    Draw the graph and highlight:
    - queued nodes in yellow,
    - the current processing node in green.
    All other nodes are colored lightblue.
    """
    G = nx.DiGraph()
    # Add all nodes, even if they have no outgoing/incoming edges.
    G.add_nodes_from(pos.keys())
    for node, neighbors in graph.items():
        for neighbor in neighbors:
            G.add_edge(node, neighbor)
    
    node_colors = []
    for node in pos.keys():
        if node == current:
            node_colors.append("green")
        elif node in queue:
            node_colors.append("yellow")
        else:
            node_colors.append("lightblue")
    
    plt.clf()
    nx.draw(G, pos, with_labels=True, node_color=node_colors, edge_color="red",
            node_size=2000, font_size=12, font_weight="bold", arrows=True)
    
    title = "BFS Step-by-Step Visualization"
    if current is not None:
        title += f" (Processing: {current})"
    plt.title(title)
    plt.draw()
    plt.pause(1)

def bfs(graph, start, goal):
    queue = deque([start])
    print(f"Starting BFS from {start} to reach {goal}...\n")
    
    # Initial visualization with just the start node in the queue.
    plot_graph_state(graph, list(queue))
    
    while queue:
        # Dequeue the next node and highlight it as current.
        node = queue.popleft()
        plot_graph_state(graph, list(queue), current=node)
        print(f"Dequeued: {node}")
        
        # Clear the current highlight (only the queue remains highlighted).
        plot_graph_state(graph, list(queue))
        
        if node == goal:
            print(f"Goal {goal} reached!\n")
            break
        
        # Enqueue each neighbor one by one and update visualization.
        for neighbor in graph[node]:
            queue.append(neighbor)
            print(f"Enqueued: {neighbor}")
            plot_graph_state(graph, list(queue))
            print(f"Current Queue: {list(queue)}\n")
    
    return list(queue)

bfs(graph, 'A', 'E')

plt.ioff()
plt.show()