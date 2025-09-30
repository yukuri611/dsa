#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int main() {
    int N;
    cin >> N;
    set<string> S;
    for (int i = 1; i <= N; ++i) {
        string s;
        cin >> s;
        if (S.find(s) == S.end()) {
            cout << i << endl;
            S.insert(s);
        }
    }

    return 0;
}
