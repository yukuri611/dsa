#include <iostream>
#include <vector>

using namespace std;

int main() {
  int R, C; cin >> R >> C;
  vector a(R, vector(C, 0));
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      cin >> a[i][j];
    }
  }

  int res = 0;
  for (int bit = 0; bit < (1 << R); ++bit) {
    int temp = 0;
    for (int i = 0; i < C; ++i) {
      int count = 0;
      for (int j = 0; j < R; ++j) {
        if ((bit >> j) & 1) {
          count += 1 - a[j][i];
        }
        else count += a[j][i];
      }
      temp += max(count, R - count);
    }
    res = max(res, temp);
  }

  cout << res << endl;
  return 0;
}
