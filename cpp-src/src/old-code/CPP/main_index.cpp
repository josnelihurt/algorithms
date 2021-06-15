#include <iostream>
#include <deque>
#include <algorithm>
#include <set>
#include <sstream>
using namespace std;
//https://www.hackerrank.com/challenges/deque-stl
void printKMax(int arr[], int n, int k){
    //Write your code here.
    auto removeAllLessThanInIndex = [](deque<int>& indexes,int arr[], int currentIndex){
        while(!indexes.empty() && arr[currentIndex] >= arr[indexes.back()]){
            indexes.pop_back();
        }
    };
    deque<int> indexes;
    for(int i=0; i<k;++i){
        removeAllLessThanInIndex(indexes,arr,i);
        indexes.push_back(i);
    }

    for(int i=k; i<n; ++i){
        cout <<" "<< arr[indexes.front()];
        while ((!indexes.empty()) && indexes.front() <= i - k){
            indexes.pop_front(); // Remove from front of queue
        }
        removeAllLessThanInIndex(indexes,arr,i);
        indexes.push_back(i);
    }
    cout <<" "<< arr[indexes.front()];
    cout << "\n";
}

int main(){
#ifdef LOCAL
    string raw = R"(2
    6 2
    3 4 4 6 -3 4
    7 4
    3 4 5 8 1 4 10)";
    stringstream iss(raw);
    cin.rdbuf(iss.rdbuf());
#endif
    int t;
    cin >> t;
    while(t>0) {
        int n,k;
        cin >> n >> k;
        int i;
        int arr[n];
        for(i=0;i<n;i++)
            cin >> arr[i];
        printKMax(arr, n, k);
        t--;
    }
    std::flush(std::cout);
    return 0;
}

