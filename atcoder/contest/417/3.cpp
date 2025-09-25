#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int main() {
  int N; cin >> N;
  map<int, ll> m1;
  map<int, ll> m2;
  for (int i = 0; i < N; ++i) {
    int a; cin >> a;
    m1[i + a]++;
    m2[i - a]++;
  }

  ll res = 0;
  for (auto p: m1) {
    res += p.second * m2[p.first];
  }

  cout << res << endl;
  return 0;
}
