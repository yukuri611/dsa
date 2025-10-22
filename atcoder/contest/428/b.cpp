#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    map<string, int> Map;
    rep(i, N - K + 1) {
        string s = S.substr(i, K);
        Map[s]++;
    }

    int maximum = 0;
    for (auto [s, c] : Map) {
        maximum = max(maximum, c);
    }

    cout << maximum << endl;
    for (auto [s, c] : Map) {
        if (c == maximum) cout << s << " ";
    }
    cout << endl;
    return 0;
}
