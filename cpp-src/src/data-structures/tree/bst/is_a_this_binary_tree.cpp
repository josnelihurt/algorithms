/*
https://www.hackerrank.com/challenges/is-binary-search-tree/problem
*/

//This file problem was solved without a tdd approach
//maybe I will be back to create at least some test cases :)git

/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
untested code :/
*/
bool checkLessThan(Node *root, int value)
{
    if (root == nullptr)
        return true;
    if (checkLessThan(root->left, value) && checkLessThan(root->right, value) && root->data < value)
        return true;
    else
        return false;
            
    }
    bool checkMoreThan(Node* root, int value){
        if(root==nullptr) return true;
        if(checkMoreThan(root->left,value)
          &&checkMoreThan(root->right,value)
          &&root->data>value)
            return true;
        else
            return false;
            
        
    }
	bool checkBST(Node* root) {
		if(root==nullptr) return true;
        
        if(checkLessThan(root->left, root->data) 
           && checkMoreThan(root->right,root->data)
           && checkBST(root->left)
           && checkBST(root->right)){
            return true;
        } else{
            return false;
        }        
	}