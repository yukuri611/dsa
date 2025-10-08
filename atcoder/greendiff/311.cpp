#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

vector<int> dr = {1,0,-1,0};
vector<int> dc = {0,1,0,-1};
vector<string> S;
int N, M; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    S.resize(N);
    rep(i, N) cin >> S[i];

    queue<pair<int, int>> q;
    q.push({1,1});
    vector<vector<bool>> visited(N, vector<bool>(M,false));
    vector<vector<bool>> searched(N, vector<bool>(M, false));
    visited[1][1] = true;
    searched[1][1] = true;
    while(!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        rep(i, 4) {
            int curR = r, curC = c;
            while(S[curR + dr[i]][curC + dc[i]] == '.') {
                curR += dr[i];
                curC += dc[i];
                visited[curR][curC] = true;
            }
            if (searched[curR][curC]) continue;
            searched[curR][curC] = true;
            q.push({curR,curC});
        }
    }

    int res = 0;
    rep(i, N) {
        rep(j, M) {
            if (visited[i][j]) res++;
        }
    }

    cout << res << endl;
    return 0;


}
