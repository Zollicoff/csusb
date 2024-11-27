import matplotlib.pyplot as plt

domain = [1, 2, 3] # Domain of the function

def draw_all_arrow_diagrams_fixed():
    fig, axs = plt.subplots(1, 3, figsize=(18, 6))

    # Function to draw an arrow diagram on a given subplot
    def draw_diagram(ax, domain, codomain, mapping, title):
        # Plot domain points
        for i, x in enumerate(domain):
            ax.scatter(0, len(domain) - i, color='blue', s=50)
            ax.text(-0.2, len(domain) - i, str(x), fontsize=12, ha='center')
        
        # Plot codomain points
        for i, y in enumerate(codomain):
            ax.scatter(1, len(codomain) - i, color='orange', s=50)
            ax.text(1.2, len(codomain) - i, str(y), fontsize=12, ha='center')
        
        # Draw arrows for mappings
        for i, x in enumerate(domain):
            output_index = len(codomain) - codomain.index(mapping[x]) - len(domain) + i
            ax.arrow(0, len(domain) - i, 0.8, output_index,
                     head_width=0.1, head_length=0.05, fc='black', ec='black')
        
        ax.axis('off')
        ax.set_title(title, fontsize=14)

    # Injective example
    injective_codomain = ['a', 'b', 'c']
    injective_mapping = {1: 'a', 2: 'b', 3: 'c'}
    draw_diagram(axs[0], domain, injective_codomain, injective_mapping, "Injective (One-to-One)")

    # Surjective example
    surjective_codomain = ['a', 'b', 'c']
    surjective_mapping = {1: 'a', 2: 'b', 3: 'b'}
    draw_diagram(axs[1], domain, surjective_codomain, surjective_mapping, "Surjective (Onto)")

    # Bijective example
    bijective_codomain = ['x', 'y', 'z']
    bijective_mapping = {1: 'x', 2: 'y', 3: 'z'}
    draw_diagram(axs[2], domain, bijective_codomain, bijective_mapping, "Bijective (One-to-One and Onto)")

    plt.tight_layout()
    plt.show()

# Replot with fixes
draw_all_arrow_diagrams_fixed()
