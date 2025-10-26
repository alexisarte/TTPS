#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int v) {
    visited[v] = true;
    for (int w : adj[v]) {
        if (!visited[w])
        dfs(w);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    adj.resize(n + 1);
    visited.resize(n + 1, false);
    
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    
    // Vector para guardar la primera ciudad que encontramos de cada componente
    vector<int> representatives;

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            representatives.push_back(i);
            dfs(i);
        }
    }

    // El número de carreteras nuevas es el número de componentes - 1
    int k = representatives.size() - 1;

    cout << k << "\n";

    for (int i = 0; i < k; ++i) {
        cout << representatives[i] << " " << representatives[i + 1] << "\n";
    }

    return 0;
}