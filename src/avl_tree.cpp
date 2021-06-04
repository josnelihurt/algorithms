#include "avl_tree.h"

int max(int l, int r){
    return (l >= r) ? l : r;
}

node* newNode(int val){
    node* root = new node();
    root->val = val;
    root->right = nullptr;
    root->left = nullptr;
    root->ht = 0;
    return root;
}

int getHeight(node *root){
    if(root == nullptr){
        return 0;
    }
    return 1 + max(getHeight(root->left), getHeight(root->right));
}

node* insert(node* root, int val){
    if(root == nullptr){
        return newNode(val);
    }

    if(root->val == val){
        return root;
    }
    if(val > root->val){
        root->right = insert(root->right, val);
    }
    if(val < root->val){
        root->left = insert(root->left, val);
    }
    //update height
    root->ht = getHeight(root);

    return root;
}