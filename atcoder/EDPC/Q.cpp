#include <bits/stdc++.h>

using namespace std;
using ll = long long;


class SegmentTree {
  int n;
  vector<ll> node;

public:
  SegmentTree(vector<ll> v) {
    int sz = v.size();
    n = 1; while(n < sz) n *= 2;
    node.resize(2 * n - 1, 0);
    for (int i = 0; i < sz; ++i) {
      node[n - 1 + i] = v[i];
    }
    for (int i = n - 2; i >= 0; --i) {
      node[i] = max(node[2 * i + 1], node[2 * i + 2]);
    }
  }

  void update(int x, ll a) {
    x += n - 1;
    node[x] = a;
    while(x > 0) {
      x = (x - 1) / 2;
      node[x] = max(node[2 * x + 1], node[2 * x + 2]);
    }
  }

  ll getMax(int x, int y, int k=0, int l=0, int r=-1) {
    if (r < 0) r = n;
    if (x >= r || y <= l) return 0;
    if (x <= l && r <= y) return node[k];
    else {
      ll maxL = getMax(x, y, 2 * k + 1, l, (l + r) / 2);
      ll maxR = getMax(x, y, 2 * k + 2, (l + r) / 2, r);
      return max(maxL, maxR);
    }
  }
};

int main() {
  int N; cin >> N;
  vector<int> H(N), A(N);
  for (int i = 0; i < N; ++i) cin >> H[i];
  for (int i = 0; i < N; ++i) cin >> A[i];

  vector<ll> v(N + 1, 0);
  SegmentTree st(v);
  for (int i = 0; i < N; ++i) {
    ll max_beauty = st.getMax(0,H[i]);
    ll curr_max = st.getMax(H[i], H[i] + 1);
    if (curr_max < max_beauty + A[i]) st.update(H[i], max_beauty + A[i]); 
  }
  ll res = st.getMax(1, N + 1);
  cout << res << endl;
  return 0;
}
