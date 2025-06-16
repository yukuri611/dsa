#include <iostream>
#include <string>

using namespace std;
long long int dfs(string s, int l, int r, long long int sum) {
  if(r == s.size()-1) {
    return sum + stoll(s.substr(l, r-l+1));
  }
  return dfs(s, l, r+1, sum) + dfs(s, r+1, r+1, sum + stoll(s.substr(l, r - l + 1)));
}

int main() {
  string S;
  cin >> S;
  long long int sum = dfs(S, 0, 0, 0);
  cout << sum << endl;
  return 0;
}


