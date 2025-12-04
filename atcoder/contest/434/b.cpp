#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(N);
    rep(i, N) {
        cin >> A[i] >> B[i];
        A[i]--;
    }

    vector<int> total_weights(M), cnts(M);
    rep(i, N) {
        int a = A[i];
        int b = B[i];
        total_weights[a] += b;
        cnts[a]++;
    }

    rep(i, M) {
        double average = (double)total_weights[i] / cnts[i];
        cout << fixed << setprecision(5) << average << endl;
    }
    return 0;
}
