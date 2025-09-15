#include <vector>
#include <iostream>

using namespace std;

bool check(string s) {
  int count = 0;
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == '(') count++;
    else {
      count--;
      if (count < 0) return false;
    }
  }
  return count == 0;
}

int main() {
  int N; cin >> N;
  if (N % 2 == 1) return 0;
  
  vector<string> res_list;

  for (int i = 0; i < (1 << N); ++i) {
    //0が(, 1が)
    string s = "";
    for (int j = N - 1; j >= 0; --j) {
      if (i & (1 << j)) s += ")";
      else s += "(";
    }
    if (check(s)) res_list.push_back(s);
  }
  for (string res: res_list) cout << res << endl;
  return 0;

}
