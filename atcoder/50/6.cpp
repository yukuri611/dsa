// 半分以上の重さの荷物は別で考える

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void makeVector(vector<pair<ll,ll>> &dp, vector<ll> & V, vector<ll> & W, ll s, ll e) {
  //sからe-1まで使用可能
  ll n = e - s;
  vector<pair<ll, ll>> allCombination;
  for (ll i = 0; i < (1 << n); ++i) {
    ll curr_w = 0; ll curr_v = 0;
    for (ll j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        curr_w += W[s + j];
        curr_v += V[s + j];
      }
    }
    allCombination.push_back({curr_w, curr_v});
  }

  //冗長な情報は消去した状態でdpに記録する。
  if (allCombination.empty()) return;
  sort(allCombination.begin(), allCombination.end());
  dp.push_back(allCombination[0]);
  for (int i = 1; i < allCombination.size(); ++i) {
    if (allCombination[i].second > dp.back().second) {
      if (allCombination[i].first > dp.back().first) {
        dp.push_back(allCombination[i]);
      }
      else {
        dp.back() = allCombination[i];
      }
    }
  }
}
int main() {
  ll N, wMax; cin >> N >> wMax;
  vector<ll> V(N), W(N);
  for (int i = 0; i < N; ++i) {
    cin >> V[i] >> W[i];
  }

  // 半分全列挙で解く
  ll n1 = N / 2;
  vector<pair<ll, ll>> dp1;
  makeVector(dp1, V, W, 0, n1);
  vector<pair<ll, ll>> dp2;
  makeVector(dp2, V, W, n1, N);

  ll res = 0;
  for (auto p: dp1) {
    ll w2 = wMax - p.first;
    auto it = upper_bound(dp2.begin(), dp2.end(), make_pair(w2,LLONG_MAX));
    if (it == dp2.begin()) continue;
    it--;
    res = max(res, p.second + (*(it)).second);
  }

  cout << res << endl;

  return 0;


}
