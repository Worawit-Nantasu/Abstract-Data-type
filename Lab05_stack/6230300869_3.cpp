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
void Push(string data, Stack S);
void Pop(Stack S);

int IsEmpty(Stack S){
    return S->next == NULL;
}

Stack CreateStack(void){
    Stack S;
    S = new struct Node;
    if(S == NULL){
        cout << "Out of space!!!" << endl;
    }
    S->next = NULL;
    return S;
}

void MakeEmpty(Stack S){
    if(S == NULL){
        cout << "Must use CreateStack first" << endl;
    }else{
        while(!IsEmpty(S)){
            Pop(S);
        }
    }
}

void Push(string data, Stack S){
    Stack TmpCell;
    TmpCell = new struct Node;
    TmpCell->next = NULL;
    if(TmpCell == NULL){
        cout << "Out of space!!!" << endl;
    }else{
        TmpCell->value = data;
        TmpCell->next = S->next;
        S->next = TmpCell;
    }
}

void Pop(Stack S){
    Stack FirstCell;
    if(IsEmpty(S)){
        cout << "Empty Stack!!!";
    }else{
        FirstCell = S->next;
        S->next = S->next->next;
        delete(FirstCell);
    }
}

int main(){
    Stack S;
    S = CreateStack();
    string data = "";
    int number;
    cout << "Input : ";
    while(true){
        cin >> data;
        if(data == "."){
            break;
        }else{
            if(data == "+"){
                cout << data << "\tsymbol" << endl;
            }else{
                cout << data << "\tdigit" << endl;
            }
            Push(data, S);
        }
    }
    int result = 0;
    while(!IsEmpty(S)){
        string val = S->next->value;
        S->next = S->next->next;
        if(val != "+"){
            result += stoi(val);
        }
    }
    cout << "Output = " << result << endl;
    MakeEmpty(S);
    return 0;
}
