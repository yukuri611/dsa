#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, Q; cin >> N >> Q;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  

  vector<int> S1(N + 1); //S1[i] = 0からi-1までの和
  S1[0] = 0;
  for (int i = 1; i < N + 1; ++i) {
    S1[i] = S1[i - 1] + A[i - 1];
  }
  vector<int> S2(N + 1); //S2[i] = 
  S2[0] = 0;
  for (int i = 1; i < N + 1; ++i) {
    S2[i] = S2[i-1] + S1[i-1];
  }

  vector<LL> res_list;
  for (int i = 0; i < Q; ++i) {
    int L, R; cin >> L >> R;
    LL res = 

  }



}
