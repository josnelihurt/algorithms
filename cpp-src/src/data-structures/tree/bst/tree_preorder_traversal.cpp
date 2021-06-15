//https://www.hackerrank.com/challenges/tree-preorder-traversal/problem

/* you only have to complete the function given below.  
Node is defined as  

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

void preOrder(Node *root)
{
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