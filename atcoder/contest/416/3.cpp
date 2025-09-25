#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  int N, K, X; cin >> N >> K >> X;
  vector<string> S(N);
  for (int i = 0; i < N; ++i) cin >> S[i];

  vector<string> memo = S;
  for (int k = 2; k <= K; ++k) {
    vector<string> newMemo;
    for (string s: memo) {
      for (string t: S){
        newMemo.push_back(s + t);
      }
    }
    memo = newMemo;
  }

  sort(memo.begin(), memo.end());
  cout << memo[X - 1] << endl;
  return 0;
}
