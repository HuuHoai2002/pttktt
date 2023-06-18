## Các công việc

1. Mô tả chi tiết thuật toán "Thuật toán tìm dãy con có tổng bằng M quay lui"

```text
- Sử dụng phương pháp quay lui để duyệt qua tất cả các dãy con của dãy số đã cho.
- Với mỗi dãy con, tính tổng các phần tử trong dãy con đó. Nếu tổng bằng M, thì đưa dãy con đó vào danh sách kết quả.
- Thuật toán kết thúc khi đã duyệt qua tất cả các dãy con của dãy số.
```

2. Chỉ rõ phương pháp thiết kế thuật toán trong thuật toán vừa nêu

```text
- Sử dụng phương pháp quay lui để duyệt qua tất cả các dãy con của dãy số.
- Tại mỗi bước đệ quy, ta có thể thêm một phần tử vào dãy con hiện tại hoặc không thêm.
- Nếu tổng các phần tử trong dãy con đó bằng M, đưa dãy con đó vào danh sách kết quả.
- Nếu tổng các phần tử trong dãy con đó nhỏ hơn M, ta tiếp tục đệ quy đến các phần tử tiếp theo.
- Nếu tổng các phần tử trong dãy con đó lớn hơn M, ta quay lui để thử các phương án khác.
```

3. Cài đặt thuật toán trên bằng ngôn ngữ lập trình C++

```cpp
#include <iostream>
#include <vector>

using namespace std;

/// @brief Tìm tất cả các dãy con của một dãy số cho trước có tổng bằng M
/// @param nums Dãy số cho trước
/// @param M Tổng cần tìm
/// @param subseq Dãy con
/// @param res Kết quả
/// @param start Vị trí bắt đầu
void findSubsequences(vector<int> &nums, int M, vector<int> &subseq, vector<vector<int>> &res, int start)
{
  int sum = 0;

  for (int i = 0; i < subseq.size(); i++)
  {
    sum += subseq[i];
  }

  if (sum == M)
  {
    res.push_back(subseq);
  }

  if (sum < M)
  {
    for (int i = start; i < nums.size(); i++)
    {
      subseq.push_back(nums[i]);

      findSubsequences(nums, M, subseq, res, i + 1);

      subseq.pop_back();
    }
  }
}

/// @brief Tìm tất cả các dãy con của một dãy số cho trước có tổng bằng M
/// @param nums Dãy số cho trước
/// @param M Tổng cần tìm
/// @return Tất cả các dãy con
vector<vector<int>> findSubsequences(vector<int> &nums, int M)
{
  vector<vector<int>> res;
  vector<int> subseq;

  findSubsequences(nums, M, subseq, res, 0);

  return res;
}

int main()
{
  vector<int> nums = {5, 7, 1, 3, 2, 4, 5, 9, 8};

  int M = 11;

  vector<vector<int>> res = findSubsequences(nums, M);

  for (int i = 0; i < res.size(); i++)
  {
    for (int j = 0; j < res[i].size(); j++)
    {
      cout << res[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
```

4. Thực hiện bài toán với bộ dữ liệu 5, 7, 1, 3, 2, 4, 5, 9, 8

```output
5 1 3 2
5 1 5
5 2 4
7 1 3
7 4
1 3 2 5
1 2 8
3 8
2 4 5
2 9
```

5. Đánh giá thời gian thực hiện của thuật toán

```text
- Độ phức tạp thời gian của thuật toán là O(2^n), với n là số lượng phần tử trong dãy số.
```
