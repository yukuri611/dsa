#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

string int_to_3(int n, int length) {
    string res = "0";
    while (n > 0) {
        int digit = n % 3;
        n /= 3;
        res += to_string(digit);
    }
    while (res.size() < length + 1) {
        res += "0";
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int K, N;
    cin >> K >> N;
    vector<string> V(N), W(N);
    rep(i, N) { cin >> V[i] >> W[i]; }

    rep(i, pow(3, K)) {
        string lengths = int_to_3(i, K);
        map<int, string> Map;
        bool valid2 = true;
        rep(j, N) {
            string v = V[j];
            string w = W[j];
            int curr_index = 0;
            bool valid = true;
            rep(k, v.size()) {
                int digit = v[k] - '0';
                int curr_len = lengths[digit] - '0' + 1;
                if (curr_index + curr_len > w.size()) {
                    valid = false;
                    break;
                }
                string curr_string = w.substr(curr_index, curr_len);
                if (Map.count(digit) == 1 && Map[digit] != curr_string) {
                    valid = false;
                    break;
                } else {
                    Map[digit] = curr_string;
                    curr_index += curr_len;
                }
            }
            if (!valid || curr_index != w.size()) {
                valid2 = false;
                break;
            }
        }
        if (valid2) {
            for (int j = 1; j <= K; ++j) {
                cout << Map[j] << endl;
            }
            return 0;
        }
    }

    return 0;
}
