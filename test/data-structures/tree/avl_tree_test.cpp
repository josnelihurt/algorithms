#include "gtest/gtest.h"
#include "data-structures/tree/avl_tree.h"
#include <stdlib.h> 

int getValue(){
  srand (time(NULL));
  auto value = rand() + 1;
  return value;
}

TEST(UtilsFunctions, max) {
  auto zValue = 0;
  auto nValue = -1;
  auto pValue = 1;
  EXPECT_EQ(max(nValue, nValue), nValue);
  EXPECT_EQ(max(nValue, zValue), zValue);
  EXPECT_EQ(max(zValue, nValue), zValue);
  EXPECT_EQ(max(zValue, zValue), zValue);
  EXPECT_EQ(max(pValue, zValue), pValue);
  EXPECT_EQ(max(zValue, pValue), pValue);
  EXPECT_EQ(max(nValue, pValue), pValue);
  EXPECT_EQ(max(pValue, nValue), pValue);
}


TEST(AVLNode, newNode) {
  auto value = getValue();
  auto root = newNode(value);
  EXPECT_EQ(root->ht, 0);
  EXPECT_EQ(root->val, value);
  EXPECT_EQ(root->left, nullptr);
  EXPECT_EQ(root->right, nullptr);
  deleteNode(root);
}

// I wonder how can I properly test this case,
// a callback umm maybe later I can test it
// TEST(AVLNode, deleteNode) {
//   auto value = getValue();
//   auto root = newNode(value++);
//   auto l = newNode(value++);
//   auto r = newNode(value++);
//   auto ll = newNode(value++);
//   auto lr = newNode(value++);
//   auto rl = newNode(value++);
//   auto rr = newNode(value++);
  
//   root->left = l;
//   root->right = r;
//   root->left->left = ll;
//   root->left->right = lr;
//   root->right->left = rl;
//   root->right->right = rr;

//   deleteNode(root);

//   EXPECT_EQ(l, nullptr);
//   EXPECT_EQ(r, nullptr);
//   EXPECT_EQ(ll, nullptr);
//   EXPECT_EQ(lr, nullptr);
//   EXPECT_EQ(rl, nullptr);
//   EXPECT_EQ(rr, nullptr);
// }

TEST(AVLNode, insertNullInput) {
  auto value = getValue();
  auto root = insert(nullptr, value);
  EXPECT_EQ(root->ht, 0);
  EXPECT_EQ(root->val, value);
  EXPECT_EQ(root->left, nullptr);
  EXPECT_EQ(root->right, nullptr);
  deleteNode(root);
}

TEST(AVLNode, insertTwiceSameValue) {
  auto value = getValue();
  auto root = insert(nullptr, value);
  root = insert(root, value);
  EXPECT_EQ(root->ht, 0);
  EXPECT_EQ(root->val, value);
  EXPECT_EQ(root->left, nullptr);
  EXPECT_EQ(root->right, nullptr);
  deleteNode(root);
}

TEST(AVLNode, insert12) {
  auto root = insert(nullptr, 1);
  root = insert(root, 2);

  EXPECT_EQ(root->val, 1);
  EXPECT_EQ(root->left, nullptr);
  EXPECT_NE(root->right, nullptr);
  
  EXPECT_EQ(root->right->val, 2);
  EXPECT_EQ(root->right->left, nullptr);
  EXPECT_EQ(root->right->right, nullptr);
  deleteNode(root);
}

TEST(AVLNode, insert21) {
  auto root = insert(nullptr, 2);
  root = insert(root, 1);

  EXPECT_EQ(root->val, 2);
  EXPECT_NE(root->left, nullptr);
  EXPECT_EQ(root->right, nullptr);
  
  EXPECT_EQ(root->left->val, 1);
  EXPECT_EQ(root->left->left, nullptr);
  EXPECT_EQ(root->left->right, nullptr);
  deleteNode(root);
}

TEST(AVLNode, getHeightNullTree) {
  auto ht = getHeight(nullptr);
  EXPECT_EQ(ht, -1);
}

TEST(AVLNode, getHeightSingleNodeTree) {
  auto root = insert(nullptr, 1);
  auto ht = getHeight(root);
  EXPECT_EQ(ht, 0);
  deleteNode(root);
}

TEST(AVLNode, getHeightNodeTree) {
  auto value = getValue();
  auto root = insert(nullptr, 2);
  root = insert(root, 1);
  auto ht = getHeight(root);
  /* Should looks like
          2
        │  
      1 │  0
  1  ◄──┘  
  0        
  */
  EXPECT_EQ(ht, 1);

  root = insert(root, 3);
  ht = getHeight(root);
  /* Should looks like
         2
       │  │
     1 │  │ 1
 1  ◄──┘  └──►  3
 0              0
  */
  EXPECT_EQ(ht, 1);

  root = insert(root, 4);
  ht = getHeight(root);
  /* Should looks like
         2
       │  │
     1 │  │ 2
 1  ◄──┘  └──►  3
 0                │
               0  │1
                  └──► 4
  */
  EXPECT_EQ(ht, 2);
  
  deleteNode(root);
}

TEST(AVLNode, RRRotate) {
  auto shouldBeNull = RRRotate(nullptr);
  EXPECT_EQ(shouldBeNull, nullptr);

  auto value = getValue();
  auto x = newNode(100);
  auto y = newNode(10);
  auto z = newNode(1);
  x->left = y;
  x->left->left = z;

  /* Should looks like
                x
              │  
        y  ◄──┘  
        │  
  z  ◄──┘  
  */

  auto root = RRRotate(x);
  /* Should looks like
         y
        ││
  z  ◄──┘└──►  x
  */
  EXPECT_NE(root, nullptr);
  EXPECT_NE(root->left, nullptr);
  EXPECT_NE(root->right, nullptr);
  EXPECT_EQ(root->left->left, nullptr);
  EXPECT_EQ(root->left->right, nullptr);
  EXPECT_EQ(root->right->left, nullptr);
  EXPECT_EQ(root->right->right, nullptr);
  EXPECT_EQ(root->ht, 1);
  EXPECT_EQ(root->left->ht, 0);
  EXPECT_EQ(root->right->ht, 0);
  deleteNode(root);
}

TEST(AVLNode, LLRotate) {
  auto shouldBeNull = LLRotate(nullptr);
  EXPECT_EQ(shouldBeNull, nullptr);

  auto value = getValue();
  auto x = newNode(1);
  auto y = newNode(10);
  auto z = newNode(100);
  x->right = y;
  x->right->right = z;

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
  auto root = LLRotate(x);

  EXPECT_NE(root, nullptr);
  EXPECT_NE(root->left, nullptr);
  EXPECT_NE(root->right, nullptr);
  
  EXPECT_EQ(root->left->left, nullptr);
  EXPECT_EQ(root->left->right, nullptr);
  EXPECT_EQ(root->right->left, nullptr);
  EXPECT_EQ(root->right->right, nullptr);
  EXPECT_EQ(root->ht, 1);
  EXPECT_EQ(root->left->ht, 0);
  EXPECT_EQ(root->right->ht, 0);

  deleteNode(root);
}

TEST(AVLNode, RLRotate) {
  auto shouldBeNull = RLRotate(nullptr);
  EXPECT_EQ(shouldBeNull, nullptr);

  auto value = getValue();
  auto x = newNode(10);
  auto y = newNode(1);
  auto z = newNode(5);
  x->left = y;
  x->left->right = z;

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
  auto root = RLRotate(x);

  EXPECT_NE(root, nullptr);
  EXPECT_NE(root->left, nullptr);
  EXPECT_NE(root->right, nullptr);
  
  EXPECT_EQ(root->left->left, nullptr);
  EXPECT_EQ(root->right->right, nullptr);
  EXPECT_EQ(root->right->left, nullptr);
  EXPECT_EQ(root->right->right, nullptr);
  EXPECT_EQ(root->ht, 1);
  EXPECT_EQ(root->left->ht, 0);
  EXPECT_EQ(root->right->ht, 0);

  deleteNode(root);
}

TEST(AVLNode, LRRotate) {
  auto shouldBeNull = LRRotate(nullptr);
  EXPECT_EQ(shouldBeNull, nullptr);

  auto value = getValue();
  auto x = newNode(1);
  auto y = newNode(10);
  auto z = newNode(5);
  x->right = y;
  x->right->left = z;

  /* Should looks like
      x  
      └──► y
           |  
       z◄──┘  

             z
             ││
        x ◄──┘└──► y
  */
  auto root = LRRotate(x);

  EXPECT_NE(root, nullptr);
  EXPECT_NE(root->left, nullptr);
  EXPECT_NE(root->right, nullptr);
  
  EXPECT_EQ(root->left->left, nullptr);
  EXPECT_EQ(root->right->right, nullptr);
  EXPECT_EQ(root->right->left, nullptr);
  EXPECT_EQ(root->right->right, nullptr);
  EXPECT_EQ(root->ht, 1);
  EXPECT_EQ(root->left->ht, 0);
  EXPECT_EQ(root->right->ht, 0);

  deleteNode(root);
}

TEST(AVLNode, getBalanceFactor) {
  auto root = insert(nullptr, 2);
  auto bf = getBalanceFactor(root);
  EXPECT_EQ(bf, 0);
  
  root = insert(root, 1);
  bf = getBalanceFactor(root);
  EXPECT_EQ(bf, 1);

  root = insert(root, 3);
  bf = getBalanceFactor(root);
  EXPECT_EQ(bf, 0);

  root = insert(root, 10);
  bf = getBalanceFactor(root);
  EXPECT_EQ(bf, -1);
}

TEST(AVLNode, insert1to7) {
  /* Should looks like
        4
      2   6
    1  3 5  7
  */
  auto root = newNode(1);
  for(int i = 1; i < 8; ++i){
    root = insert(root, i);
  }
  
  EXPECT_NE(root, nullptr);
  EXPECT_NE(root->left, nullptr);
  EXPECT_NE(root->right, nullptr);

  EXPECT_NE(root->left->left, nullptr);
  EXPECT_NE(root->left->right, nullptr);
  EXPECT_NE(root->right->left, nullptr);
  EXPECT_NE(root->right->right, nullptr);

  EXPECT_EQ(root->val, 4);
  EXPECT_EQ(root->left->val, 2);
  EXPECT_EQ(root->right->val, 6);
  
  EXPECT_EQ(root->left->left->val, 1);
  EXPECT_EQ(root->left->right->val, 3);
  EXPECT_EQ(root->right->left->val, 5);
  EXPECT_EQ(root->right->right->val, 7);

  deleteNode(root);
}


TEST(AVLNode, insert7to1) {
  /* Should looks like
        4
      2   6
    1  3 5  7
  */
  auto root = newNode(7);
  for(int i = 7; i > 0; --i){
    root = insert(root, i);
  }
  
  EXPECT_NE(root, nullptr);
  EXPECT_NE(root->left, nullptr);
  EXPECT_NE(root->right, nullptr);

  EXPECT_NE(root->left->left, nullptr);
  EXPECT_NE(root->left->right, nullptr);
  EXPECT_NE(root->right->left, nullptr);
  EXPECT_NE(root->right->right, nullptr);

  EXPECT_EQ(root->val, 4);
  EXPECT_EQ(root->left->val, 2);
  EXPECT_EQ(root->right->val, 6);
  
  EXPECT_EQ(root->left->left->val, 1);
  EXPECT_EQ(root->left->right->val, 3);
  EXPECT_EQ(root->right->left->val, 5);
  EXPECT_EQ(root->right->right->val, 7);

  deleteNode(root);
}