#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    cin >> Q;
    vector<bool> res_list;
    vector<vector<char>> vec(1);
    int cnt0 = 0, curr_cnt = 0, curr_i = 0;
    rep(i, Q) {
        int f;
        cin >> f;
        if (f == 1) {
            char c;
            cin >> c;
            if (c == '(') {
                curr_cnt++;
                if (curr_i == 0) cnt0++;
            } else {
                curr_cnt--;
                if (curr_i == 0) cnt0--;
            }
            vec[curr_i].push_back(c);
            if (curr_cnt == -1) {
                curr_i++;
                vec.push_back({});
            }
        } else {
            if (vec[curr_i].size() == 0) {
                curr_i--;
                curr_cnt = -1;
            }
            if (vec[curr_i].back() == '(') {
                curr_cnt--;
                if (curr_i == 0) cnt0--;
            } else {
                curr_cnt++;
                if (curr_i == 0) cnt0++;
            }
            vec[curr_i].pop_back();
        }

        res_list.push_back(cnt0 == 0);
    }

    for (bool res : res_list) {
        if (res)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}
