#include "bst.h"
#include <iostream>
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

    if (v1 < root->data && v2 < root->data){
        return lca(root->left, v1, v2);
    }

    if (v1 > root->data && v2 > root->data){
        return lca(root->right, v1, v2);
    }

    return root;
}

//https://www.hackerrank.com/challenges/tree-inorder-traversal/problem
void inOrder(Node *root){
    Node *node = root;
    if (root == nullptr){
        return;
    }
    if (root->left != nullptr){
        inOrder(root->left);
    }
    std::cout << node->data << " ";
    if (root->right != nullptr){
        inOrder(root->right);
    }
}
//https://www.hackerrank.com/challenges/tree-level-order-traversal/problem
void levelOrder(Node *root){
    if (root == nullptr){
        return;
    }
    Node *queue[501];
    int front{0}, back{0};
    queue[back++] = root;

    while (back - front > 0)    {
        //pop all elements in q
        int lastBack = back;
        for (; front < lastBack; front++)        {
            std::cout << queue[front]->data << " ";
            if (queue[front]->left)            {
                queue[back++] = queue[front]->left;
            }
            if (queue[front]->right)            {
                queue[back++] = queue[front]->right;
            }
        }
    }
}
//https://www.hackerrank.com/challenges/tree-postorder-traversal/problem
void postOrder(Node *root){
    Node *node = root;
    if (root == nullptr)
    {
        return;
    }
    if (root->left != nullptr)
    {
        postOrder(root->left);
    }
    if (root->right != nullptr)
    {
        postOrder(root->right);
    }
    std::cout << node->data << " ";
}
//https://www.hackerrank.com/challenges/tree-preorder-traversal/problem
void preOrder(Node *root){
    Node *node = root;
    if (root == nullptr)
    {
        return;
    }
    std::cout << node->data << " ";
    if (root->left != nullptr)
    {
        preOrder(root->left);
    }
    if (root->right != nullptr)
    {
        preOrder(root->right);
    }
}
}