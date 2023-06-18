## Các công việc

1. Mô tả chi tiết thuật toán "Thuật toán tìm dãy con có tổng bằng M quay lui"

```text
Thuật toán quay lui để giải bài toán lộ trình của quân mã trên bàn cờ sẽ thực hiện như sau:
- Bắt đầu từ ô đầu tiên có tọa độ (x0, y0), ta đánh dấu ô này đã được đi qua.
- Với mỗi bước đi tiếp theo của quân mã, ta kiểm tra xem ô đó có nằm trên bàn cờ không, có bị trùng lặp với các ô đã đi qua không, nếu không ta đánh dấu ô đó đã đi qua và tiếp tục thực hiện đệ quy để tìm các bước đi tiếp theo.
- Nếu tất cả các ô trên bàn cờ đã được đi qua thì ta đã tìm được lộ trình phủ toàn bộ bàn cờ, ta in ra lộ trình này và kết thúc thuật toán.
- Nếu không tìm được lộ trình phủ toàn bộ bàn cờ, ta quay lui và thử các bước đi khác.
```

2. Chỉ rõ phương pháp thiết kế thuật toán trong thuật toán vừa nêu

```text
- Sử dụng phương pháp quay lui để tìm lộ trình của quân mã trên bàn cờ.
- Sử dụng đệ quy để thực hiện các bước đi tiếp theo của quân mã.
```

3. Cài đặt thuật toán trên bằng ngôn ngữ lập trình C++

```cpp
#include "../../helpers/utilities.hpp"
#include <iomanip>

using namespace std;

const int MAXN = 1005;

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

  visited[x][y] = false;

  path.pop_back(); // xóa ô (x, y) khỏi đường đi, chỉ xóa nếu không tìm được đường đi, quay lui

  return false;
}

int main()
{

  if (dfs(0, 0, 1) == false)
  {
    cout << "Khong tim thay duong di...";
  }

  return 0;
}
```

4. Thực hiện bài toán với bộ dữ liệu

```output
(0,0) (1,2) (2,4) (1,6) (2,8) (4,7) (6,8) (8,7) (7,5) (5,6) (3,7) (1,8) (2,6) (3,8) (5,7) (7,8) (8,6) (6,7) (4,8) (3,6) (1,7) (2,5) (4,6) (2,7) (3,5) (5,4) (6,6) (5,8) (7,7) (8,5) (7,3) (6,5) (8,4) (7,6) (6,4) (4,5) (3,3) (1,4) (2,2)
(4,1) (5,3) (7,2) (5,1) (3,2) (1,1) (2,3) (1,5) (3,4) (1,3) (2,1) (4,2) (6,1) (8,2) (7,4) (5,5) (4,3) (3,1) (5,2) (4,4) (6,3) (7,1) (8,3) (6,2) (8,1)
```

5. Đánh giá thời gian thực hiện của thuật toán

```text
- Thời gian thực hiện của thuật toán phụ thuộc vào kích thước của bàn cờ. Độ phức tạp của thuật toán là O(n^(n^2)), vì trong trường 8 ô tiếp theo cho mỗi ô đã đi qua trên bàn cờ nên số lần gọi đệ quy lên đến 8^(n^2). Tuy nhiên, trong thực tế, thuật toán quay lui sẽ được cắt ngắn bởi việc phát hiện ra sự trùng lặp hoặc đi ra khỏi bàn cờ, giúp giảm thời gian thực hiện.
```
