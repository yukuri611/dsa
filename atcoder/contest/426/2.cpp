#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    string S;
    cin >> S;
    map<char, int> Map;
    for (char c : S) {
        Map[c]++;
    }

    for (auto [c, cnt] : Map) {
        if (cnt == 1) {
            cout << c << endl;
        }
    }
    return 0;
}
