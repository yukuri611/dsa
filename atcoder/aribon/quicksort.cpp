#include <iostream>
#include <vector>

using namespace std;

void QuickSort(vector<int> a, int l, int r) {
  //aのlからr-1までをソート
  if (r - l <= 1) {
    return;
  } 

  int pivot_index = l + (r-l)/2;
  int pivot = a[pivot_index];
  swap(a[pivot_index], a[r - 1]);
  
  int i = l;
  for (int j = l; j < r - 1; j++) {
    if (a[j] < pivot) {
      swap(a[i], a[j]);
    }
  }
  swap(a[i], a[r- 1]);
  QuickSort(a, l, i); //pivot未満
  QuickSort(a, i + 1, r); //pivot以上
}

int main() {
  int n; // 要素数
	cin >> n;
	vector<int> a(n); // 整列したい配列ベクトル (サイズ を n に初期化)
	for (int i = 0; i < n; ++i) {
		cin >> a[i]; // 整列したい配列を取得
	}

	/* クイックソート */
	QuickSort(a, 0, n);

	return 0;
}
