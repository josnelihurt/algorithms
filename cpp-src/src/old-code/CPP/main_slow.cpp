#include <iostream>
#include <deque>
#include <algorithm>    // std::min_element, std::max_element
using namespace std;

void printKMax(int arr[], int n, int k){
    //Write your code here.
    deque<int> window;
    for(int i=0; i<k;++i){
        window.push_back(arr[i]);
    }

    for(int i=k; i<n; ++i){
        cout << *max_element(window.begin(),window.end()) << " ";
        window.pop_front();
        window.push_back(arr[i]);
    }
    cout << *max_element(window.begin(),window.end()) << endl;
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

