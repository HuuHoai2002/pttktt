## Các công việc

1. Mô tả chi tiết thuật toán "Thuật toán cái túi với số vật phẩm vô hạn quy hoạch động"

```text
Bài toán cái túi có thể được giải quyết bằng phương pháp quy hoạch động. Ta sẽ tạo ra một bảng 2 chiều, với số hàng tương ứng với số đồ vật, và số cột tương ứng với khối lượng từ 0 đến w của túi. Các giá trị trong bảng này sẽ được tính toán theo công thức:

- Nếu i = 0 hoặc j = 0, giá trị bảng là 0.
- Nếu khối lượng đồ vật i lớn hơn khối lượng còn lại của túi (j < ai), giá trị bảng là giá trị tại ô (i-1, j).
- Nếu khối lượng đồ vật i nhỏ hơn hoặc bằng khối lượng còn lại của túi (j >= ai), ta sẽ chọn giữa cách chọn đồ vật i hoặc không chọn đồ vật i. Nếu chọn đồ vật i, giá trị bảng sẽ là giá trị tại ô (i-1, j-ai) cộng với giá trị của đồ vật i. Nếu không chọn đồ vật i, giá trị bảng sẽ là giá trị tại ô (i-1, j).

Công thức truy hồi: dp[i][j] = max(dp[i-1][j], items[i-1].value + dp[i-1][j-items[i-1].weight])

Trong đó dp[i-1][j] là giá trị lớn nhất có thể đạt được khi không chọn đồ vật thứ i và dp[i-1][j-items[i-1].weight] là giá trị lớn nhất có thể đạt được khi chọn đồ vật thứ i.

Kết quả cuối cùng sẽ là giá trị của dp[n][W] trong đó n là số lượng đồ vật và W là trọng lượng tối đa cho phép của túi.

Sau khi tính toán xong bảng, giá trị của túi có giá trị lớn nhất có thể được nhận được sẽ nằm ở ô cuối cùng của bảng.
```

2. Chỉ rõ phương pháp thiết kế thuật toán trong thuật toán vừa nêu

```text
Phương pháp thiết kế thuật toán trong trường hợp này là quy hoạch động. Ta sử dụng bảng 2 chiều để lưu trữ kết quả của các bài toán con và tính toán các giá trị của bài toán lớn dựa trên các giá trị đã tính toán được.
```

3. Cài đặt thuật toán trên bằng ngôn ngữ lập trình C++

```cpp
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

int knapsack(int W, vector<Item> items)
{
  int n = items.size();

  vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

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
        dp[i][j] = max(dp[i - 1][j], items[i - 1].value + dp[i - 1][j - items[i - 1].weight]);
      }
    }
  }

  printItems(W, items, dp);

  return dp[n][W];
}

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
```

4. Thực hiện bài toán với bộ dữ liệu

```cpp

struct Item
{
  string name;
  int weight;
  int value;
};

  vector<Item> items = {
      {"A", 15, 30, 0},
      {"B", 10, 25, 0},
      {"C", 2, 2, 0},
      {"D", 4, 6, 0},
  };

  int M = 55;

```

```output
Chon A Voi khoi luong: 15 kg  Voi gia tri: 30 VND
Chon B Voi khoi luong: 10 kg  Voi gia tri: 25 VND
Chon C Voi khoi luong: 2 kg  Voi gia tri: 2 VND
Chon D Voi khoi luong: 4 kg  Voi gia tri: 6 VND
Tong trong luong co the mang: 55 kg
Tong gia tri lay duoc: 63 VND
```

5. Đánh giá thời gian thực hiện của thuật toán

```text
- Độ phức tạp của thuật toán là O(n^2)
```
