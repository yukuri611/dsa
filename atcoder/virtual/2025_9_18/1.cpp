#include <bits/stdc++.h>

using namespace std;

int main() {
  int A, B, K; cin >> A >> B >> K;
  if (B - A + 2 <= 2 * K) {
    for (int i = A; i < B + 1; ++i) {
      cout << i << endl;
    }
  }
  else {
    for (int i = 0; i < K; ++i) {
      cout << A + i << endl;
    }
    for (int i = K - 1; i >= 0; --i) {
      cout << B - i << endl;
    }
  }

  return 0;
}
