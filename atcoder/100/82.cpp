#include <bits/stdc++.h>

using namespace std;

int change_to_second(string s) {
  int h = stoi(s.substr(0, 2));
  int m = stoi(s.substr(3,2));
  int sec = stoi(s.substr(6,2));
  return h * 3600 + m * 60 + sec;
}

int main(){
  vector<int> res_list;
  while (true) {
    int n; cin >> n;
    if (n == 0) break;
    vector<int> imos(86400, 0);
    for (int i = 0; i < n; ++i) {
      string s1, s2; cin >> s1 >> s2;
      int t1 = change_to_second(s1);
      int t2 = change_to_second(s2);
      imos[t1] += 1;
      imos[t2] -= 1;
    }
    int res = imos[0];
    for (int i = 1; i < imos.size(); ++i) {
      imos[i] += imos[i-1];
      res = max(res, imos[i]);
    }
    res_list.push_back(res);
  }
  for (int res: res_list) cout << res << endl;
  return 0;
}
