#include "the_birthday_bar.h"
#include "gtest/gtest.h"

using namespace the_birthday_bar;
using namespace std;

TEST(TBB, sampleTestCase10){
    vector<int> s{
        3, 5, 4, 1, 2, 5, 3, 4, 3, 2, 1, 1, 2, 4, 2, 3, 4, 5, 3, 1, 2, 5, 4, 5, 4, 1, 1, 5, 3, 1, 4, 5, 2, 3, 2, 5, 2, 5, 2, 2, 1, 5, 3, 2, 5, 1, 2, 4, 3, 1, 5, 1, 3, 3, 5};
    auto d = 18;
    auto m = 6;
    auto result = birthday(s, d, m);
    EXPECT_EQ(result, 10);
}
TEST(TBB, sampleTestCaseD1M1){
    vector<int> s{1, 1, 1, 1, 1};
    auto d = 1;
    auto m = 1;
    auto result = birthday(s, d, m);
    EXPECT_EQ(result, 5);
}
TEST(TBB, sampleTestCaseD0){
    vector<int> s{4, 0, 0, 0, 1};
    auto d = 0;
    auto m = 2;
    auto result = birthday(s, d, m);
    EXPECT_EQ(result, 2);
}
TEST(TBB, sampleTestCaseM0){
    vector<int> s{4,0,0,1,1};
    auto d = 4;
    auto m = 0;
    auto result = birthday(s, d, m);
    EXPECT_EQ(result, 0);
}
TEST(TBB, sampleTestCase2){
    vector<int> s{4};
    auto d = 4;
    auto m = 1;
    auto result = birthday(s, d, m);
    EXPECT_EQ(result, 1);
}
TEST(TBB, sampleTestCase0){
    vector<int> s{2, 2, 1, 3, 2};
    auto d = 4;
    auto m = 2;
    auto result = birthday(s, d, m);
    EXPECT_EQ(result, 2);
}
