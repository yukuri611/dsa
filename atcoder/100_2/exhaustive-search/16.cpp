#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

bool isSame(vector<int>& A, vector<int>& B) {
    if (A.size() != B.size()) return false;
    rep(i, A.size()) {
        if (A[i] != B[i]) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> P(N);
    rep(i, N) cin >> P[i];
    vector<int> Q(N);
    rep(i, N) cin >> Q[i];

    vector<int> permu(N);
    iota(permu.begin(), permu.end(), 1);
    int a, b;
    int cnt = 0;
    do {
        if (isSame(permu, P)) {
            a = cnt;
        }
        if (isSame(permu, Q)) {
            b = cnt;
        }
        cnt++;
    } while (next_permutation(permu.begin(), permu.end()));

    cout << abs(a - b) << endl;
    return 0;
}
