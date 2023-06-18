## Các công việc

1. Mô tả chi tiết thuật toán "Sắp xếp trộn chia để trị"

```text
- Chia mảng ban đầu thành 2 mảng con bằng cách tìm chỉ số giữa m.
- Đệ quy sắp xếp 2 mảng con bên trái và bên phải.
- Trộn 2 mảng đã sắp xếp để tạo ra mảng mới đã sắp xếp.
```

2. Chỉ rõ phương pháp thiết kế thuật toán trong thuật toán vừa nêu

```text
- Thuật toán MergeSort được thiết kế dựa trên phương pháp chia để trị.
- Chia mảng thành 2 phần bằng cách tìm chỉ số giữa m.
- Đệ quy sắp xếp 2 mảng con bên trái và bên phải.
- Trộn 2 mảng đã sắp xếp để tạo ra mảng mới đã sắp xếp.
```

3. Cài đặt thuật toán trên bằng ngôn ngữ lập trình C++

```cpp
#include "../../helpers/utilities.hpp"

using namespace std;

void merge(vector<int> &arr, int low, int mid, int high)
{
  int n1 = mid - low + 1;
  int n2 = high - mid;

  vector<int> left(n1);
  vector<int> right(n2);

  for (int i = 0; i < n1; i++)
  {
    left[i] = arr[low + i];
  }

  for (int j = 0; j < n2; j++)
  {
    right[j] = arr[mid + 1 + j];
  }

  int i = 0, j = 0, k = low;

  while (i < n1 && j < n2)
  {
    if (left[i] <= right[j])
    {
      arr[k] = left[i];
      i++;
    }
    else
    {
      arr[k] = right[j];
      j++;
    }
    k++;
  }

  while (i < n1)
  {
    arr[k] = left[i];
    i++;
    k++;
  }

  while (j < n2)
  {
    arr[k] = right[j];
    j++;
    k++;
  }
}

/// @brief Hàm sắp xếp trộn
/// @param arr Mảng cần sắp xếp
/// @param low Chỉ số phần tử đầu tiên
/// @param high Chỉ số phần tử cuối cùng
void mergeSort(vector<int> &arr, int low, int high)
{
  if (low < high)
  {
    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
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

  mergeSort(arr, 0, arr.size() - 1);

  cout << "Mang sau khi sap xep tron: " << endl;

  printArray(arr);

  return 0;
}
```

4. Thực hiện bài toán với bộ dữ liệu 10 7 8 9 1 5 2 -9 10

```output
Mang sau khi sap xep tron:
-9 1 2 5 7 8 9 10 10
```

5. Đánh giá thời gian thực hiện của thuật toán

```text
- Độ phức tạp của thuật toán chia để trị sắp xếp trộn là O(nlogn), trong đó n là số phần tử trong mảng.
```
