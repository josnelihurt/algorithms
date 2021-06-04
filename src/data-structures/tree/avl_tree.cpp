#include "data-structures/tree/avl_tree.h"

int max(int l, int r){
    return (l >= r) ? l : r;
}

node* newNode(int val){
    node* root = new node();
    root->val = val;
    root->right = nullptr;
    root->left = nullptr;
    root->ht = 0;
    return root;
}

void deleteNode(node *root){
  if(root == nullptr){
    return;
  }
  if(root->right != nullptr){
    deleteNode(root->right);
  }
  if(root->left != nullptr){
    deleteNode(root->left);
  }
  delete root;
  root = nullptr;
}

int getHeight(node *root){
    if(root == nullptr){
        return 0;
    }
    if(root->left == nullptr && root->right == nullptr){
        return 0;
    }
    auto lht = getHeight(root->left);
    auto rht = getHeight(root->right);
    return 1 + max(lht, rht);
}

node* insert(node* root, int val){
    if(root == nullptr){
        return newNode(val);
    }

    if(root->val == val){
        return root;
    }
    if(val > root->val){
        root->right = insert(root->right, val);
    }
    if(val < root->val){
        root->left = insert(root->left, val);
    }
    //update height
    root->ht = getHeight(root);

    return root;
}

node* RRRotate(node* root){
  if(root == nullptr){
    return root;
  }  
  /* Should looks like
                x
              │  
        y  ◄──┘  
        │|  
  z  ◄──┘└──►  yr

        y
        ││
  z  ◄──┘└──►  x
               │
          yr◄──┘
  */
  auto x = root;
  auto y = root->left;
  auto yr = root->left->right;
  root = y;
  root->right = x;
  x->left = yr;
  root->ht = getHeight(root);
  return root;
}



node* RLRotate(node* root){
  if(root == nullptr){
    return root;
  }  
  /* Should looks like
              x
              │  
        y  ◄──┘  
        |  
        └──►  z

             z
             ││
        y ◄──┘└──►  x

  */
  auto x = root;
  auto y = root->left;
  auto z = root->left->right;
  root = z;
  root->right = x;
  root->right->left = nullptr;
  root->left = y;
  root->left->right = nullptr;
  root->ht = getHeight(root);
  return root;
}

node* LLRotate(node* root){
  if(root == nullptr){
    return root;
  }  
  /* Should looks like
      x
      └──► y
          |│
     yl◄──┘└──► z

         y
        ││
  x  ◄──┘└──►  z
  |  
  └──►  yl
  */
  auto x = root;
  auto y = root->right;
  auto yl = root->right->left;
  root = y;
  root->left = x;
  x->right = yl;
  root->ht = getHeight(root);
  return root;
}


node* LRRotate(node* root){
  if(root == nullptr){
    return root;
  }  
  /* Should looks like
      x  
      └──► y
           |  
       z◄──┘  

             z
             ││
        x ◄──┘└──► y
  */
  auto x = root;
  auto y = x->right;
  auto z = y->left;

  root = z;
  root->left = x;
  x->right = nullptr;
  root->right = y;
  y->left = nullptr;

  root->ht = getHeight(root);
  return root;
}