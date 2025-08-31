#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int N; cin >> N;
  vector<int> A(N);
  for(int i = 0; i < N; ++i) cin >> A[i];
  vector<int> B(N);
  for(int i = 0; i < N; ++i) cin >> B[i];
  vector<int> C(N);
  for(int i = 0; i < N; ++i) cin >> C[i];
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  sort(C.begin(), C.end());

  vector<long long> countB(N);
  for (int i = 0; i < N; ++i) {
    int b = B[i];
    int j = upper_bound(C.begin(), C.end(), b) - C.begin();
    countB[i] = N - j;
  }
  for (int i = N-2; i > -1; --i) {
    countB[i] += countB[i + 1];
  }

  long long res = 0;
  for(int i = 0; i < N; ++i) {
    int a = A[i];
    int j = upper_bound(B.begin(), B.end(), a) - B.begin();
    res += countB[j];
  }

  cout << res << endl;
  return 0;

}
