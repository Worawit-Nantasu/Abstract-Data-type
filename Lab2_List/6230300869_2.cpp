//นายวรวิทย์ นันทะสุ 6230300869
#include <iostream>
using namespace std;
struct record{
    int value;
    struct record *next;
};
int menu(){
    int choose;
    cout << "========== MENU ==========\n";
    cout << "  1) Insert\n";
    cout << "  2) Print All data\n";
    cout << "  3) Print frist and last\n";
    cout << "  4) Exit\n";
    cout << "Please choose > ";
    cin >> choose;
    return choose;
}
struct record *insert(struct record *head, int data){
    struct record *node,*p;
    if(head==NULL){
        head = new struct record;
        head->value =data;
        head->next=NULL;  
    }else{
        node = new struct record;
        node->value = data;
        if(data<head->value){
            node->next=head;
            head=node;
        }else{
            p = new struct record;
            p = head;
            while(p->next != NULL){
                if(data>p->next->value){
                    p=p->next;
                }else{
                    break;
                }
            }
            node->next=p->next;
            p->next=node;
        }
    }return head;
}
void printAll(struct record *head){
    struct record *temp;
    temp=head;
    if(temp==NULL){
        cout << "Empty list!\n";
    }else{
        cout << "List : ";
        while(temp!=NULL){
            cout << temp->value << " ";
            temp = temp->next;
        }cout << endl;
    }cout << endl;
}
void FTprint(struct record *head){
    struct record *p,*temp;
    p = head;
    cout << "Frist : " << p->value << endl;
    cout << "Last : ";
    while(p->next != NULL){
        p=p->next;
        temp=p;
    }cout << temp->value << endl;
}

int main()
{
    struct record *head=NULL;
    int choose,data;
    while (choose != 4){
        choose=menu();
        switch(choose){
            case 1:
                cout << "Insert : ";
                cin >> data;
                head=insert(head, data);
                cout << "Success!\n";
                break;
            case 2:
                printAll(head);
                break;
            case 3:
                FTprint(head);
                break;
        }
    }
}












