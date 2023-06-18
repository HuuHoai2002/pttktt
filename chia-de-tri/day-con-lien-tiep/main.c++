#include "../../helpers/utilities.hpp"
#include <climits>

int max(int &a, int &b)
{
  return (a > b) ? a : b;
}

using namespace std;

/// @brief Tìm tổng lớn nhất của dãy con bắt đầu từ giữa
/// @param arr Mảng đầu vào
/// @param low Chỉ số bắt đầu của mảng con bên trái
/// @param mid Chỉ số giữa
/// @param high Chỉ số kết thúc của mảng con bên phải
/// @param maxLeft Giá trị trả về, chỉ số bắt đầu của dãy con có tổng lớn nhất
/// @param maxRight Giá trị trả về, chỉ số kết thúc của dãy con có tổng lớn nhất
/// @return Tổng lớn nhất của dãy con bắt đầu từ giữa
int maxCrossingSum(vector<int> arr, int low, int mid, int high, int &maxLeft, int &maxRight)
{
  // tính tổng bên trái
  int sum = 0;
  int left_sum = INT_MIN;
  // tìm tổng lớn nhất của dãy con bên trái
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
  // tìm tổng lớn nhất của dãy con bên phải
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
