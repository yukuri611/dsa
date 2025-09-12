#include <bits/stdc++.h>

using namespace std;
using LL = long long;

int main() {
  int N, M; cin >> N >> M;
  vector<int> imos1(N + 1,0);
  vector<int> imos2(N + 1,0);
  int p; cin >> p;
  for (int i = 1; i < M; ++i) {
    int nextP; cin >> nextP;
    if (p < nextP) {
      imos1[p] += 1;
      imos1[nextP] -= 1;
    }
    else {
      imos2[p - 1] += 1; 
      imos2[nextP - 1] -= 1;
    }
    p = nextP;
  }

  for (int i = 1; i < N; ++i) {
    imos1[i] += imos1[i-1];
  }
  for (int i = N-2; i > -1; --i) {
    imos2[i] += imos2[i + 1];
  }

  vector<LL> A(N);
  vector<LL> B(N);
  vector<LL> C(N);
  for (int i = 1; i < N; ++i) {
    cin >> A[i] >> B[i] >> C[i];
  }

  LL res = 0;
  for (int i = 1; i <= N-1; ++i) {
    int count = imos1[i] + imos2[i];
    res += min(A[i] * count, B[i] * count + C[i]);
  }

  cout << res << endl;
  return 0;

}
