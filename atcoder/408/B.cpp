#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++)
    cin >> A[i];

  unordered_set<int> set;
  for (int i = 0; i < N; i++)
  {
    set.insert(A[i]);
  }

  vector<int> v;
  for (int x : set)
  {
    v.push_back(x);
  }

  sort(v.begin(), v.end());

  int res = v.size();
  cout << res << endl;
  for (int i = 0; i < res - 1; i++)
  {
    cout << v[i] << " ";
  }
  cout << v[v.size() - 1];
  cout << endl;
  return 0;
}
