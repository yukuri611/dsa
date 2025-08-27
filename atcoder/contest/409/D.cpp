#include <iostream>

using namespace std;
int main() {
  int T;
  cin >> T;
  for (int _ = 0; _ < T; _++) {
    int N;
    string S;
    cin >> N >> S;
    string res = S;
    for (int i = 0; i < N-1; i++) {
      if (S[i] > S[i+1]) {
        //rotationが発生
        int start = i;
        int end = N-1;
        for (int j = i+2; j < N; j++) {
          if (S[i] < S[j]) {
            end = j-1;
            break;
          }
        }
        for (int k = start; k < end; k++) {
          res[k] = res[k+1];
        }
        res[end] = S[start];
        break;
      }
    }
    cout << res << endl;
  }
  return 0;
}
