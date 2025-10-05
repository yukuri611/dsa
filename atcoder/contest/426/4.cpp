#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    int T;
    cin >> T;
    vector<int> ans_list;

    rep(i, T) {
        int N;
        cin >> N;
        string S;
        cin >> S;
        vector<int> index0;
        vector<int> index1;
        rep(j, N) {
            if (S[j] == '0')
                index0.push_back(j);
            else
                index1.push_back(j);
        }

        if (index1.size() == 0 || index0.size() == 0) {
            ans_list.push_back(0);
            continue;
        }

        ll res = 2 * N;
        // change to all one
        for (int j = 0; j < index0.size(); ++j) {
            // left
            ll cnt_1_in_left = index0[j] - j;
            ll tempL = index0[j] + 1 + cnt_1_in_left;
            if (j != index0.size() - 1) {
                ll cnt_1_in_right =
                    (N - index0[j + 1]) - (index0.size() - (j + 1));
                tempL += (N - index0[j + 1]) + cnt_1_in_right;
            }
            // right
            ll cnt_1_in_right = (N - index0[j]) - (index0.size() - (j));
            ll tempR = (N - index0[j]) + cnt_1_in_right;
            if (j != 0) {
                ll cnt_1_in_left = index0[j - 1] - (j - 1);
                tempR += (index0[j - 1] + 1) + cnt_1_in_left;
            }
            res = min({res, tempL, tempR});
        }

        // change to all zero
        for (int j = 0; j < index1.size(); ++j) {
            // left
            ll cnt_0_in_left = index1[j] - j;
            ll tempL = index1[j] + 1 + cnt_0_in_left;
            if (j != index1.size() - 1) {
                ll cnt_0_in_right =
                    (N - index1[j + 1]) - (index1.size() - (j + 1));
                tempL += (N - index1[j + 1]) + cnt_0_in_right;
            }
            // right
            ll cnt_0_in_right = (N - index1[j]) - (index1.size() - (j));
            ll tempR = (N - index1[j]) + cnt_0_in_right;
            if (j != 0) {
                ll cnt_0_in_left = index1[j - 1] - (j - 1);
                tempR += (index1[j - 1] + 1) + cnt_0_in_left;
            }
            res = min({res, tempL, tempR});
        }
        ans_list.push_back(res);
    }

    for (int ans : ans_list) cout << ans << endl;
    return 0;
}
