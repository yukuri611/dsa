#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, M; cin >> N >> M;
  vector<int> points(N + 1,0);
  vector<string> S(N + 1);
  for (int i = 1; i <= N; ++i) {
    cin >> S[i];
  }

  for (int j = 0; j < M; ++j) {
    int count_1 = 0;
    for (int i = 1; i <= N; ++i) {
      if (S[i][j] == '1') count_1++;
    }
    int majority;
    if (count_1 > (N / 2)) {
      majority = 1;
    }
    else {
      majority = 0;
    }
    for (int i = 1; i <= N; ++i) {
      if (S[i][j] - '0' != majority) points[i]++;
    }
  }

  int maximum = 0;
  for (int i = 1; i <= N; ++i) {
    maximum = max(maximum, points[i]);
  }

  vector<int> res_list;
  for (int i = 1; i <= N; ++i) {
    if (points[i] == maximum) res_list.push_back(i);
  }

  for (int i = 0; i < res_list.size() - 1; ++i) {
    cout << res_list[i] << " ";
  }
  cout << res_list[res_list.size() - 1] << endl;
  return 0;
}
