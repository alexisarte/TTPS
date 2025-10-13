#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    std::cin >> n;

    long long MOD = 1e9 + 7;

    // dp[i] guardará el número de formas de sumar i
    std::vector<long long> dp(n + 1, 0);

    // Caso base: hay 1 forma de obtener la suma 0 (no tirar el dado), sirve para nuevos casos
    dp[0] = 1;

    // Iteramos desde 1 hasta n para calcular todas las combinaciones
    for (int i = 1; i <= n; ++i) {
        // Para cada suma i, consideramos el último lanzamiento posible (de 1 a 6)
        // Las formas de sumarle j a cada conbinación que necesita j para ser igual a n 
        for (int j = 1; j <= 6; ++j) {
            // Si la suma actual 'i' es mayor o igual que el valor del dado 'j', esto es la limitación del dado
            if (i - j >= 0) {
                // Sumamos las formas de obtener la suma (i - j)
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }
    }

    cout << dp[n];

    return 0;
}
