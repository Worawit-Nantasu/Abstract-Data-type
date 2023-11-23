#include <iostream>
using namespace std;
struct Node;
typedef struct Node *Stack;

struct Node{
    char value;
    struct Node *next;
};

int IsEmpty(Stack S);
Stack CreateStack(void);
void MakeEmpty(Stack S);
void Push(char data, Stack S);
void Pop(Stack S);
void checkBalancingSymbol();

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
        cout << "Must use CreatStack frist" << endl;
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

void checkBalancingSymbol(Stack S){
    int Parentheses_open = 0, Parentheses_close = 0; // วงเล็บ : ()
    int SquareBrackets_open = 0, SquareBrackets_close = 0; // วงเล็บเหลี่ยม : []
    int CurlyBrackets_open = 0, CurlyBrackets_close = 0; // สี่เหลี่ยมปีกกา : {}
    Stack ck;
    if(IsEmpty(S)){
        cout << "Empty Stack!!!";
    }else{
        ck = S->next;
        while (ck != NULL){
            if(ck->value == '(' || ck->value == ')'){
                if(ck->value == '('){
                    Parentheses_open++;
                    ck = ck->next;
                }
                else if (ck->value == ')'){
                    Parentheses_close++;
                    ck = ck->next;
                }
            }else if(ck->value == '[' || ck->value == ']'){
                if(ck->value == '['){
                    SquareBrackets_open++;
                    ck = ck->next;
                }
                else if (ck->value == ']'){
                    SquareBrackets_close++;
                    ck = ck->next;
                }
            }else if(ck->value == '{' || ck->value == '}'){
                if(ck->value == '{'){
                    CurlyBrackets_open++;
                    ck = ck->next;
                }
                else if (ck->value == '}'){
                    CurlyBrackets_close++;
                    ck = ck->next;
                }
            }
        }
        if(Parentheses_open == Parentheses_close && 
        SquareBrackets_open == SquareBrackets_close &&
        CurlyBrackets_open == CurlyBrackets_close){
            cout << "Complete!" << endl;
        }else{
            cout << "Expected ";
            if (Parentheses_open != Parentheses_close)
            {
                if(Parentheses_open < Parentheses_close){
                    cout << "( ";
                }else{
                    cout << ")";
                }
            }
            if (SquareBrackets_open != SquareBrackets_close)
            {
                if(SquareBrackets_open < SquareBrackets_close){
                    cout << "[ ";
                }else{
                    cout << "] ";
                }
            }
            if (CurlyBrackets_open != CurlyBrackets_close)
            {
                if(CurlyBrackets_open < CurlyBrackets_close){
                    cout << "{ ";
                }else{
                    cout << "} ";
                }
            }
        }
        cout << endl;
        /*cout << Parentheses_open << " " << Parentheses_close << endl;
        cout << SquareBrackets_open << " " << SquareBrackets_close << endl;
        cout << CurlyBrackets_open << " " << CurlyBrackets_close << endl;
        */
    }
}

int main(){
    Stack S;
    S = CreateStack();
    //int count = 0;
    char data;

    cout << "Input : ";
    while(true){
        cin >> data;
        if(data == '.'){
            break;
        }else{
            Push(data , S);
        }
    }
    checkBalancingSymbol(S);
    return 0;
}