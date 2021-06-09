//https://www.hackerrank.com/challenges/binary-search-tree-insertion/problem

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

Node *insert(Node *root, int data)
{
    if (root == nullptr)
    {
        return new Node(data);
    }

    if (root->data == data)
    {
        return root;
    }

    if (root->data > data)
    {
        auto n = insert(root->left, data);
        if (root->left == nullptr)
        {
            root->left = n;
        }
        return root;
    }

    auto n = insert(root->right, data);
    if (root->right == nullptr)
    {
        root->right = n;
    }
    return root;
}
