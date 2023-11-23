#include <iostream>
using namespace std;

struct Node;
typedef struct Node *Stack;

struct Node{
    string value;
    struct Node *next;
};

int IsEmpty(Stack S);
Stack CreateStack(void);
void MakeEmpty(Stack S);
void Push(char data, Stack S);
void Pop(Stack S);

int IsEmpty(Stack S){
    return S->next == NULL;
}

Stack CreateStack(void){
    Stack S;
    S = new struct Node;
    if(S == NULL){
        cout << "Out of space!!!\n";
    }
    S->next = NULL;
    return S;
}

void MakeEmpty(Stack S){
    if(S == NULL){
        cout << "Must use CreatStack frist\n";
    }else{
        while(!IsEmpty(S)){
            Pop(S);
        }
    }
}

void Pop(Stack S){
    Stack FirstCell;
    if(IsEmpty(S)){
        cout << "Empty Stack!!!";
    }else{
        FirstCell = S->next;
        S->next = S->next->next;
        delete (FirstCell);
    }
}

void Push(char data, Stack S){
    Stack TmpCell;
    TmpCell = new struct Node;
    if(TmpCell == NULL){
        cout << "Out of space!!!\n";
    }else{
        TmpCell->value = data;
        TmpCell->next = S->next;
        S->next = TmpCell;
    }
}

int main(){
    Stack S;
    S = CreateStack();
    int count = 0;
    char data;

    cout << "Input : ";
    while(true){
        cin >> data;
        if(data == '.'){
            break;
        }else{
            Push(data , S);
            if(data == '{' || data == '[' || data == '('){
                cout << data << endl;
                count++;
            }
        }
    }
    cout <<"Open = "<< count << endl;
}
