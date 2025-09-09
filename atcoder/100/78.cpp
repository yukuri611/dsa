#include <bits/stdc++.h>

using namespace std;

int main() {
  int M, N; cin >> M >> N;
  int K; cin >> K;
  vector<vector<char>>map(M + 1, vector<char>(N + 1));
  for (int i = 1; i < M + 1; ++i) {
    string s; cin >> s;
    for (int j = 1; j < N + 1; ++j) map[i][j] = s[j - 1];
  }

  vector<vector<int>> countj (M + 1, vector<int>(N + 1, 0));
  vector<vector<int>> counto (M + 1, vector<int>(N + 1, 0));
  vector<vector<int>> counti (M + 1, vector<int>(N + 1, 0));

  for (int i = 1; i < M + 1; ++i) {
    for (int j = 1; j < N + 1; ++j) {
      countj[i][j] = countj[i-1][j] + countj[i][j-1] - countj[i-1][j-1];
      counto[i][j] = counto[i-1][j] + counto[i][j-1] - counto[i-1][j-1];
      counti[i][j] = counti[i-1][j] + counti[i][j-1] - counti[i-1][j-1];
      if (map[i][j] == 'J') countj[i][j]++;
      if (map[i][j] == 'O') counto[i][j]++;
      if (map[i][j] == 'I') counti[i][j]++;
    }
  }

  vector<vector<int>> res_list(K, vector<int>(3));

  for (int k = 0; k < K; ++k) {
    int a, b, c, d; cin >> a >> b >> c >> d;
    int j = countj[c][d] - countj[a-1][d] - countj[c][b-1] + countj[a-1][b-1];
    int o = counto[c][d] - counto[a-1][d] - counto[c][b-1] + counto[a-1][b-1];
    int i = counti[c][d] - counti[a-1][d] - counti[c][b-1] + counti[a-1][b-1];
    res_list[k][0] = j;
    res_list[k][1] = o;
    res_list[k][2] = i;
  }

  for (int i = 0; i < K; ++i) {
    cout << res_list[i][0] << " " << res_list[i][1] << " " << res_list[i][2] << endl;
  }

  return 0;
}
