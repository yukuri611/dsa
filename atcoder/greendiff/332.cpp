// 普通にアルゴリズム的に解けるかどうか判定することは困難そう。
// 制約条件が小さいの全探索すれば解けそう。何をどうやって探索する？

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int H, W;

bool comp(vector<vector<int>>& A, vector<vector<int>>& B) {
    rep(i, H) {
        rep(j, W) {
            if (A[i] != B[i]) return false;
        }
    }
    return true;
}

bool isSame(vector<vector<int>>& A, vector<vector<int>>& B, vector<int>& Row,
            vector<int>& Col) {
    auto tempA1 = A;
    rep(i, H) { tempA1[i] = A[Row[i]]; }
    auto tempA2 = tempA1;
    rep(i, W) {
        rep(j, H) { tempA2[j][i] = tempA1[j][Col[i]]; }
    }
    return comp(tempA2, B);
}

int Count(vector<int>& vec, vector<int>& target) {
    // vecの転倒数を数える
    int sz = vec.size();
    map<int, int> Map;
    rep(i, sz) Map[target[i]] = i;

    vector<int> vecIndex(sz);
    rep(i, sz) vecIndex[i] = Map[vec[i]];

    int res = 0;
    rep(i, sz) {
        for (int j = i + 1; j < sz; ++j) {
            if (vecIndex[j] < vecIndex[i]) res++;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> H >> W;
    vector A(H, vector<int>(W)), B(H, vector<int>(W));
    rep(i, H) rep(j, W) cin >> A[i][j];
    rep(i, H) rep(j, W) cin >> B[i][j];

    int res = INT_MAX;
    vector<int> Row(H), Col(W);
    iota(Row.begin(), Row.end(), 0);
    iota(Col.begin(), Col.end(), 0);

    do {
        do {
            if (isSame(A, B, Row, Col)) {
                vector<int> startR(H);
                iota(startR.begin(), startR.end(), 0);
                vector<int> startC(W);
                iota(startC.begin(), startC.end(), 0);
                int cnt = Count(startR, Row) + Count(startC, Col);
                res = min(cnt, res);
            }
        } while (next_permutation(Col.begin(), Col.end()));
    } while (next_permutation(Row.begin(), Row.end()));

    if (res == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << res << endl;
    }
    return 0;
}
