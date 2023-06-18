#include "../../helpers/utilities.hpp"

using namespace std;

void swap(int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}

/// @brief Hàm chia mảng thành 2 phần, phần đầu nhỏ hơn phần sau
/// @param arr Mảng cần chia
/// @param low chỉ số phần tử đầu của mảng cần chia
/// @param high chỉ số phần tử cuối của mảng cần chia
/// @return chỉ số phần tử chốt
int partition(vector<int> &arr, int low, int high)
{
  int pivot = arr[high];

  int i = (low - 1);

  for (int j = low; j <= high - 1; j++)
  {
    if (arr[j] <= pivot)
    {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }

  swap(&arr[i + 1], &arr[high]);

  return (i + 1);
}
/// @brief Hàm sắp xếp mảng
/// @param arr Mảng cần sắp xếp
/// @param low Chỉ số phần tử đầu của mảng cần sắp xếp
/// @param high Chỉ số phần tử cuối của mảng cần sắp xếp
void quickSort(vector<int> &arr, int low, int high)
{
  if (low < high)
  {
    int pi = partition(arr, low, high); // Chỉ số phần tử chốt

    quickSort(arr, low, pi - 1);  // gọi đệ quy cho phần mảng bên trái của chốt
    quickSort(arr, pi + 1, high); // gọi đệ quy cho phần mảng bên phải của chốt
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

  quickSort(arr, 0, arr.size() - 1);

  cout << "Mang da sap xep nhanh: " << endl;

  printArray(arr);

  return 0;
}