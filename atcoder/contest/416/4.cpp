#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  int T; cin >> T;
  for (int _ = 0; _ < T; ++_) {
    ll N, M; cin >> N >> M;
    vector<ll> A(N), B(N);
    ll sumA = 0; ll sumB = 0;
    for (int i = 0; i < N; ++i) {cin >> A[i]; sumA += A[i];}
    for (int i = 0; i < N; ++i) {cin >> B[i]; sumB += B[i];}

    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int c = 0;
    for (int a: A) {
      if (a + B.back() >= M) {
        c++;
        B.pop_back();
      }
    }

    cout << sumA + sumB - c * M << endl;

    
  }
  return 0; 
}
