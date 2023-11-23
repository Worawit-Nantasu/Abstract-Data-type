#include <iostream>
using namespace std;

struct record {
    int value;
    struct record *next;
};

struct frontback {
    struct record *front;
    struct record *back;
};

struct frontback Enqueue(struct record *front, struct record *back, int data) {
    struct frontback fb;
    struct record *node;

    if (front == NULL) {
        front = new struct record;
        front->value = data;
        back = front;
        back->next = NULL;
    }else{
        node = new struct record;
        node->value = data;
        back->next = node;
        back = node;
        back->next = NULL;
    }
    fb.front = front;
    fb.back = back;
    return fb;
}

struct frontback Dequeue(struct record *front, struct record *back) {
    struct frontback fb;
    struct record *tmp;
    if(front == NULL){
        cout << "Empty! Can't Dequeue" << endl << endl;
    }else{
        tmp = front;
        front = front->next;
        cout << "Dequeue " << tmp->value << endl << endl;
        delete tmp;
    }
    fb.front = front;
    return fb;
}

    int menu() {
    int choose;
    cout << "=======MENU=======" << endl;
    cout << "1. Enqueue" << endl;
    cout << "2. Dequeue" << endl;
    cout << "3. Exit" << endl;
    cout << "Please choose > ";
    cin >> choose;
    return choose;
}

int main() {
    struct frontback fb;
    fb.front = NULL;
    fb.back = NULL;
    int choose, data;
    while (true) {
        choose = menu();
        switch (choose) {
        case 1:
            cout << "Enter data : ";
            cin >> data;
            cout << "Success!" << endl << endl;
            fb = Enqueue(fb.front, fb.back, data);
            break;
        case 2:
            fb = Dequeue(fb.front,fb.back);
            break;
        case 3:
            return 0;
            break;
        }
    }
    

}