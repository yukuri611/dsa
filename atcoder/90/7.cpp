#include <bits/stdc++.h>

using namespace std;

int main() {
  int N; cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) cin >> A[i];
  sort(A.begin(), A.end());
  int Q; cin >> Q;
  vector<int> res_list(Q);
  for (int i = 0; i < Q; ++i) {
    int b; cin >> b;
    auto it = lower_bound(A.begin(), A.end(), b);
    if (it == A.end()) {
      res_list[i] = b - A[N-1];
    }
    else if (it == A.begin()) {
      res_list[i] = A[0] - b;
    }
    else if (abs(*it - b) <= abs(*(it - 1) - b)){
      res_list[i] = *it - b;
    }
    else {
      res_list[i] = b - *(it - 1);
    }
  }

  for (int res: res_list) cout << res << endl;
  return 0;
}
