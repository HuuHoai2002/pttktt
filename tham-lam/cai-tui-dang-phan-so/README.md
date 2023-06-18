## Các công việc

1. Mô tả chi tiết thuật toán "Thuật toán cái túi dạng phân số tham lam"

```text
1. Sắp xếp các mặt hàng theo tỷ lệ giá trị/trọng lượng giảm dần.
2. Lần lượt chọn các mặt hàng có tỷ lệ này lớn nhất để đưa vào túi.
3. Nếu trọng lượng túi vượt quá sức chứa, thì chỉ lấy một phần của mặt hàng đó để đưa vào túi.
```

2. Chỉ rõ phương pháp thiết kế thuật toán trong thuật toán vừa nêu

```text
1. Sắp xếp các mặt hàng theo một tiêu chí nào đó (trong trường hợp này là tỷ lệ giá trị/trọng lượng).
2. Chọn lựa theo một tiêu chí nào đó (trong trường hợp này là tỷ lệ giá trị/trọng lượng).
3. Xác định điều kiện dừng (trong trường hợp này là khi túi đã đầy).
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

  int M = 21;

  int totalWeight = 0;   // tổng trọng lượng các đồ đã chọn
  double totalValue = 0; // tổng giá trị các đồ đã chọn
  int i = 0;             // chỉ số của đồ

  // thuật toán tham lam
  while (totalWeight < M && i < items.size())
  {
    // Nếu trọng lượng của đồ hiện tại nhỏ hơn hoặc bằng trọng lượng còn lại của túi
    if (totalWeight + items[i].weight <= M)
    {
      totalWeight += items[i].weight;
      totalValue += items[i].value;
      cout << "Chon " << items[i].name << " Voi khoi luong: " << items[i].weight << " kg "
           << " Voi gia tri: " << items[i].value << " VND "
           << " Voi ti le khoi luong: "
           << "100%" << endl;
    }
    else
    {
      // Nếu trọng lượng của đồ hiện tại lớn hơn trọng lượng còn lại của túi thì sẽ chọn một phần của đồ đó
      double remainingWeight = M - totalWeight;            // trọng lượng còn lại của túi
      double fraction = remainingWeight / items[i].weight; // tỉ lệ của trọng lượng còn lại của túi và trọng lượng của đồ đã chọn

      totalWeight += remainingWeight; // cập nhật lại trọng lượng của túi đã chọn

      totalValue += fraction * items[i].value; // cập nhật lại giá trị của túi đã chọn

      cout << "Chon " << items[i].name << " Voi khoi luong: " << remainingWeight << " kg "
           << " Voi gia tri: " << fraction * items[i].value << " VND "
           << "Voi ti le trong luong: "
           << fraction * 100 << "%" << endl;
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

int M = 21;

```

```output
Name Weight Value Ratio
B 10 25 2.5
A 15 30 2
D 4 6 1.5
C 2 2 1

Chon B Voi khoi luong: 10 kg  Voi gia tri: 25 VND  Voi ti le khoi luong: 100%
Chon A Voi khoi luong: 11 kg  Voi gia tri: 22 VND Voi ti le trong luong: 73.3333%
Tong trong luong co the mang: 21 kg
Tong trong luong lay duoc: 21 kg
Tong gia tri lay duoc: 47 VND
```

5. Đánh giá thời gian thực hiện của thuật toán

```text
- Độ phức tạp của thuật toán là O(n^2), nó phụ thuộc vào độ phức tạp của hàm sắp xếp ở đây ta dùng bubble sort.
```
