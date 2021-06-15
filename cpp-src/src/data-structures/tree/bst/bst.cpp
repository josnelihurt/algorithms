#include "bst.h"
namespace bst{
Node* newNode(int data){
    auto node = new Node();
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

//https://www.hackerrank.com/challenges/binary-search-tree-insertion/problem
Node *insert(Node *root, int data){
    if (root == nullptr){
        return newNode(data);
    }

    if (root->data == data){
        return root;
    }

    if (root->data > data){
        auto n = insert(root->left, data);
        if (root->left == nullptr){
            root->left = n;
        }
        return root;
    }

    auto n = insert(root->right, data);
    if (root->right == nullptr){
        root->right = n;
    }

    return root;
}


//https://www.hackerrank.com/challenges/binary-search-tree-lowest-common-ancestor/problem
Node *lca(Node *root, int v1,int v2) {
    // Write your code here.
    return nullptr;
}


}