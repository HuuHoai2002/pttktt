#include "../../helpers/utilities.hpp"

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
      subseq.push_back(nums[i]); // thêm phần tử vào dãy con

      findSubsequences(nums, M, subseq, res, i + 1); // tìm các dãy con bắt đầu từ vị trí i + 1

      subseq.pop_back(); // bỏ phần tử cuối cùng
    }
  }
}

/// @brief Tìm tất cả các dãy con của một dãy số cho trước có tổng bằng M
/// @param nums Dãy số cho trước
/// @param M Tổng cần tìm
/// @return Tất cả các dãy con
vector<vector<int>> findSubsequences(vector<int> &nums, int M)
{
  vector<vector<int>> res; // kết quả
  vector<int> subseq;      // dãy con

  findSubsequences(nums, M, subseq, res, 0);

  return res;
}

int main()
{
  vector<int> nums;

  readFileSpaceSeparated("data.txt", nums);

  int M;

  cout << "Nhap M: ";

  cin >> M;

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