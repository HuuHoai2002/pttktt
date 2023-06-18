#include "../../helpers/utilities.hpp"
#include <iomanip>

using namespace std;

const int MAXN = 1005; // giới hạn số ô bàn cờ

bool visited[MAXN][MAXN]; // visited[i][j] = true nếu ô (i, j) đã được đi qua

int n = 8, x0, y0; // kích thước bàn cờ, vị trí ban đầu của quân mã

int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2}; // 8 hướng đi của quân mã
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1}; // 8 hướng đi của quân mã

vector<pair<int, int>> path; // lưu lại đường đi của quân mã

// kiểm tra ô (x, y) có hợp lệ không, hợp lệ nếu nằm trong bàn cờ và chưa đi qua
bool isValid(int x, int y)
{
  return (x >= 1 && x <= n && y >= 1 && y <= n && !visited[x][y]);
}

/// @brief Tìm đường đi của quân mã
/// @param x Tọa độ x
/// @param y Tọa độ y
/// @param cnt Số ô đã đi qua
/// @return
bool dfs(int x, int y, int cnt)
{
  visited[x][y] = true; // đánh dấu ô (x, y) đã đi qua

  path.push_back({x, y}); // lưu lại đường đi

  if (cnt == n * n)
  {
    for (int i = 0; i < path.size(); i++)
    {
      cout << "(" << path[i].first << "," << path[i].second << ") ";
    }

    return true;
  }

  for (int i = 0; i < 8; i++)
  {
    int nx = x + dx[i]; // tọa độ x của ô tiếp theo
    int ny = y + dy[i]; // tọa độ y của ô tiếp theo

    // nếu ô tiếp theo hợp lệ thì đi tiếp
    if (isValid(nx, ny))
    {
      if (dfs(nx, ny, cnt + 1))
      {
        return true;
      }
    }
  }

  visited[x][y] = false; // bỏ đánh dấu ô (x, y) đã đi qua

  path.pop_back(); // xóa ô (x, y) khỏi đường đi, chỉ xóa nếu không tìm được đường đi, quay lui

  return false;
}

int main()
{

  if (dfs(1, 1, 1) == false)
  {
    cout << "Ooops Khong tim thay duong di...";
  }

  return 0;
}