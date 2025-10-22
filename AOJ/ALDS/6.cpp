#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    int cnt = 0;
    rep(i, N) {
        int minIndex = i;
        for (int j = i; j < N; ++j) {
            if (A[minIndex] > A[j]) minIndex = j;
        }
        if (i != minIndex) {
            swap(A[i], A[minIndex]);
            cnt++;
        }
    }

    rep(i, N) {
        cout << A[i];
        if (i != N - 1) cout << " ";
    }
    cout << endl;
    cout << cnt << endl;
    return 0;
}
