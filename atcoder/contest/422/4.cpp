#include <bits/stdc++.h>

using namespace std;

using LL = long long

LL dfs(vector<LL> B, LL res) {
  int N = B.size()
  if (N == 1) {
    return res;
  }
  sort(B.begin(), B.end());
  vector<LL> newB;
  for (int i = 1; i < N / 2; ++i) {
    newB.push_back(B[N / 2 - i] + B[N/2 + i - 1])
  }
}

int main() {
  LL N, K; cin >> N >> K;
  vector<LL> B((1 << N));
  LL divisor = K / (1 << N);
  LL remainder = K % (1 << N);
  B[i] = K / (1 << N);
  for (int i = 0; i < (1 << N); ++i) {
    if (i >= (1 << N) - remainder) B[i] = divisor + 1;
    else B[i] = divisor;
  }
  for (int _ = 0; _ < N; _++) {

  }
}
