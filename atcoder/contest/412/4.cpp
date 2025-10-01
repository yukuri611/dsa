#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<bool>> G(N, vector<bool>(N, false));
  for (int i = 0; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    G[a][b] = true;
    G[b][a] = true;
  }

  vector<int> P;
  for (int i = 0; i < N; ++i) P.push_back(i);

  int res = INT_MAX;
  do {
    bool valid = true;
    for (int i = 0; i < N; ++i) {
      if (P[i] == i || P[P[i]] == i) {
        valid = false;
        break;
      }
    }
    if (!valid) continue;
    int curr = 0;
    for (int i = 0; i < N; ++i) {
      if (!G[i][P[i]]) curr += 1;
    }
    int del = M - (N - curr);
    curr += del;
    res = min(res, curr);
  } while (next_permutation(P.begin(), P.end()));

  cout << res << endl;
  return 0;
}
