#include "icecream_parlor.h"
#include <bits/stdc++.h>
//https://www.hackerrank.com/challenges/icecream-parlor/problem
using namespace std;
namespace icecream_parlor{
//Implementation goes here
vector<int> icecreamParlor(int m, vector<int> arr){
    auto result = vector<int>{0,0};
    [&]{
        for(int i = 0; i < arr.size(); ++i){
            for (int j = 0; j < arr.size(); ++j){
                if(i==j){
                    continue;
                }
                if(arr[i]+arr[j] == m){
                    result[0] = i+1;
                    result[1] = j+1;
                    return;
                }
            }
        }
    }();
    sort(result.begin(), result.end());
    return result;
}
}