#include <iostream>
#include <string>
using namespace std;
struct SV {
	int ID;
	string NAME;
	float GPA;
};
struct Node {
	SV info;
	Node* next;
};
struct List {
	Node* Head;
	Node* Tail;
};
void CreateList(List &l) {
	l.Head = l.Tail = NULL;
}
Node* CreateNode(SV x) {
	Node* p = new Node();
	if (p == NULL) exit(1);
	else {
		p ->info = x;
		p->next = NULL;
		return p;
	}
}
void AddHead(List& l, Node* p) {
	if (l.Head == NULL) {
		l.Head = l.Tail = p;
	}
	else {
		p->next = l.Head;
		l.Head = p;
	}
}
void AddTail(List& l, Node* p)
{
	if (l.Head == NULL){
		l.Head = p;
		l.Tail = l.Head;
	}
	else
	{
		l.Tail->next = p;
		l.Tail = p;
	}
}
void NhapDSSV(List& l) {
	CreateList(l);
	int n;
	cout << "NHAP SO SINH VIEN: ";
	cin >> n;
	int i = 0;
	while (i < n) {
		SV x;
		cout << "NHAP ID: "; cin >> x.ID; cin.ignore();
		cout << "NHAP HO TEN: "; getline(cin, x.NAME);
		cout << "NHAP GPA: "; cin >> x.GPA;
		AddTail(l, CreateNode(x));
		i++;
	}
}
void InDSSV(List l)
{
	if (l.Head == NULL)
		cout << "Danh sach rong!";
	else
	{
		Node* p = l.Head;
		cout << "Danh sach sinh vien:\n";
		while (p != NULL) {
			cout << "MSSV: " << p->info.ID << "\n";
      cout << "HO VA TEN: " << p->info.NAME << "\n";
      cout << "GPA: " << p->info.GPA << endl;
			p = p->next;
		}
	}
}
Node * SearchID(List l, int x)
{
	Node* p;
	p = l.Head;
	while ((p != NULL) && (p->info.ID != x))
		p = p->next;
	return p;
}
Node* SearchNAME(List l, string x)
{
	Node* p;
	p = l.Head;
	while ((p != NULL) && (p->info.NAME != x))

		p = p->next;

	return p;
}
Node* SearchGPA(List l, float x)
{
	Node* p;
	p = l.Head;
	while ((p != NULL) && (p->info.GPA != x))
		p = p->next;
	return p;
}

int main() {
	List l;
	CreateList(l);
	NhapDSSV(l);
			InDSSV(l);
			cout << endl;
			int id;
			cout << "Nhap id can tim: ";
			cin >> id;
			SearchID(l, id);
			cout << endl;
			string name;
			cout << "Nhap ten can tim: ";
			cin.ignore();
			getline(cin, name);
			SearchNAME(l, name);
			cout << endl;
			float gpa;
			cout << "Nhap GPA can tim: ";
			cin >> gpa;
			SearchGPA(l, gpa);
			cout << endl;
}
