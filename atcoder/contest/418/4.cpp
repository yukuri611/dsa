#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N; cin >> N;
  string T; cin >> T;

  vector<int> Count(N + 1, 0);
  vector<int> evenCount(N + 1, 0);

  int c = 0;

  for (int i = 1; i < N + 1; ++i) {
    if (T[i - 1] == '0') c++;
    Count[i] = c;
    evenCount[i] = evenCount[i - 1];
    if ((c % 2) == 0) {
      evenCount[i]++;
    }
  }

  ll res = 0;
  for (int i = 1; i <= N; ++i) {
    //終わりのインデックスをi-1とする
    if (Count[i] % 2) {
      int odd = i - 1 - evenCount[i - 1];
      res += odd;
    }
    else {
      res += evenCount[i];
    }
  }

  cout << res << endl;
  return 0;
}
