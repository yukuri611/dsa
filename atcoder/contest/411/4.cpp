#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> F(Q, 0), P(Q, 0);
    vector<string> S(Q, "");
    for (int i = 0; i < Q; ++i) {
        int f;
        cin >> f;
        F[i] = f;
        if (f == 1) {
            cin >> P[i];
        } else if (f == 2) {
            cin >> P[i] >> S[i];
        } else {
            cin >> P[i];
        }
    }

    int index3 = -1;
    vector<string> subset;
    string currS;
    for (int i = Q - 1; i >= 0; --i) {
        int f = F[i];
        int p = P[i];
        if (f == 1) {
            if (index3 != -1 && P[index3] == p) {
                reverse(currS.begin(), currS.end());
                subset.push_back(currS);
                index3 = -1;
                currS = "";
            }
        } else if (f == 2) {
            if (index3 != -1 && P[index3] == p) {
                string s = S[i];
                reverse(s.begin(), s.end());
                currS += s;
            }
        } else {
            if (index3 == -1) {
                index3 = i;
            }
        }
    }
    if (index3 != -1) {
        reverse(currS.begin(), currS.end());
        subset.push_back(currS);
    }

    string res = "";
    for (int i = subset.size() - 1; i >= 0; --i) {
        res += subset[i];
    }
    cout << res << endl;
    return 0;
}
