#include <bits/stdc++.h>

using namespace std;

double f(double x, double P) {
  return x + P/pow(2, x/1.5);
}

double fprime(double x, double P) {
  return 1 - P * log(2) / 1.5 * pow(2,-x/1.5);
}

int main() {
  double P; cin >> P;

  double l, r; l = 0; r = P;
  while ((r - l) > pow(10,-8)) {
    double mid = (r - l) / 2 + l;
    if (fprime(mid, P) < 0) l = mid;
    else r = mid;
  }

  cout << fixed << setprecision(9) << f(l, P) << endl;
  return 0;
}
