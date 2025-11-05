#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

double calcDistance(int i, int j, vector<int>& X, vector<int>& Y) {
    return sqrt(pow(X[i] - X[j], 2) + pow(Y[i] - Y[j], 2));
}

void dfs(int curr, vector<bool>& infected, vector<vector<int>>& G) {
    for (int nxt : G[curr]) {
        if (infected[nxt]) continue;
        infected[nxt] = true;
        dfs(nxt, infected, G);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, D;
    cin >> N >> D;
    vector<int> X(N), Y(N);
    rep(i, N) cin >> X[i] >> Y[i];

    vector<vector<int>> G(N);
    rep(i, N) {
        for (int j = i + 1; j < N; ++j) {
            double d = calcDistance(i, j, X, Y);
            if (d <= D) {
                G[i].push_back(j);
                G[j].push_back(i);
            }
        }
    }

    vector<bool> infected(N);
    infected[0] = true;
    dfs(0, infected, G);

    rep(i, N) {
        if (infected[i])
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}
