#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  int N; cin >> N;
  vector<int> A(N);
  for(int i = 0; i < N; ++i) cin >> A[i];
  int X; cin >> X;
  if (count(A.begin(), A.end(), X) != 0) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
