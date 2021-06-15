#include "bst.h"
namespace bst{
Node* newNode(int data){
    auto node = new Node();
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

void deleteNode(Node *root){
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

//https://www.hackerrank.com/challenges/tree-height-of-a-binary-tree/problem
int height(Node *root){
    if (root == nullptr){
        return -1;
    }
    int lDepth = height(root->left);
    int rDepth = height(root->right);

    /* use the larger one */
    if (lDepth > rDepth)
        return (lDepth + 1);
    else
        return (rDepth + 1);
}

//https://www.hackerrank.com/challenges/binary-search-tree-lowest-common-ancestor/problem
Node *lca(Node *root, int v1,int v2) {
    if(root == nullptr){
        return nullptr;
    }

    return root;
}


}