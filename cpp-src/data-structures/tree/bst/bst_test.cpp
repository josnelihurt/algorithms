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