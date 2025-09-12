#include <stack>
#include <iostream>

using namespace std;

int main() {
  int n; cin >> n;
  stack<pair<int, int>> s1, s0;

  int prev = -1;
  for (int i = 1; i <= n; ++i){
    int k; cin >> k;
    if (i % 2 == 1) {
      if (k==0) {
        if (prev == 0) {
          s0.top().second = i;
        }
        else {
          s0.push({i,i});
        }
      }
      else {
        if (prev == 1) {
          s1.top().second = i;
        }
        else {
          s1.push({i,i});
        }
      }
    }
    else {
      if (prev == k) {
        if (k == 0) s0.top().second = i;
        else s1.top().second = i;
      }
      else {
        if (k == 0) {
          s1.pop();
          if (s0.empty()) s0.push({1,i});
          else s0.top().second = i;
        }
        else {
          s0.pop();
          if (s1.empty()) s1.push({1,i});
          else s1.top().second = i;
        }
      }
    }
    prev = k;
  }
  int res = 0;
  while(!s0.empty()) {
    pair<int, int> p = s0.top();
    s0.pop();
    res += p.second - p.first + 1;
  }
  cout << res << endl;
  return 0;
}
