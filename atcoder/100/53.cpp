#include <bits/stdc++.h>

using namespace std;

int LIS(vector<int> &A) {
  int n = A.size();
  vector<int> L;
  for (int i= 0; i<n; ++i) {
    auto it = lower_bound(L.begin(), L.end(), A[i]);
    if (it == L.end()) {L.push_back(A[i]);}
    else {*it = A[i];}
  }
  return L.size();
}


int main() {
  int n; cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; ++i) cin >> A[i];

  int res = LIS(A);
  cout << res << endl;
  return 0;
}
