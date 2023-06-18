#include "../../helpers/utilities.hpp"

using namespace std;

/// @brief Hàm trộn 2 mảng con của mảng arr
/// @param arr Mang đầu vào
/// @param low Chỉ số phần tử đầu tiên
/// @param mid Chỉ số phần tử giữa
/// @param high Chỉ số phần tử cuối cùng
void merge(vector<int> &arr, int low, int mid, int high)
{
  int n1 = mid - low + 1; // số phần tử của mảng con bên trái
  int n2 = high - mid;    // số phần tử của mảng con bên phải

  vector<int> left(n1);  // mảng con bên trái
  vector<int> right(n2); // mảng con bên phải

  // copy dữ liệu vào mảng con bên trái
  for (int i = 0; i < n1; i++)
  {
    left[i] = arr[low + i];
  }

  // copy dữ liệu vào mảng con bên phải
  for (int j = 0; j < n2; j++)
  {
    right[j] = arr[mid + 1 + j];
  }

  // i, j là chỉ số của mảng con bên trái và bên phải, k là chỉ số của mảng arr
  int i = 0, j = 0, k = low;

  // trộn 2 mảng con vào mảng arr
  while (i < n1 && j < n2)
  {
    if (left[i] <= right[j])
    {
      arr[k] = left[i];
      i++;
    }
    else
    {
      arr[k] = right[j];
      j++;
    }
    k++;
  }

  // copy các phần tử còn lại của mảng con bên trái vào mảng arr
  while (i < n1)
  {
    arr[k] = left[i];
    i++;
    k++;
  }

  // copy các phần tử còn lại của mảng con bên phải vào mảng arr
  while (j < n2)
  {
    arr[k] = right[j];
    j++;
    k++;
  }
}

/// @brief Hàm sắp xếp trộn
/// @param arr Mảng cần sắp xếp
/// @param low Chỉ số phần tử đầu tiên
/// @param high Chỉ số phần tử cuối cùng
void mergeSort(vector<int> &arr, int low, int high)
{
  if (low < high)
  {
    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
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

  mergeSort(arr, 0, arr.size() - 1);

  cout << "Mang sau khi sap xep tron: " << endl;

  printArray(arr);

  return 0;
}