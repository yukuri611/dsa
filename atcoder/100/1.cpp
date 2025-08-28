#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> res_list;
  while (true) {
    int n, x; cin >> n >> x;
    if (n == 0 && x == 0) break;
    int res = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = i + 1; j <= n; ++j) {
        int k = x - i - j;
        if (k > j && k <= n) res++;
      }
    
    }
    res_list.push_back(res);
  }
  for (int res: res_list) {
    cout << res << endl;
  }
  return 0;
}
