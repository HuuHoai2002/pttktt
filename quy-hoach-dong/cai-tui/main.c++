#include <iostream>
#include <vector>

using namespace std;

struct Item
{
  string name;
  int weight;
  int value;
};

void printItems(int W, vector<Item> items, vector<vector<int>> dp);

int max(int a, int b)
{
  return (a > b) ? a : b;
}

/// @brief Bài toán cái túi
/// @param W Khối lượng tối đa của cái túi
/// @param items Danh sách các vật phẩm
/// @return
int knapsack(int W, vector<Item> items)
{
  int n = items.size();

  vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0)); // khởi tạo bảng dp là một ma trận có n + 1 hàng và W + 1 cột

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= W; j++)
    {
      if (items[i - 1].weight > j)
      {
        dp[i][j] = dp[i - 1][j];
      }
      else
      {
        dp[i][j] = max(dp[i - 1][j], items[i - 1].value + dp[i - 1][j - items[i - 1].weight]); // công thức truy hồi
      }
    }
  }

  printItems(W, items, dp);

  return dp[n][W];
}

/// @brief In ra các vật phẩm được chọn
/// @param W Khối lượng tối đa của cái túi
/// @param items Danh sách các vật phẩm
/// @param dp Bảng lưu trữ các giá trị tối ưu
void printItems(int W, vector<Item> items, vector<vector<int>> dp)
{
  int n = items.size();

  vector<bool> chosen(n, false);

  int i = n, j = W;

  while (i > 0 && j > 0)
  {
    if (dp[i][j] != dp[i - 1][j])
    {
      chosen[i - 1] = true;
      j -= items[i - 1].weight;
    }
    i--;
  }

  for (int i = 0; i < n; i++)
  {
    if (chosen[i])
    {
      cout << "Chon " << items[i].name << " Voi khoi luong: " << items[i].weight << " kg "
           << " Voi gia tri: " << items[i].value << " VND "
           << endl;
    }
  }
}

int main()
{
  vector<Item> items = {
      {"A", 15, 30},
      {"B", 10, 25},
      {"C", 2, 2},
      {"D", 4, 6},
  };

  int W = 55;

  int maxValue = knapsack(W, items);

  cout << "Tong trong luong co the mang: " << W << " kg" << endl;
  cout << "Tong gia tri lay duoc: " << maxValue << " VND" << endl;

  return 0;
}