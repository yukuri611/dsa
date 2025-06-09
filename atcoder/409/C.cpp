#include <unordered_map>
#include <iostream>

using namespace std;
int main() {
  int N, L;
  cin >> N >> L;

  unordered_map<int, long long int> counter;
  int curr_pos = 0;
  counter[0] = 1;

  for (int i = 1; i < N; i++) {
    int d_i;
    cin >> d_i;
    curr_pos = (curr_pos + d_i) % L;
    counter[curr_pos] += 1;
  }

  if (L % 3 != 0) {
    cout << 0 << endl;
    return 0;
  }

  long long int res = 0;
  for (int i = 0; i < L / 3; i++) {
    res += counter[i] * counter[i + L / 3] * counter[i + 2 * L / 3];
  }
  cout << res << endl;
  return 0;
}
