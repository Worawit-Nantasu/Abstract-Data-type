/*
2 3 5 2 3 1 2 0 -99
10 20 15 3 12 2 -99

10x^20 + 17x^3 + 17x^2 + 3x + 2
*/
#include<iostream>
using namespace std;

struct record{
    int coeff, expo;
  struct record *next;
};

struct record *insertP1(struct record *head1, int coeff, int expo){
    struct record *p, *node;
    if(head1 == NULL){
        head1 = new struct record;
        head1->coeff = coeff;
        head1->expo = expo;
        head1->next = NULL;
    }else{
        p = head1;
        node = new struct record;
        node->coeff = coeff;
        node->expo = expo;
        node->next = NULL;
        if(expo > head1->expo){
            node->next = head1;
            head1 = node;
        }else{
            while(p->next != NULL){
                if(expo > p->next->expo){
                    node->next = p->next;
                    p->next = node;
                }
                else{
                    p = p->next;
                }
            }
            p->next = node;
        }
    }
    return head1;
}

struct record *insertP2(struct record *head2, int coeff, int expo){
    struct record *p, *node;
    if(head2 == NULL){
        head2 = new struct record;
        head2->coeff = coeff;
        head2->expo = expo;
        head2->next = NULL;
    }else{
        p = head2;
        node = new struct record;
        node->coeff = coeff;
        node->expo = expo;
        node->next = NULL;
        if(expo > head2->expo){
            node->next = head2;
            head2 = node;
        }else{
            while(p->next != NULL){
                if(expo > p->next->expo){
                    node->next = p->next;
                    p->next = node;
                }
                else{
                    p = p->next;
                }
            }
            p->next = node;
        }
    }
    return head2;
}

struct record *calculate(struct record *P1, struct record *P2){
    struct record *ptr1, *ptr2, *res, *tv, *node;
    ptr1 = P1;
    ptr2 = P2;
    res = NULL;
    while(ptr1 != NULL || ptr2 != NULL){
        int coeff, expo;
        if((ptr1 != NULL && ptr2 != NULL) && ptr1->expo == ptr2->expo) {
            expo = ptr1->expo;
            coeff = ptr1->coeff + ptr2->coeff;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }else if(ptr2 == NULL || ptr1->expo > ptr2->expo) {
            expo = ptr1->expo;
            coeff = ptr1->coeff;
            ptr1 = ptr1->next;
        }else if(ptr1 == NULL || ptr1->expo < ptr2->expo) {
            expo = ptr2->expo;
            coeff = ptr2->coeff;
            ptr2 = ptr2->next;
        }else{
            cout << "BOTH LINKED LIST ARE NULL!"  << endl;
        }
        node = new struct record;
        node->coeff = coeff;
        node->expo = expo;
        node->next = NULL;
        if(res == NULL){
            res = node;
        }else{
            tv = res;
            while (tv->next != NULL){
                tv = tv->next;
            }
            tv->next = node;
        }
    }
    return res;  
}

void printt(struct record *head){
    struct record *tmp;
    tmp = head;
    while (tmp != NULL) {   
        if(tmp->coeff != 1 || tmp->expo == 0){
            cout << tmp->coeff;
        }
        if(tmp->expo > 1){
            cout << "x^" << tmp->expo;
        }else if(tmp->expo == 1){
            cout << "x";
        }
        if(tmp->next != NULL){
            cout << " + ";
        }
        tmp = tmp->next;
    }
    cout << endl;
}

int main(){
    struct record *P1 = NULL;
    struct record *P2 = NULL;
    struct record *pResult = NULL;
    int coeff, expo;

    cout << "Input P1 : ";
    while(true){
        cin >> coeff;
        if(coeff == -99){
            break;
        }
        cin >> expo;
        if(expo == -99){
            break;
        }
        P1 = insertP1(P1, coeff, expo);
    }

    coeff = 0, expo = 0;
    cout << "Input P2 : ";
    while(true){
        cin >> coeff;
        if(coeff == -99){
            break;
        }
        cin >> expo;
        if(expo == -99){
            break;
        }
        P2 = insertP2(P2, coeff, expo);
    }
    pResult = calculate(P1, P2);
    printt(pResult);
}
