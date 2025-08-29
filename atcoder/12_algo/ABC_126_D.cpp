#include <iostream>
#include <vector>

using namespace std;

struct Edge {
  int v, w;
  Edge(int v, int w) : v(v), w(w) {}
};

bool dfs(vector<vector<Edge>> &g, vector<int> &color, int u) {
  for (Edge e: g[u]) {
    int v, w; v = e.v; w = e.w;
    if (color[v] == -1) {
      color[v] = (w%2) ? 1 - color[u] : color[u];
      if (!dfs(g, color, v)) return false;
    }
    else {
      if ((w % 2 && color[v] == color[u]) || (!(w % 2) && color[v] != color[u])) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  int N; cin >> N;
  vector<vector<Edge>> graph(N + 1);
  for (int i = 0; i < N-1; ++i) {
    int u, v, w; cin >> u >> v >> w;
    graph[u].push_back(Edge(v, w));
    graph[v].push_back(Edge(u, w));
  }

  vector<int> color(N + 1,-1);
  color[1] = 0;
  bool can_color = dfs(graph, color, 1);
  if (can_color) {
    for (int i = 1; i < N + 1; ++i) cout << color[i] << endl;
  }
  return 0;
}

