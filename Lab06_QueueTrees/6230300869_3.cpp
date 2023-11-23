#include <iostream>
using namespace std;

struct node {
    int value;
    struct node *left;
    struct node *right;
};

struct node *insert(struct node *root, int data){
    if(root == NULL){
        root = new struct node;
        root->value = data;
        root->left = NULL;
        root->right = NULL;
    }else{
        if(data < root->value){
            root->left = insert(root->left, data);
        } else if (data > root->value){
            root->right = insert(root->right, data);
        }
    }
    return root;
}

void Preorder(struct node *root){// 
    if(root == NULL){
        return;
    }else{
        cout << root->value << " "; // 
        Preorder(root->left); // 
        Preorder(root->right); // 
    }
    return;
}

void Inorder(struct node *root) {
    if (root == NULL) {
        return;
    } else {
        Inorder(root->left);
        cout << root->value << " ";
        Inorder(root->right);
    }
    return;
}

void Postorder(struct node *root) {
    if (root == NULL) {
        return;
    } else {
        Postorder(root->left);
        Postorder(root->right);
        cout << root->value << " ";
    }
    return;
}

int findMin(struct node *root) {
    if (root->left == NULL)
        return root->value;
    else
        return (findMin(root->left));
}

    int menu() {
    int choose;
    cout << "=====MENU=====\n";
    cout << "1) Insert\n";
    cout << "2) Print\n";
    cout << "3) Find min\n";
    cout << "4) Exit\n";
    cout << "Please choose > ";
    cin >> choose;
    return choose;
}
int main() {
    struct node *root = NULL;
    int choose, data;
    while (true) {
        choose = menu();
        switch (choose) {
        case 1 :
            cout << "Enter : ";
            cin >> data;
            root = insert(root, data);
            cout << "Success!\n";
            break;
        case 2 :
            cout << "Preorder : ";
            Preorder(root);
            cout << endl;
            cout << "Inorder : ";
            Inorder(root);
            cout << endl;
            cout << "Postorder : ";
            Postorder(root);
            cout << endl;    

        case 3 :
            cout << "Min = ";
            cout << findMin(root) << endl;
        }
    }
    return 0;
}
