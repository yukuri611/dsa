#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int P[8] = {0, 1, 2, 3, 4, 5, 6, 7};

int main() {
  int N; cin >> N;
  vector<int> x(N), y(N);
  for (int i = 0; i < N; ++i) cin >> x[i] >> y[i];
  
  double total_dist = 0;
  int path_count = 0;
  do {
    for (int i = 0; i < N-1; ++i) {
      total_dist += pow(pow(x[P[i]] - x[P[i+1]], 2) + pow(y[P[i]] - y[P[i+1]], 2), 0.5);
    }
    path_count++;
  } while(next_permutation(P, P+N));
  double average_dist = total_dist / path_count;
  cout << setprecision(11) <<  average_dist << endl;
  return 0;
}
