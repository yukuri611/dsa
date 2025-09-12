#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;
// M_PIを使った方がより高精度です
const double PI = acos(-1.0);

int main() {
    double a, b, x;
    cin >> a >> b >> x;

    double ans = 0.0;

    // x は水の体積なので、a*aで割ると、傾けない状態での水の高さになる
    double water_height = x / (a * a);

    if (water_height >= b / 2.0) {
        // 水が半分以上入っている場合
        // 空気の体積を考える
        // 空気の体積 = a*a*b - x
        // (a*a*b - x) = 1/2 * a * h * a  (hは空気部分の三角形の高さ)
        // h = 2 * (a*a*b - x) / (a*a)
        // tan(theta) = h / a
        double h = 2 * (a * a * b - x) / (a * a);
        ans = atan(h / a) * 180.0 / PI;
    } else {
        // 水が半分未満の場合
        // 水の体積を考える
        // x = 1/2 * w * b * a  (wは水面の横の長さ)
        // w = 2 * x / (a * b)
        // tan(theta) = b / w
        double w = 2 * x / (a * b);
        ans = atan(b / w) * 180.0 / PI;
    }

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}
