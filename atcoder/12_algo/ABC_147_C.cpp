#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N; cin >> N;
  vector<vector<int>> kind_list(N + 1); //kind_list[i] は、iがkindと発言した人のリスト
  vector<vector<int>> unkind_list(N + 1);
  for (int i = 1; i < N + 1; i++) {
    int A; cin >> A;
    for (int j = 0; j < A; j++) {
      int x, y; cin >> x >> y;
      if (y) kind_list[i].push_back(x);
      else unkind_list[i].push_back(x);
    }
  }

  int res = 0; 
  for (int i = 0; i < (1 << N); i++) {
    bool bit[N];
    for (int j = 0; j < N; j++) {
      bit[j] = (i / (1 << j)) % 2;
    }
    bool valid = true;
    for (int j = 0; j < N && valid; j++) {
      if (!bit[j]) continue;
      for (int k: kind_list[j + 1]) {
        if (!bit[k-1]) valid = false;
      }
      for (int k: unkind_list[j + 1]) {
        if (bit[k-1]) valid = false;
      }
    }
    
    if (valid) {
      int count = 0;
      for (int j = 0; j < N; j++) {
        if (bit[j]) count++;
      }
      res = max(res, count);
    }
  }

  cout << res << endl;
  return 0;

}
