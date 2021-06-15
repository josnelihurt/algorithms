#include <iostream>
#include <deque>
#include <algorithm>
#include <set>
#include <sstream>
using namespace std;
//https://www.hackerrank.com/challenges/deque-stl
void printKMax(int arr[], int n, int k){
    //Write your code here.
    set<int> windowSorted;
    for(int i=0; i<k;++i){
        windowSorted.insert(arr[i]);
    }
    auto max = *windowSorted.rbegin();
    int next, prev;
    cout << max;
    for(int i=k; i<n; ++i){
        prev = arr[i-k];
        next = arr[i];
        windowSorted.insert(next);
        if(windowSorted.size() > k){
            //remove an element
            windowSorted.erase(prev);
        }
        max = *windowSorted.rbegin();


        cout <<" "<< max ;
    }
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

