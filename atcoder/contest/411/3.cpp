#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main() {
    // 入力
    int N, Q;
    cin >> N >> Q;
    vector<int> A(Q);
    for (int i = 0; i < Q; ++i) cin >> A[i];

    // 各クエリに対して計算
    vector<int> G(N + 2,
                  0);  // 0は白。1が黒。左右それぞれ1つ白色パディングを追加
    int c = 0;
    for (int i = 0; i < Q; ++i) {
        int a = A[i];
        if (G[a] == 1) {
            // 黒を白にかえる場合
            if (G[a - 1] == 1 && G[a + 1] == 1)
                c++;
            else if (G[a - 1] == 0 && G[a + 1] == 0)
                c--;
            G[a] = 0;
        } else {
            // 白を黒にかえる場合
            if (G[a - 1] == 0 && G[a + 1] == 0)
                c++;
            else if (G[a - 1] == 1 && G[a + 1] == 1)
                c--;
            G[a] = 1;
        }
        cout << c << endl;
    }
    return 0;
}
