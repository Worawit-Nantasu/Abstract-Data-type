#include <iostream>
using namespace std;

struct Node{
    int value;
    struct Node *next;
};

struct Node *CreatStack(){
    struct Node *S;
    S = new struct Node;
    if(S == NULL){
        cout << "Out of space!!!\n";
    }else{
        S->next = NULL;
    }
    return S;
}

int IsEmpty(struct Node *S){
     return S->next == NULL;
}

void Push(struct Node *S, int data){
    struct Node *Tmpcell;
    Tmpcell = new struct Node;
    if(Tmpcell == NULL){
        cout << "Out of space!!!\n";
    }else{
        Tmpcell->value = data;
        Tmpcell->next = S->next;
        S->next = Tmpcell;
    }
}

void Pop(struct Node *S){
    struct Node *FirstCell;
    if(!IsEmpty(S)){
        FirstCell = S->next;
        S->next = S->next->next;
        cout << "Pop\n";
        delete (FirstCell);
    }else{
        cout << "Empty Stack!!!\n";
    }
}

int Top(struct Node *S){
    if(!IsEmpty(S)){
        return S->next->value;
    }else{
        cout << "Empty Stack!!!\n";
    }
    return 0;
}

int menu(){
    int choose;
    cout << "=======MENU=======\n";
    cout << "1) Push \n";
    cout << "2) Pop\n";
    cout << "3) Top\n";
    cout << "4) Exit\n";
    cout << "   Please choose > ";
    cin >> choose;
    return choose;
}

int main(){
    struct Node *S;
    int choose, data;
    S = CreatStack();
    while (true){
        choose = menu();
        switch (choose){
            case 1 :
                cout << "Push : ";
                cin >> data;
                cout << "Success!\n";
                Push(S, data);
                break;
            case 2 :
                Pop(S);
                break;

            case 3 :
                cout <<"Top : " << Top(S) << endl;
                break;
            case 4:
                exit(0);
                break;
        }
    }
    return 0;
}