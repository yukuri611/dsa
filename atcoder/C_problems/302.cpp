#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

bool check(string& s1, string& s2) {
    if (s1.size() != s2.size()) return false;
    int c = 0;
    rep(i, s1.size()) {
        if (s1[i] != s2[i]) {
            c++;
        }
    }
    return c == 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    vector<int> p(N);
    iota(p.begin(), p.end(), 0);

    do {
        bool valid = true;
        rep(i, N - 1) {
            if (!check(S[p[i]], S[p[i + 1]])) {
                valid = false;
                break;
            }
        }
        if (valid) {
            cout << "Yes" << endl;
            return 0;
        }
    } while (next_permutation(p.begin(), p.end()));

    cout << "No" << endl;
    return 0;
}
