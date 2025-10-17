#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int main() {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    vector<char> ans;
    rep(i, N) {
        while (ans.size() > 0 && K < N - i + ans.size() && ans.back() > S[i]) {
            ans.pop_back();
        }
        ans.push_back(S[i]);
    }
    string res;
    rep(i, K) res += ans[i];
    cout << res << endl;
    return 0;
}
