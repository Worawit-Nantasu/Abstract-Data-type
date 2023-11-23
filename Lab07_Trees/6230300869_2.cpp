//
//  2.cpp
//  Lab07
//
//  Created by วรวิทย์ นันทะสุ on 3/9/2566 BE.
//

#include <iostream>
using namespace std;

struct node{
    int value, height;
    struct node *left, *right;
};

int fheight(struct node *tree){
    if(tree == NULL){
        return -1;
    }else{
        return tree->height;
    }
}

struct node *single_rotate_left(struct node *k2){
    struct node *k1;
    k1 = k2->left;
    k2->left = k1->right;
    k1->right= k2;
    k2->height = max(fheight(k2->left), fheight(k2->right)) +1;
    k1->height = max(fheight(k1->left), k2->height) +1;
    return k1;
}

struct node *single_rotate_right(struct node *k2){
    struct node *k1;
    k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;
    k2->height = max(fheight(k2->left), fheight(k2->right)) + 1;
    k1->height = max(fheight(k1->right), k2->height) + 1;
    return k1;
}

struct node *double_rotate_left(struct node *k3){
    k3->left = single_rotate_right(k3->left);
    return single_rotate_left(k3);
}

struct node *double_rotate_right(struct node *k3){
    k3->right = single_rotate_left(k3->right);
    return single_rotate_right(k3);
}

struct node *insert(struct node * tree, int data){
    if(tree == NULL){ // สร้าง node ใหม่
        tree = new struct node;
        tree->value = data;
        tree->left = tree->right = NULL;
        tree->height = 0;
        cout << "Success!" << endl;
    }
    else
    {
        if(data < tree->value){
            tree->left = insert(tree->left, data);
            if(fheight(tree->left) - fheight(tree->right) == 2){
                if(data < tree->left->value){
                    tree = single_rotate_left(tree);
                    cout << "You have to rotate trees!" << endl;
                }
                else{
                    tree = double_rotate_left(tree);
                    cout << "You have to rotate trees!" << endl;
                }
            }
        }else if(data > tree->value){
            tree->right = insert(tree->right, data);
            if(fheight(tree->right) - fheight(tree->left) == 2){
                if(data > tree->right->value) {
                    tree = single_rotate_right(tree);
                    cout << "You have to rotate trees!" << endl;
                }else{
                    tree = double_rotate_right(tree);
                    cout << "You have to rotate trees!" << endl;
                }
            }
        }
    }
    //cout << endl;
    tree->height = max(fheight(tree->left), fheight(tree->right)) + 1;
    return tree;
}

void Inorder(struct node *tree){
    if(tree == NULL)
        return;
    else{
        Inorder(tree->left);
        cout << tree->value << " ";
        Inorder(tree->right);
    }
    return;
}

int menu(){
    int choose;
    cout << "==========MENU===========" << endl;
    cout << "1) Insert" << endl;
    cout << "2) Print Inorder" << endl;
    cout << "3) Exit" << endl;
    cout << "Please choose > ";
    cin >> choose;
    return  choose;
}

int main(){
    struct node *tree = NULL;
    int choose, data;
    while(true){
        choose = menu();
        switch (choose) {
            case 1:
                cout << "Enter : ";
                cin >> data;
                tree = insert(tree, data);
                break;
            case 2:
                cout << "Inorder : ";
                Inorder(tree);
                cout << endl;
                break;
            case 3:
                exit(0);
            }
    }
    return 0;
}

