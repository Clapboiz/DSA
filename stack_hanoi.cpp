#include <bits/stdc++.h>
using namespace std;
const int size_stak = 100;

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
  return j >= size_stak;
}

void PrintStack(Stack &l)
{
  string res = ">\t";
  if (!isEmpty(l))
  {
    for (Node *i = l.head; i != NULL; i = i->next)
    {
      res += to_string(i->info) + '\t';
    }
  }
  res += "<";
  reverse(res.begin(), res.end());
  cout << res << endl;
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

int main()
{
  int option;
  Stack a, b, c;
  do
  {
    cout << "\n\n =========== Menu =========" << endl;
    cout << "\t0. Creating Tower." << endl;
    cout << "\t1. A->B" << endl;
    cout << "\t2. B->A" << endl;
    cout << "\t3. B->C" << endl;
    cout << "\t4. C->B" << endl;
    cout << "\t5. C->A" << endl;
    cout << "\t6. A->C" << endl;
    cout << "\t7. Thua" << endl;

    cout << endl;
    cout << "Chose your option: ";
    cin >> option;
    if (option == 0)
    {
      int height;
      cout << "Enter tower's height: ";
      cin >> height;
      while (height--)
      {
        Push(a, new Node(height + 1));
      }
    }
    switch (option)
    {
    case 1: // A->B
      if (!isEmpty(a) && (isEmpty(b) || Top(a) < Top(b)))
        Push(b, new Node(Pop(a)));
      else
        cout << "Can't move" << endl;
      break;
    case 2: // B->A
      if (!isEmpty(b) && (isEmpty(a) || Top(b) < Top(a)))
        Push(a, new Node(Pop(b)));
      else
        cout << "Can't move" << endl;
      break;
    case 3: // B->C
      if (!isEmpty(b) && (isEmpty(c) || Top(b) < Top(c)))
        Push(c, new Node(Pop(b)));
      else
        cout << "Can't move" << endl;
      break;
    case 4: // C->B
      if (!isEmpty(c) && (isEmpty(b) || Top(c) < Top(b)))
        Push(b, new Node(Pop(c)));
      else
        cout << "Can't move" << endl;
      break;
    case 5: // C->A
      if (!isEmpty(c) && (isEmpty(a) || Top(c) < Top(a)))
        Push(a, new Node(Pop(c)));
      else
        cout << "Can't move" << endl;
      break;
    case 6: // A->B
      if (!isEmpty(a) && (isEmpty(c) || Top(a) < Top(c)))
        Push(c, new Node(Pop(a)));
      else
        cout << "Can't move" << endl;
      break;
    case 7:
      a = *(new Stack);
      b = *(new Stack);
      c = *(new Stack);
    default:
      break;
    }

    cout << "A tower:";
    PrintStack(a);
    cout << "=============================\n";
    cout << "B tower:";
    PrintStack(b);
    cout << "=============================\n";
    cout << "C tower:";
    PrintStack(c);

  } while (option <= 7 && option >= 0);
  return 0;
}
