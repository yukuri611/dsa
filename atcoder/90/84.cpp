#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int main() {
    int N; cin >> N;
    string S; cin >> S;
    
    //ランレングス圧縮で解く
    vector<int> len;
    int i = 0;
    while(i < N) {
        int l = 1;
        while(i + l < N && S[i + l] == S[i]) l++;
        len.push_back(l);
        i += l;
    }
    
    ll res = 0;
    res += (N * (N - 1)) / 2;
    for (int l: len) {
        res -= (l * (l - 1)) / 2;
    }
    cout << res << endl;
    return 0;
}
