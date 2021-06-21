#include "breaking_best_and_worst_records.h"
#include <limits> // std::numeric_limits

using namespace std;
namespace breaking_best_and_worst_records
{


vector<int> breakingRecords(vector<int> scores){
    auto max = numeric_limits<int>::min();
    auto min = numeric_limits<int>::max();
    enum resultValues
    {
        HSCORE,
        LSCORE
    };
    auto result = vector<int>{0,0};
    bool init = false;
    for(auto& score : scores){
        if(!init){
            max = score;
            min = score;
            init = true;
            continue;
        }
        if(score>max){
            result[HSCORE]++;
            max = score;
        }
        if (score<min){
            result[LSCORE]++;
            min = score;
        }
    }
    return result;
}

}