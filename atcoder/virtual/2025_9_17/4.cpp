#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, C, K; cin >> N >> C >> K;
  vector<int> T(N);
  for (int i = 0; i < N; ++i) cin >> T[i];
  sort(T.begin(), T.end());

  int i = 0;
  int res = 0;
  while (i < N) {
    //人数を二分探索で求める
    int l = 1; int r = C; 
    if (i + r > N - 1) r = N - i;
    while (l < r) {
      int mid = (r - l) / 2 + l;
      if (T[i + mid] <= T[i] + K) l = mid + 1;
      else r = mid;
    }
    //人数は最初の一人を含めてl
    i += l;
    res++;
  }

  cout << res << endl;

  return 0;
}
