#include <iostream>
using namespace std;

struct record {
    int value;
    struct record *next;
};

struct record *insertP1(struct record *head1, int data){
    struct record *node, *p;
    if(head1==NULL){
        head1 = new struct record;
        head1->value = data;
        head1->next = NULL;
    }else{
        p = head1;
        node = new struct record;
        node->value = data;
        while(p->next != NULL){
            p = p->next;
        }
        node->next = NULL;
        p->next = node;
    }
    return head1;
}

struct record *insertP2(struct record *head2, int data){
    struct record *node, *p;
    if(head2==NULL){
        head2 = new struct record;
        head2->value = data;
        head2->next = NULL;
    }else{
        p = head2;
        node = new struct record;
        node->value = data;
        while(p->next != NULL){
            p = p->next;
        }
        node->next = NULL;
        p->next = node;
    }
    return head2;
}

void printP1(struct record *head){
    struct record *p = head;
    struct record *tmp = head;
    // 2 3 5 2 3 1 2 0 -99
    // 10 20 15 2 12 2 -99
    int size = 0;
    cout << "P1 : ";
    // คำนวณค่า size
    while (p != NULL){
        p = p->next;
        size++;
    }
    
    p = head; 
    int i;
    while (p != NULL && i != size) {
        for (i = 0; i < size; i++){
            if(i == 0){
                cout << p->value;
            }
            if((i % 2 == 0) && ( i != 0)){
                cout << " + " <<  p->value;
            }
            if((i % 2 == 1) && (p->value != 1) && (p->value != 0)){
                cout << "x^" << p->value;
            }
            if((i % 2 == 1) && (p->value == 1) && (p->value != 0)){
                cout << "x";
            }
            p = p->next;
        }
        cout << endl;
    }
}

void printP2(struct record *head){
    struct record *p = head;
    struct record *tmp = head;

    int size = 0;
    cout << "P2 : ";
    // คำนวณค่า size
    while (p != NULL){
        p = p->next;
        size++;
    }
    
    p = head; // กลับไปที่เริ่มต้นของ linked list
    int i;
    while (p != NULL && i != size) {
        for (i = 0; i < size; i++){
            if(i == 0){
                cout << p->value;
            }
            if((i % 2 == 0) && ( i != 0)){
                cout << " + " <<  p->value;
            }
            if((i % 2 == 1) && (p->value != 1) && (p->value != 0)){
                cout << "x^" << p->value;
            }
            if((i % 2 == 1) && (p->value == 1) && (p->value != 0)){
                cout << "x";
            }
            p = p->next;
        }
        cout << endl;
    }
}

int countSizeP1(struct record *head){
    struct record *p = head;
    int size = 0;
    // คำนวณค่า size
    while (p != NULL) {
        p = p->next;
        size++;
    }
    return size;
}

int countSizeP2(struct record *head){
    struct record *p = head;
    int size = 0;
    // คำนวณค่า size
    while (p != NULL) {
        p = p->next;
        size++;
    }
    return size;
}

int main(){
    struct record *headP1 = NULL;
    struct record *headP2 = NULL;

    int data;

    cout << "Input P1 : ";
    while(true){
        cin >> data;
        if(data == -99){
            break;
        }
        headP1 = insertP1(headP1, data);
    }
    int sizeP1 = countSizeP1(headP1);

    cout << "Input P2 : ";
    while(true){
        cin >> data;
        if(data == -99){
            break;
        }
        headP2 = insertP2(headP2, data);
    }
    int sizeP2 = countSizeP2(headP2);


    if(sizeP1 > sizeP2){
        printP1(headP1);
    }else if(sizeP2 > sizeP1){
        printP2(headP2);
    }else{
        printP1(headP1);
        printP2(headP2);
    }
    return 0;
}

