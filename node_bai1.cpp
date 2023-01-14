// Họ tên: Phạm Công Lập
// Mssv: 21522281

#include<iostream>
#define max 100
using namespace std;

//xây dựng cấu trúc NODE
struct NODE
{
	int info;
	NODE* next;
};
//xây dựng cấu trúc dslk đơn
struct List
{
	NODE* head;
	NODE* tail;
};
//khởi tạo dslk đơn
void CreateList(List& l)
{
	l.head = NULL;
	l.tail = NULL;
}
//khởi tạo node
NODE* CreateNode(int x)
{
	NODE* p = new NODE;
	p->info = x;
	p->next = NULL;
	return p;
}
//chèn node vào đầu danh sách
void AddHead(List& l, NODE* p)
{
	if (l.head == NULL)
	{
		l.head = p;
		l.tail = l.head;
	}
	else
	{
		p->next = l.head;
		l.head = p;
	}
}
//chèn node vào cuối danh sách
void AddTail(List& l, NODE* p)
{
	if (l.head == NULL)
	{
		l.head = p;
		l.tail = l.head;
	}
	else
	{
		l.tail->next = p;
		l.tail = p;
	}
}
//nhập giá trị cho danh sách theo phương pháp thủ công
void Input(List& l)
{
	int n, x;
	cin >> n;
	do
	{
		cin >> x;
		AddTail(l, CreateNode(x));
		n--;
	} while (n != 0);
}
//nhập giá trị cho danh sách từ mảng một chiều
void InputFromArray(int a[], int& n, List& l)
{
	int i = 0;
	cin >> n;
	do
	{
		cin >> a[i];
		AddTail(l, CreateNode(a[i]));
		i++;
	} while (i < n);
}
NODE* CheckNode(List l, int n)
{
	int i = 1;
	NODE* p = l.head;
	while (p != NULL && i < n / 2)
	{
		i++;
		p = p->next;
	}
	return p;
}
void AddAfterQ(List& l, NODE* Q, NODE* p)
{
	if (Q != NULL)
	{
		p->next = Q->next;
		Q->next = p;
		if (Q == l.tail) l.tail = p;
	}
	else AddHead(l, p);
}
//chèn node vào vị trí giữa
void AddMid(List& l, NODE* p, int n) // n là số node được nhập từ hàm InputFromArray
{
	if (l.head == NULL)
	{
		l.head = p;
		l.tail = l.head;
	}
	else
	{
		AddAfterQ(l, CheckNode(l, n), p);
	}
}
NODE* SearchNode(List l, int x)
{
	NODE* p = l.head;
	while (p != NULL && p->info != x) p = p->next;
	return p;
}

NODE* FindNode(List l, int x)
{
	NODE* p = l.head;
	NODE* q;
	do
	{
		q = p;
		p = p->next;
	} while (p != NULL && p->info != x);
	return q;
}
//thêm X đằng trước Y trong danh sách
void AddXBeforeY(List& l, int x, int y)
{
	NODE* Q;
	NODE* p = new NODE;
	p->info = x;
	Q = FindNode(l, y);
	if (Q != NULL)
	{
		p->next = Q->next;
		Q->next = p;
		if (l.tail == Q) l.tail = p;
	}
	else AddTail(l, p);
}
//thêm X đằng sau Y trong danh sách
void AddXAfterY(List& l, int x, int y) 
{
	NODE* Q;
	NODE* p = new NODE;
	p->info = x;
	Q = SearchNode(l, y);
	if (Q != NULL) 
	{
		p->next = Q->next;
		Q->next = p;
		if (l.tail == Q) l.tail = p;
	}
	else AddHead(l, p); 
}
//in danh sách
void PrintList(List l) 
{
	NODE* p = l.head;
	while (p != NULL) 
	{
		cout << p->info << "\t";
		p = p->next;
	}
}
//in giá trị kèm địa chỉ
void PrintValueAndAddress(List l)
{
	NODE* p = l.head;
	while (p != NULL)
	{
		cout << p->info << "\t" << p << endl;
		p = p->next;
	}
}
//in node đầu vào cuối
void PrintHeadAndTail(List l)
{
	cout << l.head->info << "\t" << l.head << endl;
	cout << l.tail->info << "\t" << l.tail;
}
int random(int minN, int maxN) 
{
	return minN + rand() % (maxN + 1 - minN);
}
//nhập tự động
void InputAuto(List& l)
{
	srand((unsigned int)time(NULL));
	int n = random(39, 59);
	cout << n;
	for (int i = 0; i < n; i++)
	{
		AddTail(l, CreateNode(random(-99, 99)));
	}
}
int main()
{
	List l;
	int n;
	int a[max];
	CreateList(l);
	InputAuto(l);
	Input(l);
	InputFromArray(a, n, l); 
	AddMid(l, CreateNode(9), n);
	AddXBeforeY(l, 2, 4); 
	AddXAfterY(l, 2, 4); 
	PrintList(l);
	PrintHeadAndTail(l);
	PrintValueAndAddress(l);
}