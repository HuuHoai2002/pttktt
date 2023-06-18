#include "../../helpers/utilities.hpp"

using namespace std;

int main()
{
  vector<int> coins;
  int n;

  readFileSpaceSeparated("data.txt", coins);

  toSortedArray(coins, DESC);

  cout << "Nhap vao so tien can doi: ";
  cin >> n;

  int count = 0;

  // cú pháp for-each
  for (auto coin : coins)
  {
    while (n >= coin)
    {
      n -= coin;
      count++;
    }
  }

  cout << "So dong xu toi thieu can doi la: " << count << endl;

  return 0;
}