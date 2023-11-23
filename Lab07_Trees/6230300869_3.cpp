//
//  3.cpp
//  Lab07
//
//  Created by วรวิทย์ นันทะสุ on 5/9/2566 BE.
//

#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
using namespace std;

struct record {
  string value;
  struct record *left, *right;
};

struct Node {
  struct record *tree;
  struct Node *Next;
};

int menu() {
  int choose;
  cout << "=============Menu ===========\n";
  cout << "  1)  Input postorder\n";
  cout << "  2)  Print Expression tree\n";
  cout << "  3)  Exit\n";
  cout << " Please choose > ";
  cin >> choose;
  getchar();
  return choose;
}

typedef struct Node *Stack;

Stack CreateStack(void) {
  Stack data;
  data = new struct Node;
  if (data == NULL)
    cout << "Out of space!!!" << endl;
  data->Next = NULL;
  return data;
}

void Push(struct record *x, Stack data) {
  Stack tmp;

  tmp = new struct Node;
  if (tmp == NULL)
    cout << "Out of space!!!";
  else {
    tmp->Next = data->Next;
    tmp->tree = x;
    data->Next = tmp;
  }
}

int IsEmpty(Stack data) { return data->Next == NULL; }

struct record *Top(Stack data) {
  if (!IsEmpty(data)) {
    return data->Next->tree;
  } else {
    return NULL;
  }
}

void Pop(Stack data) {
  Stack tmp;
  if (IsEmpty(data))
    cout << "Empty Stack!" << endl;
  else {
    tmp = data->Next;
    data->Next = data->Next->Next;
    delete (tmp);
  }
}

void Inorder(struct record *tree) {
  if (tree == NULL) {
    return;
  } else {
    Inorder(tree->left);
    cout << tree->value << " ";
    Inorder(tree->right);
  }
}

void Postorder(struct record *tree) {
  if (tree == NULL) {
    return;
  } else {
    Postorder(tree->left);
    Postorder(tree->right);
    cout << tree->value << " ";
  }
}

int main() {
  Stack data;
  struct record *tree, *tmp;
  int choose;
  string str;
  char chr;
  data = CreateStack();
  while (true) {
    choose = menu();
    switch (choose) {
    case 1:
      cout << "Input : ";
      while (true) {
        cin >> str;
        tree = new record;
        tree->value = str;
        if (str == ".") {
          break;
        } else {
          if (str == "+" || str == "-" || str == "*" || str == "/") {
            tree->right = Top(data);
            Pop(data);
            tree->left = Top(data);
            Pop(data);
          } else {
            tree->right = NULL;
            tree->left = NULL;
          }
          Push(tree, data);
          chr = getchar();
        }
      }
      break;
    case 2:
      cout << "Inorder : ";
      Inorder(Top(data));
      cout << endl;
      cout << "Postorder : ";
      Postorder(Top(data));
      cout << endl;
      break;
    }
  }
}
