#include "../../helpers/utilities.hpp"

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
