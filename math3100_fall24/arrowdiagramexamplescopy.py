# Re-importing matplotlib and starting fresh
import matplotlib.pyplot as plt

def plot_custom_diagrams():
    fig, axs = plt.subplots(1, 3, figsize=(18, 6))

    # Helper function to draw the mappings
    def draw_mappings(ax, A, B, mappings, title):
        # Draw points for A (left) and B (right)
        for i, a in enumerate(A):
            ax.scatter(0, len(A) - i, color='blue', s=50)
            ax.text(-0.2, len(A) - i, str(a), fontsize=12, ha='center')
        for j, b in enumerate(B):
            ax.scatter(1, len(B) - j, color='orange', s=50)
            ax.text(1.2, len(B) - j, str(b), fontsize=12, ha='center')
        
        # Draw arrows based on the mapping
        for a, b in mappings.items():
            ax.arrow(0, len(A) - A.index(a), 0.8, len(B) - B.index(b) - len(A) + A.index(a),
                     head_width=0.2, head_length=0.1, fc='black', ec='black')
        
        ax.axis('off')
        ax.set_title(title, fontsize=14)

    # Define sets A and B
    A = [1, 2, 3, 4]  # Set A
    B = [1, 2, 3, 4, 5]  # Set B

    # Define mappings for each case
    injective_mapping = {1: 2, 2: 1, 3: 3, 4: 4}  # Injective: 5 in B is unused
    surjective_mapping = {1: 2, 2: 1, 3: 3, 4: 3}  # Surjective: All B values are hit, but 3 is reused
    bijective_mapping = {1: 2, 2: 1, 3: 5, 4: 3}  # Bijective: Perfect one-to-one correspondence

    # Plot each case
    draw_mappings(axs[0], A, B, injective_mapping, "Injective (One-to-One, Not Surjective)")
    draw_mappings(axs[1], A, B, surjective_mapping, "Surjective (Onto, Not Injective)")
    draw_mappings(axs[2], A, B, bijective_mapping, "Bijective (One-to-One and Onto)")

    plt.tight_layout()
    plt.show()

# Run the function to display diagrams
plot_custom_diagrams()
