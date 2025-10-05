#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int main() {
    int N, L;
    cin >> N >> L;
    int K;
    cin >> K;
    vector<int> A(N + 1);
    A[0] = 0;
    rep(i, N) cin >> A[i + 1];

    int l = -1;
    int r = L + 1;
    while (r - l > 1) {
        int mid = (r - l) / 2 + l;
        int prev = 0;
        bool valid = true;
        rep(j, K) {
            int curr = prev + 1;
            while (curr < N && A[curr] - A[prev] < mid) {
                curr++;
            }
            if (curr == N + 1) {
                valid = false;
                break;
            }
            prev = curr;
        }
        valid = valid && (L - A[prev] >= mid);
        if (valid) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << l << endl;
    return 0;
}
