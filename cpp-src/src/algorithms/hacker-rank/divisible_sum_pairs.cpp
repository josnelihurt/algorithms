
#include "the_birthday_bar.h"
#include <algorithm>
//https://www.hackerrank.com/challenges/divisible-sum-pairs/problem
namespace divisible_sum_pairs{
using namespace std;
/*
 * Complete the 'divisibleSumPairs' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. INTEGER_ARRAY ar
 */
int divisibleSumPairs(int n, int k, vector<int> ar) {
    int result{};
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if(j>=i){
                continue;
            }
            auto s = ar[i] + ar[j];
            if(s%k==0){
                result++;
            }
        }    
    }
    return result;
}
}
