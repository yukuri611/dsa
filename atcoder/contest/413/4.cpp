#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int T; cin >> T;
  vector<bool> res_list;
  for (int _ = 0; _ < T; ++_) {
    int N; cin >> N;
    vector<ll> A_decrease(N);
    vector<ll>A_increase(N);
    for (int i = 0; i < N; ++i) {
      ll a; cin >> a;
      A_decrease[i] = a;
      A_increase[i] = a;
    }

    sort(A_increase.begin(), A_increase.end(), [](ll a, ll b) {
      return abs(a) < abs(b);
    });
    sort(A_decrease.begin(), A_decrease.end(), [](ll a, ll b) {
      return abs(a) > abs(b);
    });

    
    bool valid = true;

    if (abs(A_increase[0]) == abs(A_increase[1])) {
      //全部同じあるいはマイナスプラスが同じだけ存在
      int c1 = 0; int c2 = 0;
      for (int i = 0; i < N; ++i) {
        if (A_increase[i] == A_increase[0]) c1++;
        else if (A_increase[i] == -A_increase[0]) c2++;
        else {
          valid = false;
          break;
        }
      }
      if (c1 != N && abs(c1 - c2) > 1) valid = false;  
      res_list.push_back(valid);
      continue;
    }

    for (int i = 2; i < N; ++i) {
      if ((A_increase[i - 1] * A_increase[1]) % A_increase[0] != 0) {
        valid = false;
        break;
      }
      if (A_increase[i] != (A_increase[i - 1] * A_increase[1]) / A_increase[0]) {
        valid = false;
        break;
      }
    }
    if (valid) {
      res_list.push_back(true);
      continue;
    }

    valid = true;
    for (int i = 2; i < N; ++i) {
      if ((A_decrease[i - 1] * A_decrease[1]) % A_decrease[0] != 0) {
        valid = false;
        break;
      }
      if (A_decrease[i] != (A_decrease[i - 1] * A_decrease[1]) / A_decrease[0]) {
        valid = false;
        break;
      }
    }
    res_list.push_back(valid);
  }

  for (bool res: res_list) {
    if (res) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}
