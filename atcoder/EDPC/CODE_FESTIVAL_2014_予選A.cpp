#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

// DP計算のためにグローバル変数として宣言
string A_str;
int K_val;
// メモ化用配列: memo[index][tight][mask][is_leading_zero]
string memo_less[20][2][1 << 10][2];
// メモ化用配列: memo[index][tight][mask]
string memo_greater[20][2][1 << 10];

// 立っているビットの数を数える (GCC/Clangの組み込み関数が高速)
int countSetBits(int n) {
#ifdef __GNUC__
    return __builtin_popcount(n);
#else
    int count = 0;
    while (n > 0) {
        n &= (n - 1);
        count++;
    }
    return count;
#endif
}

/**
 * @brief A以下の条件を満たす最大の数を探す再帰関数
 * @param index 現在見ている桁
 * @param tight Aの桁の数字による上限の制約があるか
 * @param mask これまで使った数字の集合（ビットマスク）
 * @param is_leading_zero 先頭の0を許容する状態か（桁数が少なくなるケースを扱う）
 * @return 見つかった数を文字列で返す。見つからなければ"-1"。
 */
string find_less_recursive(int index, bool tight, int mask, bool is_leading_zero) {
    if (index == A_str.length()) {
        // 全ての桁を決めた。先行ゼロのみの場合は"0"、それ以外は空文字列（接尾辞）を返す
        return is_leading_zero ? "0" : "";
    }
    if (memo_less[index][tight][mask][is_leading_zero] != "!") {
        return memo_less[index][tight][mask][is_leading_zero];
    }

    string res = "-1"; // "-1"は「解が見つからなかった」ことを示す
    int upper_bound = tight ? (A_str[index] - '0') : 9;

    // 大きい数から試すことで、最初に見つかったものが最大値となる
    for (int d = upper_bound; d >= 0; --d) {
        bool new_is_leading_zero = is_leading_zero && (d == 0);
        int new_mask = new_is_leading_zero ? mask : (mask | (1 << d));

        if (countSetBits(new_mask) <= K_val) {
            bool new_tight = tight && (d == upper_bound);
            string suffix = find_less_recursive(index + 1, new_tight, new_mask, new_is_leading_zero);

            if (suffix != "-1") { // 有効な下位の桁が見つかった
                if (new_is_leading_zero && suffix == "0") {
                    res = "0";
                } else {
                    res = (new_is_leading_zero ? "" : to_string(d)) + suffix;
                }
                return memo_less[index][tight][mask][is_leading_zero] = res;
            }
        }
    }
    return memo_less[index][tight][mask][is_leading_zero] = res;
}

/**
 * @brief A以上の条件を満たす最小の数（Aと同桁数）を探す再帰関数
 * @param index 現在見ている桁
 * @param tight Aの桁の数字による下限の制約があるか
 * @param mask これまで使った数字の集合（ビットマスク）
 * @return 見つかった数を文字列で返す。見つからなければ"-1"。
 */
string find_greater_recursive(int index, bool tight, int mask) {
    if (index == A_str.length()) {
        return "";
    }
    if (memo_greater[index][tight][mask] != "!") {
        return memo_greater[index][tight][mask];
    }

    string res = "-1";
    int lower_bound = tight ? (A_str[index] - '0') : 0;

    // 小さい数から試すことで、最初に見つかったものが最小値となる
    for (int d = lower_bound; d <= 9; ++d) {
        int new_mask = mask | (1 << d);
        if (countSetBits(new_mask) <= K_val) {
            bool new_tight = tight && (d == lower_bound);
            string suffix = find_greater_recursive(index + 1, new_tight, new_mask);

            if (suffix != "-1") {
                res = to_string(d) + suffix;
                return memo_greater[index][tight][mask] = res;
            }
        }
    }
    return memo_greater[index][tight][mask] = res;
}

// メインの解答処理
void solve() {
    string A;
    int K;
    cin >> A >> K;

    A_str = A;
    K_val = K;

    // --- 1. A以下の最大の数を探す ---
    for (int i = 0; i < 20; ++i) for (int j = 0; j < 2; ++j) for (int k = 0; k < (1 << 10); ++k) for (int l = 0; l < 2; ++l) memo_less[i][j][k][l] = "!";
    string less_str = find_less_recursive(0, true, 0, true);
    ll val_less = stoll(less_str);

    // --- 2. A以上の最小の数を探す ---
    ll val_greater;

    // ケースA: Aと同桁数の最小値
    for (int i = 0; i < 20; ++i) for (int j = 0; j < 2; ++j) for (int k = 0; k < (1 << 10); ++k) memo_greater[i][j][k] = "!";
    string greater_str_same_len = find_greater_recursive(0, true, 0);
    
    // ケースB: Aより1桁多い最小値
    ll val_greater_longer;
    if (K_val == 1) { // 使える数字が1種類なら "11...1"
        string s(A.length() + 1, '1');
        val_greater_longer = stoll(s);
    } else { // 2種類以上使えるなら "100...0"
        string s = "1";
        s += string(A.length(), '0');
        val_greater_longer = stoll(s);
    }
    
    // ケースAとBを比較
    if (greater_str_same_len == "-1") {
        // 同桁数で見つからなければ、1桁多いものが最小値
        val_greater = val_greater_longer;
    } else {
        val_greater = min(stoll(greater_str_same_len), val_greater_longer);
    }

    ll target = stoll(A);
    cout << min(target - val_less, val_greater - target) << endl;
}

int main() {
    // 高速化のためのおまじない
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
