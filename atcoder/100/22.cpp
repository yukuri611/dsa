#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


// 元の関数 (計算完了までの時間)
double f(double x, double P) {
    return x + P * pow(2.0, -x / 1.5);
}

int main() {
  double P; cin >> P;
  
  double l = 0, r = P;
  while (r - l > pow(10, -8)) {
    double c1 = (l + l + r) / 3;
    double c2 = (l + r + r) / 3;
    if (f(c1,P) > f(c2,P)) l = c1;
    else r = c2;
  }

  cout << fixed << setprecision(10) << f(l, P) << endl;
  return 0;
}
