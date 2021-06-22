#include "camelcase.h"
#include "gtest/gtest.h"
using namespace camelcase;
using namespace std;

TEST(CamelCase, testCase0){
    auto s = "theString";
    auto result = camelcase::camelcase(s);
    EXPECT_EQ(result, 2);
}
