#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, A, B; cin >> N >> A >> B;
  if (N % (A + B) == 0 || N % (A + B) > A) {
    cout << "Bug" << endl;
  }
  else {
    cout << "Ant" << endl;
  }
  return 0;
}
  