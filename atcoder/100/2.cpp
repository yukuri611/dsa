#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
  int N; cin >> N;
  vector<int> prime;
  for (int i = 3; i <= N; ++i) {
    bool isprime = true;
    for (int j = 2; j < i; ++j) {
      if (!(i%j)) isprime = false;
    }
    if (isprime) prime.push_back(i);
  }
  int l = prime.size();
  int res = 0;
  for (int i = 0; i < l; ++i) {
    for (int j = i + 1; j < l; ++j) {
      for (int k = j + 1; k < l; ++k) {
        if (prime[i] * prime[j] * prime[k] <= N) res++;
      }
    }
  }
  for (int i = 0; i < l; ++i) {
    for (int j = i + 1; j < l; ++j) {
      if (pow(prime[i], 3) * prime[j] <= N) res++;
      if (pow(prime[j], 3) * prime[i] <= N) res++;
    }
  }

  cout << res << endl;
  return 0;

}
