#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, M; cin >> N >> M;
  vector<vector<long long>> points(N, vector<long long>(M));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> points[i][j];
    }
  }

  long long res = 0;
  for (int s1 = 0; s1 < M; ++s1) {
    for (int s2 = s1 + 1; s2 < M; ++s2) {
      long long total = 0; 
      for (int i = 0; i < N; ++i) {
        total += max(points[i][s1], points[i][s2]);
      }
      res = max(res, total);
    }
  }

  cout << res << endl;
  return 0;
}
