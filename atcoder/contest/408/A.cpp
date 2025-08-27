#include <iostream>

using namespace std;

int main()
{
  int N, S;
  cin >> N >> S;
  int T[N + 1];
  T[0] = 0;
  for (int i = 1; i < N + 1; i++)
  {
    cin >> T[i];
  }
  bool res = true;
  for (int i = 0; i < N; i++)
  {
    if (T[i + 1] - T[i] >= S + 0.5)
    {
      res = false;
      break;
    }
  }
  if (res)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
  return 0;
}
