#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
  if (b == 0) {
    return a;
  }
  else {
    return gcd(b, a % b);
  }
}

struct PairHash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        // 2つのハッシュ値を適切に混ぜる
        // この方法は一般的なテクニックの一つ
        return h1 ^ (h2 << 1);
    }
};

int main() {
  int N; cin >> N;
  vector<int> X(N), Y(N);
  for (int i = 0; i < N; ++i) cin >> X[i] >> Y[i];

  unordered_map<pair<int, int>, int, PairHash> m1;
  unordered_map<pair<int, int>, int, PairHash> m2;
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      int dx = X[i] - X[j];
      int dy = Y[i] - Y[j];
      if (dx == 0) {
        dy = 1;
      }
      else if (dy == 0) {
        dx = 1;
      }
      else {
        int d = gcd(dx, dy);
        dx /= d; dy /= d;
        if (dx < 0 && dy < 0) {
          dx = -dx; dy = -dy;
        }
        else if (dx < 0) {
          dy = -dy;
          dx = -dx;
        }
      }
      m1[{dx, dy}]++;
      pair<int, int> c = {X[i] + X[j], Y[i] + Y[j]};
      m2[c]++;
    }
  }

  ll res = 0;
  for (auto p: m1) {
    int c = p.second;
    res += (c * (c - 1)) / 2;
  }
  for (auto p: m2) {
    int c = p.second;
    res -= (c * (c - 1)) / 2;
  }

  cout << res << endl;
}
