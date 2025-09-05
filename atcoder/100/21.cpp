#include <bits/stdc++.h>

using namespace std;
using LL = long long;


int main() {
  int N; cin >> N;
  vector<int> H(N), S(N);
  for (int i = 0; i < N; ++i) cin >> H[i] >> S[i];

  LL l = 0; LL r = LLONG_MAX;
  while (l < r) {
    LL mid = (r - l) / 2 + l;
    vector<LL> time(N);
    for (int i = 0; i < N; ++i) {
      if (mid < H[i]) time[i] = -1;
      else time[i] = (mid - H[i]) / S[i];
    }
    sort(time.begin(), time.end());
    bool valid = true;
    for (int i = 0; i < N; ++i) {
      if (time[i] < i) valid = false;
    }
    if (valid) r = mid;
    else l = mid + 1;
  }

  cout << l << endl;
  return 0;
}
