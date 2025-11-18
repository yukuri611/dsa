#include <bits/stdc++.h>

using namespace std;

using LL = long long;

int main() {
    int N;
    cin >> N;
    vector<int> X(2 * N), Y(2 * N);
    set<int> setX, setY;
    for (int i = 0; i < 2 * N; i += 2) {
        cin >> X[i] >> Y[i] >> X[i + 1] >> Y[i + 1];
        setX.insert(X[i]);
        setX.insert(X[i + 1]);
        setY.insert(Y[i]);
        setY.insert(Y[i + 1]);
    }

    vector<int> uX(setX.begin(), setX.end());
    vector<int> uY(setY.begin(), setY.end());
    sort(uX.begin(), uX.end());
    sort(uY.begin(), uY.end());

    int W = uX.size();
    int H = uY.size();
    vector<vector<int>> imos(
        H, vector<int>(W, 0));  // imos[i][j] = uY[i]からuY[i + 1],
                                // uX[i]からuX[i + 1]の長方形ブロックについて
    for (int i = 0; i < N; ++i) {
        int c1 = lower_bound(uX.begin(), uX.end(), X[2 * i]) - uX.begin();
        int c2 = lower_bound(uX.begin(), uX.end(), X[2 * i + 1]) - uX.begin();
        int r1 = lower_bound(uY.begin(), uY.end(), Y[2 * i]) - uY.begin();
        int r2 = lower_bound(uY.begin(), uY.end(), Y[2 * i + 1]) - uY.begin();
        imos[r1][c1]++;
        imos[r1][c2]--;
        imos[r2][c1]--;
        imos[r2][c2]++;
    }

    for (int i = 0; i < H; ++i) {
        for (int j = 1; j < W; ++j) {
            imos[i][j] += imos[i][j - 1];
        }
    }
    for (int j = 0; j < W; ++j) {
        for (int i = 1; i < H; ++i) {
            imos[i][j] += imos[i - 1][j];
        }
    }
    LL total_area = 0;
    for (int i = 0; i < H - 1; ++i) {
        for (int j = 0; j < W - 1; ++j) {
            if (imos[i][j] > 0) {
                LL width = uX[j + 1] - uX[j];
                LL height = uY[i + 1] - uY[i];
                total_area += width * height;
            }
        }
    }

    cout << total_area << endl;
    return 0;
}
