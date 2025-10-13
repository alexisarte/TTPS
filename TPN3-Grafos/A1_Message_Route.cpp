#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, a, b;
    cin >> n >> m;

    // Usamos n + 1 para poder usar los índices 1 a n directamente
    vector <vector<int>> listaDeAdyacencias(n+1); 

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        // Es una conexión de dos vías (grafo no dirigido)
        listaDeAdyacencias[a].push_back(b);
        listaDeAdyacencias[b].push_back(a);
    }


    // BFS
    queue <int> cola;
    vector<int> parent (n+1, 0);
    vector<bool> visited(n+1, false);
    
    // La primer computadora siempre es la computadora 1
    cola.push(1);
    visited[1] = true;

    while (!cola.empty()) {
        int t = cola.front();
        cola.pop();

        if (t == n) {
            break;
        }

        for (int v : listaDeAdyacencias[t]) {
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = t;
                cola.push(v);
            }
        }

    }


    // CONSTRUIR RESPUESTA
    if (!visited[n]) {
        cout << "IMPOSSIBLE";
    } else {
        // Reconstruimos el camino hacia atrás, desde n hasta 1.
        vector<int> path;
        int curr = n;
        while (curr != 0) {
            path.push_back(curr);
            curr = parent[curr];
        }
        // El camino está al revés, así que lo invertimos.
        reverse(path.begin(), path.end());

        cout << path.size() << "\n";
        for (int i = 0; i < path.size(); ++i) {
            cout << path[i] << (i == path.size() - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}
