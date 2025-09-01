#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool isprime(int x) {
  if (x == 2) return true;
  for (int i = 2; i <= sqrt(x); ++i) {
    if (x % i == 0) return false;
  }
  return true;
} 

int main() {
  vector<int> count(100001, 0);
  for (int i = 3; i < count.size(); ++i) {
    if (isprime(i) && isprime((i + 1) / 2)) count[i]++;
    count[i] += count[i-1];
  }
  int Q; cin >> Q;
  vector<int> res(Q);
  for (int i = 0; i < Q; ++i) {
    int l, r; cin >> l >> r;
    res[i] = count[r] - count[l - 1];
  }
  for (int i = 0; i < Q; ++i) cout << res[i] << endl;
  return 0;
}
