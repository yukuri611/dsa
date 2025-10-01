#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  int N; cin >> N;
  vector<int> A(N);
  bool valid = true;
  for (int i = 0; i < N; ++i) {
    int a; cin >> a;
    A[i] = a;
  }

  vector<bool> found(N + 1, false);
  for (int i = 0; i < N; ++i) {
    int a = A[i];
    if (a == -1) continue;
    if (found[a]) {
      valid = false;
    }
    else {
      found[a] = true;
    }
  }

  if (!valid) {
    cout << "No" << endl;
    return 0;
  }

  vector<int> notFound;
  for (int i = 1; i < N + 1; ++i) {
    if (!found[i]) notFound.push_back(i);
  }

  vector<int> P(N);
  int j = 0;
  for (int i = 0; i < N; ++i) {
    if (A[i] == -1) {
      P[i] = notFound[j];
      j++;
    }
    else {
      P[i] = A[i];
    }
  }

  cout << "Yes" << endl;
  for (int p: P) cout << p << " ";
  cout << endl;

  return 0;
}
