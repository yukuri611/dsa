#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int N;
string R, C;
map<char, vector<string>> orders = {
    {'A', {"ABC", "ACB"}}, {'B', {"BAC", "BCA"}}, {'C', {"CAB", "CBA"}}};
vector<set<char>> Setvec;

bool canPut(const string s) {
    rep(i, N) {
        if (s[i] != '.') {
            if (Setvec[i].count(s[i])) return false;
            if (Setvec[i].size() == 0 && C[i] != s[i]) return false;
        }
    }
    return true;
}

void Put(int r, const string s) {
    rep(i, N) {
        if (s[i] != '.') {
            Setvec[i].insert(s[i]);
        }
    }
}

void Remove(int r, const string s) {
    rep(i, N) {
        if (s[i] != '.') {
            Setvec[i].erase(s[i]);
        }
    }
}

bool dfs(int currR, vector<string>& grid) {
    if (currR == N) return true;

    rep(i, 2) {
        vector<bool> p(N, false);
        rep(i, 3) p[i] = true;
        reverse(p.begin(), p.end());
        string order = orders[R[currR]][i];
        do {
            string s;
            int order_i = 0;
            rep(i, N) {
                if (!p[i])
                    s += '.';
                else
                    s += order[order_i++];
            }
            if (canPut(s)) {
                grid[currR] = s;
                Put(currR, s);
                if (dfs(currR + 1, grid)) return true;
                Remove(currR, s);
            }
        } while (next_permutation(p.begin(), p.end()));
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> R >> C;

    vector<string> res(N);
    Setvec.resize(N);

    bool found = dfs(0, res);
    if (found) {
        cout << "Yes" << endl;
        for (string s : res) {
            cout << s << endl;
        }
    } else {
        cout << "No" << endl;
    }

    return 0;
}
