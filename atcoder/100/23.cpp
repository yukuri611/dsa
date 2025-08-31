#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int N, M; cin >> N >> M;
  vector<int> P(N);
  for (int i = 0; i < N; ++i) cin >> P[i];
  P.push_back(0);
  vector<int> two_sum;
  for (int i = 0; i < N + 1; ++i) {
    for (int j = 0; j < N + 1; ++j) {
      two_sum.push_back(P[i] + P[j]);
    }
  }

  sort(two_sum.begin(), two_sum.end());

  int res = 0;
  for (int s: two_sum) {
    int i = upper_bound(two_sum.begin(), two_sum.end(), M - s) - two_sum.begin();
    if (i == 0) continue;
    res = max(res, s + two_sum[i-1]);
  }
  cout << res << endl;
  return 0;
}
