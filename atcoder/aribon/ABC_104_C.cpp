#include <iostream>

using namespace std;
int main() {
  int D, G, p[11], c[11];
  cin >> D >> G;
  for (int i = 0; i < D; i++) {
    cin >> p[i] >> c[i];
  }

  int ans = 1e9;
  for (int mask = 0; mask < (1 << D); ++mask) {
    int s = 0, rest_max = -1, count = 0;
    for (int i = 0; i < D; i++) {
      if ((mask >> i) & 1) {
        s += 100 * (i+1) * p[i] + c[i];
        count += p[i];
      }
      else {
        rest_max = i;
      }
    }

    if (s < G) {
      int s1 = 100 * (rest_max + 1);
      int need = (G - s + s1 - 1) / s1;
      if (need >= p[rest_max]) {
        continue;
      }
      count += need;
    }
    ans = min(ans, count);
  }
  cout << ans << endl;
  return 0;
}
