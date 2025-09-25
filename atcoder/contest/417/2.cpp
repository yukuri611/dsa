#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N, M; cin >> N >> M;
  vector<int> A(N);
  vector<int> B(M);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  for (int i = 0; i < M; ++i) {
    cin >> B[i];
  }

  for (int b: B) {
    vector<int> newA;
    bool f = true;
    for (int i = 0; i < A.size(); ++i) {
      if (f & A[i] == b) {
        f = false; 
        continue;
      } 
      else {
        newA.push_back(A[i]);
      }
    }
    A = newA;
  }

  for (int a: A) cout << a << " ";
  cout << endl;

  return 0;
}
