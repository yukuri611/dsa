#include <iostream>
#include <vector>

using namespace std;

struct Node {
  int count;
  vector<Node*> children;
  Node(int count): count(count) {}
};

void dfs(Node &p, int x) {
  p.count += x;
  for (Node* child: p.children) {
    dfs(*child, x);
  }
  return;
}
int main() {
  int N, Q; cin >> N >> Q;
  vector<Node> tree(N + 1, Node(0));
  for (int i = 0; i < N-1; ++i) {
    int a, b; cin >> a >> b;
    tree[a].children.push_back(&tree[b]);
  }

  for (int i = 0; i < Q; ++i) {
    int p, x; cin >> p >> x;
    dfs(tree[p], x);
  }

  for (int i = 1; i < N + 1; ++i) {
    cout << tree[i].count << " ";
  }
  cout << endl;
  return 0;
}
