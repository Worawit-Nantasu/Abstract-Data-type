#include <iostream>
using namespace std;

struct record{
    int value;
    record *next;
};

struct headend{
    record *head;
    record *end;
};

struct headend insert(record *head, record *end, int data){
    headend HE;
    record *node;
    if(head == NULL){
        head = new record;
        head->value = data;
        head->next = NULL;
        end = head;
    }else{
        node = new record;
        node->value = data;
        node->next = NULL;
        end->next = node;
        end = node;
    }
    HE.head = head;
    HE.end = end;
    return HE;
}

void print(record *head){
    record *p;
    p = head;
    while( p != NULL){
        cout << p->value << " ";
        p = p->next;
    }
}

int main(){
    headend HE;
    HE.head = NULL;
    HE.end = NULL;
    int data;
    cout << "Input : ";
    while(true){   
        cin >> data;
        if (data == -1){
            break;
        }else{
            
            HE = insert(HE.head,HE.end, data);
        }
    }
    cout << "List : ";
    print(HE.head);
    cout << endl;
}