#include <iostream>
using namespace std;

int menu() {
    int choose;
    cout << "===========MENU===========\n";
    cout << " 1) Insert\n";
    cout << " 2) Delete\n";
    cout << " 3) Print min to max / max to min\n";
    cout << " 4) Count node\n";
    cout << " 5) Print only odd node\n";
    cout << " 6) Exit\n";
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

struct headtail deleteData(struct record *head, struct record *tail, int data) {
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

void countNode(struct record *head) {
    int count = 0;
    struct record *p = head;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    cout << "Number of node = " << count << endl;
}

void printOnlyOddNode(struct record *head) {
    struct record *p = head;
    int k, i, count = 0, size = 3;
    while (p != NULL) {
        p = p->next;
        count++;
    }
    cout << "Insert only odd node : ";
    int data;
    int dataa[size];
    for (i = 0; i < size; i++) {
        cin >> data;
        dataa[i] = data;
    }
    cout << "Odd node = ";
    for (int j = 0; j < size; j++) {
        if (dataa[j] <= count && dataa[j] >= 1) {
            p = head;
            for (k = 1; k < dataa[j]; k++) {
                p = p->next;
            }
            cout << p->value << " ";
        } else {
            cout << "No data found for index: " << dataa[j] << " ";
        }
    }
    cout << endl;
}

int main() {
    int choose, data;
    struct headtail ht;
    ht.h = NULL;
    ht.t = NULL;
    while (true) {
        choose = menu();
        switch (choose) {
            case 1:
                cout << "Insert : ";
                cin >> data;
                cout << "Success!\n\n";
                ht = insertData(ht.h, ht.t, data);
                break;
            case 2:
                cout << "Delete : ";
                cin >> data;
                cout << "Success!\n\n";
                ht = deleteData(ht.h, ht.t, data);
                break;
            case 3:
                printMinToMax(ht.h);
                printMaxToMin(ht.t);
                cout << endl;
                break;
            case 4:
                countNode(ht.h);
                cout << endl;
                break;
            case 5:
                printOnlyOddNode(ht.h);
                cout << endl;
                break;
            case 6:
                exit(0);
        }
    }
    return 0;
}
