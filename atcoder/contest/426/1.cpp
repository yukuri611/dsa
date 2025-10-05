#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    map<string, int> Map{{"Ocelot", 0}, {"Serval", 1}, {"Lynx", 2}};
    string X, Y;
    cin >> X >> Y;
    if (Map[X] >= Map[Y])
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
