#include <iostream>
using namespace std;

struct record {
    int value;
    struct record *prev;
   struct record *next;
};

struct headtail {
    struct record *head;
    struct record *tail;
};
struct headtail insert(struct record *head, struct record *tail, int data) {
    struct headtail ht;
    struct record *node, *p;

  if (head == NULL && tail == NULL) {
      head = new struct record;
      head->value = data;
      head->next = NULL;
      head->prev = NULL;
      tail = head;
    } else {

      node = new struct record;
      node->value = data;
      node->next = head;
      node->prev = tail;
      tail->next = node;
      tail = node;
      head->prev = tail;
    }
    ht.head = head;
    ht.tail = tail;
    return ht;
}

int survival(struct record *head, int M) {
    int i;
    struct record *knocked, *ball;
    ball = head;
    while (ball != ball->next) {
      for (i = 0; i < M; i++) {
        ball = ball->next;
      }
      knocked = ball;
      ball->prev->next = ball->next;
      ball->next->prev = ball->prev;
      ball = ball->next;
      delete (knocked);
    }
    return ball->value;
}

int main() {
    struct headtail jose;
    jose.head = NULL;
    jose.tail = NULL;
    int N, M;
    cout << "M : ";
    cin >> M;
    cout << "N : ";
    cin >> N;
    for (int i = 1; i <= N; i++) {
      jose = insert(jose.head, jose.tail, i);
    }
    cout << "Winner is : " << survival(jose.head, M) << endl;
}
