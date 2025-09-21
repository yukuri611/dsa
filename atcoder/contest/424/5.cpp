#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <numeric>
#include <algorithm>
#include <map>

// 高速化のための標準入出力設定
void setup_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

// 1つのテストケースを解く関数
void solve() {
    int N;
    long long K, X;
    cin >> N >> K >> X;
    vector<double> A(N);
    double max_a = 0.0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        max_a = max(max_a, A[i]);
    }

    // --- ステップ1: 二分探索で「最長の棒の長さの最小値 L_max」を求める ---
    double l = 0.0, r = max_a;
    // 浮動小数点数の二分探索は100回程度の繰り返しで十分な精度が得られる
    for (int iter = 0; iter < 100; ++iter) {
        double mid = l + (r - l) / 2.0;
        if (mid == 0) { // midが0になると割り算で問題が起きるため
            l = mid;
            continue;
        }
        long long total_cuts = 0;
        for (int i = 0; i < N; ++i) {
            if (A[i] > mid) {
                // ceil(log2(A[i]/mid)) を計算し、必要な分割回数を求める
                // A[i]を2でb回割るとmid以下になる -> A[i] / 2^b <= mid
                long long b = ceil(log2(A[i] / mid));
                
                // bが大きすぎると 1LL << b がオーバーフローする可能性があるため上限を設ける
                if (b >= 60) {
                    total_cuts = K + 1; // Kを確実に超える十分大きい数
                } else {
                    total_cuts += (1LL << b) - 1;
                }
            }
            if (total_cuts > K) {
                break; // 途中でKを超えたら計算を打ち切る
            }
        }

        if (total_cuts <= K) {
            r = mid; // もっと短くできる可能性がある
        } else {
            l = mid; // midが短すぎた
        }
    }
    double l_max = r;

    // --- ステップ2: 最終状態を再現し、使用した操作回数を計算 ---
    long long k_used = 0;
    // map<長さ, 本数> を降順で管理する
    map<double, long long, greater<double>> final_pieces;

    for (int i = 0; i < N; ++i) {
        if (A[i] <= l_max) {
            final_pieces[A[i]]++;
            continue;
        }
        
        long long b = ceil(log2(A[i] / l_max));
        long long num_pieces = (b >= 60) ? (1LL << 60) : (1LL << b);
        long long num_cuts = num_pieces - 1;
        
        double final_length = A[i] / num_pieces;

        final_pieces[final_length] += num_pieces;
        k_used += num_cuts;
    }

    // --- ステップ3: 余った操作を適用 ---
    if (k_used < K) {
        long long k_left = K - k_used;
        
        // 最も長い棒はmapの先頭にある
        auto it = final_pieces.begin();
        double longest_len = it->first;
        long long num_longest = it->second;

        long long num_to_cut = min(k_left, num_longest);

        // 元の最も長い棒の情報を更新
        final_pieces[longest_len] -= num_to_cut;
        if (final_pieces[longest_len] == 0) {
            final_pieces.erase(longest_len);
        }

        // 新しくできた棒を追加
        final_pieces[longest_len / 2.0] += num_to_cut * 2;
    }

    // --- ステップ4: X番目の長さを特定 ---
    long long current_rank = 0;
    for (auto const& [len, count] : final_pieces) {
        current_rank += count;
        if (current_rank >= X) {
            cout << len << endl;
            return;
        }
    }
}

int main() {
    setup_io();
    cout << fixed << setprecision(10); // 出力精度を先に設定

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
