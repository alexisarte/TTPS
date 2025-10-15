#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string word, substring;
    int caracteres_sustituidos;
    string vowels = "aoyeui";

    cin >> word;
    string part_first, part_second;
    
    // transformar a minuscula
    transform(word.begin(), word.end(), word.begin(), [](unsigned char c){ return tolower(c); });

    for (int i = 0; i < word.length(); i++) {
        if (vowels.find(word.at(i)) == string::npos) {
            word.insert(i, ".");
            i++;
        } else {
            part_first = "";
            part_second = "";

            // si estoy en la primera posición, no hay primera parte
            if (i != 0) {
                part_first = word.substr(0, i);
            }
            // si estoy en la última posición, no hay segunda parte
            if ((word.length() - 1) > i) {
                part_second = word.substr(i + 1, word.length());
            }
            word = part_first + part_second;
            i--;
        }
    }

    cout << word;
    
    return 0;
}