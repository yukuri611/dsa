#include <algorithm>
#include <iostream>
#include <ranges>  // rangesライブラリをインクルード
#include <vector>

using namespace std;

int main() {
    vector<int> v = {3, 3, 1};
    do {
        for (int i = 0; i < v.size(); ++i) cout << v[i] << " ";
        cout << endl;
    } while (next_permutation(v.begin(), v.end()));
    return 0;
}
