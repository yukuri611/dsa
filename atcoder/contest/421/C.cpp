#include <iostream>

using namespace std;

int main() {
  int N; cin >> N;
  string S; cin >> S;
  long long res1 = 0;
  for (int i = 0; i < 2*N; ++i) {
    char curr_char = (i % 2) ? 'B': 'A';
    if (S[i] == curr_char) continue;
    int j;
    for (j = i + 1; j < 2 * N ; j++) {
      if ((i % 2 && S[j] == 'B') || (!(i%2) && S[j] == 'A')) break;
    }
    S[j] = S[i];
    S[i] = curr_char;
    res1 += j - i;
  }

  long long res2 = 0;
  for (int i = 0; i < 2*N; ++i) {
    char curr_char = (i % 2) ? 'A': 'B';
    if (S[i] == curr_char) continue;
    int j;
    for (j = i + 1; j < 2 * N ; j++) {
      if ((i % 2 && S[j] == 'A') || (!(i%2) && S[j] == 'B')) break;
    }
    S[j] = S[i];
    S[i] = curr_char;
    res2 += j - i;
  }


  cout << min(res1, res2) << endl;

  return 0;

}
