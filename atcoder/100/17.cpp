#include <bits/stdc++.h>

using namespace std;

bool check(vector<int> qr, vector<int> qc, int r, int c) {
  for (int i = 0; i < qr.size(); ++i) {
    if (qr[i] == r || qc[i] == c) return false;
    if (abs(qr[i] - r) == abs(qc[i] - c)) return false;
  }
  return true;
}

void print_grid(vector<int> qr, vector<int> qc) {
  for (int i = 0; i < 8; ++i) {
    string S;
    for (int j = 0; j < 8; ++j) {
      char c = '.';
      for (int k = 0; k < 8; ++k) {
        if (qr[k] == i && qc[k] == j) {
          c = 'Q';
          break;
        }
      }
      S += c;
    }
    cout << S << endl;
  }
}

int main() {
  int k; cin >> k;
  vector<int> qr(k), qc(k);
  for (int i = 0; i < k; ++i) {
    cin >> qr[i] >> qc[i];
  }
  vector<int> rR;
  vector<int> rC;
  for (int i = 0; i < 8; ++i) {
    bool validr = true;
    bool validc = true;
    for (int j = 0; j < k; ++j) {
      if (qr[j] == i) validr = false;
      if (qc[j] == i) validc = false;
    }
    if (validr) rR.push_back(i);
    if (validc) rC.push_back(i);
  }

  do {
    vector<int> curr_qr = qr;
    vector<int> curr_qc = qc;
    bool valid = true;
    for (int i = 0; i < rC.size(); ++i) {
      int r = rR[i]; int c = rC[i];
      if (!check(curr_qr, curr_qc, r, c)) {
        valid = false;
        break;
      }
      curr_qr.push_back(r);
      curr_qc.push_back(c);
    }
    if (valid) {
      print_grid(curr_qr, curr_qc);
      return 0;
    }
  } while(next_permutation(rC.begin(), rC.end()));
  
}
