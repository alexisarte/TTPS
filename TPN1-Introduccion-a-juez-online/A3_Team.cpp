#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int problemsToSolve = 0;

    for (int i = 0; i < n; i++) {
        int sureCount = 0;
        int opinion;

        for (int j = 0; j < 3; j++) {
            cin >> opinion;
            if (opinion == 1)
                sureCount++;
        }

        if (sureCount >= 2)
            problemsToSolve++;
    }

    cout << problemsToSolve;
    return 0;
}
