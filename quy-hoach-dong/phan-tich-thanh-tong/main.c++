#include <iostream>

using namespace std;

const int MAXN = 100;

int dp[MAXN];

int countWays(int n)
{
  dp[0] = 1;

  for (int i = 1; i <= n; i++)
  {
    for (int j = i; j <= n; j++)
    {
      dp[j] += dp[j - i]; // công thức truy hồi
    }
  }
  return dp[n];
}

int main()
{
  int n = 5;

  cout << "Co " << countWays(n) << " cach phan tich " << n << " thanh tong cac so nguyen duong" << endl;

  return 0;
}