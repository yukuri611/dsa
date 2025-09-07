#include <bits/stdc++.h>
using namespace std;

using LL = long long;

int main() {
  srand((unsigned)time(NULL));
  int N; cin >> N;
  vector<LL> X(N);
  vector<LL> Y(N);
  for (int i = 0; i < N; ++i) cin >> X[i] >> Y[i];

  for (int _ = 0; _ < 100; ++_) {
    int i = rand() % N;
    int j = rand() % N;
    if(i == j) continue;
    pair<LL, LL> vec_i_j = {X[i] - X[j], Y[i] - Y[j]};
    int count = 0;
    for (int k = 0; k < N; ++k) {
      pair<LL, LL> vec_i_k = {X[i] - X[k], Y[i] - Y[k]};
      if (vec_i_j.first * vec_i_k.second == vec_i_j.second * vec_i_k.first) {
        count++;
      }
    }
    if (count >= (N + 1) / 2) {
      cout << "Yes" << endl;
      LL x, y, c;
      if (vec_i_j.first == 0) {
        x = 1; y = 0; c = -X[i];
      }
      else if (vec_i_j.second == 0) {
        x = 0; y = 1; c = -Y[i];
      }
      else {
        x = vec_i_j.second; y = -vec_i_j.first; c = -vec_i_j.second * X[i] + vec_i_j.first * Y[i];
      }
      cout << x << " " << y << " " << c << endl;
      return 0;
    }
  }

  cout << "No" << endl;
  return 0;
}
