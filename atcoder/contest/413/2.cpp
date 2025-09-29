#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N; cin >> N;
  vector<string> S(N);
  for (int i = 0; i < N; ++i) cin >> S[i];
  set<string> stringset;
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      string concat1 = S[i] + S[j];
      stringset.insert(concat1);
      string concat2 = S[j] + S[i];
      stringset.insert(concat2);
    }
  } 

  cout << stringset.size() << endl; 
  return 0;
}
