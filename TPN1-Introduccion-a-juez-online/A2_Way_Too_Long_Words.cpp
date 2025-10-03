#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    vector<string> words;
    string word, substring;
    int caracteres_sustituidos;

    for (int i = 0; i < n; i++) {
        cin >> word;
        words.push_back(word);
    }

    for (int i = 0; i < n; i++) {
        if (words[i].length() > 10) {
            substring = words[i].substr(1, words[i].length() - 2);
            caracteres_sustituidos = substring.length();
            cout << words[i].at(0) + to_string(caracteres_sustituidos) + words[i].at(words[i].length() - 1)  << "\n";
        }
        else {
            cout << words[i] << "\n";
        }
    }
    
    return 0;
}