#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

vector<vector<ll>> A;
int N, P, K; 

int count_number(ll lens) {
    vector<vector<ll>> dist(N, vector<ll>(N));
    //ワーシャルフロイド法
    rep(i, N) {
        rep(j, N) {
            if (A[i][j] == -1) dist[i][j] = lens;
            else dist[i][j] = A[i][j]; 
        }
    }
    rep(k, N){
        rep(i, N) {
            rep(j, N) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int res = 0;
    rep(i, N) {
        for (int j = i + 1; j < N; ++j) {
            res += (dist[i][j] <= P);
        }
    }
    return res;
}
 
ll get_border(ll cnts) {
    ll l = 0, r = 5e9, minx = 5e9; 
    while((r - l) > 1) {
        ll mid = (l + r) / 2;
        int res = count_number(mid);
        if (res <= cnts) {
            r = mid;
            minx = min(minx, r);
        }
        else l = mid;
    }
    return minx;
}

int main() {
    cin >> N >> P >> K;
    A.resize(N, vector<ll>(N));
    rep(i, N) rep(j, N) cin >> A[i][j];

    ll L = get_border(K);
    ll R = get_border(K - 1);
    if (R - L > 2e9) {
        cout << "Infinity" << endl;
        return 0;
    }

    cout << R - L << endl;
    return 0;
}
