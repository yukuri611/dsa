#include <bits/stdc++.h>

using namespace std;

int main() {
  int Q; cin >> Q;
  priority_queue<int, vector<int>, greater<int>> Ball;
  vector<int> res_list;
  for (int i = 0; i < Q; ++i) {
    int f; cin >> f;
    if (f == 1) {
      int x; cin >> x;
      Ball.push(x);
    }
    else {
      res_list.push_back(Ball.top());
      Ball.pop();
    }
  }
  for (int res: res_list) cout << res << endl;
  return 0;
}
