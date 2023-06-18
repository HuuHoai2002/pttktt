#include <iostream>
using namespace std;

long factorialQHD(int n)
{
  long *arr = new long[n + 1];

  arr[0] = arr[1] = 1;

  for (int i = 2; i <= n; i++)
  {
    arr[i] = i * arr[i - 1];
  }

  long result = arr[n];

  delete[] arr;

  return result;
}

long factorialCDT(int n)
{
  if (n == 0 || n == 1)
  {
    return 1;
  }

  if (n % 2 == 0)
  {
    return factorialCDT(n / 2) * factorialCDT(n / 2);
  }
  else
  {
    return factorialCDT((n - 1) / 2) * factorialCDT((n - 1) / 2) * n;
  }
}

int main()
{
  int n = 5;
  long result = factorialQHD(n);
  cout << n << "! =  " << result << endl;
  return 0;
}