#include <iostream>
using namespace std;

int menu(){
    int choose;
    cout << "========MENU=======\n";
    cout << "1) Insert\n";
    cout << "2) Odd, even\n";
    cout << "2) Decode\n";
    cout << "3) Exit\n";
    cout << "Please choose > ";
    cin >> choose;
    return choose;
}
struct record{
    char value;
    struct record *next;
};

struct record *insertd(struct record *head, char data){
    struct record *node, *p;
    if(head==NULL){
        head = new struct record;
        head->value = data;
        head->next = NULL;
    }else{
        p = head;
        node = new struct record;
        node->value = data;
        while(p->next != NULL){
            p = p->next;
        }
        node->next = NULL;
        p->next = node;
    }
    return head;
}

void printlist(struct record *head){
    struct record *p = head;
    cout << "List : ";
    while (p != NULL)
    {
        cout << p->value;
        p = p->next;
    }
    cout << endl;
}

void decode(struct record *head){
    struct record *p = head;
    int state = 0;
    cout << "Decode : ";
    while (p != NULL)
    {
        cout << p->value;
        p = p->next->next;
    }
    cout << endl;
}

void OddEven(struct record *head){
    struct record *p = head;
    int size = 0;
    while (p != NULL){
        size++;
        p = p->next;
    }
    p = head;
    int i;
    cout << "Odd : ";
    while ((p != NULL) && i != size)
    {
        for(i = 0; i < size; i++){
            if(i % 2 == 0){
                cout << p->value << " ";
            }
            p = p->next;
        }
        cout << endl;
    }
    p = head;
    int j;
    cout << "Even : ";
    while ((p != NULL) && j != size)
    {
        for(j = 0; j < size; j++){
            if(j % 2 == 1){
                cout << p->value << " ";
            }
            p = p->next;
        }
        cout << endl;
    }
}


int main(){
    struct record *head = NULL;
    int choose;
    char data;

    while(true){
        choose = menu();
        switch(choose){
            case 1 :
                cout << "Enter code : ";
                cin >> data;
                while(data != '.'){
                    head = insertd(head, data);
                    cin >> data;
                }
                printlist(head);
                cout << endl;
                break;
            case 2 :
                OddEven(head);
                //Even(head);
                cout << endl;
                break;

            case 3 :
                decode(head);
                cout << endl;
                break;
            case 4 :
                exit(0);
        }

    }
}