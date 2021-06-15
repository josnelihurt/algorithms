namespace bst{
    struct Node{
        int data;
        Node *left;
        Node *right;
    };

    Node* newNode(int data);
}