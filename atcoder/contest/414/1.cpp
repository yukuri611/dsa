#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  int N, L, R; cin >> N >> L >> R;
  int res = 0;
  for (int i = 0; i < N; ++i) {
    int x, y; cin >> x >> y;
    if (x <= L && y >= R) {
      res++;
    }
  } 
  cout << res << endl;
  return 0;
}
