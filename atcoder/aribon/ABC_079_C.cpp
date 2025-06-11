#include <iostream>

using namespace std;
void dfs(string&, char (&)[3], int, int, bool*);
int main() {
  string input_num;
  cin >> input_num;
  char ops[3];
  bool found = false;
  dfs(input_num, ops, input_num[0]-'0', 1, &found);
  if (found) {
    for (int i = 0; i < 3; i++) {
      cout << input_num[i] << ops[i];
    }
    cout << input_num[3] << "=7" << endl;
  }
  return 0;
}

void dfs(string& num, char (&ops)[3], int cur_sum, int index, bool *found) {
  if (*found) {
    return;
  }
  if (index == 4) {
    *found = (cur_sum == 7);
    return;
  }
  ops[index-1] = '+';
  dfs(num, ops, cur_sum + num[index] - '0', index + 1, found);
  if (!*found) {
    ops[index-1] = '-';
    dfs(num, ops, cur_sum - (num[index] - '0'), index + 1, found);
  }
}
