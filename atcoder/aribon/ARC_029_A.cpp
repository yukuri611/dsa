#include <iostream>
using namespace std;
int main() {
  int N, t[4];
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> t[i];
  }

  int res = 1e9;
  for (int mask = 0; mask < (1 << N); ++mask) {
    int s1 = 0, s2 = 0;
    for(int i = 0; i < N; i++) {
      if((mask >> i) & 1) {
        s1 += t[i];
      }
      else {
        s2 += t[i];
      }
    }
    res = min(res, max(s1, s2));
  }
  cout << res << endl;
  return 0;
}
