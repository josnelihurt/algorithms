
struct node{
    int val;
    struct node* left;
    struct node* right;
    int ht;
}; 
//utils functions
int max(int l, int r);
//newNode creates a new instance of the node
node* newNode(int val);
//insert insets a new value into the datastructure
node* insert(node* root, int val);
//getHeight gets the hight of the current tree
int getHeight(node *root);

