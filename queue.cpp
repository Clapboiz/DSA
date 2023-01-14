#include <iostream>
#include <string.h>
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

struct Queue
{
  Node *head;
  Node *tail;
  Queue()
  {
    this->head = NULL;
    this->tail = NULL;
  }
};

bool isFull(Queue s)
{
  int j = 0;
  for (Node *i = s.head; i != NULL; i = i->next)
    j++;
  return j >= SIZE_LINKEDLIST;
}

bool isEmpty(Queue q)
{
  return q.head == NULL;
}

void EnQueue(Queue &q, Node *e)
{
  if (q.head != NULL)
  {
    Node *p = q.tail;
    p->next = e;
    q.tail = e;
  }
  else
  {
    q.head = e;
    q.tail = e;
  }
}

void DeQueue(Queue &q)
{
  if (isEmpty(q))
    return;
  if (q.head->next == NULL)
  {
    Node *p = q.head;
    delete p;
    q.head = NULL;
    q.tail = NULL;
  }
  else
  {
    Node *p = q.head;
    q.head = p->next;
    delete p;
  }
}

int Front(Queue q)
{
  if (q.head == NULL)
  {
    cout << "Queue rong!" << endl;
    return -1;
  }
  return q.head->info;
}

int Rear(Queue q)
{
  if (q.head == NULL)
  {
    cout << "Queue rong!" << endl;
    return -1;
  }
  return q.tail->info;
}

void PrintQueue(Queue q)
{
  if (!isEmpty(q))
  {
    for (Node *i = q.head; i != NULL; i = i->next)
    {
      cout << i->info << " ";
    }
  }
  else
  {
    cout << "Empty!";
  }
  cout << endl;
}

void RandomQueue(Queue &q)
{
  srand(time(NULL));
  int a, b, n;
  cout << "Enter size of stack: ";
  cin >> n;
  cout << "Enter range (a b): ";
  cin >> a >> b;
  while (n--)
  {
    EnQueue(q, new Node(1 + rand() % b));
  }
}

int main()
{
  int option;
  Queue q;
  do
  {
    cout << "\n=========== Menu =========" << endl;
    cout << "\t1. Enqueue: " << endl;
    cout << "\t2. Dequeue: " << endl;
    cout << "\t3. Front: " << endl;
    cout << "\t4. Rear: " << endl;
    cout << "\t5. Random: " << endl;
    cout << "Stack bay gio la: ";
    PrintQueue(q);
    cout << endl;
    cout << "Moi ban chon: ";
    cin >> option;
    cout << endl;

    switch (option)
    {
    case 1:
      int val;
      cout << "Moi ban nhap: ";
      cin >> val;
      EnQueue(q, new Node(val));
      break;
    case 2:
      DeQueue(q);
      break;
    case 3:
      cout << "Front: " << Front(q) << endl;
      break;
    case 4:
      cout << "Rear: " << Rear(q) << endl;
      break;
    case 5:
      RandomQueue(q);
      break;
    default:
      option = 0;
      break;
    }
  } while (option);
  return 0;
}