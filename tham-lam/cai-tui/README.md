## Các công việc

1. Mô tả chi tiết thuật toán "Thuật toán cái túi với số vật phẩm vô hạn tham lam"

```text
1. Tính tỉ lệ giá trị trên khối lượng của mỗi đồ vật.
2. Sắp xếp các đồ vật theo tỉ lệ giá trị trên khối lượng giảm dần.
3. Lần lượt duyệt qua các đồ vật, chọn các đồ vật có tỉ lệ giá trị trên khối lượng cao nhất để đưa vào túi, đảm bảo tổng khối lượng các đồ vật đã chọn không vượt quá khối lượng tối đa của túi.
```

2. Chỉ rõ phương pháp thiết kế thuật toán trong thuật toán vừa nêu

```text
- Sử dụng phương pháp tham lam để giải quyết bài toán cái túi.
- Sắp xếp các đồ vật theo tỉ lệ giá trị trên khối lượng giảm dần, chọn các đồ vật có tỉ lệ cao nhất để đưa vào túi.
```

3. Cài đặt thuật toán trên bằng ngôn ngữ lập trình C++

```cpp
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

  int M = 55;

  int totalWeight = 0;   // tổng trọng lượng các đồ đã chọn
  double totalValue = 0; // tổng giá trị các đồ đã chọn
  int i = 0;             // chỉ số của đồ

  // thuật toán tham lam
  while (totalWeight < M && i < items.size())
  {
    for (int j = 0; j < M / items[i].weight; j++)
    {
      if (totalWeight + items[i].weight <= M)
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

  cout << "Tong trong luong co the mang: " << M << " kg" << endl;
  cout << "Tong trong luong lay duoc: " << totalWeight << " kg" << endl;
  cout << "Tong gia tri lay duoc: " << totalValue << " VND" << endl;

  return 0;
}
```

4. Thực hiện bài toán với bộ dữ liệu

```cpp

struct Item
{
  string name;
  int weight;
  int value;
  double ratio;
};

  vector<Item> items = {
      {"A", 15, 30, 0},
      {"B", 10, 25, 0},
      {"C", 2, 2, 0},
      {"D", 4, 6, 0},
  };

  int M = 55;

```

```output
Name Weight Value Ratio
B 10 25 2.5
A 15 30 2
D 4 6 1.5
C 2 2 1

Chon B Voi khoi luong: 10 kg  Voi gia tri: 25 VND
Chon B Voi khoi luong: 10 kg  Voi gia tri: 25 VND
Chon B Voi khoi luong: 10 kg  Voi gia tri: 25 VND
Chon B Voi khoi luong: 10 kg  Voi gia tri: 25 VND
Chon B Voi khoi luong: 10 kg  Voi gia tri: 25 VND
Chon D Voi khoi luong: 4 kg  Voi gia tri: 6 VND
Tong trong luong co the mang: 55 kg
Tong trong luong lay duoc: 54 kg
Tong gia tri lay duoc: 131 VND
```

5. Đánh giá thời gian thực hiện của thuật toán

```text
- Độ phức tạp của thuật toán là O(n^2), nó phụ thuộc vào độ phức tạp của hàm sắp xếp ở đây ta dùng bubble sort.
```
