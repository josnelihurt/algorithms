#include "camelcase.h"
//https://www.hackerrank.com/challenges/camelcase
namespace camelcase{
//Implementation goes here

int camelcase(std::string s){
    int result{};
    for(char c : s){
        if((int)c>=(int)'A' && (int)c<=(int)'Z'){
            result++;
        }
    }
    return result+1;
}
}