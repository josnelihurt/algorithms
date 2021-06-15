//https://www.hackerrank.com/challenges/between-two-sets/problem
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

namespace between_two_sets{
int getTotalX(vector<int> a, vector<int> b) {
    vector<int> result{};
    if(a.size() == 0){ 
        return 0;
    }
    auto maxA = *max_element(begin(a), end(a));
    auto maxB = *max_element(begin(b), end(b));
    auto maxAB = max(maxA,maxB);
    for (int i = 1; i <= maxAB; ++i){
        if (any_of(a.begin(), a.end(), [i](int v) { return i % v != 0; })){
            continue;
        }
        //The elements of the first array are all factors of the integer being considered
        if (any_of(b.begin(), b.end(), [i](int v) { return v % i != 0; })){
            continue;
        }
        //The integer being considered is a factor of all elements of the second array
        result.push_back(i);
    }    

    return result.size();
}
}
