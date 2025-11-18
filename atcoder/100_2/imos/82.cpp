#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

int time_to_int(string s) {
    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 2));
    int sec = stoi(s.substr(6, 2));
    return h * 3600 + m * 60 + sec;
}

void solve(int n) {
    int M = 86400;
    vector<int> S(M + 1);
    rep(i, n) {
        string s, e;
        cin >> s >> e;
        int s_int = time_to_int(s);
        int e_int = time_to_int(e);
        S[s_int]++;
        S[e_int]--;
    }

    rep(i, M) { S[i + 1] += S[i]; }

    int max_cnt = 0;
    rep(i, M + 1) max_cnt = max(max_cnt, S[i]);

    cout << max_cnt << endl;
}

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        solve(n);
    }
    return 0;
}
