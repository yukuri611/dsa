#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int N, M; cin >> N >> M;
  vector<vector<bool>> graph(N + 1, vector<bool>(N+1, false));
  for (int i = 0; i < M; ++i) {
    int a, b; cin >> a >> b;
    graph[a][b] = true;
    graph[b][a] = true;
  }

  int permutation[N]; // 1 ~ Nまで
  for (int i = 0; i < N; i++) permutation[i] = i + 1;
  int res = 0;
  do {
    bool valid = true;
    for (int i = 0; i < N-1; ++i) {
      if (!graph[permutation[i]][permutation[i+1]]) valid = false;
    }
    if (valid) res++;
  } while (next_permutation(permutation + 1, permutation + N));

  cout << res << endl;


}
