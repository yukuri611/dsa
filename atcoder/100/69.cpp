#include <iostream>
#include <cmath>
#include <vector>


using namespace std;

int n = pow(10,5);
int main() {
  vector<int> isPrime(n + 1, true);
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i <= sqrt(n); ++i) {
    if (isPrime[i]) {
      for (int k = 2; i * k < n + 1; k++) {
        isPrime[i * k] = false;
      }
    }
  }

  vector<int> count(n + 1, 0);
  for(int i = 2; i < n + 1; ++i) {
    count[i] = count[i - 1];
    if (isPrime[i] && isPrime[(i + 1)/2]) count[i]++;
  }
  vector<int> res_list;
  int Q; cin >> Q;
  for (int i = 0; i < Q; ++i) {
    int l, r; cin >> l >> r;
    res_list.push_back(count[r] - count[l - 1]);
  } 

  for (int res: res_list) cout << res << endl;
  return 0;
}
