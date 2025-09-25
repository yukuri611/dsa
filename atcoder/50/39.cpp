#include <bits/stdc++.h>

using namespace std;

#define rep(i,N) for (int i = 0; i < N; ++i)

int INF = INT_MAX;

struct SegmentTree {
  int n;
  vector<int> node; //各区間の最小値を保有
public: 
  SegmentTree(vector<int> v) {
    int sz = v.size();
    n = 1;
    while(n < sz) n *= 2;
    node.resize(2 * n - 1, INF);
    for (int i = 0; i < sz; ++i) {
      node[n + i - 1] = v[i];
    }
    for (int i = n-2; i >= 0; --i) {
      node[i] = min(node[2 * i + 1], node[2 * i + 2]);
    }
  }

  void update(int x, int y) {
    //配列のx番目の要素をyにアップデート
    //seg配列の下のノードから順に変更による最小値変化を伝播
    x += n-1;
    node[x] = y;
    while(x > 0) {
      x = (x - 1) / 2;
      node[x] = min(node[2 * x + 1], node[2 * x + 2]);
    }
  }

  int find(int x, int y) {
    //[x, y]の最小値を返す
    return getMin(x, y + 1);
  }

  int getMin(int x, int y, int k=0, int l=0, int r=-1) {
    if (r < 0) r = n;
    //[x,y)が[l,r)とかぶってないとき
    if (y <= l || x >= r) return INF;
    //[l, r)が[x,y)に完全に包含されているとき
    if (l >= x && r <= y) return node[k];
    else {
      int minL = getMin(x, y, 2 * k + 1, l, (l + r) / 2);
      int minR = getMin(x, y, 2 * k + 2, (r + l)/2, r);
      return min(minL, minR);
    }
  }
};

int main() {
  int n, q; cin >> n >> q;
  vector<int> res_list;
  vector<int> v(n, INF);
  SegmentTree segTree(v);
  rep(_, q) {
    int com, x, y; cin >> com >> x >> y;
    if(com == 0) {
      segTree.update(x, y);
    }
    else {
      res_list.push_back(segTree.find(x, y));
    }
  }

  for (int res: res_list) cout << res << endl;
  return 0;
}
