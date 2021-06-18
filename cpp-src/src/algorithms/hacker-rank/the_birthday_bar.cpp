
#include "the_birthday_bar.h"
#include <algorithm>
//https://www.hackerrank.com/challenges/the-birthday-bar/problem
namespace the_birthday_bar{
using namespace std;
/*
 * Complete the 'birthday' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY s
 *  2. INTEGER d
 *  3. INTEGER m
 */

int birthday(vector<int> s, int d, int m) {
    if(s.size() == 0){
        return 0;
    }
    if(s.size() == 1 && m == 1){
        return s[0] == d;
    }
    auto endFor = s.end();
    std::advance(endFor, -m+1);
    int result{};
    for (auto it = begin(s); it != endFor; ++it){
        auto acc =  accumulate(it, it + m, 0);
        if(acc == d){
            result++;
        }
    }
    return result;
}
}
