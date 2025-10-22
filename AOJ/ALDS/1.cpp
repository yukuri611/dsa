#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int N;
vector<int> A;

void printvec() {
    rep(i, N - 1) cout << A[i] << " ";
    cout << A[N - 1] << endl;
}

void insertionSort() {
    rep(i, N) {
        int v = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        printvec();
    }
}

int main() {
    cin >> N;
    A.resize(N);
    rep(i, N) cin >> A[i];

    insertionSort();

    return 0;
}
