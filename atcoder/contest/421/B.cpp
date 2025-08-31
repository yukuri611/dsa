#include <iostream>
#include <vector>

using namespace std;

long long rev(long long x) {
  long long res = 0;
  while(x) {
    res *= 10;
    res += x % 10;
    x /= 10;
  }
  return res;
}

int main() {
  int X, Y; cin >> X >> Y;
  vector<long long> res_list(10);
  res_list[0] = X, res_list[1] = Y;
  for (int i = 2; i < 10; i++) {
    res_list[i] = rev(res_list[i-1] + res_list[i-2]);
  }
  cout << res_list[9] << endl;
  return 0;
}
