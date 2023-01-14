#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <time.h>
#include <math.h>
#include <ctime>

using namespace std;
float random()
{
    return rand() + (rand() % 1000) * pow(10, -3);
}

float random2()
{
    int a = 39000 + rand() % (99000 - 39000 + 1);
    if (a == 99000)
        return a;
    else
        return a + (rand() % 1000) * pow(10, -3);
}

void nhap_thu_cong(float* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void khoi_tao_tu_dong(float* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = random();
    }
}

void khoi_tao_tu_dong_2(float* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = random2();
    }
}

void xuat_mang(float* arr, int n)
{
    for (int i = 0; i < 100; i++)
    {
        cout << fixed << setprecision(3) << arr[i] << endl;
    }
}

bool comparator_tang_dan(float a, float b)
{
    return a < b;
}

bool comparator_giam_dan(float a, float b)
{
    return a > b;
}

void swap(float& a, float& b)
{
    float temp = a;
    a = b;
    b = temp;
}

float selection_sort(float* arr, int n, bool cmp(float, float))
{
    time_t begin = clock();
    for (int i = 0; i < n; i++)
    {
        int m = i;
        for (int j = i + 1; j < n; j++)
        {
            if (cmp(arr[j], arr[m]))
            {
                m = j;
            }
        }
        swap(arr[i], arr[m]);
    }
    // return 1;
    time_t end = clock();
    return (float)(end - begin) / CLOCKS_PER_SEC;
}

float insertion_sort(float* arr, int n, bool cmp(float, float))
{
    time_t begin = clock();
    for (int i = 1; i < n; i++)
    {
        if (!(cmp(arr[i - 1], arr[i]) || arr[i - 1] == arr[i]))
        {
            for (int j = 0; j < i; j++)
            {
                if (cmp(arr[i], arr[j]) || arr[i] == arr[j])
                {
                    float temp = arr[i];
                    for (int k = i; k >= j + 1; k--)
                    {
                        arr[k] = arr[k - 1];
                    }
                    arr[j] = temp;
                    break;
                }
            }
        }
    }

    time_t end = clock();
    return (float)(end - begin);
}

int main()
{
    srand(time(0));
    float* arr = new float[1000000];
    int n;
    while (1)
    {
        system("cls");
        cout << "\t\t\t=============== Menu ===============\n" << endl;
        cout << "1. nhap mang thu cong." << endl;
        cout << "2. khoi tao mang tu dong 100000 phan tu voi gia tri bat ky." << endl;
        cout << "3. khoi tao mang tu dong 100000 phan tu voi gia tri trong khoang [39000;99000]." << endl;
        cout << "4. sap xep tang dan bang thuat toan selection sort." << endl;
        cout << "5. sap xep giam dan bang thuat toan selection sort." << endl;
        cout << "6. sap xep tang dan bang thuat toan insertion sort." << endl;
        cout << "7. sap xep giam dan bang thuat toan insertion sort." << endl;
        cout << "8. so sanh thoi gian chay cua selection sort va insertion sort tren 15 bo gia tri." << endl;
        cout << "9. xuat mang." << endl;
        cout << "10. thoat chuong trinh." << endl;
        cout << "lua chon: ";
        int c;
        cin >> c;
        switch (c)
        {
        case 1:
        {
            system("cls");
            cout << "nhap so luong phan tu:";
            cin >> n;
            nhap_thu_cong(arr, n);
            system("cls");
            cout << "nhap lieu thanh cong!" << endl;
            system("pause");
            break;
        }
        case 2:
        {
            system("cls");
            n = 100000;
            khoi_tao_tu_dong(arr, n);
            cout << "khoi tao thanh cong!" << endl;
            system("pause");
            break;
        }
        case 3:
        {
            system("cls");
            n = 100000;
            khoi_tao_tu_dong_2(arr, n);
            cout << "khoi tao thanh cong!" << endl;
            system("pause");
            break;
        }
        case 4:
        {
            system("cls");
            cout << "sap xep tang dan theo thuat selection sort thanh cong!" << endl;
            cout << "thoi gian chay: " << fixed << setprecision(5) << selection_sort(arr, n, comparator_tang_dan) << endl;
            system("pause");
            break;
        }
        case 5:
        {
            system("cls");
            cout << "sap xep giam dan theo thuat selection sort thanh cong!" << endl;
            cout << "thoi gian chay: " << fixed << setprecision(5) << selection_sort(arr, n, comparator_giam_dan) << endl;
            system("pause");
            break;
        }
        case 6:
        {
            system("cls");
            cout << "sap xep tang dan theo thuat insertion sort thanh cong!" << endl;
            cout << "thoi gian chay: " << fixed << setprecision(5) << insertion_sort(arr, n, comparator_tang_dan) << endl;
            system("pause");
            break;
        }
        case 7:
        {
            system("cls");
            cout << "sap xep giam dan theo thuat insertion sort thanh cong!" << endl;
            cout << "thoi gian chay: " << fixed << setprecision(5) << insertion_sort(arr, n, comparator_giam_dan) << endl;
            system("pause");
            break;
        }
        case 8:
        {
            system("cls");
            float* arr2 = new float[1000000];
            float* arr3 = new float[1000000];
            float* arr4 = new float[1000000];
            n = 100000;
            for (int i = 0; i < 15; i++)
            {
                khoi_tao_tu_dong_2(arr, n);
                for (int j = 0; j < n; j++)
                {
                    arr2[j] = arr3[j] = arr4[j] = arr[j];
                }
                cout << "Bo gia tri thu " << i + 1 << endl;
                cout << "Thoi gian sap xep tang dan:" << endl;
                cout << "+ Selection sort: " << selection_sort(arr, n, comparator_tang_dan) << endl;
                cout << "+ Insertion sort: " << insertion_sort(arr2, n, comparator_tang_dan) << endl;
                cout << "Thoi gian sap xep giam dan:" << endl;
                cout << "+ Selection sort: " << selection_sort(arr, n, comparator_giam_dan) << endl;
                cout << "+ Insertion sort: " << insertion_sort(arr2, n, comparator_giam_dan) << endl;
            }
            delete[] arr2;
            delete[] arr3;
            delete[] arr4;
            system("pause");
            break;
        }
        case 9:
        {
            system("cls");
            xuat_mang(arr, n);
            system("pause");
            break;
        }
        case 10:
        {
            return 1;
        }
        }
    }
    system("pause");
    return 1;
}