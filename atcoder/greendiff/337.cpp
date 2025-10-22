#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int M = 0;
    while (1 << M < N) M++;
    cout << M << endl;

    int juice_id = 1;
    vector<vector<int>> vec(M);  // vec[i] = i番目の人が飲むジュースのリスト
    rep(i, (1 << M)) {
        if (juice_id > N) break;
        rep(j, M) {
            if ((i >> j) & 1) vec[j].push_back(juice_id);
        }
        juice_id++;
    }

    rep(i, M) {
        cout << vec[i].size() << " ";
        for (int juice : vec[i]) {
            cout << juice << " ";
        }
        cout << endl;
    }

    string S;
    cin >> S;
    reverse(S.begin(), S.end());
    int res = stoi(S, nullptr, 2);

    cout << res + 1 << endl;
    return 0;
}
