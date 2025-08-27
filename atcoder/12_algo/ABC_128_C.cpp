#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;


int main() {
  int N, M;
  cin >> N >> M;
  vector<int> k(M+1);
  vector<vector<int>> switch_bulb(N+1);
  for (int i = 1; i < M + 1; i++) {
    cin >> k[i];
    for (int j = 0; j < k[i]; ++j) {
      int switch_id; cin >> switch_id;
      switch_bulb[switch_id].push_back(i);
    }
  }
  vector<int> p(M + 1);
  for (int i = 1; i < M + 1; ++i) cin >> p[i];

  int res = 0;
  for (int i = 0; i < (1 << N); ++i) {
    bool bit[N];
    for(int j = 0; j < N; ++j) {
      bit[j] = (i / (1 << j)) % 2;
    }
    vector<int> temp(M+1);
    for (int j = 0; j < N; ++j) {
      if (bit[j]) { //switch番号はj+1
        for (int bulb: switch_bulb[j+1]) {
          temp[bulb] += 1;
        }
      }
    }
    int valid = true;
    for (int j = 1; j < M + 1; ++j) {
      if (p[j] != temp[j] % 2) valid = false;
    }
    if (valid) res += 1;
  }
  cout << res << endl;

  return 0;


  
}
