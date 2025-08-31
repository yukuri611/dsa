#include <map>
#include <iostream>

using namespace std;

int main() {
  int N; cin >> N;
  map<int, string> m;
  for (int i = 1; i < N + 1; i++) {
    string s; cin >> s;
    m[i] = s;
  }

  int x; string y; cin >> x >> y;
  if (m[x] == y) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
