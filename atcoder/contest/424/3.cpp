#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  int N; cin >> N;
  vector<vector<int>> D(N + 1); //D[i] = iをa or bに持つスキル番号
  queue<int> q;
  vector<bool> seen(N + 1, false);
  for (int i = 1; i <= N; ++i) {
    int a, b; cin >> a >> b;
    if (a == 0 && b == 0) {
      q.push(i);
      seen[i] = true;
    }
    else{
      D[a].push_back(i);
      D[b].push_back(i);
    }
  }

  int count = 0;
  while(!q.empty()) {
    int s = q.front();
    q.pop();
    count++;
    for (int d: D[s]) {
      if (!seen[d]) {
        q.push(d);
        seen[d] = true;
      }
    }
  }

  cout << count << endl;
  return 0;

}
