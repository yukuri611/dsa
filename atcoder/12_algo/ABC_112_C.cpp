#include <iostream> 
#include <vector>
#include <cmath>

using namespace std;

int main() { 
  int N;
  cin >> N;
  vector<int> x(N), y(N), h(N);
  for (int i = 0; i < N; ++i) cin >> x[i] >> y[i] >> h[i];

  
  bool detect = false;
  int res_h, res_x, res_y;
  for (int cx = 0; !detect && cx <= 100; ++cx) {
    for (int cy = 0; !detect && cy <=100; ++cy) {
      int H = -1;
      for (int i = 0; i < N; i++) {
        if(h[i]) H = h[i] + abs(x[i] - cx) + abs(y[i] - cy);
      }
      bool valid = true;
      for (int i = 0; i < N; i++) {
        if (h[i] != max(H - abs(x[i] - cx) - abs(y[i] - cy), 0)) {
            valid = false;
            break;
        }
      }
      if (valid) {
        cout << cx << " " << cy << " " << H << endl;
        return 0;
      }
    }
  }
}
