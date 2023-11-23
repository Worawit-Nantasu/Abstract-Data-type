#include <iostream>
using namespace std;

struct record{
    int value;
    record *next;
};

record *insert(record *head, int data){
    record *node, *p;
    if(head == NULL){
        head = new record;
        head->value = data;
        head->next = NULL;
    }else{
        node = new record;
        node->value = data;
        node->next = NULL;

        p = head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = node;
    }
    return head;
}

void print(record *head){
    record *p;
    p = head;
    while( p != NULL){
        cout << p->value << " ";
        p = p->next;
    }
}

void inputAdjacencyList(record *adj[]){
    int i, data;
    for (i = 0; i < 6; i++) {
        cout << "Enter #" << i << " : ";
        cin >> data;
        adj[i] = NULL;
        while (data != -1) {
            adj[i] = insert(adj[i], data);
            cin >> data;
        }
    }

    cout << endl;
    cout << "ADJACENCY LIST" << endl;
    for (i = 0; i < 6; i++) {
        cout << "#" << i << " : ";
        print(adj[i]);
        cout << endl;
    }
}

void inputAdjacencyMatrix(record *matrix[]) {
    int i, j, data;
    for (i = 0; i < 6; i++) {
        cout << "Enter #" << i << " (Enter -1 to end input): ";
        cin >> data;
        matrix[i] = NULL;
        while (data != -1) {
            matrix[i] = insert(matrix[i], data);
            cin >> data;
        }
    }

    cout << endl;
    cout << "ADJACENCY MATRIX" << endl;
    cout << "---------------------------" << endl;
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 6; j++) {
            record *tmp;
            tmp = matrix[i];
            int connected = 0;
            while (tmp != NULL) {
              if (tmp->value == j) {
                connected = 1;
                break;
              }
              tmp = tmp->next;
            }
            if (connected) {
              cout << "1 ";
            } else {
              cout << "0 ";
            }
        }
        cout << endl;
    }
}

void findVerticesWithSelfLoop(record *adj[]) {
    cout << "Selfloop  : ";
    for (int i = 0; i < 6; i++) {
        record *tmp = adj[i];
        while (tmp != NULL) {
            if (tmp->value == i) {
              cout << i << " ";
              break;
            }
            tmp = tmp->next;
        }
    }
    cout << endl;
}

int menu() {
    int choose;
    cout << "===========MENU==========" << endl;
    cout << "1)  Input adjacency list" << endl;
    cout << "2)  Input adjacency matrix" << endl;
    cout << "3)  Show self loop from adjacency list" << endl;
    cout << "4)  Exit" << endl;
    cout << "Please choose > ";
    cin >> choose;
    return choose;
}

int main(){
    record *head = NULL, *adj[6], *matrix[6];
    int choose, data;
    while(true){
        choose = menu();
        switch (choose){
            case 1:
                inputAdjacencyList(adj);
                break;
            
            case 2:
                inputAdjacencyMatrix(matrix);
                break;
            
            case 3:
                findVerticesWithSelfLoop(adj);
                break;
            
            case 4:
                exit(0);
        }
    }
    return 0;
}