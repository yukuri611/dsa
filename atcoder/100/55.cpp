#include <bits/stdc++.h>

using namespace std;

int main() {
  int N; cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
    A[i] = -A[i];
  }

  vector<int>S;
  for (int i = 0; i < N; ++i) {
    auto it = upper_bound(S.begin(), S.end(), A[i]);
    if (it == S.end()) S.push_back(A[i]);
    else *it = A[i]; 
  }
  cout << S.size() << endl;
  return 0;
}
