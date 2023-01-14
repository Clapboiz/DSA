/*
Họ tên: Phạm Công Lập
MSSV: 21522281
*/

#include <iostream>
#define max 100
using namespace std;

int random(int minN, int maxN)
{
  return minN + rand() % (maxN + 1 - minN);
}

void InputAuto(int X[], int &n)
{
  srand((unsigned int)time(NULL));
  n = random(30, 50);
  for (int i = 0; i < n; i++)
  {
    X[i] = random(100, 999);
  }
}

void InputAscendingAuto(int Y[], int &n)
{
  srand((unsigned int)time(NULL));
  n = random(30, 50);
  do
  {
    Y[0] = random(100, 999);
  } while (Y[0] > 130);
  for (int i = 1; i < n; i++)
  {
    do
    {
      Y[i] = random(100, 999);
    } while (abs(Y[i] - Y[i - 1]) > 15 || Y[i] <= Y[i - 1]);
  }
}

void OutputArray(int A[], int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << A[i] << " ";
  }
  cout << endl;
}

void LinearSearch(int A[], int n)
{
  int x;
  cout << "Nhap x = ";
  cin >> x;
  A[n] = x;
  int i = 0;
  while (A[i] != x)
    i++;
  if (i < n)
    cout << "Co x trong mang" << endl;
  else
    cout << "Khong co x trong mang" << endl;
}

void BinarySearch(int A[], int n)
{
  int x;
  cout << "Nhap x = ";
  cin >> x;
  int left = 0;
  int right = n - 1;
  int mid;
  while (left <= right)
  {
    mid = (left + right) / 2;
    if (x == A[mid])
      break;
    if (x > A[mid])
      left = mid + 1;
    else
      right = mid - 1;
  }
  if (left > right)
    cout << "Khong co x trong mang" << endl;
  else
    cout << "Co x trong mang" << endl;
}

void InterpolationSearch(int A[], int n)
{
  int x;
  cout << "Nhap x = ";
  cin >> x;
  int left = 0;
  int right = n - 1;
  int mid;
  while (left <= right)
  {
    mid = left + (right - left) * (x - A[left]) / (A[right] - A[left]);
    if (x == A[mid])
      break;
    if (x > A[mid])
      left = mid + 1;
    else
      right = mid - 1;
  }
  if (left > right)
    cout << "Khong co x trong mang" << endl;
  else
    cout << "Co x trong mang" << endl;
}

void Compare(int A[], int n)
{
  int x, dem1 = 1, dem2 = 0, dem3 = 0;
  cout << "Nhap x = ";
  cin >> x;
  A[n] = x;
  int i = 0;
  while (A[i] != x)
  {
    i++;
    dem1++;
  }
  int left = 0;
  int right = n - 1;
  int mid;
  while (left <= right)
  {
    dem2++;
    mid = (left + right) / 2;
    if (x == A[mid])
      break;
    if (x > A[mid])
      left = mid + 1;
    else
      right = mid - 1;
  }
  int l = 0;
  int r = n - 1;
  int m;
  while (l <= r)
  {
    dem3++;
    m = l + (r - l) * (x - A[l]) / (A[r] - A[l]);
    if (x == A[m])
      break;
    if (x > A[m])
      l = m + 1;
    else
      r = m - 1;
  }
  cout << "So lan thuc hien:" << endl;
  cout << "LinearSearch: " << dem1 << endl;
  cout << "BinarySearch: " << dem2 << endl;
  cout << "InterpolationSearch: " << dem3 << endl;
}

int main()
{
  cout << "---------------------- MENU --------------------" << endl;
  cout << "1. Tao mang" << endl;
  cout << "	A. Tao mang arrayX" << endl;
  cout << "	B. Tao mang arrayY" << endl;
  cout << "2. Xuat mang" << endl;
  cout << "	A. Xuat mang arrayX" << endl;
  cout << "	B. Xuat mang arrayY" << endl;
  cout << "3. Tim kiem tuyen tinh" << endl;
  cout << "	A. Ap dung mang arrayX" << endl;
  cout << "	B. Ap dung mang arrayY" << endl;
  cout << "4. Tim kiem nhi phan, ap dung mang arrayY" << endl;
  cout << "5. Tim kiem noi suy, ap dung mang arrayY" << endl;
  cout << "6. So sanh so lan tim kiem, ap dung mang arrayY" << endl;
  cout << "7. Ket thuc" << endl;
  cout << "---------------------- END ---------------------" << endl;
  cout << "	Xin moi lua chon: ...!!!" << endl;
  int x, n = 0;
  int X[max];
  int Y[max];
  do
  {
    cin >> x;
    if (x == 1)
    {
      char a;
      cin >> a;
      if (a == 'A')
        InputAuto(X, n);
      else if (a == 'B')
        InputAscendingAuto(Y, n);
      else if (a == '7')
        x = 7;
    }
    else if (x == 2)
    {
      char a;
      cin >> a;
      if (a == 'A')
        OutputArray(X, n);
      else if (a == 'B')
        OutputArray(Y, n);
      else if (a == '7')
        x = 7;
    }
    else if (x == 3)
    {
      char a;
      cin >> a;
      if (a == 'A')
        LinearSearch(X, n);
      else if (a == 'B')
        LinearSearch(Y, n);
      else if (a == '7')
        x = 7;
    }
    else if (x == 4)
      BinarySearch(Y, n);
    else if (x == 5)
      InterpolationSearch(Y, n);
    else if (x == 6)
      Compare(Y, n);
  } while (x != 7);
}