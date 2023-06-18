## Các công việc

1. Mô tả chi tiết thuật toán "Dãy con liên tiếp"

```text
1. Chia dãy số thành 2 phần bằng cách lấy phần giữa (mid).
2. Tìm dãy con liên tiếp có tổng lớn nhất trong 2 phần bằng cách đệ quy tìm dãy con liên tiếp có tổng lớn nhất trong từng phần.
3. Tìm dãy con liên tiếp có tổng lớn nhất bắt đầu từ phần tử ở giữa (mid) và kết thúc ở 2 phía trái và phải của dãy số.
4. So sánh tổng lớn nhất của 3 dãy con liên tiếp trên và chọn dãy có tổng lớn nhất là kết quả của thuật toán.
- Phương pháp chia để trị là một kỹ thuật thiết kế thuật toán trong đó bài toán ban đầu được chia thành các bài toán con nhỏ hơn và giống nhau. Sau đó, các bài toán con này được giải quyết độc lập và kết hợp lại để tạo ra lời giải cho bài toán ban đầu.
```

2. Chỉ rõ phương pháp thiết kế thuật toán trong thuật toán vừa nêu

```text
- Thuật toán sử dụng phương pháp chia để trị để tìm dãy con liên tiếp có tổng lớn nhất.
- Bước chia dãy số thành 2 phần bằng cách lấy phần giữa giúp giảm số lượng phần tử cần xét trong mỗi bước đệ quy.
- Tìm dãy con liên tiếp có tổng lớn nhất trong từng phần giúp tối ưu hóa việc tìm kiếm.
- Tìm dãy con liên tiếp có tổng lớn nhất bắt đầu từ phần tử ở giữa và kết thúc ở 2 phía trái và phải của dãy số giúp tìm được dãy con liên tiếp có tổng lớn nhất bao quát cả 2 phần của dãy số.
- So sánh 3 dãy con liên tiếp trên để chọn ra dãy có tổng lớn nhất.
```

3. Cài đặt thuật toán trên bằng ngôn ngữ lập trình C++

```cpp
#include "../../helpers/utilities.hpp"
#include <algorithm>
#include <climits>

int max(int &a, int &b)
{
  return (a > b) ? a : b;
}

using namespace std;

int maxCrossingSum(vector<int> arr, int low, int mid, int high, int &maxLeft, int &maxRight)
{
  // tính tổng bên trái
  int sum = 0;
  int left_sum = INT_MIN;
  for (int i = mid; i >= low; i--)
  {
    sum = sum + arr[i];
    if (sum > left_sum)
    {
      left_sum = sum;
      maxLeft = i;
    }
  }

  // tính tổng bên phải
  sum = 0;
  int right_sum = INT_MIN;
  for (int i = mid + 1; i <= high; i++)
  {
    sum = sum + arr[i];
    if (sum > right_sum)
    {
      right_sum = sum;
      maxRight = i;
    }
  }

  // trả về tổng lớn nhất của 2 bên
  return max(left_sum + right_sum, max(left_sum, right_sum));
}

/// @brief Tìm tổng lớn nhất của dãy con liên tiếp
/// @param arr  mảng đầu vào
/// @param low  chỉ số bắt đầu
/// @param high  chỉ số kết thúc
/// @param maxLeft  chỉ số bắt đầu của dãy con có tổng lớn nhất
/// @param maxRight  chỉ số kết thúc của dãy con có tổng lớn nhất
/// @return   tổng lớn nhất của dãy con liên tiếp
int maxSubArraySum(vector<int> arr, int low, int high, int &maxLeft, int &maxRight)
{
  if (low == high)
  {
    maxLeft = low;
    maxRight = high;

    return arr[low];
  }

  int mid = (low + high) / 2; // tìm chỉ số giữa, chia mảng thành 2 phần

  int leftMaxLeft, leftMaxRight, rightMaxLeft, rightMaxRight, crossMaxLeft, crossMaxRight;

  int leftMaxSum = maxSubArraySum(arr, low, mid, leftMaxLeft, leftMaxRight);          // tìm tổng lớn nhất của dãy con bên trái
  int rightMaxSum = maxSubArraySum(arr, mid + 1, high, rightMaxLeft, rightMaxRight);  // tìm tổng lớn nhất của dãy con bên phải
  int crossMaxSum = maxCrossingSum(arr, low, mid, high, crossMaxLeft, crossMaxRight); // tìm tổng lớn nhất của dãy con bắt đầu từ giữa

  // so sánh 3 tổng lớn nhất, trả về tổng lớn nhất trong 3 tổng đó
  if (leftMaxSum >= rightMaxSum && leftMaxSum >= crossMaxSum)
  {
    maxLeft = leftMaxLeft;
    maxRight = leftMaxRight;

    return leftMaxSum;
  }
  else if (rightMaxSum >= leftMaxSum && rightMaxSum >= crossMaxSum)
  {
    maxLeft = rightMaxLeft;
    maxRight = rightMaxRight;

    return rightMaxSum;
  }
  else
  {
    maxLeft = crossMaxLeft;
    maxRight = crossMaxRight;

    return crossMaxSum;
  }
}

int main()
{
  vector<int> arr;

  readFileSpaceSeparated("data.txt", arr);

  int maxLeft, maxRight;

  int max_sum = maxSubArraySum(arr, 0, arr.size() - 1, maxLeft, maxRight);

  cout << "Tong lon nhat cua day con lien tiep la: " << max_sum << endl;

  cout << "Day do la: ";

  for (int i = maxLeft; i <= maxRight; i++)
  {
    cout << arr[i] << " ";
  }

  return 0;
}
```

4. Thực hiện bài toán với bộ dữ liệu -2 1 -3 4 -1 2 1 -5 4

```output
Tong lon nhat cua day con lien tiep la: 6
Day do la: 4 -1 2 1
```

5. Đánh giá thời gian thực hiện của thuật toán

```text
- Độ phức tạp của thuật toán chia để trị để tìm dãy con liên tiếp có tổng lớn nhất là O(nlogn), trong đó n là số phần tử trong mảng.
- Vì thuật toán sử dụng phương pháp chia để trị, nên độ phức tạp sẽ phụ thuộc vào số lần chia mảng. Trong trường hợp tốt nhất, khi mảng đã được sắp xếp trước đó, số lần chia mảng sẽ là log(n), và do đó độ phức tạp sẽ là O(nlogn). Trong trường hợp xấu nhất, khi mảng không được sắp xếp và phải chia đều ở mỗi bước, số lần chia mảng sẽ là n, và do đó độ phức tạp sẽ là O(n^2). Tuy nhiên, trường hợp xấu nhất này rất hiếm khi xảy ra.

- Vì vậy, độ phức tạp trung bình của thuật toán là O(nlogn).
```
