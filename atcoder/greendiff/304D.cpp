#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    int W, H;
    cin >> W >> H;
    int N;
    cin >> N;
    vector<int> P(N), Q(N);
    rep(i, N) cin >> P[i] >> Q[i];
    int Asize;
    cin >> Asize;
    vector<int> A(Asize + 1);
    A[0] = 0;
    rep(i, Asize) cin >> A[i + 1];
    int Bsize;
    cin >> Bsize;
    vector<int> B(Bsize + 1);
    B[0] = 0;
    rep(i, Bsize) cin >> B[i + 1];

    map<pair<int, int>, int> Map;

    rep(i, N) {
        int p = P[i], q = Q[i];
        int indexA = upper_bound(A.begin(), A.end(), p) - B.begin();
        int indexB = upper_bound(B.begin(), B.end(), q) - B.begin();
        Map[{indexA, indexB}]++;
    }

    int minimum = N, maximum = 0;
    for (auto [p, c] : Map) {
        minimum = min(minimum, c);
        maximum = max(maximum, c);
    }

    if (Map.size() < (Asize + 1) * (Bsize + 1)) minimum = 0;

    cout << minimum << " " << maximum << endl;
    return 0;
}
