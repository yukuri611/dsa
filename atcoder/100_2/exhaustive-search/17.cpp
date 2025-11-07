#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

bool isValid(vector<int>& A) {
    int N = A.size();
    rep(i, N) {
        for (int j = i + 1; j < N; ++j) {
            if (abs(A[i] - A[j]) == abs(i - j)) return false;
        }
    }
    return true;
}

void printGrid(vector<int>& A) {
    int N = A.size();
    rep(i, N) {
        rep(j, N) {
            if (A[i] == j)
                cout << 'Q';
            else
                cout << '.';
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin >> k;
    map<int, int> Map;
    rep(i, k) {
        int r, c;
        cin >> r >> c;
        Map[r] = c;
    }

    int N = 8;
    vector<int> p(N);
    iota(p.begin(), p.end(), 0);
    do {
        bool valid = true;
        rep(i, N) {
            if (Map.count(i) && Map[i] != p[i]) {
                valid = false;
                break;
            }
        }
        if (!isValid(p)) {
            valid = false;
        }
        if (valid) {
            printGrid(p);
            break;
        }
    } while (next_permutation(p.begin(), p.end()));

    return 0;
}
