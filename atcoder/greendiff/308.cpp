#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int mex(int a, int b, int c) {
    rep(i, 3) {
        if (a != i && b != i && c != i) return i;
    }
    return 3;
}

int main() {
    int N; cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    string S; cin >> S;

    ll res = 0;
    
    // cnt_x[v_x]: これまで見た'X'の個数
    vector<ll> cnt_x(3, 0);

    // sum_ex[v_m]: Mの値をv_mと仮定したときの、
    //              これまで見たE-Xペアによるmexの総和
    vector<ll> sum_ex(3, 0);

    // 文字列を右から左へ走査
    for (int i = N - 1; i >= 0; --i) {
        if (S[i] == 'X') {
            cnt_x[A[i]]++;
        } else if (S[i] == 'E') {
            // この'E'が、左側の各M(v_m)に対してどれだけ貢献するか計算し、sum_exに加算
            rep(v_m, 3) { // 仮のMの値
                rep(v_x, 3) { // 既知のXの値
                    sum_ex[v_m] += mex(v_m, A[i], v_x) * cnt_x[v_x];
                }
            }
        } else { // S[i] == 'M'
            // この'M'と、既知のE-Xペア群とのmexの総和を答えに加算
            res += sum_ex[A[i]];
        }
    }

    cout << res << endl;
    return 0;
}
