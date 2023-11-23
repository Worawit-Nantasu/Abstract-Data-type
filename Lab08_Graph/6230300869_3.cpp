#include <iostream>

using namespace std;

int menu() {
  int choose;
  cout << "=====================\n";
  cout << "         MENU\n";
  cout << "=====================\n";
  cout << "1)Insert Graph\n";
  cout << "2)BFS\n";
  cout << "3)Show path\n";
  cout << "4)Exit\n";
  cout << "Please choose > ";
  cin >> choose;
  getchar();
  return choose;
}

struct node {
  int value;
  struct node *next;
};

struct node *tail = NULL;

struct node *insert(struct node *head, int data) {
  struct node *p, *node;
  if (head == NULL) {
    head = new struct node;
    head->value = data;
    head->next = NULL;
  } else {
    node = new struct node;
    node->value = data;
    node->next = NULL;
    p = head;
    while (p->next != NULL) {
      p = p->next;
    }
    p->next = node;
  }
  return head;
}

struct node *enQueue(struct node *head, int data) {
  struct node *nod = new struct node;
  nod->value = data;
  nod->next = NULL;
  if (head == NULL && tail == NULL) {
    head = nod;
    tail = nod;
  } else {
    tail->next = nod;
    tail = nod;
  }
  return head;
}

struct node *deQueue(struct node *head) {
  struct node *del;
  if (head != NULL) {
    del = head;
    head = head->next;
    delete (del);
  } else {
    cout << "empty!" << endl;
  }
  return head;
}

void printPath(int pred[], int i) {
  if (pred[pred[i]] == 1) {
    cout << pred[i] << "," << i;
  } else {
    printPath(pred, pred[i]);
    cout << "," << pred[i] << "," << i;
  }
}

int main() {
  struct node *adj[8], *head = NULL;
  struct node *nodes = new struct node;
  int pass[8], pred[8], d[8];
  int i, j, choose, num, u, v, m;
  string str, temp;
  for (i = 0; i < 8; i++) {
    adj[i] = NULL;
    pass[i] = 0;
    pred[i] = -1;
    d[i] = -1;
  }
  while (choose != 4) {
    choose = menu();
    switch (choose) {
    case 1:
      for (i = 0; i < 8; i++) {
        cout << "Input #" << i << " : ";
        for (int j = 0; j < 8; j++) {
          cin >> num;
          if (num != -1) {
            adj[i] = insert(adj[i], num);
          } else {
            break;
          }
        }
      }
      cout << endl;
      break;

    case 2:
      cout << "Input Source node : ";
      cin >> num;
      pass[num] = 1;
      d[num] = 0;
      pred[num] = num;
      head = enQueue(head, num);
      while (head != NULL) {
        u = head->value;
        nodes = adj[u]; // เริ่มต้นใหม่ที่ nodes = adj[u]
        while (nodes != NULL) {
          v = nodes->value;
          if (pass[v] == 0) {
            pass[v] = 1;
            d[v] = d[u] + 1;
            pred[v] = u;
            head = enQueue(head, v);
          }
          nodes = nodes->next;
        }
        head = deQueue(head);
      }
      cout << "     |  d  | pred" << endl;
      cout << "=====================" << endl;
      for (i = 0; i < 8; i++) {
        cout << i << " | "
             << "  " << d[i] << "   " << pred[i];
        cout << endl;
      }
      cout << endl;
      break;

    case 3:
      cout << "Input destination : ";
      cin >> choose; // ใช้ choose แทน m
      pass[choose] = 1;
      cout << pass[choose] << ",";
      printPath(pred, choose); // ใช้ choose แทน m
      cout << endl;
      break;
    }
  }
}