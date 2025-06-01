#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>

using namespace std;
int main()
{
  int N, M;
  cin >> N >> M;
  unordered_map<int, int> starts;
  unordered_map<int, int> ends;
  for (int i = 0; i < M; i++)
  {
    int s, e;
    cin >> s >> e;
    starts[s] += 1;
    ends[e + 1] += 1;
  }

  vector<int> sorted_starts;
  for (const auto &kv : starts)
  {
    sorted_starts.push_back(kv.first);
  }
  sort(sorted_starts.begin(), sorted_starts.end());

  vector<int> sorted_ends;
  for (const auto &kv : ends)
  {
    sorted_ends.push_back(kv.first);
  }
  sort(sorted_ends.begin(), sorted_ends.end());

  int res = starts[1];
  int cur = starts[1];
  if (res == 0 or sorted_ends[sorted_ends.size() - 1] <= N)
  {
    cout << 0 << endl;
    return 0;
  }

  int end_idx = 0;
  for (int i = 1; i < sorted_starts.size(); i++)
  {
    int s = sorted_starts[i];
    while (end_idx < sorted_ends.size() and sorted_ends[end_idx] <= s)
    {
      cur -= ends[sorted_ends[end_idx]];
      if (sorted_ends[end_idx] != s)
        res = min(res, cur);
      end_idx += 1;
    }
    cur += starts[s];
  }

  while (sorted_ends[end_idx] <= N)
  {
    cur -= ends[sorted_ends[end_idx]];
    res = min(res, cur);
    end_idx += 1;
  }

  cout << res << endl;
  return 0;
}
