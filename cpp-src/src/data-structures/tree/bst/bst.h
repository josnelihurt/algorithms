namespace bst{
    struct Node{
        int data;
        Node *left;
        Node *right;
    };

    Node* newNode(int data);
    Node *insert(Node *root, int data);
    Node *lca(Node *root, int v1,int v2);
    int height(Node *root);
    void deleteNode(Node *root);
    void inOrder(Node *root);
    void levelOrder(Node *root);
    void postOrder(Node *root);
    void preOrder(Node *root);
}