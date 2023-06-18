## Các công việc

1. Mô tả chi tiết thuật toán "Tính giai thừa chia để trị"

```text
Thuật toán tính n! theo phương pháp chia để trị được thực hiện như sau:
- Thuật toán tính giai thừa bằng chia để trị sử dụng phương pháp đệ quy. Để tính giai thừa của một số n, ta chia bài toán thành hai phần: tính giai thừa của n/2 và tính bình phương của kết quả đó. Nếu n là số lẻ, ta nhân kết quả với n. Cuối cùng, ta trả về kết quả tính được.

Thuật toán tính n! theo pp Quy hoạch động được thực hiện như sau:
- Thuật toán tính giai thừa bằng quy hoạch động sử dụng một mảng để lưu trữ các giá trị giai thừa đã tính được. Ban đầu, ta khởi tạo mảng với giá trị đầu tiên là 1. Sau đó, ta dùng vòng lặp for để tính giá trị giai thừa của các số từ 2 đến n và lưu vào mảng. Cuối cùng, ta trả về giá trị giai thừa của n là phần tử cuối cùng của mảng.
```

2. Chỉ rõ phương pháp thiết kế thuật toán trong thuật toán vừa nêu

```text
- Nếu n = 0 hoặc n = 1, trả về 1.
- Nếu n là số chẵn, tính giai thừa của n/2 và tính bình phương của kết quả đó.
- Nếu n là số lẻ, tính giai thừa của (n-1)/2, tính bình phương của kết quả đó, và nhân với n.

QHĐ
- Khởi tạo mảng với giá trị đầu tiên là 1.
- Sử dụng vòng lặp for để tính giá trị giai thừa của các số từ 2 đến n và lưu vào mảng.
- Trả về giá trị giai thừa của n là phần tử cuối cùng của mảng.
```

3. Cài đặt thuật toán trên bằng ngôn ngữ lập trình C++

```cpp
#include <iostream>

using namespace std;

// chia để trị
int factorial(int n)
{
  if (n == 0)
  {
    return 1;
  }

  int half_factorial = factorial(n / 2); // n/2! = 1*2*3*...*(n/2), chia để trị

  if (n % 2 == 0)
  {
    return half_factorial * half_factorial;
  }
  else
  {
    return half_factorial * half_factorial * n;
  }
}

int main()
{
  int n;

  cout << "Nhap n: ";
  cin >> n;

  int result = factorial(n);

  cout << n << "! = " << result << endl;

  return 0;
}
```

4. Thực hiện bài toán với bộ dữ liệu

```output

```

5. Đánh giá thời gian thực hiện của thuật toán

```text
- Thuật toán tính giai thừa bằng chia để trị có độ phức tạp O(log n) do ta chia bài toán thành hai phần và giảm độ lớn của n mỗi lần đệ quy. Do đó, thời gian thực hiện của thuật toán rất nhanh và hiệu quả đối với các giá trị lớn của n. Tuy nhiên, do sử dụng đệ quy nên có thể gặp phải vấn đề về bộ nhớ đối với các giá trị quá lớn của n.
- Thuật toán tính giai thừa bằng quy hoạch động có độ phức tạp O(n), tương đương với số lần lặp của vòng lặp for. Do đó, thời gian thực hiện của thuật toán là tuyến tính và không bị phụ thuộc vào giá trị của n. Vì vậy, thuật toán này có thời gian thực hiện rất nhanh và hiệu quả.
```
