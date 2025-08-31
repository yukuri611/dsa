#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  int N; cin >> N;
  vector<int> H(N), S(N);
  for (int i = 0; i < N; ++i) cin >> H[i] >> S[i];
  
  long long l = 0; long long r = pow(10, 15);

  while(l < r) {
    long long mid = (r - l) / 2 + l;
    bool ok = true;
    vector<long long> t(N);
    for(int i = 0; i < N; ++i) {
      if (H[i] > mid) ok = false;
      t[i] = (mid - H[i])/ S[i];
    }
    sort(t.begin(), t.end());
    for (int i = 0;  i < N; ++i) {
      if (t[i] < i) ok = false;
    }
    if (ok) r = mid;
    else l = mid + 1;
  }

  cout << r << endl;
  return 0;


}
