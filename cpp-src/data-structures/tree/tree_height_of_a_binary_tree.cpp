//https://www.hackerrank.com/challenges/tree-height-of-a-binary-tree/problem

/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};
1) Create an empty stack S.
2) Initialize current node as root
3) Push the current node to S and set current = current->left until current is NULL
4) If current is NULL and stack is not empty then 
     a) Pop the top item from stack.
     b) Print the popped item, set current = popped_item->right 
     c) Go to step 3.
5) If current is NULL and stack is empty then we are done.
*/
int height(Node *root)
{
    if (root == nullptr)
        return -1;
    int lDepth = height(root->left);
    int rDepth = height(root->right);

    /* use the larger one */
    if (lDepth > rDepth)
        return (lDepth + 1);
    else
        return (rDepth + 1);
    // if(root->left== nullptr && root->right == nullptr) return 0;
    // Node* stack[100];
    // int stack_index{0}, max{0};
    // Node* current = root;
    // while(1){
    //     if(current != nullptr){
    //         stack[stack_index++] = current;
    //         current = current->left;
    //         max = max<stack_index?stack_index:max;
    //     } else if(stack_index > 0){
    //         current = stack[--stack_index];
    //         current = current->right;
    //     } else {
    //         break;
    //     }
    // }

    //return max;
}