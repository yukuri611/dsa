#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

struct Rect {
    ll lx, rx, ly, ry;
};
int main() {
    int N, X, Y;
    cin >> N >> X >> Y;

    vector<Rect> rects;
    rects.push_back({0, X, 0, Y});

    rep(i, N) {
        char c;
        int a, b;
        cin >> c >> a >> b;
        vector<Rect> old = move(rects);
        for (auto e : old) {
            if (c == 'X') {
                if (e.rx <= a)
                    rects.push_back({e.lx, e.rx, e.ly - b, e.ry - b});
                else if (e.lx >= a)
                    rects.push_back({e.lx, e.rx, e.ly + b, e.ry + b});
                else {
                    rects.push_back({e.lx, a, e.ly - b, e.ry - b});
                    rects.push_back({a, e.rx, e.ly + b, e.ry + b});
                }
            } else {
                if (e.ry <= a)
                    rects.push_back({e.lx - b, e.rx - b, e.ly, e.ry});
                else if (e.ly >= a)
                    rects.push_back({e.lx + b, e.rx + b, e.ly, e.ry});
                else {
                    rects.push_back({e.lx - b, e.rx - b, e.ly, a});
                    rects.push_back({e.lx + b, e.rx + b, a, e.ry});
                }
            }
        }
    }

    int M = rects.size();
    dsu uf(M);
    rep(i, M) {
        rep(j, i) {
            auto e_i = rects[i];
            auto e_j = rects[j];
            ll cx = min(e_i.rx, e_j.rx) - max(e_i.lx, e_j.lx);
            ll cy = min(e_i.ry, e_j.ry) - max(e_i.ly, e_j.ly);
            if (cx < 0 || cy < 0) continue;
            if (cx > 0 || cy > 0) {
                uf.merge(i, j);
            }
        }
    }

    vector<ll> areas(M);
    rep(i, M) {
        auto e = rects[i];
        ll cur_area = (e.rx - e.lx) * (e.ry - e.ly);
        areas[uf.leader(i)] += cur_area;
    }
    sort(areas.rbegin(), areas.rend());
    while (areas.back() == 0) areas.pop_back();
    reverse(areas.begin(), areas.end());
    cout << areas.size() << endl;
    for (auto a : areas) cout << a << " ";
    cout << endl;
    return 0;
}
