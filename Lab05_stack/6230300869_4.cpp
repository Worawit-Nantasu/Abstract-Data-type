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
string Top(Stack S);
void sort(Stack S1, Stack S);
int GetPrecedence(string op);
void print(Stack S);

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

string Top(Stack S){
    if(!IsEmpty(S)){
        return S->next->value;
    }else{
        cout << "Empty Stack!!!\n";
    }
    return "";
}

void sort(Stack S1, Stack S){
    while(!IsEmpty(S1)){
        Push(Top(S1), S);
        Pop(S1);
    }
}

void print(Stack S){
    Stack p;
    p = S->next;
    cout << "Postfix : ";
    while (p != NULL)
    {
        cout << p->value << " ";
        p = p->next;
    }
    cout << endl;
}
int GetPrecedence(string op){
    int precedence = 0;
    if (op == "(" || op == ")") {
        precedence = 1;
    }else if(op == "+" || op == "-"){
        precedence = 2;
    }else if (op == "*" || op == "/") {
        precedence = 3;
    }
    return precedence;
}

int menu(){
    int choose;
    cout << "1. Infix" << endl;
    cout << "2. Infix()" << endl;
    cout << "Please choose > ";
    cin >> choose;
    return choose;
}

int main(){
    int choose;
    Stack S,S1;
    string data = "";
    S = CreateStack();
    S1 = CreateStack();

    while (true){
        choose = menu();
        switch(choose){
            case 1 : 
                cout << "Infix : ";
                while(true){
                    cin >> data;
                    if(data == "."){
                        break;
                    }else{
                        if(data != "+" && data != "-" && data != "*" && data !="/"){
                            Push(data, S1);
                        }else if(data == "+" || data == "-" ){
                            while(!IsEmpty(S)){
                                Push(Top(S), S1);
                                Pop(S);
                            }
                            Push(data, S);
                        }else if (data == "*" || data == "/"){
                            while(!IsEmpty(S) && Top(S) != "+" && Top(S) != "-"){
                                Push(Top(S), S1);
                                Pop(S);
                            }
                            Push(data, S);
                        }
                    }
                }
                while(!IsEmpty(S)){
                    Push(Top(S), S1);
                    Pop(S);
                }
                // sort เพื่อพิมพ์ Postfix
                sort(S1, S);
                print(S);
                cout << endl;
                MakeEmpty(S);
                break;
            case 2 :
                cout << "Infix : ";
                while(true){
                    cin >> data;
                    if(data == "."){
                        break;
                    }else{
                        if(data != "+" && data != "-" && data != "*" && data !="/" && data !="(" && data !=")"){
                            Push(data, S1);
                        }
                        else if (data == "+" || data == "-")
                        {   while(!IsEmpty(S) && Top(S) != "("){
                                Push(Top(S), S1);
                                Pop(S);
                            }
                            Push(data, S);
                        }
                        else if (data == "*" || data == "/")
                        {
                            while(!IsEmpty(S) && Top(S) !="(" && Top(S) !="+" && Top(S) !="-"){
                                Push(Top(S),S1);
                                Pop(S);
                            }
                            Push(data, S);
                        }else if(data == "("){
                            Push(data, S);
                        }else if(data == ")"){
                            while(Top(S) != "("){
                                Push(Top(S), S1);
                                Pop(S);
                            }
                            Pop(S);
                        }
                    }
                }
                while(!IsEmpty(S)){
                    Push(Top(S), S1);
                    Pop(S);
                }
                // sort เพื่อพิมพ์ Postfix
                sort(S1, S);
                print(S);
                cout << endl;
                MakeEmpty(S);
                break;
        }
    }
    return 0;
}