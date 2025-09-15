#include <bits/stdc++.h>

using namespace std;

struct Node {
  int num;
  int parent = -1;
  vector<int> children;
  Node(int n) : num(n) {}
};

int dfs(vector<Node> & tree, int n, int &maxLength) {
  //自分を含めたmaxHeightを返す。maxLengthを更新する。
  int maxHeight1 = 0; //一番高い
  int maxHeight2 = 0; //二番目に高い
  for(int child: tree[n].children) {
    int temp = dfs(tree, child, maxLength);
    if (temp > maxHeight2) maxHeight2 = temp;
    if (maxHeight2 > maxHeight1) swap(maxHeight1, maxHeight2);
  }
  int curr_length = maxHeight1 + maxHeight2 + 1;
  maxLength = max(maxLength, curr_length);
  return maxHeight1 + 1;
}

int main() {
  int N; cin >> N;
  vector<vector<int>> G(N);
  for (int i = 0; i < N - 1; ++i) {
    int a, b; cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  vector<Node> tree;
  for (int i = 0; i < N; ++i) {
    tree.push_back(Node(i)); 
  }

  queue<int> q;
  q.push(0);
  while(!q.empty()) {
    int n = q.front();
    q.pop();
    Node &curr_node = tree[n];
    for (int child: G[n]) {
      if (child == curr_node.parent) continue;
      curr_node.children.push_back(child);
      tree[child].parent = n;
      q.push(child);
    }
  }

  int maxLength=0;
  dfs(tree, 0, maxLength);
  cout << maxLength << endl;
  return 0;
}
