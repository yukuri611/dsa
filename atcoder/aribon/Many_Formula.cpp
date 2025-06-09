#include <iostream>
#include <string>
#define LL long long int

using namespace std;
LL dfs(string& S, LL sum, int start, int end) {
  if (end == S.size()-1) {
    sum += stoll(S.substr(start, end - start + 1));
    return sum;
  }
  else {
    LL total_sum = dfs(S, sum, start, end+1);
    sum += stoll(S.substr(start, end - start + 1));
    total_sum += dfs(S, sum, end+1, end+1);
    return total_sum;
  }
}

int main() {
  string S;
  cin >> S;
  LL res = dfs(S, 0, 0, 0);
  cout << res << endl;
  return 0;
}
