## Các công việc

1. Mô tả chi tiết thuật toán "Sắp xếp nhanh chia để trị"

```text
- Thuật toán này hoạt động bằng cách chọn một phần tử làm chốt (pivot) và phân chia mảng thành hai phần, một phần có các phần tử nhỏ hơn hoặc bằng chốt và một phần có các phần tử lớn hơn hoặc bằng chốt. Sau đó, thuật toán QuickSort được áp dụng đệ quy cho hai phần này.
- Phương pháp chia để trị là một kỹ thuật thiết kế thuật toán trong đó bài toán ban đầu được chia thành các bài toán con nhỏ hơn và giống nhau. Sau đó, các bài toán con này được giải quyết độc lập và kết hợp lại để tạo ra lời giải cho bài toán ban đầu.
```

2. Chỉ rõ phương pháp thiết kế thuật toán trong thuật toán vừa nêu

```text
- QuickSort là sử dụng đệ quy để giải quyết bài toán. Đầu tiên, chọn một phần tử làm chốt và phân chia mảng thành hai phần. Sau đó, áp dụng đệ quy cho hai phần này để sắp xếp chúng.
```

3. Cài đặt thuật toán trên bằng ngôn ngữ lập trình C++

```cpp
#include "../../helpers/utilities.hpp"

using namespace std;

void swap(int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}

/// @brief Hàm chia mảng thành 2 phần, phần đầu nhỏ hơn phần sau
/// @param arr Mảng cần chia
/// @param low chỉ số phần tử đầu của mảng cần chia
/// @param high chỉ số phần tử cuối của mảng cần chia
/// @return chỉ số phần tử chốt
int partition(vector<int> &arr, int low, int high)
{
  int pivot = arr[high];

  int i = (low - 1);

  for (int j = low; j <= high - 1; j++)
  {
    if (arr[j] <= pivot)
    {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }

  swap(&arr[i + 1], &arr[high]);

  return (i + 1);
}
/// @brief Hàm sắp xếp mảng
/// @param arr Mảng cần sắp xếp
/// @param low Chỉ số phần tử đầu của mảng cần sắp xếp
/// @param high Chỉ số phần tử cuối của mảng cần sắp xếp
void quickSort(vector<int> &arr, int low, int high)
{
  if (low < high)
  {
    int pi = partition(arr, low, high); // Chỉ số phần tử chốt

    quickSort(arr, low, pi - 1);  // gọi đệ quy cho phần mảng bên trái của chốt
    quickSort(arr, pi + 1, high); // gọi đệ quy cho phần mảng bên phải của chốt
  }
}

void printArray(vector<int> arr)
{
  for (auto item : arr)
  {
    cout << item << " ";
  }
}

int main()
{
  vector<int> arr;

  readFileSpaceSeparated("data.txt", arr);

  quickSort(arr, 0, arr.size() - 1);

  cout << "Mang da sap xep nhanh: " << endl;

  printArray(arr);

  return 0;
}
```

4. Thực hiện bài toán với bộ dữ liệu 10 7 8 9 1 5 2 -9 10

```output
Mang sau khi sap xep nhanh:
-9 1 2 5 7 8 9 10 10
```

5. Đánh giá thời gian thực hiện của thuật toán

```text
- Độ phức tạp của thuật toán QuickSort là O(nlogn) trong trường hợp trung bình và tốt nhất, và là O(n^2) trong trường hợp xấu nhất.
- Trong trường hợp trung bình, thuật toán QuickSort thực hiện nhiều hơn logn lần so sánh để sắp xếp n phần tử. Do đó, độ phức tạp của thuật toán là O(nlogn).
- Tuy nhiên, trong trường hợp xấu nhất, QuickSort sẽ thực hiện nhiều hơn n lần so sánh để sắp xếp n phần tử. Trường hợp xấu nhất xảy ra khi dãy ban đầu đã được sắp xếp hoặc đảo ngược thứ tự. Trong trường hợp này, độ phức tạp của thuật toán là O(n^2).
- Để giảm thiểu trường hợp xấu nhất, người ta thường sử dụng các biến tham chiếu để chọn phần tử chốt ngẫu nhiên hoặc tối ưu hơn, và sử dụng phương pháp chia để trị để sắp xếp các phần tử con.
```
