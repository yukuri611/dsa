#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    string S;
    cin >> S;
    sort(S.begin(), S.end());

    ll maximum = 1;
    rep(i, N) maximum *= 10;
    maximum -= 1;

    int res = 0;
    ll M = sqrt(maximum) + 1;
    rep(i, M) {
        string curr = to_string((ll)i * i);
        curr.resize(N, '0');
        sort(curr.begin(), curr.end());
        if (curr == S) res++;
    }

    cout << res << endl;
    return 0;
}
