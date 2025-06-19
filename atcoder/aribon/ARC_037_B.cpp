#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;
int main() {
  int N, M;
  cin >> N >> M;
  unordered_map<int, vector<int>> neighbors;
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    neighbors[u].push_back(v);
    neighbors[v].push_back(u);
  }

  int res = 0;
  unordered_set<int> visited;  
  for (int n = 1; n < N+1; n++) {
    queue<pair<int, int>> q;
    q.push({n, 0});
    bool isTree = true;
    while(!q.empty()) { 
      auto& [curr_n, parent] = q.front();
      if (visited.count(curr_n)) {
        isTree = false;
        break;
      }
      for (int nei: neighbors[curr_n]){
        if (nei == parent) {
          continue;
        }
        q.push({nei, curr_n});
      }
      visited.insert(curr_n);
      q.pop();
    }
    if (isTree) {
      res += 1;
    }
  }

  cout << res << endl;
  return 0;

}
