#include <bits/stdc++.h>
using namespace std;

/**
 * @struct DSU
 * @brief Implementa la estructura de datos Disjoint Set Union (Union-Find).
 * * Esta estructura mantiene una colección de conjuntos disjuntos y
 * proporciona operaciones eficientes para fusionar (unite) conjuntos y
 * encontrar (find) el representante de un conjunto.
 */
struct DSU {
    vector<int> parent; // parent[i] = padre del elemento i
    vector<int> sz;     // sz[i] = tamaño del componente con raíz i
    int num_components;
    int max_component_size;

    // Constructor: Inicializa n elementos, cada uno en su propio conjunto.
    DSU(int n) {
        num_components = n;
        max_component_size = 1;

        // Redimensionamos a n+1 para usar índices 1-based (ciudades 1 a n)
        parent.resize(n + 1);
        sz.resize(n + 1, 1); // Cada componente empieza con tamaño 1

        // Inicialmente, cada elemento es su propio padre
        // std::iota(parent.begin(), parent.end(), 0); // Alternativa para 0-based
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }

    /**
     * @brief Encuentra el representante (raíz) del conjunto al que pertenece i.
     * * Utiliza la optimización de "compresión de caminos": hace que todos los
     * nodos en el camino de i a la raíz apunten directamente a la raíz.
     */
    int find(int i) {
        if (parent[i] == i)
            return i;
        // Compresión de camino
        return parent[i] = find(parent[i]);
    }

    /**
     * @brief Fusiona los conjuntos que contienen a los elementos i y j.
     * * Utiliza la optimización de "unión por tamaño": el conjunto más pequeño
     * se une al más grande para mantener el árbol lo más plano posible.
     */
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);

        if (root_i != root_j) {
            // No están en el mismo componente, así que los fusionamos
            num_components--;

            // Unión por tamaño
            if (sz[root_i] < sz[root_j]) {
                swap(root_i, root_j); // Aseguramos que root_i es el más grande
            }

            parent[root_j] = root_i; // Unimos el más pequeño (j) al más grande (i)
            sz[root_i] += sz[root_j]; // Actualizamos el tamaño del nuevo componente

            // Actualizamos el tamaño máximo global
            max_component_size = max(max_component_size, sz[root_i]);
        }
        // Si root_i == root_j, ya están unidos, no hacemos nada.
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    DSU dsu(n);

    for (int k = 0; k < m; ++k) {
        int u, v;
        cin >> u >> v;

        // Procesamos la nueva carretera
        dsu.unite(u, v);

        // Imprimimos el estado actual
        cout << dsu.num_components << " " << dsu.max_component_size << "\n";
    }

    return 0;
}