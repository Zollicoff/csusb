import matplotlib.pyplot as plt

def plot_injective_surjective_bijective():
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
        for a, bs in mappings.items():
            for b in bs:
                ax.arrow(0, len(A) - A.index(a), 0.8, len(B) - B.index(b) - len(A) + A.index(a),
                         head_width=0.2, head_length=0.05, fc='black', ec='black')
        ax.axis('off')
        ax.set_title(title, fontsize=14)

    # Define A, B, and mappings for each case
    A = [1, 2, 3]
    B = ['a', 'b', 'c', 'd']

    # Injective (Not Surjective)
    injective_mapping = {1: ['a'], 2: ['b'], 3: ['c']}  # 'd' is not covered
    draw_arrows(axs[0], A, B, injective_mapping, "Injective (not surjective)")

    # Surjective (Not Injective)
    surjective_mapping = {1: ['a'], 2: ['b'], 3: ['b']}  # 'a', 'b', and 'c' are hit, but overlap exists
    draw_arrows(axs[1], A, B, surjective_mapping, "Surjective (not injective)")

    # Bijective (Injective and Surjective)
    bijective_mapping = {1: ['a'], 2: ['b'], 3: ['c']}  # Perfect one-to-one
    draw_arrows(axs[2], A, B[:3], bijective_mapping, "Bijective (injective, surjective)")

    plt.tight_layout()
    plt.show()

# Call the function to create the plots
plot_injective_surjective_bijective()
