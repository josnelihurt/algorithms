#include "gtest/gtest.h"
#include "avl_tree.h"
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
  delete root;
}

TEST(AVLNode, insertNullInput) {
  auto value = getValue();
  auto root = insert(nullptr, value);
  EXPECT_EQ(root->ht, 0);
  EXPECT_EQ(root->val, value);
  EXPECT_EQ(root->left, nullptr);
  EXPECT_EQ(root->right, nullptr);
  delete root;
}

TEST(AVLNode, insertTwiceSameValue) {
  auto value = getValue();
  auto root = insert(nullptr, value);
  root = insert(root, value);
  EXPECT_EQ(root->ht, 0);
  EXPECT_EQ(root->val, value);
  EXPECT_EQ(root->left, nullptr);
  EXPECT_EQ(root->right, nullptr);
  delete root;
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
  delete root->right;
  delete root;
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
  delete root->left;
  delete root;
}

TEST(AVLNode, getHeightNullTree) {
  auto ht = getHeight(nullptr);
  EXPECT_EQ(ht, 0);
}

TEST(AVLNode, getHeightSingleNodeTree) {
  auto root = insert(nullptr, 1);
  auto ht = getHeight(root);
  EXPECT_EQ(ht, 1);
  delete root;
}

TEST(AVLNode, getHeight1NodeTree) {
  return;
  auto value = getValue();
  auto root = insert(nullptr, 111);
  root = insert(root, 222);
  auto ht = getHeight(root);
  EXPECT_EQ(ht, 2);

  root = insert(root, 333);
  ht = getHeight(root);
  EXPECT_EQ(ht, 2);

  EXPECT_NE(root->left, nullptr);
  EXPECT_NE(root->right, nullptr);
  
  delete root;
  delete root->left;
  delete root->right;
}

// TEST(AVLNode, insertMoreThanOnceValidateHeight) {
//   auto value = getValue();
//   auto root = insert(nullptr, value);
//   root = insert(root, value + 1);

//   EXPECT_EQ(root->val, 1);
//   EXPECT_EQ(root->ht, 1);
// }