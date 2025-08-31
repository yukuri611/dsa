#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> res;
  while (true) {
    int n, k; cin >> n >> k;
    if (n == 0 && k == 0) break;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    vector<int> sum(n+1); //sum[i] = i-1までの総和
    sum[0] = a[0];
    for (int i = 1; i < n + 1; ++i) {
      sum[i] = sum[i-1] + a[i-1];
    }

    int maximum = 0;
    for (int i = k; i < n + 1; ++i) {
      maximum = max(maximum, sum[i] - sum[i - k]);
    }
    res.push_back(maximum);
  }
  for (int r: res) cout << r << endl;
  return 0;
}
