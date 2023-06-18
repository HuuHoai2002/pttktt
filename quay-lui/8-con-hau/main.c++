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
