#include <iostream>
#include <vector>

using namespace std;
using Field = vector<vector<int> >;


void rec(Field &field, vector<Field> &res) {
  // finding empty space
  int emptyi = -1, emptyj = -1;
  for (int i = 0; i < 9 && emptyi == -1; ++i) {
    for (int j = 0; j < 9 && emptyj == -1; ++j) {
      if (field[i][j] == -1) {
        emptyi = i, emptyj = j;
        break;
      }
    }
  }

  if (emptyi == -1 || emptyj == -1) {
    res.push_back(field);
    return;
  }

  vector<bool> valid(10, true);
  for (int i = 0; i < 9; ++i) {
    if (field[emptyi][i] != -1) valid[field[emptyi][i]] = false;
    if (field[i][emptyj] != -1) valid[field[i][emptyj]] = false;
  }

  int bi = (emptyi / 3) * 3 + 1, bj = (emptyj / 3) * 3 + 1;
  for (int i = -1; i <= 1; ++i) {
    for (int j = -1; j <= 1; ++j) {
      if (field[bi + i][bj + j] != -1) valid[field[bi+i][bj+j]] = false;
    }
  }

  for (int i = 1; i <= 9; i++) {
    if (!valid[i]) continue;
    field[emptyi][emptyj] = i;
    rec(field, res);
  }

  field[emptyi][emptyj] = -1;
}

int main() {
  Field field(9,vector<int>(9,-1));
  for (int i = 0; i < 9; ++i) {
    string line; cin >> line;
    for (int j = 0; j < 9; ++j) {
      if (line[j] == '*') continue;
      field[i][j] = line[j] - '0';
    }
  }

  vector<Field> res;
  rec(field, res);
  if (res.size() == 0) cout << "no solutions." << endl;
  else if (res.size() > 1) cout << "more than one solutions." << endl;
  else {
      Field ans = res[0];
      for (int i = 0; i < 9; ++i) {
          for (int j = 0; j < 9; ++j) {
              cout << ans[i][j] << " ";
          }
          cout << endl;
      }
  }

}
