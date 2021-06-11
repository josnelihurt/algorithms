#include <cmath>
#include <cstdint>
#include <cstdio>
#include <iterator>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;


int main() {
#ifdef LOCAL
    string raw = R"(100000000 831602480 704408287 1134515747)";
    stringstream iss(raw);
    cin.rdbuf(iss.rdbuf());
#endif
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    uint64_t n,s,p,q;
    uint64_t thatNumber = static_cast<uint64_t>(pow(2, 31));
    cin >> n >> s >> p >> q;
    vector<uint64_t> v;
    v.push_back(uint64_t(s % thatNumber));
    for(uint64_t i=1;i<n;++i){
        v.push_back(v[i-1]*p+uint64_t(q%thatNumber));
    }
    std::sort(v.begin(), v.end());
    auto it = std::unique(v.begin(), v.end());
    int result = std::distance(v.begin(), it);
    cout << result;
    return 0;
}

