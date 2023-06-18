## Các công việc

1. Mô tả chi tiết thuật toán "Thuật toán cái túi với số vật phẩm vô hạn quy hoạch động"

```text
dp[j] += dp[j-i];

Trong đó dp[j] là số cách phân tích số j thành tổng của dãy các số nguyên dương và dp[j-i] là số cách phân tích số j-i thành tổng của dãy các số nguyên dương.

Công thức truy hồi này cho thấy rằng ta có thể tính số cách phân tích số j thành tổng của dãy các số nguyên dương bằng cách sử dụng kết quả đã tính toán cho các giá trị nhỏ hơn j. Cụ thể, ta có thể cộng dồn số cách phân tích số j-i thành tổng của dãy các số nguyên dương vào kết quả cuối cùng

```

2. Chỉ rõ phương pháp thiết kế thuật toán trong thuật toán vừa nêu

```text
- Sử dụng phương pháp quy hoạch động để giải quyết bài toán.
- Dùng mảng dp để lưu số cách phân tích số i thành tổng của dãy các số nguyên dương.
- Sử dụng công thức dp[j] += dp[j-i] để tính số cách phân tích số j với số i được thêm vào.
```

3. Cài đặt thuật toán trên bằng ngôn ngữ lập trình C++

```cpp
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
```

4. Thực hiện bài toán với bộ dữ liệu n = 5

```output
Co 7 cach phan tich 5 thanh tong cac so nguyen duong
```

5. Đánh giá thời gian thực hiện của thuật toán

```text
- Độ phức tạp của thuật toán là O(n^2)
```
