#include "bst.h"
namespace bst{
Node* newNode(int data){
    auto node = new Node();
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

}