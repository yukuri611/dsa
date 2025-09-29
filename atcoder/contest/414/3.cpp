#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll solve(vector<ll> &B, int A, ll N) {
  ll res = 0;
  for (ll boriginal: B) {
    ll b = boriginal;
    if (b > N) break;
    vector<int> temp;
    while(b > 0) {
      temp.push_back(b % A);
      b /= A;
    }
    int l = 0; int r = temp.size() -1;
    bool valid = true;
    while(l < r) {
      if (temp[l] != temp[r]) {
        valid = false;
        break;
      }
      l++;
      r--;
    }
    if (valid) res+=boriginal;
  }
  return res;
}

int main() {
  vector<ll> B;
  for (int k = 1; k < 1000000; ++k) {
    int n = k;
    int max_digit = 0;
    while (n > 0) {
      n /= 10;
      max_digit++;
    }
    n = k;
    vector<int> temp(max_digit);
    for (int i = 0; i < max_digit; ++i) {
      temp[max_digit - 1 - i] = n % 10;
      n /= 10;
    }
    string S;
    for (int i = 0; i < max_digit; ++i) {
      S += '0' + temp[i];
    }
    for (int i = max_digit - 1; i > -1; --i) {
      S += '0' + temp[i];
    }
    ll b = stoll(S);
    B.push_back(b);
  }
  for (int k = 0; k < 100000; ++k) {
    int n = k;
    int max_digit = 0;
    while (n > 0) {
      n /= 10;
      max_digit++;
    }
    n = k;
    vector<int> temp(max_digit);
    for (int i = 0; i < max_digit; ++i) {
      temp[max_digit - 1 - i] = n % 10;
      n /= 10;
    }

    for (int mid = 0; mid < 10; ++mid) {
      if (mid == 0 && k == 0) continue;
      string S;
      for (int i = 0; i < max_digit; ++i) {
        S += '0' + temp[i];
      }
      S += ('0' + mid);
      for (int i = max_digit - 1; i > -1; --i) {
        S += '0' + temp[i];
      }
      ll b = stoll(S);
      B.push_back(b);
    }
  }

  sort(B.begin(), B.end());

  int A; cin >> A;
  ll N; cin >> N;

  ll res = solve(B, A, N);

  cout << res << endl;
  return 0;
}
