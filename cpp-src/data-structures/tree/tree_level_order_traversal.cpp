//https://www.hackerrank.com/challenges/tree-level-order-traversal/problem
/*
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

void levelOrder(Node *root)
{
    if (root == nullptr)
        return;
    Node *queue[501];
    int front{0}, back{0};
    queue[back++] = root;

    while (back - front > 0)
    {
        //pop all elements in q
        int lastBack = back;
        for (; front < lastBack; front++)
        {
            cout << queue[front]->data << " ";
            if (queue[front]->left)
            {
                queue[back++] = queue[front]->left;
            }
            if (queue[front]->right)
            {
                queue[back++] = queue[front]->right;
            }
        }
    }
}
