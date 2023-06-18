#include "../../helpers/utilities.hpp"
#include <iomanip>

using namespace std;

struct Item
{
  string name;
  int weight;
  int value;
  double ratio;
};

/// @brief In ra các vật phẩm được chọn
/// @param items Danh sách các vật phẩm
void printItems(vector<Item> items)
{
  cout << "Name Weight Value Ratio" << endl;

  for (auto item : items)
  {
    cout << item.name << " " << item.weight << " " << item.value << " " << item.ratio << endl;
  }

  cout << endl;
}

void swap(Item &a, Item &b)
{
  Item temp = a;
  a = b;
  b = temp;
}

/// @brief Sắp xếp các vật phẩm theo tỉ lệ giá trị trên khối lượng
/// @param items Danh sách các vật phẩm
void sortItems(vector<Item> &items)
{
  // sắp xếp các vật phẩm theo tỉ lệ giá trị trên khối lượng
  for (int i = 0; i < items.size() - 1; i++)
  {
    for (int j = i + 1; j < items.size(); j++)
    {
      if (items[i].ratio < items[j].ratio)
      {
        swap(items[i], items[j]);
      }
    }
  }
}

int main()
{
  vector<Item> items = {
      {"A", 15, 30, 0},
      {"B", 10, 25, 0},
      {"C", 2, 2, 0},
      {"D", 4, 6, 0},
  };

  for (auto &item : items)
  {
    item.ratio = (double)item.value / item.weight;
  }

  sortItems(items);

  printItems(items);

  int W = 55;

  int totalWeight = 0;   // tổng trọng lượng các đồ đã chọn
  double totalValue = 0; // tổng giá trị các đồ đã chọn
  int i = 0;             // chỉ số của đồ

  // thuật toán tham lam
  while (totalWeight < W && i < items.size())
  {
    for (int j = 0; j < W / items[i].weight; j++)
    {
      if (totalWeight + items[i].weight <= W)
      {
        totalWeight += items[i].weight;
        totalValue += items[i].value;

        cout << "Chon " << items[i].name << " Voi khoi luong: " << items[i].weight << " kg "
             << " Voi gia tri: " << items[i].value << " VND "
             << endl;
      }
    }

    i++;
  }

  cout << "Tong trong luong co the mang: " << W << " kg" << endl;
  cout << "Tong trong luong lay duoc: " << totalWeight << " kg" << endl;
  cout << "Tong gia tri lay duoc: " << totalValue << " VND" << endl;

  return 0;
}