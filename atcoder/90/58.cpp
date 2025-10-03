#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int digitSum(int n) {
    int res = 0;
    while (n > 0) {
        res += (n % 10);
        n /= 10;
    }
    return res;
}

int main() {
#define int ll
    // input
    ll N, K;
    cin >> N >> K;

    // find loop
    int M = 100000;
    vector<int> memo(100001, -1);
    vector<int> A;
    int curr = N;
    memo[curr] = 0;
    A.push_back(curr);
    int start = 0;  // index where loop starts;
    int l;          // loop len.
    for (int i = 1; i < M + 1; ++i) {
        int next_num = (curr + digitSum(curr)) % M;
        if (memo[next_num] != -1) {
            start = memo[next_num];
            l = i - memo[next_num];
            break;
        } else {
            memo[next_num] = i;
            A.push_back(next_num);
            curr = next_num;
        }
    }

    if (start > K) {
        cout << A[K] << endl;
        return 0;
    }

    ll index_in_loop = (K - start) % l;
    ll final_index = start + index_in_loop;
    ll ans = A[final_index];
    cout << ans << endl;

    return 0;
}
