#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, A, B;
    cin >> N >> A >> B;
    string S;
    cin >> S;

    int cnt_a = 0, cnt_b = 0;
    int l = 0, r = -1;
    ll res = 0;
    while (r < N) {
        r++;
        while (cnt_b < B && r < N) {
            if (S[r] == 'a')
                cnt_a++;
            else {
                cnt_b++;
                if (cnt_b == B) break;
            }
            r++;
        }
        if (cnt_a >= A && cnt_b == B) {
            res += ((r - l + 1 - A) * (r - l - A)) / 2;
        }
        while (cnt_b == B) {
            if (S[l] == 'a')
                cnt_a--;
            else
                cnt_b--;
            l++;
        }
    }

    cout << res << endl;
    return 0;
}
