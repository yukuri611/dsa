#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// 財宝の情報を格納する構造体
struct Item {
    long long v; // 市場価値
    long long w; // 貴重度
};

int N;
long long D;
vector<Item> items;
vector<pair<long long, long long>> first_half_list;

// 前半部分の全探索を行う再帰関数
void generate_first_half(int index, int end, long long current_v_diff, long long current_w_diff) {
    // ベースケース：前半の最後まで探索したら結果を保存
    if (index == end) {
        first_half_list.push_back({current_v_diff, current_w_diff});
        return;
    }

    // 1. Annaが取る場合
    generate_first_half(index + 1, end, current_v_diff + items[index].v, current_w_diff - items[index].w);

    // 2. Brunoが取る場合
    generate_first_half(index + 1, end, current_v_diff - items[index].v, current_w_diff + items[index].w);

    // 3. 誰も取らない場合
    generate_first_half(index + 1, end, current_v_diff, current_w_diff);
}

long long max_w_diff = -1; // Bruno - Anna の貴重度の差の最大値（見つからない場合を考慮）

// 後半部分の全探索と、前半との組み合わせ計算を行う再帰関数
void solve_second_half(int index, int end, long long current_v_diff, long long current_w_diff) {
    // ベースケース：全体の最後まで探索したら前半の結果と組み合わせる
    if (index == end) {
        // 条件 |d1 + d2| <= D  =>  -D - d2 <= d1 <= D - d2
        // d1 <= D - d2 を満たす最大のd1を探す
        long long target_v_diff = D - current_v_diff;

        // upper_boundで target_v_diff より大きい最初の要素を探す
        auto it = upper_bound(first_half_list.begin(), first_half_list.end(), make_pair(target_v_diff, 2e18)); // 貴重度は非常に大きな値

        // その一つ前が、条件を満たす最大のd1を持つ要素
        if (it != first_half_list.begin()) {
            --it;
            // 候補となる解を計算し、最大値を更新
            // it->second には、そのd1以下でのp1の最大値が格納されている
            long long current_total_w_diff = it->second + current_w_diff;
            if (max_w_diff < current_total_w_diff) {
                max_w_diff = current_total_w_diff;
            }
        }
        return;
    }

    // 1. Annaが取る場合
    solve_second_half(index + 1, end, current_v_diff + items[index].v, current_w_diff - items[index].w);

    // 2. Brunoが取る場合
    solve_second_half(index + 1, end, current_v_diff - items[index].v, current_w_diff + items[index].w);

    // 3. 誰も取らない場合
    solve_second_half(index + 1, end, current_v_diff, current_w_diff);
}


int main() {
    // 高速化のための設定
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 入力
    cin >> N >> D;
    items.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> items[i].v >> items[i].w;
    }

    // --- ステップ1 & 2: 前半グループの全パターンを列挙 ---
    int n1 = N / 2;
    generate_first_half(0, n1, 0, 0);

    // --- ステップ3: 前半グループのデータを高速検索用に整理 ---
    // 1. 市場価値の差(d1)でソート
    sort(first_half_list.begin(), first_half_list.end());

    // 2. 同じd1について貴重度の差(p1)が最大のものを残す
    // mapを使うと自動的にd1でソートされ、p1を最大値に更新できる
    map<long long, long long> processed_map;
    for (const auto& p : first_half_list) {
        if (processed_map.find(p.first) == processed_map.end()) {
            processed_map[p.first] = p.second;
        } else {
            processed_map[p.first] = max(processed_map[p.first], p.second);
        }
    }
    
    first_half_list.assign(processed_map.begin(), processed_map.end());

    // 3. p1を累積最大値に更新する
    // これにより、あるd1以下の範囲におけるp1の最大値がO(1)でわかるようになる
    for (size_t i = 1; i < first_half_list.size(); ++i) {
        first_half_list[i].second = max(first_half_list[i].second, first_half_list[i-1].second);
    }
    
    // --- ステップ4 & 5: 後半グループを探索し、最大値を見つける ---
    solve_second_half(n1, N, 0, 0);

    // 結果の出力
    cout << max_w_diff << endl;

    return 0;
}
