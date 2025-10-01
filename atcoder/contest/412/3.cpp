#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  int T;
  cin >> T;
  vector<int> res_list;
  for (int _ = 0; _ < T; ++_) {
    int N;
    cin >> N;
    vector<int> S(N - 2);
    int start;
    cin >> start;
    for (int i = 0; i < N - 2; ++i) cin >> S[i];
    int end;
    cin >> end;

    sort(S.begin(), S.end());

    int curr = start;
    int ans = 2;
    bool valid = true;
    while (curr * 2 < end) {
      auto it = upper_bound(S.begin(), S.end(), curr * 2);
      if (it == S.begin() || *(it - 1) <= curr) {
        res_list.push_back(-1);
        valid = false;
        break;
      }
      curr = *(it - 1);
      ans++;
    }
    if (valid) {
      res_list.push_back(ans);
    }
  }
  for (int res : res_list) cout << res << endl;
  return 0;
}
