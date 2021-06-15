#include "bst.h"
#include "gtest/gtest.h"
#include "tools/functions.h"
using namespace bst;
namespace newNode_cases{
TEST(BST, newNode){
    auto k = getRandomValue();
    auto root = newNode(k);
    EXPECT_NE(root, nullptr);
    EXPECT_EQ(root->data, k);
    EXPECT_EQ(root->left, nullptr);
    EXPECT_EQ(root->right, nullptr);  
    deleteNode(root);
}
}
namespace insert_cases{
TEST(BST, insertNullRoot){
    auto k = getRandomValue();
    auto root = insert(nullptr, k);
    EXPECT_NE(root, nullptr);
    EXPECT_EQ(root->data, k);
    EXPECT_EQ(root->left, nullptr);
    EXPECT_EQ(root->right, nullptr);  
    deleteNode(root);
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
    deleteNode(root);
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
    deleteNode(root);
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
    deleteNode(root);
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
    deleteNode(root);
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
    deleteNode(root);
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
    deleteNode(root);   
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
    deleteNode(root);  
}
}
namespace height_cases{
TEST(BST, heightNull){
    auto ht = height(nullptr);
    EXPECT_EQ(ht, -1);  
}
TEST(BST, heightSingle){
    auto k = getRandomValue();
    auto root = insert(nullptr, k);
    auto ht = height(root);
    EXPECT_EQ(ht, 0);    
    deleteNode(root);
}
TEST(BST, heightSingleLeft){
    auto k = getRandomValue();
    auto root = insert(nullptr, k);
    root = insert(root, k-1);
    auto ht = height(root);
    EXPECT_EQ(ht, 1);    
    deleteNode(root);
}
TEST(BST, heightSingleRight){
    auto k = getRandomValue();
    auto root = insert(nullptr, k);
    root = insert(root, k+1);
    auto ht = height(root);
    EXPECT_EQ(ht, 1);    
    deleteNode(root);
}
TEST(BST, height100inserts){
    auto k = getRandomValue();
    auto root = insert(nullptr, k);
    for(int i = 0; i < 100; ++i){
        root = insert(root, k + i);
    }
    auto ht = height(root);
    EXPECT_EQ(ht, 99);  
    deleteNode(root);
}
}
namespace lca_cases{
TEST(BST, lcaBase){
    auto k = getRandomValue();
    auto root = lca(nullptr, k, k);
    EXPECT_EQ(root, nullptr);  
    deleteNode(root);
}
TEST(BST, lcaLevel1){
    auto k = getRandomValue();
    auto root = insert(nullptr, k);
    root = insert(root, k+1);
    root = insert(root, k-1);
    auto lcaNode = lca(root, k-1, k+1);
    EXPECT_NE(root, nullptr);
    EXPECT_NE(lcaNode, nullptr);
    EXPECT_EQ(root, lcaNode);  
    deleteNode(root);
}
Node* makeTestTree(){
    /*
                        100
                50               150        
           25      75       125      175
        24    26  74 76   124 126 174  176
    */
   int values[] = {
        100,
        50,150,
        25,75,125,175,
        24,26,74,76,124,126,174,176
    };
    Node* root = nullptr;
    for (int i = 0; i < sizeof(values)/sizeof(values[0]); ++i){
        root = insert(root, values[i]);
    }

    EXPECT_EQ(root->data, 100);

    EXPECT_EQ(root->left->data, 50);
    EXPECT_EQ(root->right->data, 150);

    EXPECT_EQ(root->left->left->data, 25);
    EXPECT_EQ(root->left->right->data, 75);
    EXPECT_EQ(root->right->left->data, 125);
    EXPECT_EQ(root->right->right->data, 175);

    EXPECT_EQ(root->left->left->left->data, 24);
    EXPECT_EQ(root->left->left->right->data, 26);
    EXPECT_EQ(root->left->right->left->data, 74);
    EXPECT_EQ(root->left->right->right->data, 76);
    EXPECT_EQ(root->right->left->left->data, 124);
    EXPECT_EQ(root->right->left->right->data, 126);
    EXPECT_EQ(root->right->right->left->data, 174);
    EXPECT_EQ(root->right->right->right->data, 176);

    EXPECT_EQ(root->left->left->left->left, nullptr);
    EXPECT_EQ(root->left->left->left->right, nullptr);
    EXPECT_EQ(root->left->left->right->left, nullptr);
    EXPECT_EQ(root->left->left->right->right, nullptr);
    EXPECT_EQ(root->left->right->left->left, nullptr);
    EXPECT_EQ(root->left->right->left->right, nullptr);
    EXPECT_EQ(root->left->right->right->left, nullptr);
    EXPECT_EQ(root->left->right->right->right, nullptr);
    EXPECT_EQ(root->right->left->left->left, nullptr);
    EXPECT_EQ(root->right->left->left->right, nullptr);
    EXPECT_EQ(root->right->left->right->left, nullptr);
    EXPECT_EQ(root->right->left->right->right, nullptr);
    EXPECT_EQ(root->right->right->left->left, nullptr);
    EXPECT_EQ(root->right->right->left->right, nullptr);
    EXPECT_EQ(root->right->right->right->left, nullptr);
    EXPECT_EQ(root->right->right->right->right, nullptr);

    auto ht = height(root);
    EXPECT_EQ(ht, 3);
    return root;
}
TEST(BST, lcaLevel2){
    auto root = makeTestTree();
    auto lcaNode = lca(root, 50, 150);
    EXPECT_NE(root, nullptr);
    EXPECT_NE(lcaNode, nullptr);
    EXPECT_EQ(root, lcaNode);
    deleteNode(root);
}
TEST(BST, lcaLevelSameParent)
{
    auto root = makeTestTree();
    auto lcaNode = lca(root, 24, 26);
    EXPECT_NE(root, nullptr);
    EXPECT_NE(lcaNode, nullptr);
    EXPECT_EQ(lcaNode->data, 25);
    deleteNode(root);
}
TEST(BST, lcaLevelParent150){
    auto root = makeTestTree();
    auto lcaNode = lca(root, 125, 176);
    EXPECT_NE(root, nullptr);
    EXPECT_NE(lcaNode, nullptr);
    EXPECT_EQ(lcaNode->data, 150);
    deleteNode(root);
}
}

