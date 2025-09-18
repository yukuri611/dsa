#include <bits/stdc++.h>

using namespace std;

int n, q;
vector<int> A;

int main() {
  cin >> n;
  A.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
  }

  vector<bool> sum(20 * 2000 + 1, false);
  for (int bit = 0; bit < (1 << n); ++bit) {
    int total = 0;
    for (int i = 0; i < n; ++i) {
      if ((bit >> i) & 1) total += A[i];
    }
    sum[total] = true;
  }

  cin >> q;
  vector<string> res_list;
  for (int i = 0; i < q; ++i) {
    int m; cin >> m;
    if (sum[m]) res_list.push_back("yes");
    else res_list.push_back("no");
  }
  for (string s: res_list) cout << s << endl;
  return 0;
}
