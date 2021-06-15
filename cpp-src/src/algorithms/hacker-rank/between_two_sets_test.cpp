#include "between_two_sets.h"
#include "gtest/gtest.h"
using namespace between_two_sets;
using namespace std;

TEST(BTS, sampleTestCase0){
    vector<int> a{2,6};
    vector<int> b{24,36};
    auto result = getTotalX(a,b);
    EXPECT_EQ(result, 2);
}

TEST(BTS, sampleTestCase8){
    vector<int> a{3,4};
    vector<int> b{24,48};
    auto result = getTotalX(a,b);
    EXPECT_EQ(result, 2);
}


TEST(BTS, sampleTestCase4){
    vector<int> a{1};
    vector<int> b{100};
    auto result = getTotalX(a,b);
    EXPECT_EQ(result, 9);
}