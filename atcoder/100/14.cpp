#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int main() {
  int K, N; cin >> N >> K;
  vector<long long> a(N);
  for (int i = 0; i < N; ++i) cin >> a[i];
  
  long long res = LLONG_MAX;
  for (int n = 1; n < (1 << N); ++n) {
    vector<int> bit(N);
    for(int i = 0; i < N; ++i) {
      bit[i] = ((n >> i) & 1) % 2;
    }
    int c = count(bit.begin(), bit.end(), 1);
    if (c != K) continue;
    long long cost = 0;
    long long curr_max = 0;
    for (int i = 0; i < N; ++i) {
      if (!bit[i] || curr_max < a[i]) {
        curr_max = max(curr_max, a[i]);
        continue;
      }
      curr_max++;
      cost += curr_max - a[i];
    }
    res = min(res, cost);
  }

  cout << res << endl;
  return 0;
}
