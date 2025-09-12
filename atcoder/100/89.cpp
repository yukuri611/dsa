#include <bits/stdc++.h>

using namespace std;
int main() {
  int N; cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }

  vector<vector<int>> B; //{{start, length}}
  B.push_back({-1,0});
  int i = 0;
  while (i < N) {
    int start = i;
    int c = A[i];
    while (i < N && A[i] == c) {
      i++;
      c = 1 - c;
    }
    B.push_back({start, i - start});
  }
  B.push_back({N,0});
  
  int res = 0;
  for (int i = 1; i < B.size() - 1; i++) {
    res = max(res, B[i][1]+ B[i - 1][1] + B[i + 1][1]);
  }

  cout << res << endl;
  return 0;
}
