# Re-importing matplotlib and starting fresh
import matplotlib.pyplot as plt

def plot_aligned_diagrams():
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

    # Define sets A and B for each case
    injective_A = [1, 2, 3, 4]  # Injective: 4 As
    injective_B = [1, 2, 3, 4, 5]  # Injective: 5 Bs

    surjective_A = [1, 2, 3, 4, 5]  # Surjective: 5 As
    surjective_B = [1, 2, 3, 4]  # Surjective: 4 Bs

    bijective_A = [1, 2, 3, 4, 5]  # Bijective: 5 As
    bijective_B = [1, 2, 3, 4, 5]  # Bijective: 5 Bs

    # Define mappings for each case
    injective_mapping = {1: 1, 2: 2, 3: 3, 4: 4}  # Injective: Top-aligned
    surjective_mapping = {1: 1, 2: 2, 3: 3, 4: 3, 5: 4}  # Surjective: All Bs covered, 3 is reused
    bijective_mapping = {1: 1, 2: 2, 3: 3, 4: 4, 5: 5}  # Bijective: One-to-one, top-aligned

    # Plot each case
    draw_mappings(axs[0], injective_A, injective_B, injective_mapping, "Injective (4 A's, 5 B's, Top Aligned)")
    draw_mappings(axs[1], surjective_A, surjective_B, surjective_mapping, "Surjective (5 A's, 4 B's, Top Aligned)")
    draw_mappings(axs[2], bijective_A, bijective_B, bijective_mapping, "Bijective (5 A's, 5 B's, Top Aligned)")

    plt.tight_layout()
    plt.show()

# Run the function to display diagrams
plot_aligned_diagrams()
