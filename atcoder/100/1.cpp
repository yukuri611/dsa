#include <iostream>
#include <climits>

using namespace std;

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  
  int res = INT_MAX;
  for (int c = 1; c <= 2 * X && c <= 2 * Y; ++c) {
    int a = X - c / 2;
    int b = Y - c / 2;
    int cost = a * A + b * B + c * C;
    res = max(res, cost);
  }

  cout << res << endl;
  return 0;
}
