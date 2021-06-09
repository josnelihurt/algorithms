//https://www.hackerrank.com/challenges/tree-inorder-traversal/submissions/code/144766325

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

void inOrder(Node *root)
{
    Node *node = root;
    if (root == nullptr)
    {
        return;
    }
    if (root->left != nullptr)
    {
        inOrder(root->left);
    }
    std::cout << node->data << " ";
    if (root->right != nullptr)
    {
        inOrder(root->right);
    }
}
