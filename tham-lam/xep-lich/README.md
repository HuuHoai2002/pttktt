## Các công việc

1. Mô tả chi tiết thuật toán "Thuật toán xếp lịch tham lam"

```text
1. Sắp xếp các hoạt động theo thời gian kết thúc tăng dần.
2. Chọn hoạt động đầu tiên và đưa vào lịch làm việc.
3. Duyệt lần lượt các hoạt động còn lại, nếu thời điểm bắt đầu của hoạt động đó lớn hơn hoặc bằng thời điểm kết thúc của hoạt động cuối cùng trong lịch làm việc thì đưa hoạt động đó vào lịch làm việc.
4. Lặp lại bước trên cho đến khi duyệt hết tất cả các hoạt động.
```

2. Chỉ rõ phương pháp thiết kế thuật toán trong thuật toán vừa nêu

```text
- Sử dụng phương pháp tham lam (greedy algorithm) để giải quyết bài toán.
- Tìm cách xác định được hoạt động nào có thể được đưa vào lịch làm việc một cách tối ưu.
- Sắp xếp các hoạt động theo thời gian kết thúc tăng dần, sau đó chọn lần lượt các hoạt động có thời điểm bắt đầu lớn hơn hoặc bằng thời điểm kết thúc của hoạt động cuối cùng trong lịch làm việc.
```

3. Cài đặt thuật toán trên bằng ngôn ngữ lập trình C++

```cpp
#include "../helper/utilities.hpp"

using namespace std;

struct Activity
{
  int id;
  int start;
  int finish;
};

void printActivities(vector<Activity> &activities)
{
  cout << "ID Start  Finish" << endl;
  for (auto &activity : activities)
  {
    cout << activity.id << "  " << activity.start << "  " << activity.finish << endl;
  }
}

void swap(Activity &a, Activity &b)
{
  Activity temp = a;
  a = b;
  b = temp;
}

void sortActivities(vector<Activity> &activities)
{
  // sắp xếp các hoạt động theo thời gian kết thúc
  for (int i = 0; i < activities.size() - 1; i++)
  {
    for (int j = i + 1; j < activities.size(); j++)
    {
      if (activities[i].finish > activities[j].finish)
      {
        swap(activities[i], activities[j]);
      }
    }
  }
}

int main()
{
  vector<Activity> activities = {
      // {1, 1, 3},
      // {2, 3, 4},
      // {3, 4, 6},
      // {4, 2, 8},
      // {5, 6, 10},
      // {6, 4, 13},
      // {7, 10, 14},
      // {8, 12, 15},
      // {9, 11, 16},
      {1, 1, 4},
      {2, 3, 5},
      {3, 0, 6},
      {4, 5, 7},
      {5, 3, 9},
      {6, 5, 9},
      {7, 6, 10},
      {8, 8, 11},
      {9, 8, 12},
      {10, 2, 14},
      {11, 12, 16},
  };

  sortActivities(activities);

  // printActivities(activities);

  // xếp lịch, in ra các hoạt động được chọn
  int lastFinish = 0;

  cout << "ID Start  Finish" << endl;

  // thuật toán tham lam
  for (auto &activity : activities)
  {
    if (activity.start >= lastFinish)
    {
      cout << activity.id << "  " << activity.start << "  " << activity.finish << endl;
      lastFinish = activity.finish;
    }
  }

  return 0;
}
```

4. Thực hiện bài toán với bộ dữ liệu

```cpp
struct Activity
{
  int id;
  int start;
  int finish;
};

vector<Activity> activities = {
      // {1, 1, 3},
      // {2, 3, 4},
      // {3, 4, 6},
      // {4, 2, 8},
      // {5, 6, 10},
      // {6, 4, 13},
      // {7, 10, 14},
      // {8, 12, 15},
      // {9, 11, 16},
      {1, 1, 4},
      {2, 3, 5},
      {3, 0, 6},
      {4, 5, 7},
      {5, 3, 9},
      {6, 5, 9},
      {7, 6, 10},
      {8, 8, 11},
      {9, 8, 12},
      {10, 2, 14},
      {11, 12, 16},
  };
```

```output
ID Start  Finish
1  1  4
4  5  7
8  8  11
11  12  16
```

5. Đánh giá thời gian thực hiện của thuật toán

```text
- Độ phức tạp của thuật toán là O(n^2) độ phức tạp của thuật toán này phụ thuộc vào độ phức tạp của giải thuật sắp xếp mà ta dùng.
```
