#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  int N, M, K; cin >> N >> M >> K;
  vector<int> Remain(N + 1, M);
  vector<int> res_list;
  for (int i = 0; i < K; ++i) {
    int a,b; cin >> a >> b;
    Remain[a]--;
    if (Remain[a] == 0) res_list.push_back(a);
  }

  if (res_list.size() > 0) {
    for (int i = 0; i < res_list.size() - 1; ++i) {
      cout << res_list[i] << " ";
    }
    cout << res_list[res_list.size() - 1] << endl;
  }
  
  return 0;
}
