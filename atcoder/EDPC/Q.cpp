#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> dp; // dp[i][j] = 0からi-1番目の花までで、最終高さがjの時の最大価値
vector<ll> H, A;

class SegmentTree {

public:
  vector<ll> node;
  int N;
  SegmentTree(vector<ll> vec) {
    int len = vec.size();
    N = 1; while(N < len) N *= 2;
    node.resize(2 * N - 1, 0);
    for (int i = 0; i < len; ++i) node[i + N - 1] = vec[i];
    for (int i = N - 2; i > -1; --i) node[i] = max(node[2 * i + 1], node[2 * i + 2]);
  }

  void update(int x, ll a) {
    x += N - 1;
    node[x] = a;
    while(x > 0) {
      x = (x - 1) / 2;
      node[x] = max(node[2 * x + 1], node[2 * x + 2]);
    }
  }

  ll getMax(int x, int y, int k=0, int l=0, int r=-1) {
    if (r < 0) r = N;
    if (x >= r || y <= l) return -1;
    if (x <= l && r <= y) return node[k];
    else {
      ll vl = getMax(x, y, 2 * k + 1, l, (l + r) / 2);
      ll vr = getMax(x, y, 2 * k + 2, (l + r) / 2, r);
      return max(vl, vr);
    }
  }
};

int main() {
  int N; cin >> N;
  H.resize(N); A.resize(N);
  for (int i = 0; i < N; ++i) cin >> H[i];
  for (int i = 0; i < N; ++i) cin >> A[i];

  auto Horiginal = H;
  sort(H.begin(), H.end());
  vector<ll> B(N);
  for (int i = 0; i < N; ++i) {
    int n = lower_bound(H.begin(), H.end(), Horiginal[i]) - H.begin();
    B[i] = n;
  }

  dp.assign(N + 1, 0);
  SegmentTree st(dp);
  for (int i = 0; i < N; ++i) {
    int currH = B[i];
    ll temp = st.getMax(0, currH + 1) + A[i];
    if (dp[currH] < temp) {
      dp[currH] = temp;
      st.update(currH, temp);
    }
  }
  ll res = 0;
  for (int i = 0; i < N; ++i) res = max(res, dp[i]);
  cout << res << endl;
  return 0;
}
