#include <bits/stdc++.h>

using namespace std;

int main() {
  int n; cin >> n;
  
  vector<int> res;
  int curr = n;
  for (int i = 2; curr > 1 && i <= sqrt(n); ++i) {
    while (curr % i == 0) {
      res.push_back(i);
      curr /= i;
    }
  }
  if (curr != 1) res.push_back(curr);
  cout << n << ":";
  for (int r: res) {
    cout << " " << r;
  }
  cout << endl;
  return 0;
}
