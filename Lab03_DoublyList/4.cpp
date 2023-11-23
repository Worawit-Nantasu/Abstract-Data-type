#include <iostream>
using namespace std;

int menu(){
    int choose;
    cout << "========MENU=======\n";
    cout << "1) Insert\n";
    cout << "2) Print min to max / max to min\n";
    cout << "3) Exit\n";
    cout << "Please choose > ";
    cin >> choose;
    return choose;
}

struct record {
    int value;
    struct record *next;
    struct record *prev;
};

struct headtail {
    struct record *h;
    struct record *t;
};

struct headtail insertData(struct record *head, struct record *tail, int data) {
    struct record *node, *p;
    struct headtail ht;
    if (head == NULL || tail == NULL) {
        head = new struct record;
        head->value = data;
        head->next = NULL;
        head->prev = NULL;
        tail = head;
    } else {
        node = new struct record;
        node->value = data;
        p = head;
        if (data < head->value) {
            node->next = head;
            node->prev = NULL;
            head->prev = node;
            head = node;
        } else if (data > tail->value) {
            node->next = NULL;
            node->prev = tail;
            tail->next = node;
            tail = node;
        } else {
            while (data > p->next->value) {
                p = p->next;
            }
            node->next = tail;
            node->prev = p;
            tail->prev = node;
            p->next = node;
        }
    }
    ht.h = head;
    ht.t = tail;
    return ht;
}

void printMinToMax(struct record *head) {
    struct record *p;
    cout << "Min to max: ";
    p = head;
    while (p != NULL) {
        cout << p->value << " ";
        p = p->next;
    }
    cout << endl;
}

void printMaxToMin(struct record *tail) {
    struct record *p;
    cout << "Max to min: ";
    p = tail;
    while (p != NULL) {
        cout << p->value << " ";
        p = p->prev;
    }
    cout << endl;
}


int main(){
    int choose, data;
    struct headtail ht;
    ht.h = NULL;
    ht.t = NULL;
    while(true){
        choose = menu();
        switch(choose){
            case 1 :
                cout << "Insert : ";
                cin >> data;
                cout << "Success!\n\n";
                ht = insertData(ht.h, ht.t, data);
                break;
            case 2 :
                printMinToMax(ht.h);
                printMaxToMin(ht.t);
                cout << endl;
                break;
            case 3 :
                exit(0);
        }
    }
    return 0;
}