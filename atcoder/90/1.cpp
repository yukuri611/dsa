#include <bits/stdc++.h>

using namespace std;

int main() {
  long long N, L; cin >> N >> L;
  long long K; cin >> K;
  vector<long long> A(N + 2);
  A[0] = 0; A[N + 1] = L;
  for (long long i = 1; i <= N; ++i) cin >> A[i];

  long long l = 0; long long r = L;
  while (l + 1 < r) {
    long long mid = (r - l) / 2 + l;
    long long i = 1;
    long long curr = 0;
    long long count = 0;
    while (i < N + 2) {
      if (curr >= mid) {
        count++;
        curr = 0;
      }
      curr += A[i] - A[i-1];
      i++;
    }
    if (curr >= mid) count++;
    bool valid = count >= K + 1;
    if (valid) l = mid;
    else r = mid;
  }

  cout << l << endl;
  return 0;
}
