#include <iostream>
#include <vector>

using namespace std;

int main(){
  int N; cin >> N;
  vector<vector<int>> D(N, vector<int>(N));
  for(int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) cin >> D[i][j];
  }

  vector<vector<int>> S(N+1, vector<int>(N+1)); //S[i + 1][j + 1] = (0,0)から(i, j)までの総和
  for (int i = 1; i < N+1; ++i) {
    for (int j = 1; j < N+1; ++j) {
      S[i][j] = S[i][j-1] + S[i-1][j] - S[i - 1][j - 1] + D[i-1][j-1];
    }
  }
  vector<int>val(N * N + 1, 0); //val[i] = 面積iの長方形の中で最大の合計値
  for (int x_1 = 0; x_1 < N; ++x_1) {
    for (int x_2 = x_1 + 1; x_2 <= N; ++x_2) {
      for (int y_1 = 0; y_1 < N; ++y_1) {
        for (int y_2 = y_1 + 1; y_2 <= N; ++y_2) {
          int area = (x_2 - x_1) * (y_2 - y_1);
          int sum = S[x_2][y_2] - S[x_2][y_1] - S[x_1][y_2] + S[x_1][y_1];
          val[area] = max(val[area], sum);
        }
      }
    }
  }
  for (int i = 0; i < val.size() - 1; ++i) {
    val[i + 1] = max(val[i], val[i + 1]); 
  }

  int Q; cin >> Q;
  vector<int> res(Q);
  for (int i = 0; i < Q; ++i) {
    int P; cin >> P;
    res[i] = val[P];
  }
  for (int r: res) cout << r << endl;
  return 0;
}
