#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ll N, M; cin >> N >> M;
  vector<pair<ll, ll>> D(M);
  for (int i = 0; i < M; ++i) {
    ll a, b; cin >> a >> b;
    D[i] = {a - b, a};
  }

  sort(D.begin(), D.end());

  ll sticker_c = 0;
  ll remain = N;
  for (int i = 0; i < M; ++i) {
    if (remain < D[i].second) continue;
    ll c = (remain - D[i].second) / (D[i].first) + 1; //取引回数
    remain -= c * D[i].first;
    sticker_c += c; 
  }

  cout << sticker_c << endl;
  return 0;


}
