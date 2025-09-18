#include <bits/stdc++.h>

using namespace std;

void generate_sums_bitmask(int s, int e, const vector<long long> &a, vector<vector<long long>> &sums) {
  //sからe-1まで。
  int n = e - s;
  for (int i = 0; i < (1 << n); ++i) {
    long long curr_sum = 0;
    int count = 0;
    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        curr_sum += a[s + j];
        count++;
      }
    }
    sums[count].push_back(curr_sum);
  }
}

int main() {
  int N, K;
  long long L, R;
  cin >> N >> K >> L >> R;

  // N枚のコインの値段 a_i を入力
  vector<long long> a(N);
  for (int i = 0; i < N; ++i) {
      cin >> a[i];
  }

  int n1 = N / 2;
  int n2 = N - n1;
  vector<vector<long long>> sum1(n1 + 1);
  generate_sums_bitmask(0, n1, a, sum1);
  vector<vector<long long>> sum2(n2 + 1);
  generate_sums_bitmask(n1, N, a, sum2);

  for (auto & v: sum2) {
    sort(v.begin(), v.end());
  }
  long long ans = 0;
  for (int i = 0; i <= n1; ++i) {
    int j = K - i;
    if (j < 0 || j > n2) continue;
    for (long long s1: sum1[i]) {
      long long l = L - s1;
      long long r = R - s1;
      auto it_l = lower_bound(sum2[j].begin(), sum2[j].end(), l);
      auto it_r = upper_bound(sum2[j].begin(), sum2[j].end(), r);
      ans += it_r - it_l;
    }
  }

  cout << ans << endl;
  return 0;

}
