#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> scores(n);

    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }
    
    int advancersCount = 0;
    int threshold_score = scores[k-1];

    for (int i = 0; i < n; i++) {
        if (scores[i] > 0 && scores[i] >= threshold_score)
            advancersCount++;
    }

    cout << advancersCount;
    
    return 0;
}