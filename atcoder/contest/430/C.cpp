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

    int r1 = 0, r2 = 0;
    int cnt_a = 0, cnt_b = 0;
    ll res = 0;
    rep(l, N) {
        while (r1 < N && ((S[r1] == 'b') || (cnt_a + 1 < A))) {
            if (S[r1] == 'a') cnt_a++;
            r1++;
        }
        while (r2 < N && ((S[r2] == 'a') || (cnt_b + 1 < B))) {
            if (S[r2] == 'b') cnt_b++;
            r2++;
        }

        //[r1, N)が条件1、[l, r2)が条件2を満たす範囲
        res += max(r2 - r1, 0);
        if (r1 == l)
            r1++;
        else if (S[l] == 'a')
            cnt_a--;

        if (r2 == l)
            r2++;
        else if (S[l] == 'b')
            cnt_b--;
    }

    cout << res << endl;
    return 0;
}
