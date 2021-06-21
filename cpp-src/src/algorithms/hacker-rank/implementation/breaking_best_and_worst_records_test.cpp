#include "breaking_best_and_worst_records.h"

#include "gtest/gtest.h"
using namespace breaking_best_and_worst_records;
using namespace std;

TEST(BBAWR, sampleTestCase1){
    vector<int> s{3,4,21,36,10,28,35,5,24,42};
    auto result = breakingRecords(s);
    EXPECT_EQ(result.size(), 2);
    EXPECT_EQ(result[0], 4);
    EXPECT_EQ(result[1], 0);
}

TEST(BBAWR, sampleTestCase0){
    vector<int> s{10,5,20,20,4,5,2,25,1};
    auto result = breakingRecords(s);
    EXPECT_EQ(result.size(), 2);
    EXPECT_EQ(result[0], 2);
    EXPECT_EQ(result[1], 4);
}


