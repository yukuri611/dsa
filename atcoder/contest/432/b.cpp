#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

void printAns(vector<int> D) {
    int curr = 1;
    rep(i, D.size() - 1) curr *= 10;
    int res = 0;
    rep(i, D.size()) {
        res += D[i] * curr;
        curr /= 10;
    }
    cout << res << endl;
}

int main() {
    int X;
    cin >> X;
    vector<int> D;
    while (X > 0) {
        D.push_back(X % 10);
        X /= 10;
    }

    sort(D.begin(), D.end());
    int d = 1;
    rep(i, D.size() - 1) d *= 10;
    if (D[0] == 0) {
        vector<int> newD;
        int first_d;
        int i = 0;
        while (true) {
            if (D[i] == 0) {
                newD.push_back(0);
                ++i;
            } else {
                first_d = D[i];
                ++i;
                break;
            }
        }

        for (; i < D.size(); ++i) {
            newD.push_back(D[i]);
        }
        vector<int> new_new_D;
        new_new_D.push_back(first_d);
        rep(i, newD.size()) { new_new_D.push_back(newD[i]); }
        printAns(new_new_D);
    } else {
        printAns(D);
    }
    return 0;
}
