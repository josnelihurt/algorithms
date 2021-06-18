#include "the_birthday_bar.h"
#include "gtest/gtest.h"

using namespace the_birthday_bar;
using namespace std;

TEST(TBB, sampleTestCase0){
    vector<int> s{2,2,1,3,2};
    auto d = 4;
    auto m = 2;
    auto result = birthday(s, d, m);
    EXPECT_EQ(result, 2);
}