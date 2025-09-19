#include <bits/stdc++.h>

using namespace std;

int main() {
  int N; cin >> N;
  int minR = INT_MAX; int maxR = INT_MIN; int minC = INT_MAX; int maxC = INT_MIN;
  for (int i = 0; i < N; ++i) {
    int r, c; cin >> r >> c;
    minR = min(r, minR);
    maxR = max(r, maxR);
    minC = min(c, minC);
    maxC = max(c, maxC);
  } 
  int max_dist = max(maxR - minR, maxC - minC);
  cout << (max_dist + 1)/ 2 << endl;
  return 0;
}
