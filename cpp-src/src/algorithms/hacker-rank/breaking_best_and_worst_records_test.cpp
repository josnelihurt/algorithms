#include "breaking_best_and_worst_records.h"

#include "gtest/gtest.h"
using namespace breaking_best_and_worst_records;
using namespace std;

TEST(BBAWR, sampleTestCase0){
    vector<int> a{2, 6};
    vector<int> b{24, 36};
    auto result = breakingRecords(a, b);
    EXPECT_EQ(result, 2);
}


