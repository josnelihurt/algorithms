#include "bst.h"
#include "gtest/gtest.h"
#include "tools/functions.h"
using namespace bst;

TEST(BST, newNode){
    auto k = getRandomValue();
    auto root = newNode(k);
    EXPECT_NE(root, nullptr);
    EXPECT_EQ(root->data, k);
    EXPECT_EQ(root->left, nullptr);
    EXPECT_EQ(root->right, nullptr);
}

TEST(BST, insertNullRoot){
    auto k = getRandomValue();
    auto root = insert(nullptr, k);
    EXPECT_NE(root, nullptr);
    EXPECT_EQ(root->data, k);
    EXPECT_EQ(root->left, nullptr);
    EXPECT_EQ(root->right, nullptr);
}

TEST(BST, insertSameData){
    auto k = getRandomValue();
    auto root = insert(nullptr, k);
    auto sameRoot = insert(root, k);
    EXPECT_NE(root, nullptr);
    EXPECT_EQ(root->data, k);
    EXPECT_EQ(root->left, nullptr);
    EXPECT_EQ(root->right, nullptr);
    EXPECT_EQ(root, sameRoot);
}

TEST(BST, insertRight){
    auto k = getRandomValue();
    auto root = insert(nullptr, k);
    root = insert(root, ++k);
    EXPECT_NE(root->right, nullptr);
    EXPECT_NE(root->right, root);
    EXPECT_EQ(root->right->data, k);
    EXPECT_EQ(root->right->left, nullptr);
    EXPECT_EQ(root->right->right, nullptr);
    EXPECT_EQ(root->left, nullptr);
}

TEST(BST, insertRightSameValue){
    auto k = getRandomValue();
    auto root = insert(nullptr, k);
    root = insert(root, ++k);
    EXPECT_NE(root->right, nullptr);
    root = insert(root, k);
    EXPECT_NE(root->right, root);
    EXPECT_EQ(root->right->data, k);
    EXPECT_EQ(root->right->left, nullptr);
    EXPECT_EQ(root->right->right, nullptr);
    EXPECT_EQ(root->left, nullptr);
}

TEST(BST, insertLeft){
    auto k = getRandomValue();
    auto root = insert(nullptr, k);
    root = insert(root, --k);
    EXPECT_NE(root->left, nullptr);
    EXPECT_EQ(root->left->data, k);
    EXPECT_NE(root->left, root);
    EXPECT_EQ(root->left->left, nullptr);
    EXPECT_EQ(root->left->right, nullptr);
    EXPECT_EQ(root->right, nullptr);
}

TEST(BST, insertLeftSameValue){
    auto k = getRandomValue();
    auto root = insert(nullptr, k);
    root = insert(root, --k);
    EXPECT_NE(root->left, nullptr);
    root = insert(root, k);
    EXPECT_EQ(root->left->data, k);
    EXPECT_NE(root->left, root);
    EXPECT_EQ(root->left->left, nullptr);
    EXPECT_EQ(root->left->right, nullptr);
    EXPECT_EQ(root->right, nullptr);
}

TEST(BST, insertLeftRight){
    auto k = getRandomValue();
    auto root = insert(nullptr, k);
    root = insert(root, k-1);
    root = insert(root, k+1);
    
    EXPECT_NE(root, nullptr);
    EXPECT_NE(root->left, nullptr);
    EXPECT_NE(root->right, nullptr);
    EXPECT_EQ(root->left->data, k-1);
    EXPECT_EQ(root->right->data, k+1);
    
    EXPECT_EQ(root->left->left, nullptr);
    EXPECT_EQ(root->left->right, nullptr);
    EXPECT_EQ(root->right->left, nullptr);
    EXPECT_EQ(root->right->right, nullptr);   
}

TEST(BST, insertRightLeft){
    auto k = getRandomValue();
    auto root = insert(nullptr, k);
    root = insert(root, k+1);
    root = insert(root, k-1);
    
    EXPECT_NE(root, nullptr);
    EXPECT_NE(root->left, nullptr);
    EXPECT_NE(root->right, nullptr);
    EXPECT_EQ(root->left->data, k-1);
    EXPECT_EQ(root->right->data, k+1);
    
    EXPECT_EQ(root->left->left, nullptr);
    EXPECT_EQ(root->left->right, nullptr);
    EXPECT_EQ(root->right->left, nullptr);
    EXPECT_EQ(root->right->right, nullptr);   
}