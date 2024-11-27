import matplotlib.pyplot as plt

def draw_arrow_diagram(domain, codomain, mapping, title):
    plt.figure(figsize=(6, 4))
    
    # Domain points
    for i, x in enumerate(domain):
        plt.scatter(0, len(domain)-i, color='blue', s=50, label='Domain' if i == 0 else "")
        plt.text(-0.2, len(domain)-i, str(x), fontsize=12, ha='center')
    
    # Codomain points
    for i, y in enumerate(codomain):
        plt.scatter(1, len(codomain)-i, color='orange', s=50, label='Codomain' if i == 0 else "")
        plt.text(1.2, len(codomain)-i, str(y), fontsize=12, ha='center')
    
    # Arrows for mappings
    for i, x in enumerate(domain):
        plt.arrow(0, len(domain)-i, 0.8, len(codomain)-codomain.index(mapping[x])-len(domain)+i,
                  head_width=0.1, head_length=0.05, fc='black', ec='black')
    
    plt.axis('off')
    plt.title(title, fontsize=14)
    plt.show()

# Example data for injective, surjective, bijective mappings
domain = [1, 2, 3]
injective_codomain = ['a', 'b', 'c']
injective_mapping = {1: 'a', 2: 'b', 3: 'c'}

surjective_codomain = ['a', 'b', 'c']
surjective_mapping = {1: 'a', 2: 'b', 3: 'b'}

bijective_codomain = ['x', 'y', 'z']
bijective_mapping = {1: 'x', 2: 'y', 3: 'z'}

# Plot diagrams
draw_arrow_diagram(domain, injective_codomain, injective_mapping, "Injective (One-to-One)")
draw_arrow_diagram(domain, surjective_codomain, surjective_mapping, "Surjective (Onto)")
draw_arrow_diagram(domain, bijective_codomain, bijective_mapping, "Bijective (One-to-One and Onto)")
