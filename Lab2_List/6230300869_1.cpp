//นายวรวิทย์ นันทะสุ 6230300869
#include <iostream>
using namespace std;
struct record
{
    int value;
    struct record *next;
};
//------------------------------------------------
struct record *insert(struct record *head, int data){
    struct record *node;
    if(head==NULL){
        head = new struct record;
        head->value =data;
        head->next=NULL;  
    }
    return head;

}
//------------------------------------------------
int main()
{
    struct record *head=NULL, *p;
    int data;
    cout << "Enter : ";
    cin >> data;
    head = insert(head, data);
    p=head;
    cout << "Value = " << p->value << endl;
}