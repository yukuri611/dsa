
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;
    vector<int> A(K);
    rep(i, K) { cin >> A[i]; }

    vector<int> socks;
    int curr = 0;
    rep(i, N) {
        socks.push_back(i);
        if (A[curr] == i) {
            curr++;
        } else {
            socks.push_back(i);
        }
    }
    int sz = socks.size();
    vector<int> pre(sz + 1), suf(sz + 1);
    for (int i = 1; i < sz + 1; ++i) {
        pre[i] = pre[i - 1];
        if (i % 2 == 0) pre[i] += socks[i - 1] - socks[i - 2];
    }
    for (int i = sz - 1; i >= 0; --i) {
        suf[i] = suf[i + 1];
        if ((sz - i) % 2 == 0) suf[i] += socks[i + 1] - socks[i];
    }
}
