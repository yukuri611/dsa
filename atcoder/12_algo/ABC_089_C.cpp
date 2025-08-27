#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  int N;
  cin >> N;
  unordered_map<char, long long> map;
  for (int i = 0; i < N; ++i) {
    string S;
    cin >> S;
    map[S[0]] += 1;
  }

  long long res = 0;
  string march = "MARCH";
  for (int i = 0; i < 5; ++i) {
    for (int j = i + 1; j < 5; ++j) {
      for (int k = j + 1; k < 5; ++k) {
        res += map[march[i]] * map[march[j]] * map[march[k]];
      }
    }
  }

  cout << res << endl;
  return 0;

}
