#include <iostream>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm> // max を使うため

using namespace std;

int main() {
  int n;
  cin >> n;
  set<pair<int, int>> points;
  // vectorに座標を保存しておくと、インデックスでのアクセスが簡単
  vector<pair<int, int>> p_vec(n); 
  for (int i = 0; i < n; ++i) {
    cin >> p_vec[i].first >> p_vec[i].second;
    points.insert(p_vec[i]);
  }

  long long max_area = 0; // 面積は整数で、大きくなる可能性があるのでlong long

  // 2つの点P1, P2を総当たりで選ぶ
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      // P1 = (x1, y1), P2 = (x2, y2)
      int x1 = p_vec[i].first;
      int y1 = p_vec[i].second;
      int x2 = p_vec[j].first;
      int y2 = p_vec[j].second;

      // P1からP2へのベクトル(dx, dy)
      int dx = x2 - x1;
      int dy = y2 - y1;

      // 残りの2頂点P3, P4の候補を計算
      // ベクトル(dx, dy)を90度回転させると(-dy, dx)になる
      pair<int, int> p3 = {x1 - dy, y1 + dx};
      pair<int, int> p4 = {x2 - dy, y2 + dx};

      // P3とP4が両方とも点の集合に存在するか確認
      if (points.count(p3) && points.count(p4)) {
        // 面積を計算（辺の長さの2乗）
        long long area = (long long)dx * dx + (long long)dy * dy;
        if (area > max_area) {
          max_area = area;
        }
      }
    }
  }

  cout << max_area << endl;

  return 0;
}
