#include "divisible_sum_pairs.h"
#include "gtest/gtest.h"

using namespace divisible_sum_pairs;
using namespace std;

TEST(DSP, sampleTestCase0){
    auto n = 6;
    auto k = 5;
    vector<int> ar{1,2,3,4,5,6};
    auto result = divisibleSumPairs(n,k,ar);
    EXPECT_EQ(result, 3);
}
