#include <iostream>
#include <vector>

using namespace std;

int main(){
  int N, Q; cin >> N >> Q;
  string S; cin >> S;
  vector<int> s(N, 0);
  for (int i = 1; i < N; ++i) {
    if (S[i] == 'C' && S[i-1] == 'A') s[i] = s[i-1] + 1;
    else s[i] = s[i-1];
  }
  vector<int> res(Q);
  for (int i = 0; i < Q; ++i) {
    int l, r; cin >> l >> r; l--; r--;
    if (l == 0) res[i] = s[r];
    else res[i] = s[r] - s[l];
  }

  for (int i = 0; i < Q; ++i) {
    cout << res[i] << endl;
  }

  return 0;
}
