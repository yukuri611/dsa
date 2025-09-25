#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll INF = LLONG_MAX;

class SegmentTree {
  int n; 
  vector<ll> node;
public:
  SegmentTree(vector<ll> v) {
    int sz = v.size();
    n = 1; while(n < sz) n *= 2;
    node.resize(2 * n - 1, INF);
    for (int i = 0; i < sz; ++i) {
      node[n - 1 + i] = v[i];
    }
    for (int i = n - 2; i >= 0; --i) {
      node[i] = min(node[2 * i + 1], node[2 * i + 2]);
    }
  }

  void update(int x, int a) {
    x += n - 1;
    node[x] = a;
    while(x > 0) {
      x = (x - 1) / 2;
      node[x] = min(node[2 * x + 1], node[2 * x + 2]);
    }
  }

  ll minNum(int x, int y, int k=0, int l=0, int r=-1) { 
    if (r < 0) r = n;
    if (r <= x || y <= l) return INF;
    if (x <= l && r <= y) return node[k];
    else {
      ll minl = minNum(x, y, 2 * k + 1, l, (l + r) / 2);
      ll minR = minNum(x, y, 2 * k + 2, (l + r) / 2, r);
      return min(minl, minR);
    }
  }
};

int main() {
  ll N, x; cin >> N >> x;
  vector<ll> A(N);
  for (int i = 0; i < N; ++i) cin >> A[i];

  SegmentTree st(A);
  ll res = INF;
  for (int k = 0; k < N; ++k) {// k = 魔法の使用回数
    ll total_cost = 0;
    for (int i = 0; i < N; ++i) {
      ll minimum = INF;
      if (i - k < 0) {
        minimum = st.minNum(0, i + 1);
        minimum = min(minimum, st.minNum(N + (i - k), N));
      }
      else {
        minimum = st.minNum(i - k, i + 1); //i番目のスライムをどのスライムを魔法変換することで取得したものとするかを選択
      }
      total_cost += minimum;
    }
    total_cost += k * x; //魔法の使用量コスト
    res = min(res, total_cost);
  }

  cout << res << endl;
  return 0;
}
