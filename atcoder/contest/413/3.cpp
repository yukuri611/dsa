#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  #define int ll
  queue<pair<ll, ll>> q;

  int Q; cin >> Q;
  vector<ll> res_list;
  for (int _ = 0; _ < Q; ++_) {
    int flag; cin >> flag;
    if (flag == 1) {
      ll c, x; cin >> c >> x;
      q.push({c,x});
    }
    else {
      ll k; cin >> k;
      ll curr_len = 0;
      ll sum = 0;
      while(!q.empty()) {
        auto p = q.front();
        if (curr_len + p.first <= k) {
          curr_len += p.first;
          sum += p.second * p.first;
          q.pop();
        }
        else {
          sum += p.second * (k - curr_len);
          q.front().first -= (k - curr_len);
          break;
        }
      }
      res_list.push_back(sum);
    }
  }

  for (ll res : res_list) cout << res << endl;
  return 0;
}
