## Các công việc

1. Mô tả chi tiết thuật toán "Thuật toán đổi tiền xu tham lam"

```text
1. Nhập vào số tiền cần đổi và khởi tạo một vector chứa các mệnh giá đồng xu có sẵn để đổi.
2. Khởi tạo biến count bằng 0 để đếm số đồng xu cần thiết để đổi được số tiền cần đổi.
3. Sử dụng vòng lặp for để duyệt qua các mệnh giá đồng xu có sẵn, bắt đầu từ mệnh giá cao nhất đến mệnh giá thấp nhất.
4. Trong mỗi vòng lặp, sử dụng vòng lặp while để đổi đồng xu cho đến khi số tiền cần đổi nhỏ hơn mệnh giá đồng xu đang xét.
5. Nếu số tiền cần đổi vẫn lớn hơn hoặc bằng mệnh giá đồng xu đang xét, ta sẽ trừ số tiền đó đi mệnh giá đồng xu đang xét và tăng biến count lên 1.
6. Lặp lại quá trình này cho đến khi số tiền cần đổi bằng 0.
7. In ra kết quả, tức là số đồng xu cần thiết để đổi được số tiền cần đổi.
```

2. Chỉ rõ phương pháp thiết kế thuật toán trong thuật toán vừa nêu

```text
- Thuật toán này được thiết kế theo phương pháp tham lam, tức là luôn chọn đồng xu có mệnh giá lớn nhất có thể đổi được cho đến khi không thể đổi tiếp nữa. Việc chọn đồng xu lớn nhất đảm bảo số lượng đồng xu đổi ra nhỏ nhất.
```

3. Cài đặt thuật toán trên bằng ngôn ngữ lập trình C++

```cpp
#include "../helper/utilities.hpp"

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
  // cú pháp for thông thường
  // for (int i = 0; i < coins.size(); i++)
  // {
  //   while (n >= coins[i])
  //   {
  //     n -= coins[i];
  //     count++;
  //   }
  // }

  cout << "So dong xu toi thieu can doi la: " << count << endl;

  return 0;
}
```

4. Thực hiện bài toán với bộ dữ liệu n = 12345

```output
Nhập số tiền cần đổi (n): 12345
Số đồng xu đổi ra ít nhất là: 5
```

5. Đánh giá thời gian thực hiện của thuật toán

```text
- Độ phức tạp của thuật toán là O(n^2) độ phức tạp của thuật toán này phụ thuộc vào độ phức tạp của giải thuật sắp xếp mà ta dùng.
```
