// 全列挙すると間に合わない。どうやって大きい順で探索するの？
// Lこの中に含まれるかどうか。これは、セットを使えばよさそう。

// 二つ変数があることが大きい順に探索できない理由。一つの変数を固定すれば、ソートにより簡単に探索可能。
// 固定した一つの変数に関しては、pqを使えば和がさいだいとなるものを探索できる。

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, L;
    cin >> N >> M >> L;
    vector<int> A(N), B(M);
    rep(i, N) { cin >> A[i]; }
    rep(i, M) { cin >> B[i]; }
    set<pair<int, int>> Set;
    rep(i, L) {
        int c, d;
        cin >> c >> d;
        c--;
        d--;
        Set.insert({c, d});
    }

    vector<int> IndexB(M);
    iota(IndexB.begin(), IndexB.end(), 0);
    sort(IndexB.begin(), IndexB.end(),
         [&](int a, int b) { return B[a] > B[b]; });

    vector<int> curr(N, 0);
    priority_queue<pair<int, int>> pq;  // cost, IndexA
    rep(i, N) { pq.push({A[i] + B[IndexB[0]], i}); }

    while (!pq.empty()) {
        auto [cost, indexA] = pq.top();
        pq.pop();
        int indexB = IndexB[curr[indexA]];
        if (!Set.count({indexA, indexB})) {
            cout << cost << endl;
            return 0;
        }
        if (curr[indexA] == M - 1) continue;
        curr[indexA]++;
        pq.push({A[indexA] + B[IndexB[curr[indexA]]], indexA});
    }
    return 0;
}
