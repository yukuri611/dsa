#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int main() {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    string T;

    rep(i, N) {
        int currCh = S[i];
        while (K - T.size() < N - i && T.size() > 0 && T.back() > currCh) {
            T.pop_back();
        }
        if (T.size() < K) T.push_back(currCh);
    }
    cout << T << endl;
    return 0;
}
