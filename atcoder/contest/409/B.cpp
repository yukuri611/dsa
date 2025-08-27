#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
int main() {
  int N;
  cin >> N;
  unordered_map<long long int, int> map;
  for (int i = 0; i < N; i++) {
    long long int curr;
    cin >> curr;
    map[curr] += 1;
  }

  vector<long long int> cand;
  for (const auto& pair: map) {
    cand.push_back(pair.first);
  }
  sort(cand.begin(), cand.end());

  int curr_count = N;
  int res = -1;
  for (size_t i = 0; i < cand.size(); i++) {
    if (curr_count >= cand[i]) {
      res = cand[i];
      curr_count -= map[cand[i]];
    }
    else {
      res = max(res, curr_count);
      break;
    }
  }
  cout << res << endl;
  return 0;
}
