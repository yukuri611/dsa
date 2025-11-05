#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string S;
    cin >> S;

    string target = "ACGT";

    int max_len = 0;
    int curr_len = 0;

    rep(i, S.size()) {
        if (count(target.begin(), target.end(), S[i]) == 1) {
            curr_len++;
        } else {
            max_len = max(max_len, curr_len);
            curr_len = 0;
        }
    }

    cout << max_len << endl;
    return 0;
}
