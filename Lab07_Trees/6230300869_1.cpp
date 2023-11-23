//
//  1.cpp
//  Lab07
//
//  Created by วรวิทย์ นันทะสุ on 2/9/2566 BE.
//

#include <iostream>
using namespace std;


struct node{
    int value;
    struct node *left;
    struct node *right;
};

struct node *insert(struct node *tree, int data){
    if(tree == NULL){
        tree = new struct node;
        tree->value = data;
        tree->left = NULL;
        tree->right = NULL;
    }else{
        if(data < tree->value){
            tree->left = insert(tree->left, data);
        } else if (data > tree->value){
            tree->right = insert(tree->right, data);
        }
    }
    return tree;
}

void Inorder(struct node *tree) {
    if (tree == NULL) {
        return;
    } else {
        Inorder(tree->left);
        cout << tree->value << " ";
        Inorder(tree->right);
    }
    return;
}

void Leave(struct node *tree){
    if(tree == NULL){
        return;
    }else{
        if(tree->left == NULL && tree->right == NULL){
            cout << tree->value << " ";
        }else{
            Leave(tree->left);
            Leave(tree->right);
        }
    }
    return;
}

void NonLeave(struct node *tree){
    if(tree == NULL){
        return;
    }else{
        NonLeave(tree->left);
        if(tree->left != NULL || tree->right != NULL){
            cout << tree->value << " ";
        }
        NonLeave(tree->right);
    }
}

struct node *FindMin(struct node *tree){
    if(tree == NULL){
        return NULL;
    }else{
        if(tree->left == NULL){
            return tree;
        }else{
            return FindMin(tree->left);
        }
    }
}

struct node *dTree(struct node *tree, int data){
    if(tree == NULL){ // กรณีที่ไม่มีโหนดในต้นไม้
        cout << "No Node" << endl;
        return NULL;
    }else{
        if(data < tree->value){// กรณีที่ต้องการลบโหนดที่มีค่าน้อยกว่า
            tree->left = dTree(tree->left, data);
        }else if(data > tree->value){// กรณีที่ต้องการลบโหนดที่มีค่ามากกว่า
            tree->right = dTree(tree->right, data);
        }else{// กรณีที่ต้องการลบโหนดที่มีค่าเท่ากับ data
            if(tree->left && tree->right){ // กรณีที่โหนดนี้มีลูกสองข้าง
                struct node *tmpcell = FindMin(tree->right);
                tree->value = tmpcell->value;
                tree->right = dTree(tree->right, tree->value);//-------
            }else{// กรณีที่โหนดนี้เป็นใบหรือมีลูกเดียว
                struct node *tmpcell = tree;
                if(tree->left == NULL){
                    tree = tree->right;
                }else if(tree->right == NULL){
                    tree = tree->left;
                }
                delete tmpcell;
            }
        }
        return tree;
    }
}
struct node *FindT(struct node *tree, int data){
    if(tree == NULL){
        cout << "Not found!" << endl;
        return NULL;
    }else{
        if(data < tree->value){
            return FindT(tree->left, data);
        }else if(data > tree->value){
            return FindT(tree->right, data);
        }else{
            cout << "Found!" << endl;
            return tree;
        }
    }
}



int menu(){
    int choose;
    cout << "=====MENU=====\n";
    cout << "1) Insert" << endl;
    cout << "2) Print Inorder, Leave node, Non-Leave node" << endl;
    cout << "3) Delete" << endl;
    cout << "4) Find" << endl;
    cout << "5) Exit" << endl;
    cout << "Please choose > ";
    cin >> choose;
    return choose;
}

int main() {
    struct node *tree = NULL;
    int choose, data;
    while (true) {
        choose = menu();
        switch (choose) {
            case 1 :
                cout << "Enter : ";
                cin >> data;
                tree = insert(tree, data);
                cout << "Success!" << endl << endl;
                break;
            case 2 :
                cout << "Inorder : ";
                Inorder(tree);
                cout << endl;
                cout << "Leave : ";
                Leave(tree);
                cout << endl;
                cout << "Nonleave : ";
                NonLeave(tree);
                cout << endl;
                cout << endl;
                break;
            case 3 :
                cout << "Delete : ";
                cin >> data;
                tree = dTree(tree, data);
                cout << "Success!" << endl << endl;
                break;
            case 4 :
                cout << "Search : ";
                cin >> data;
                FindT(tree, data);
                cout << endl;
                break;
            case 5 :
                exit(0);
                
                
        }
    }
    return 0;
}
