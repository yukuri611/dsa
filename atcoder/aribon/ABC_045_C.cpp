#include <iostream>

using namespace std;

long long dfs(string S, int i, int l, long long curr) {
  if (i + l == S.length()) {
    return curr + stoll(S.substr(i, l));
  }

  return dfs(S, i + l, 1, curr + stoll(S.substr(i, l))) + dfs(S, i, l + 1, curr);

}


int main() {
  string S;
  cin >> S;
  long long res = dfs(S, 0, 1, 0);
  cout << res << endl;
  return 0;
}
