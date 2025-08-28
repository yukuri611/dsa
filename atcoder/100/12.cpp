#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int N, M; cin >> N >> M;
  vector<vector<int>> relationship(N);
  for (int _ = 0; _ < M; ++_) {
    int x, y; cin >> x >> y; x--; y--;
    relationship[x].push_back(y);
    relationship[y].push_back(x);
  }

  int res = 0;
  for(int i = 1; i < (1 << N); ++i) {
    int bit[N];
    int count = 0;
    for (int j = 0; j < N; ++j) {
      bit[N - 1 - j] = ((i >> j) & 1);
      count += (i >> j) & 1;
    }
    bool valid = true;
    for (int j = 0; j < N; ++j) {
      if (!bit[j]) continue;
      for (int k = j + 1; k < N; ++k) {
        if (!bit[k]) continue;
        if (find(relationship[j].begin(), relationship[j].end(), k) == relationship[j].end()) valid = 0;
      }
    }
    if (valid) res = max(res, count);
  }

  cout << res << endl;
}
