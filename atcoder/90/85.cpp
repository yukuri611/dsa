#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int main() {
    ll K; cin >> K;
    vector<ll> div;
    for (ll i = 1; i * i <= K; ++i) {
        if (K % i != 0LL) continue;
        div.push_back(i);
        if ((K / i) != i) div.push_back(K / i);
    }

    sort(div.begin(), div.end());
    ll ans = 0;
    rep(i, div.size()) {
        for (int j = i; j < div.size(); ++j) {
            ll a = div[i];
            ll b = div[j];
            if ((K / a) % b != 0) continue; //オーバーフローに注意
            ll c = K / (a * b);  
            if (b <= c) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
