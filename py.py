import networkx as nx
import matplotlib.pyplot as plt

# Matrice de transition
P = [
    [0.95, 0.04, 0.01, 0],
    [0, 0.90, 0.05, 0.05],
    [0, 0, 0.80, 0.20],
    [1, 0, 0, 0]
]

# Création du graphe orienté
G = nx.DiGraph()

# Ajout des arcs avec probabilités
for i in range(4):
    for j in range(4):
        if P[i][j] > 0:
            G.add_edge(i+1, j+1, weight=P[i][j])

# Positionnement visuel des nœuds
pos = {
    1: (0, 1),
    2: (1, 1),
    3: (2, 1),
    4: (1, 0)
}

# Dessin des nœuds
nx.draw_networkx_nodes(G, pos, node_color='skyblue', node_size=1800)

# Dessin des arcs
nx.draw_networkx_edges(G, pos, arrowstyle="->", arrowsize=20)

# Labels des nœuds
nx.draw_networkx_labels(G, pos, font_size=12, font_weight='bold')

# Labels des probabilités
edge_labels = {(u, v): f"{d['weight']}" for u, v, d in G.edges(data=True)}
nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels, font_size=10)

plt.title("Graphe de la chaîne de Markov (vieillissement d'une machine)")
plt.axis('off')
plt.show()
