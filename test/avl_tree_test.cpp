#include "gtest/gtest.h"
#include "avl_tree.h"

TEST(AVLNode, DefaultValues) {
  node* root = new node();
  EXPECT_EQ(root->ht, 0);
  EXPECT_EQ(root->val, 0);
  EXPECT_EQ(root->left, nullptr);
  EXPECT_EQ(root->right, nullptr);
}