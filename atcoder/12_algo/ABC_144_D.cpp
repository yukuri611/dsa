#include <iostream>
#include <cmath>

using namespace std;

int main() {
  double A, B, X;
  cin >> A >> B >> X;

  double half = A * A * B / 2;
  double ans;

  if (X < half) ans = atan(A * B * B / (2.0 * X));
  else ans = atan((2.0 * B - 2.0 * X / (A * A)) / A);

  ans = ans / M_PI * 180;

  printf("%.10f\n", ans);
}
