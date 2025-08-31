#include <iostream>
#include <vector>

using namespace std;

pair<int, int> move(char ch, int l, int r, int c){
  if (ch == 'U') return {r - l, c};
  if (ch == 'D') return {r + l, c};
  if (ch == 'R') return {r, c + l};
  if (ch == 'L') return {r, c - l};
}

int main() {
  long long R_t, C_t, R_a, C_a; cin >> R_t >> C_t >> R_a >> C_a;
  long long N, M, L; cin >> N >> M >> L;
  vector<char> S(M);
  vector<long long> A(M);
  for (int i = 0; i < M; ++i) {
    cin >> S[i] >> A[i];
  }
  vector<char> T(L);
  vector<long long> B(L);
  for (int i = 0; i < L; ++i) {
    cin >> T[i] >> B[i];
  }

  int s_i, t_i; s_i = 0; t_i = 0;
  int s_count = 0, t_count = 0;
  
  while(s_count != N && t_count != N) {
    if (s_count < t_count) {
      pair<int, int> next = move(S[s_i], A[s_i], R_t, C_t);
      R_t = next.first; C_t = next.second;
      
    }
  }
}
