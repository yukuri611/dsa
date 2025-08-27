#include <iostream>
#include <vector>
#include <climits>

using namespace std;
int main () {
  int N;
  cin >> N;
  vector<long long> A(N), B(N);
  for (int i = 0; i < N; ++i) cin >> A[i] >> B[i];
  vector<long long> candid(2 * N);
  for (int i = 0; i < N; ++i) {
    candid[i] = A[i];
    candid[N + i] = B[i];
  }

  long long res = LLONG_MAX;
  for (int in_id = 0; in_id < 2 * N; ++in_id) {
    for (int out_id = in_id; out_id < 2 * N; ++out_id) {
      long long temp = 0;
      for (int i = 0; i < N; ++i) {
        long long distance = min(abs(candid[in_id] - A[i])+ abs(candid[out_id] - B[i]), abs(candid[in_id] - B[i])+ abs(candid[out_id] - A[i])) + abs(A[i] - B[i]);
        temp += distance;
      }
      res = min(res, temp);
    }
  }

  cout << res << endl;
  return 0;

}
