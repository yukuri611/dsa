#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N, A, B; cin >> N >> A >> B;
  string S; cin >> S;
  cout << S.substr(A, N - A - B) << endl;
  return 0;
}
