#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    string S;
    cin >> S;

    int res = 0;
    rep(i, 1000) {
        string password = to_string(i);
        password.insert(0, 3 - password.length(), '0');
        int curr_digit = 0;
        rep(j, N) {
            if (curr_digit == 3) break;
            if (S[j] == password[curr_digit]) {
                curr_digit++;
            }
        }
        if (curr_digit == 3) res++;
    }

    cout << res << endl;
    return 0;
}
