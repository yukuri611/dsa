#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N; cin >> N;
  string S; cin >> S;
  string res;
  if (S.size() < 3) {
    res = "No";
  }
  else {
    if (S[N -3] !='t' || S[N - 2] != 'e' || S[N-1] != 'a') {
      res = "No";
    }
    else {
      res = "Yes";
    }
  }

  cout << res << endl;
  return 0;

}
