#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main() {
    int N;
    cin >> N;
    vector<int> sumD(N + 1, 0);  // sumD[i] = 駅0からiまでの距離
    for (int i = 0; i < N - 1; ++i) {
        int d;
        cin >> d;
        sumD[i + 1] = sumD[i] + d;
    }
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            int dist;
            if (i == 0)
                dist = sumD[j];
            else
                dist = sumD[j] - sumD[i];
            cout << dist << " ";
        }
        if (i < N - 1) cout << endl;
    }

    return 0;
}
