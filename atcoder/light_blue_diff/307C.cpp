#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// シートを型として定義しておくと分かりやすい
using Sheet = std::vector<std::string>;

// (r, c) が指定された高さH, 幅Wの範囲内か判定するヘルパー関数
bool is_inside(int r, int c, int H, int W) {
    return 0 <= r && r < H && 0 <= c && c < W;
}

/**
 * @brief ある配置が問題の条件を満たすか判定する関数
 * @param A シートA
 * @param B シートB
 * @param X 目標シートX
 * @param ra シートAを置くy座標
 * @param ca シートAを置くx座標
 * @param rb シートBを置くy座標
 * @param cb シートBを置くx座標
 * @return 条件を満たせばtrue, そうでなければfalse
 */
bool check(const Sheet& A, const Sheet& B, const Sheet& X, int ra, int ca,
           int rb, int cb) {
    int HA = A.size(), WA = A[0].size();
    int HB = B.size(), WB = B[0].size();
    int HX = X.size(), WX = X[0].size();

    // 条件1: AとBの黒マスがすべてXの領域内に収まっているか
    for (int i = 0; i < HA; ++i) {
        for (int j = 0; j < WA; ++j) {
            if (A[i][j] == '#' && !is_inside(ra + i, ca + j, HX, WX)) {
                return false;  // Aの黒マスがはみ出しているのでダメ
            }
        }
    }
    for (int i = 0; i < HB; ++i) {
        for (int j = 0; j < WB; ++j) {
            if (B[i][j] == '#' && !is_inside(rb + i, cb + j, HX, WX)) {
                return false;  // Bの黒マスがはみ出しているのでダメ
            }
        }
    }

    // 条件2: 合成したシートがXと一致するか
    for (int i = 0; i < HX; ++i) {
        for (int j = 0; j < WX; ++j) {
            // Xの(i,j)に対応するA, B上の座標を計算
            int cur_ra = i - ra, cur_ca = j - ca;
            int cur_rb = i - rb, cur_cb = j - cb;

            bool is_black_on_A =
                is_inside(cur_ra, cur_ca, HA, WA) && A[cur_ra][cur_ca] == '#';
            bool is_black_on_B =
                is_inside(cur_rb, cur_cb, HB, WB) && B[cur_rb][cur_cb] == '#';

            char combined_char = (is_black_on_A || is_black_on_B) ? '#' : '.';

            if (X[i][j] != combined_char) {
                return false;  // (i,j)の色がXと一致しないのでダメ
            }
        }
    }

    // すべての条件をクリアした
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int HA, WA;
    std::cin >> HA >> WA;
    Sheet A(HA);
    for (int i = 0; i < HA; ++i) std::cin >> A[i];

    int HB, WB;
    std::cin >> HB >> WB;
    Sheet B(HB);
    for (int i = 0; i < HB; ++i) std::cin >> B[i];

    int HX, WX;
    std::cin >> HX >> WX;
    Sheet X(HX);
    for (int i = 0; i < HX; ++i) std::cin >> X[i];

    // シートAを置く位置(ra, ca)を全探索
    for (int ra = -HA + 1; ra < HX; ++ra) {
        for (int ca = -WA + 1; ca < WX; ++ca) {
            // シートBを置く位置(rb, cb)を全探索
            for (int rb = -HB + 1; rb < HX; ++rb) {
                for (int cb = -WB + 1; cb < WX; ++cb) {
                    // この配置で条件を満たすかチェック
                    if (check(A, B, X, ra, ca, rb, cb)) {
                        std::cout << "Yes" << std::endl;
                        return 0;
                    }
                }
            }
        }
    }

    std::cout << "No" << std::endl;
    return 0;
}
