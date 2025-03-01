import networkx as nx
import matplotlib.pyplot as plt
import heapq  # For priority queue

# Graph with weighted edges (city connections with distances)
graph = {
    'A': [('B', 3), ('C', 3), ('D', 7)],
    'B': [('C', 3)],
    'C': [],
    'D': [('E', 1)],
    'E': []
}

def ucs_tree_search(graph, start, goal):
    expansion_order = []
    # Priority queue entries are (cumulative_cost, node, [path])
    priority_queue = [(0, start, [])]
    heapq.heapify(priority_queue)
    
    print(f"Starting UCS Tree Search from {start} to reach {goal}...")
    print(f"NO check on repeated states - can visit same city multiple times.")
    print(f"Checking for goal when nodes are EXPANDED (removed from queue).\n")
    
    while priority_queue:
        # Get node with lowest cumulative cost
        cost, node, path = heapq.heappop(priority_queue)
        path = path + [node]
        
        print(f"Dequeued: {node} with cost {cost}")
        
        # Goal test when node is expanded (popped from queue)
        if node == goal:
            expansion_order.append(node)
            print(f"Goal {goal} reached!")
            print(f"Final path: {' -> '.join(path)}")
            print(f"Total cost: {cost}")
            return expansion_order
        
        # Expand the node - NO check for repeated states
        expansion_order.append(node)
        print(f"Expanded: {node}, Cost so far: {cost}")
        
        # Add neighbors to the priority queue - NO check for repeated states
        for neighbor, edge_cost in graph[node]:
            new_cost = cost + edge_cost
            heapq.heappush(priority_queue, (new_cost, neighbor, path))
            print(f"Enqueued: {neighbor} with cost {new_cost}")
        
        print(f"Current Priority Queue: {[(c, n) for c, n, _ in priority_queue]}\n")
    
    print("No path found.")
    return expansion_order

# Function to plot the graph with a specific layout
def plot_graph(graph):
    G = nx.DiGraph()  # Create a directed graph
    for node, neighbors in graph.items():
        for neighbor_info in neighbors:
            neighbor, weight = neighbor_info
            G.add_edge(node, neighbor, weight=weight)

    # Custom layout with A and E at the top, B, C, D in the second row
    pos = {
        'A': (2, 3),  # Top row (center)
        'E': (4, 3),  # Top row (aligned with A but to the right)
        'B': (1, 1),  # Second row (left)
        'C': (2, 1),  # Second row (center)
        'D': (3, 1),  # Second row (right)
    }

    plt.figure(figsize=(8, 5))
    nx.draw(G, pos, with_labels=True, node_color="lightblue", edge_color="red",
            node_size=2000, font_size=12, font_weight="bold", arrows=True)
    
    # Draw edge labels (weights)
    edge_labels = {(u, v): d['weight'] for u, v, d in G.edges(data=True)}
    nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels)
    
    plt.title("UCS Tree Search (NO check on repeated states)")
    plt.show()

# Run UCS and capture the expansion order
print("\nRunning Uniform-Cost Search (UCS) Tree Search from A to E:")
order = ucs_tree_search(graph, 'A', 'E')

# Plot the graph with the adjusted layout
plot_graph(graph)

# Print the final expansion order
print("\nFinal Expansion Order:", order) 