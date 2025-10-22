#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

bool isPrime(int n) {
    if (n == 1) return false;
    if (n == 2) return true;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    int res = 0;
    rep(i, n) {
        int a;
        cin >> a;
        if (isPrime(a)) res++;
    }
    cout << res << endl;
    return 0;
}
