#include <vector>
#include <iostream>

using namespace std;
int dfs(int D, int G, vector<int>& p, vector<int>& c, int index, int count, int sum, int remain_index) {
  if (index == D) {
    int need = 0;
    if (G > sum) {
      if (remain_index == -1) {
        return 10001;
      }
      need = ((G - sum) + 100 * (remain_index + 1) - 1) / (100 * (remain_index + 1));
      if (need >= p[remain_index]) {
        return 10001;
      }
    }
    return count + need;
  }

  return min(dfs(D, G, p, c, index + 1, count, sum, index), dfs(D, G, p, c, index + 1, count + p[index], sum + 100 * (index+1) * p[index] + c[index], remain_index));
}


int main() {
  int D, G;
  cin >> D >> G;
  vector<int> p(D, 0);
  vector<int> c(D, 0);
  for (int i = 0; i < D; i++) {
    cin >> p[i] >> c[i];
  }

  int count = dfs(D, G, p, c, 0, 0, 0, -1);

  cout << count << endl;

  return 0;
}
