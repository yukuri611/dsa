#include <iostream>
#include <climits>

using namespace std;

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  
  int res = INT_MAX;
  for (int c = 0; c <= 2 * X || c <= 2 * Y; ++c) {
    int a = max(0, X - c / 2);
    int b = max(0, Y - c / 2);
    int cost = a * A + b * B + c * C;
    res = min(res, cost);
  }

  cout << res << endl;
  return 0;
}
