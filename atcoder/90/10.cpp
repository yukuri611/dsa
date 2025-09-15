#include <bits/stdc++.h>

using namespace std;

int main() {
  int N; cin >> N;
  vector<int> sumA(N + 1,0), sumB(N + 1,0);
  for (int i = 1; i < N + 1; ++i) {
    int c, p; cin >> c >> p;
    sumA[i] = sumA[i-1];
    sumB[i] = sumB[i-1];
    if (c == 1) {
      sumA[i] += p;
    }
    else {
      sumB[i] += p;
    }
  }

  int Q; cin >> Q;
  vector<pair<int, int>> res_list(Q);
  for (int i = 0; i < Q; ++i) {
    int l, r; cin >> l >> r;
    int A = sumA[r] - sumA[l - 1];
    int B = sumB[r] - sumB[l - 1];
    res_list[i] = {A,B};
  }
  for (auto p: res_list) cout << p.first << " " << p.second << endl;
  return 0;
}
