#include <iostream>
using namespace std;

int menu(){
    int choose;
    cout << "========MENU========\n";
    cout << "1) Insert\n";
    cout << "2) Delete \n";
    cout << "3) Print\n";
    cout << "4) Exit \n";
    cout << "Please choose > ";
    cin >> choose;
    return choose;
}
struct record{
    int value;
    struct record *next;
    struct record *prev;
};

struct headtail {
    struct record *h;
    struct record *t;
};

struct headtail insertd(struct record *head, struct record *tail, int data) {
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

struct headtail deleted(struct record *head, struct record *tail, int data) {
    struct record *p, *tmp;
    struct headtail ht;
    if (head == NULL || tail == NULL) {
        cout << "No data Empty list!\n";
    } else {
        if (data == head->value) {
            tmp = head;
            head = head->next;
            head->prev = NULL;
            delete(tmp);
        } else if (data == tail->value) {
            tmp = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete(tmp);
        } else {
            p = head;
            while (p->next != NULL) {
                if (data == p->next->value) {
                    tmp = p->next;
                    p->next->next->prev = p;
                    p->next = p->next->next;
                    delete(tmp);
                    break;
                }p = p->next;
            }if (p->next == NULL) {
                cout << "No data\n";
            }
        }
    }
    ht.h = head;
    ht.t = tail;
    return ht;
}

void printt(struct record *head) {
    struct record *p;
    cout << "List : ";
    p = head;
    while (p != NULL) {
        cout << p->value << " ";
        p = p->next;
    }
    cout << endl;
}

int main(){
    struct headtail ht;
    int choose, data;
    ht.h = NULL;
    ht.t = NULL;
    while(true){
        choose = menu();
        switch(choose){
            case 1 :
                cout << "Insert : ";
                cin >> data;
                cout << "Success!\n\n";
                ht = insertd(ht.h, ht.t, data);
                break;
            case 2:
                cout << "Delete : ";
                cin >> data;
                cout << "Success!\n\n";
                ht = deleted(ht.h, ht.t, data);
                break;
            case 3:
                printt(ht.h);
                cout << endl;
                break;
            case 4:
                exit(0);
                break;
        }
    }
    return 0;
}
