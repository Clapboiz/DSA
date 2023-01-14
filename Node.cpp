#include <iostream>
#define MINN 100000

using namespace std;

struct Node
{
	int info;
	Node *next;
};

struct List
{
	Node *Head;
	Node *Tail;
};

void CreateList(List &l)
{
	l.Head = NULL;
	l.Tail = NULL;
}

Node *CreateNode(int x)
{
	Node *p = new Node;
	if (p == NULL)
		exit(1);
	p->info = x;
	p->next = NULL;
	return p;
}

// Them vao dau
void AddHead(List &l, Node *p)
{
	if (l.Head == NULL)
	{
		l.Head = p;
		l.Tail = l.Head;
	}
	else
	{
		p->next = l.Head;
		l.Head = p;
	}
}

// Them vao cuoi
void AddTail(List &l, Node *p)
{
	if (l.Head == NULL)
	{
		l.Head = p;
		l.Tail = l.Head;
	}
	else
	{
		l.Tail->next = p;
		l.Tail = p;
	}
}

// In danh sach
void PrintList(List l)
{
	cout << "Danh sach la : ";
	for (Node *i = l.Head; i != NULL; i = i->next)
	{
		if (i == l.Tail)
		{
			cout << i->info << endl;
			break;
		}
		cout << i->info << "-->";
	}
}

// Tao node co gia tri nhap tu ban phim
Node *Create_Node()
{
	Node *p = new Node;
	int x;
	cout << "Nhap info : ";
	cin >> x;
	p->info = x;
	p->next = NULL;
	return p;
}

// Tao node co gia tri x
Node *Create_Node(int x)
{
	Node *p = new Node;
	p->info = x;
	p->next = NULL;
	return p;
}

// Nhap tu ban phim
void InputFromKeyboard(List &l)
{
	int n;
	cout << "Nhap so node : ";
	cin >> n;
	while (n > 0)
	{
		AddTail(l, Create_Node());
		--n;
	}
}

// Them node vao truoc node Q
void AddBeforeQ(List &l, Node *p, Node *q)
{
	if (q != NULL)
	{
		p->next = q;
		if (q == l.Head)
		{
			l.Head = p;
		}
	}
	else
	{
		AddHead(l, p);
	}
}

// Them node vao sau node Q
void AddAfterQ(List &l, Node *p, Node *q)
{
	if (q != NULL)
	{
		p->next = q->next;
		q->next = p;
		if (q->next == l.Tail)
		{
			l.Tail = p;
		}
	}
	else
	{
		AddHead(l, p);
	}
}

// Nhap tu mang 1 chieu
void InputFromArray(List &l)
{
	int n;
	cout << "Nhap so luong node : ";
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap info : ";
		cin >> arr[i];
		AddTail(l, Create_Node(arr[i]));
	}
	int k = 0;
	for (Node *p = l.Head; p != NULL; p = p->next)
	{
		p->info = arr[k];
		k++;
	}
}

// In list + dia chi
void PrintListAddr(List l)
{
	for (Node *i = l.Head; i != NULL; i = i->next)
	{
		cout << "Gia tri node : " << i->info << " | Dia chi :  " << &(i->info) << "\n";
	}
}

// In gia tri dau va cuoi + dia chi
void PrintListHTAddr(List l)
{
	cout << "Gia tri Head : " << l.Head->info << " | Dia chi : " << &(l.Head->info) << "\n";
	cout << "Gia tri Tail : " << l.Tail->info << " | Dia chi : " << &(l.Tail->info) << "\n";
}

// 15. Tra ve node thu N trong danh sach

void print_N_index_node(List l)
{
	int n;
	cout << "Nhap n : ";
	cin >> n;
	int count = 1;
	Node *p = l.Head;
	while (p != NULL)
	{
		if (count == n)
		{
			cout << "Node thu " << n << " co info la : " << p->info << endl;
			break;
		}
		p = p->next;
		count++;
	}
}

// 17.Tim node co gia tri X va tra ve dia chi

Node *X_address(List l)
{
	int x;
	cout << "Nhap x : ";
	cin >> x;
	Node *p = l.Head;
	while (p != NULL)
	{
		if (p->info == x)
		{
			return &(*p);
		}
		p = p->next;
	}
	return NULL;
}

// 19. Tinh do dai danh sach

int lenOfList(List l)
{
	int count = 0;
	for (Node *p = l.Head; p != NULL; p = p->next)
	{
		count++;
	}
	return count;
}

// 21. Dem cac node co gia tri am va duong

void countNumber(List l)
{
	int pos_num = 0, neg_num = 0;
	for (Node *p = l.Head; p != NULL; p = p->next)
	{
		if (p->info > 0)
			pos_num++;
		else
			neg_num++;
	}
	cout << "So luong node co gia tri duong la: " << pos_num << endl;
	cout << "So luong node co gia tri am la: " << neg_num << endl;
}

// 23.1 Node co gia tri am lon nhat
int biggest_Negative(List l)
{
	Node *p = l.Head;
	int max = MINN;
	while (p != NULL)
	{
		if (p->info < 0)
		{
			(p->info > max) ? max = p->info : max = max;
		}
		p = p->next;
	}
	return max;
}
// 23.2 Node co gia tri le nho nhat

int biggest_Odd(List l)
{
	Node *p = l.Head;
	int max = 0;
	while (p != NULL)
	{
		if (p->info % 2 != 0)
		{
			(p->info > max) ? max = p->info : max = max;
		}
		p = p->next;
	}
	return max;
}

// 25.Cap nhat node X co gia tri Y moi

bool UpdateInfo(List &l)
{
	int x, y;
	cout << "Nhap x : ";
	cin >> x;
	cout << "Nhap y : ";
	cin >> y;
	Node *p = l.Head;
	while (p != NULL)
	{
		if (p->info == x)
		{
			p->info = y;
			return true;
		}
		p = p->next;
	}
	return false;
}

// 27.Tinh tong chan/le va so sanh

int CmpOddEven(List l)
{
	int odd_num = 0, even_num = 0;
	for (Node *p = l.Head; p != NULL; p = p->next)
	{
		if (p->info % 2 != 0)
			odd_num += p->info;
		else
			even_num += p->info;
	}
	if (odd_num > even_num)
		return 1;
	else if (odd_num == even_num)
		return 0;
	else
		return -1;
}

// 29. Dao nguoc danh sach

void ReverseList(List &l)
{
	if (l.Head == NULL)
		return;
	l.Tail = l.Head;
	Node *rev = NULL, *tmp = NULL;
	while (l.Head)
	{
		tmp = l.Head->next;
		l.Head->next = rev;
		rev = l.Head;
		l.Head = tmp;
	}
	l.Head = rev;
}

// 31. Tach danh sach tai node co info X

// 33. Xoa node cuoi danh sach

void RemoveTail(List &l)
{
	if (l.Head == NULL)
	{
		return;
	}
	for (Node *p = l.Head; p != NULL; p = p->next)
	{
		if (p->next == l.Tail)
		{
			delete l.Tail;
			p->next = NULL;
			l.Tail = p;
		}
	}
}

// 35. Noi 2 danh sach

// 37. Xoa toan bo node

void DeleteAll(List &l)
{
	Node *temp;
	while (l.Head != NULL)
	{
		temp = l.Head;
		l.Head = l.Head->next;
		delete temp;
	}
}

void Menu()
{
	cout << "============MENU=========\n";
	cout << "1. Tao danh sach\n";
	cout << "2. In danh sach\n";
	cout << "3. In ra info cua node thu n\n";
	cout << "4. In ra dia chi cua node co info X\n";
	cout << "5. In ra do dai danh sach\n";
	cout << "6. In ra so am lon nhat\n";
	cout << "7. In ra so le lon nhat\n";
	cout << "8. Update info cua node co gia tri X\n";
	cout << "9. So sanh tong so chan va tong so le\n";
	cout << "10. Dao nguoc danh sach\n";
	cout << "11. Xoa node cuoi cung\n";
	cout << "12. Xoa toan bo danh sach\n";
	cout << "13. Thoat\n";
	cout << "==========================";
}

int Option()
{
	int n = 0;
	cout << "\nChon option : ";
	cin >> n;
	if (n > 0 || n < 14)
	{
		return n;
	}
	else
	{
		return Option();
	}
}

void Menu_Process()
{
	int option = Option();
	switch (option)
	{
	case 1:
		List l;
		CreateList(l);
		InputFromKeyboard(l);
		break;
	case 2:
		PrintList(l);
		break;
	case 3:
		print_N_index_node(l);
		break;
	case 4:
		X_address(l);
		break;
	case 5:
		cout << "Do dai danh sach : " << lenOfList(l);
		break;
	case 6:
		cout << "So am lon nhat : " << biggest_Negative(l);
		break;
	case 7:
		cout << "So le lon nhat : " << biggest_Odd(l);
		break;
	case 8:
		UpdateInfo(l);
		break;
	case 9:
		cout << CmpOddEven(l);
		break;
	case 10:
		ReverseList(l);
		break;
	case 11:
		RemoveTail(l);
		break;
	case 12:
		DeleteAll(l);
		break;
	case 13:
		exit(1);
		break;
	}
}

int main()
{
	Menu();
	while (true)
	{
		Menu_Process();
	}
	return 0;
}