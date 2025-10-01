#include <bits/stdc++.h>

using namespace std;
using LL = long long;
int main() {
  LL N, K; cin >> N >> K;
  vector<LL> A(N), B(N), C(N); //待ち行列に加わる時間、出ていくのにかかる時間、人数
  for (int i = 0; i < N; ++i) {
    cin >> A[i] >> B[i] >> C[i];
  }

  vector<LL> res;
  priority_queue<pair<LL, int>, vector<pair<LL, int>>, greater<pair<LL, int>>> pq;
  int c = 0;
  LL t = 0;
  for (int i = 0; i < N; ++i) {
    t = max(t,A[i]);
    while (!pq.empty() && pq.top().first <= t) {
      //新しく行列に並ぶ前に出ていく客を一掃する
      c -= pq.top().second;
      pq.pop();
    }
    if(c + C[i] <= K) {
      //人数制限を満たすので入場できる。
      LL exit_time = t + B[i];
      res.push_back(t);
      pq.push({exit_time, C[i]});
      c += C[i];
    } 
    else {
      //十分な人数の団体が出てくるまで待つ
      while (c + C[i] > K) {
        auto p = pq.top();
        pq.pop();
        t = p.first;
        c -= p.second;
      }
      LL exit_time = t + B[i];
      res.push_back(t);
      pq.push({exit_time, C[i]});
      c += C[i];
    }
  }

  for (LL r: res) cout << r << endl;
  return 0;
}
