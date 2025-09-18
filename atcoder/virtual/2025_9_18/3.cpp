#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll power(int a, int n) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a;
    a = a * a;
    n >>= 1;
  }
  return res;
}

int main() {
  ll N, X; cin >> N >> X;
  string S; cin >> S;
  stack<char> s;
  for (int i = 0; i < N; ++i) {
    if (S[i] == 'U' && !s.empty() && s.top() != 'U') {
      s.pop();
      continue;
    }
    s.push(S[i]);
  }
  vector<char> remain;
  while (!s.empty()) {
    char c = s.top();
    remain.push_back(c);
    s.pop();
  }
  ll res = X;
  for(int i = remain.size() - 1; i > -1; --i) {
    char c = remain[i];
    if (c == 'L') res = res * 2;
    else if(c == 'R') res = res * 2 + 1;
    else res /= 2;
  }
  cout << res << endl;
  return 0;
}
