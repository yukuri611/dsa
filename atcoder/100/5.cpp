#include <iostream>
#include <climits>

using namespace std;

int main() {
  int a, b, c, x, y; cin >> a >> b >> c >> x >> y;
  long long res =LLONG_MAX;
  for (int i = 0; i <= max(x, y) * 2; ++i) {
    int count_a = max(0, x - i/2);
    int count_b = max(0, y - i/2);
    long long total = a * count_a + b * count_b + c * i;
    res = min(total, res);
  }
  cout << res << endl;
  return 0;
}
