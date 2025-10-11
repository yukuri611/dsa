#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int digitSum(int n) {
    int res = 0;
    while (n > 0) {
        res += n % 10;
        n /= 10;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> A(N + 1);
    A[0] = 1;
    A[1] = 1;
    for (int i = 1; i < N; ++i) {
        A[i + 1] = A[i] + digitSum(A[i]);
    }

    cout << A[N] << endl;
    return 0;
}
