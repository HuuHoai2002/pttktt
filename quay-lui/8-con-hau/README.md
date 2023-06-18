## Các công việc

1. Mô tả chi tiết thuật toán "Thuật toán tìm dãy con có tổng bằng M quay lui"

```text
- Bước 1: Tạo một bàn cờ 8x8 và khởi tạo tất cả các ô trên bàn cờ với giá trị 0.
- Bước 2: Bắt đầu quá trình đặt hậu bằng cách đặt 5 hậu đầu tiên lên bàn cờ. Để đơn giản, ta có thể đặt 5 hậu này lần lượt trên các hàng từ 1 đến 5.
- Bước 3: Sử dụng thuật toán quay lui để đặt các hậu còn lại lên bàn cờ.
- Bước 4: Trong quá trình đặt hậu, ta kiểm tra xem vị trí đặt hậu có hợp lệ hay không. Một vị trí đặt hậu được xem là hợp lệ nếu không có hậu nào đang đứng trên cùng một hàng, cột hoặc đường chéo với nó. Nếu vị trí đặt hậu không hợp lệ, ta quay lui lại và thử các vị trí khác.
- Bước 5: Nếu ta đặt được 8 hậu lên bàn cờ mà không có hậu nào tấn công nhau, ta in ra bàn cờ đó là một lời giải của bài toán.
- Bước 6: Tiếp tục quay lui để thử các vị trí khác cho các hậu còn lại.
```

2. Chỉ rõ phương pháp thiết kế thuật toán trong thuật toán vừa nêu

```text
- Sử dụng thuật toán quay lui để thử từng vị trí đặt hậu trên bàn cờ.
- Kiểm tra xem vị trí đặt hậu có hợp lệ hay không bằng cách kiểm tra xem có hậu nào đang đứng trên cùng một hàng, cột hoặc đường chéo với nó hay không.
- Nếu vị trí đặt hậu không hợp lệ, ta tiếp tục thử các vị trí khác.
- Nếu ta đặt được 8 hậu lên bàn cờ mà không có hậu nào tấn công nhau, ta in ra bàn cờ đó là một lời giải của bài toán.
```

3. Cài đặt thuật toán trên bằng ngôn ngữ lập trình C++

```cpp
#include <iostream>
using namespace std;

const int N = 8;       // kích thước bàn cờ
int board[N][N] = {0}; // ban đầu chưa có quân hậu nào được đặt

void printSolution()
{ // in ra cách đặt 8 con hậu lên bàn cờ
  static int count = 0;
  cout << "Solution " << ++count << ":" << endl;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
      cout << board[i][j] << " ";
    cout << endl;
  }
  cout << endl;
}

/// @brief Kiểm tra xem có thể đặt quân hậu vào vị trí (row, col) không
/// @param row Vị trí hàng
/// @param col Vị trí cột
/// @return true nếu có thể đặt quân hậu vào vị trí (row, col), ngược lại false
bool isSafe(int row, int col)
{
  int i, j;
  for (i = 0; i < col; i++) // kiểm tra hàng
    if (board[row][i])
      return false;

  for (i = row, j = col; i >= 0 && j >= 0; i--, j--) // kiểm tra đường chéo trái
    if (board[i][j])
      return false;

  for (i = row, j = col; j >= 0 && i < N; i++, j--) // kiểm tra đường chéo phải
    if (board[i][j])
      return false;

  return true;
}

/// @brief Giải bài toán 8 con hậu
/// @param col Cột hiện tại
/// @return true nếu tìm được cách đặt 8 con hậu, ngược lại false
bool solveNQUtil(int col)
{
  // đặt các quân hậu vào các cột từ 0 đến N-1
  if (col == N)
  {
    // nếu đặt được N quân hậu, in ra cách đặt và kết thúc thuật toán
    printSolution();
    return true;
  }

  bool res = false;

  for (int i = 0; i < N; i++)
  {
    // nếu vị trí (i, col) an toàn
    if (isSafe(i, col))
    {
      board[i][col] = 1;                 // đặt quân hậu vào vị trí (i, col)
      res = solveNQUtil(col + 1) || res; // tiếp tục đặt các quân hậu vào các cột tiếp theo nếu có thể
      board[i][col] = 0;                 // trả lại giá trị ban đầu để thử các vị trí khác
    }
  }

  return res;
}

int main()
{
  if (!solveNQUtil(0))
  {
    cout << "Ooops Khong tim duoc loi giai!" << endl;
  }
  return 0;
}

```

4. Thực hiện bài toán với bộ dữ liệu

```output
Solution 1:
1 0 0 0 0 0 0 0
0 0 0 0 0 0 1 0
0 0 0 0 1 0 0 0
0 0 0 0 0 0 0 1
0 1 0 0 0 0 0 0
0 0 0 1 0 0 0 0
0 0 0 0 0 1 0 0
0 0 1 0 0 0 0 0

Solution 2:
...
```

5. Đánh giá thời gian thực hiện của thuật toán

```text
- Thời gian thực hiện của thuật toán O(n!).
```
