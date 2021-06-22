#include "icecream_parlor.h"
#include "gtest/gtest.h"
using namespace icecream_parlor;
using namespace std;

TEST(icecream_parlor, testCase0){
    auto prices = vector<int>{1,3,4,5,6};
    auto idx = icecreamParlor(6,prices);
    EXPECT_EQ(idx[0], 1);
    EXPECT_EQ(idx[1], 4);
}
