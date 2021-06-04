#include "data-structures/tree/avl_tree.h"

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

void deleteNode(node *root){
  if(root == nullptr){
    return;
  }
  if(root->right != nullptr){
    deleteNode(root->right);
  }
  if(root->left != nullptr){
    deleteNode(root->left);
  }
  delete root;
  root = nullptr;
}

int getHeight(node *root){
    if(root == nullptr){
        return 0;
    }
    if(root->left == nullptr && root->right == nullptr){
        return 0;
    }
    auto lht = getHeight(root->left);
    auto rht = getHeight(root->right);
    return 1 + max(lht, rht);
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

node* rotateRight(node* root){
  if(root == nullptr){
    return root;
  }  
  return nullptr;
}

