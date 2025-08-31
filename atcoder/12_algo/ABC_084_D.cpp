#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(int x) {
  for (int i = 2; i <= sqrt(x); i++) {
    if (!(x % i)) return false;
  }
  return true;
}
int main() {
  vector<int> sum(100001, 0);
  sum[3] = 1;
  for (int i = 4;i < sum.size(); ++i) {
    sum[i] = sum[i-1];
    if (isPrime(i) && isPrime((i + 1)/2)) sum[i]++;
  }

  int Q; cin >> Q;
  
  vector<int> res_list(Q);
  for (int _ = 0; _ < Q; _++) {
    int l, r; cin >> l >> r;
    int res = sum[r] - sum[l - 1];
    res_list.push_back(res);
  }

  for (int res: res_list) cout << res << endl;
  return 0;

}
