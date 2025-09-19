#include <bits/stdc++.h>

using namespace std;

int main() {
  map<string, string> M;
  M["red"] = "SSS";
  M["blue"] = "FFF";
  M["green"] = "MMM";
  string S; cin >> S;
  if (M.count(S) != 0) {
    cout << M[S] << endl;
  }
  else cout << "Unknown" << endl;
  return 0;

}
