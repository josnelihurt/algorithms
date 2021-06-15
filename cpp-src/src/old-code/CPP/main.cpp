#include <iostream>
#include <deque>
#include <algorithm>
#include <set>
using namespace std;
//https://www.hackerrank.com/challenges/deque-stl
void printKMax(int arr[], int n, int k){
    //Write your code here.
    deque<int> window;
    set<int> windowSorted;
    for(int i=0; i<k;++i){
        window.push_back(arr[i]);
        windowSorted.insert(arr[i]);
    }
    auto max = *max_element(window.begin(),window.end());
    int since_max = 0, next, prev;
    cout << max;
    for(int i=k; i<n; ++i){
        prev = window.front();
        window.pop_front();
        next = arr[i];
        window.push_back(next);
        windowSorted.insert(next);
        if(windowSorted.size() > k){
            //remove an element
            windowSorted.erase(prev);
        }
        max = *windowSorted.rbegin();


        cout <<" "<< max ;
    }
    cout << endl;
}

int main(){

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
    return 0;
}

