#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int permutation[8] = {1, 2, 3, 4, 5, 6, 7, 8};

int main() {
  int N; cin >> N;
  vector<int> P(N), Q(N);
  for (int i = 0; i < N; ++i) cin >> P[i];
  for (int i = 0; i < N; ++i) cin >> Q[i];

  int count = 1;
  int countP, countQ;
  do {
    bool valid = true;
    for (int i = 0; i < N; ++i) {
      if (P[i] != permutation[i]) valid = false;
    }
    if (valid) countP = count;
    valid = true;
    for (int i = 0; i < N; ++i) {
      if (Q[i] != permutation[i]) valid = false;
    }
    if (valid) countQ = count;
    count++;
  } while(next_permutation(permutation, permutation + N));

  cout << abs(countP - countQ) << endl;
  return 0;
}
