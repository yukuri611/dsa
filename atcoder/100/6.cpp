#include <iostream>
#include <string>
#include<cmath>
using namespace std;

int main() {
  int N; string S; cin >> N >> S;

  int res = 0;
  for (int n = 0; n < 1000; n++) {
    int digits[3];
    for (int i = 0; i < 3; ++i) {
      digits[2-i] = (n / int(pow(10, i))) % 10;
    }
    int curr_digit = 0;
    for(int i = 0; i < S.length(); ++i) {
      if (digits[curr_digit] == (S[i] - '0')) {
        curr_digit++;
      }
    }
    if (curr_digit == 3) res++;
  }
  cout << res << endl;
  return 0;
}
