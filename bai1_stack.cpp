#include <bits/stdc++.h>
using namespace std;
const int SIZE_LINKEDLIST = 100;

struct Node
{
  int info;
  Node *next;
  Node(int info)
  {
    this->info = info;
    this->next = NULL;
  }
};

struct Stack
{
  Node *head;
  Stack()
  {
    this->head = NULL;
  }
};

void Push(Stack &s, Node *e)
{
  if (s.head != NULL)
  {
    Node *t = s.head;
    s.head = e;
    e->next = t;
  }
  else
    s.head = e;
}
int Pop(Stack &s)
{
  if (s.head == NULL)
  {
    cout << "Stack rong";
    return -1;
  }
  Node *p = s.head;
  int t = p->info;
  s.head = p->next;
  delete p;
  return t;
}

bool isEmpty(Stack s)
{
  return s.head == NULL;
}

bool isFull(Stack s)
{
  int j = 0;
  for (Node *i = s.head; i != NULL; i = i->next)
    j++;
  return j >= SIZE_LINKEDLIST;
}

void PrintStack(Stack &l)
{
  if (!isEmpty(l))
  {
    for (Node *i = l.head; i != NULL; i = i->next)
      cout << i->info << " ";
  }
  else
    cout << "Empty!";
  cout << endl;
}
int Top(Stack s)
{
  if (s.head == NULL)
  {
    cout << "Empty!" << endl;
    return -1;
  }
  return s.head->info;
}

void RandomStack(Stack &s)
{
  srand(time(NULL));
  int a, b, n;
  cout << "Enter size of stack: ";
  cin >> n;
  cout << "Enter range (a b): ";
  cin >> a >> b;
  while (n--)
  {
    Push(s, new Node(1 + rand() % b));
  }
}
int main()
{
  int option;
  Stack s;
  do
  {
    cout << "\n\n =========== Menu =========" << endl;
    cout << "\t1. Push" << endl;
    cout << "\t2. Pop" << endl;
    cout << "\t3. Top" << endl;
    cout << "\t4. Randomize" << endl;

    cout << "Your current stack: ";
    PrintStack(s);
    cout << endl;
    cout << "Moi ban chon: ";
    cin >> option;
    switch (option)
    {
    case 1:
      int val;
      cout << "Enter value: ";
      cin >> val;
      Push(s, new Node(val));
      break;
    case 2:
      Pop(s);
      break;
    case 3:
      cout << "Top: " << Top(s) << endl;
      break;
    case 4:
      RandomStack(s);
      break;
    }
  } while (option);
  return 0;
}