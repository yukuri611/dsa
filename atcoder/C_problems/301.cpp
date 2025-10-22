#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string S, T;
    cin >> S >> T;
    map<char, int> MapS, MapT;
    for (char c : S) {
        MapS[c]++;
    }
    for (char c : T) {
        MapT[c]++;
    }

    int atCntS = 0;
    int atCntT = 0;
    string atcoder = "atcoder";
    rep(i, 26) {
        char currCh = 'a' + i;
        int cntS = MapS[currCh];
        int cntT = MapT[currCh];
        int diff = abs(cntS - cntT);
        if (diff > 0 && (count(atcoder.begin(), atcoder.end(), currCh) == 0)) {
            cout << "No" << endl;
            return 0;
        }

        if (cntS > cntT) atCntT += diff;
        if (cntT > cntS) atCntS += diff;
    }

    if (atCntS <= MapS['@'] && atCntT <= MapT['@']) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
