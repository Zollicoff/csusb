import matplotlib.pyplot as plt

def plot_corrected_diagrams():
    fig, axs = plt.subplots(1, 3, figsize=(18, 6))

    # Helper function to draw arrows and points
    def draw_arrows(ax, A, B, mappings, title):
        # Draw points for A and B
        for i, a in enumerate(A):
            ax.scatter(0, len(A) - i, color='blue', s=50)
            ax.text(-0.2, len(A) - i, str(a), fontsize=12, ha='center')
        for j, b in enumerate(B):
            ax.scatter(1, len(B) - j, color='orange', s=50)
            ax.text(1.2, len(B) - j, str(b), fontsize=12, ha='center')
        # Draw arrows
        for a, b in mappings.items():
            ax.arrow(0, len(A) - A.index(a), 0.8, len(B) - B.index(b) - len(A) + A.index(a),
                     head_width=0.2, head_length=0.05, fc='black', ec='black')
        ax.axis('off')
        ax.set_title(title, fontsize=14)

    # Define A, B, and mappings for each case
    A = [1, 2, 3, 4]
    B = [1, 2, 3, 4, 5]

    # Injective
    injective_mapping = {1: 2, 2: 1, 3: 3, 4: 4}  # 5 is unused
    draw_arrows(axs[0], A, B, injective_mapping, "Injective")

    # Surjective
    surjective_mapping = {1: 2, 2: 1, 3: 3, 4: 3}  # 4 and 3 in B are hit, some overlap
    draw_arrows(axs[1], A, B, surjective_mapping, "Surjective")

    # Bijective
    bijective_mapping = {1: 2, 2: 1, 3: 5, 4: 3}  # Perfect one-to-one matching
    draw_arrows(axs[2], A, B, bijective_mapping, "Bijective")

    plt.tight_layout()
    plt.show()

# Call the function to create the plots
plot_corrected_diagrams()
