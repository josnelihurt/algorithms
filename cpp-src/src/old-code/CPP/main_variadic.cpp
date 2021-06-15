#include <iostream>
using namespace std;
#include <vector>
#include <sstream>
// Enter your code for reversed_binary_value<bool...>()
//std::vector<bool> vec;// = {args...};
//auto result = 0;
//for(int i=0; i<vec.size(); ++i){
//    result |= (vec[i]<<i);
//}
//return result;

template <bool a> int reversed_binary_value() { return a; }
template<bool a, bool b, bool... d> int reversed_binary_value() {
    return (reversed_binary_value<b, d...>() << 1) + a;
}
template <int n, bool...digits>
struct CheckValues {
        static void check(int x, int y)
        {
        CheckValues<n-1, 0, digits...>::check(x, y);
        CheckValues<n-1, 1, digits...>::check(x, y);
        }
};

template <bool...digits>
struct CheckValues<0, digits...> {
        static void check(int x, int y)
        {
        int z = reversed_binary_value<digits...>();
        std::cout << (z+64*y==x);
        }
};

int main()
{
#ifdef LOCAL
    string raw = R"(2
65 1
10 0)";
    stringstream iss(raw);
    cin.rdbuf(iss.rdbuf());
#endif
        int t; std::cin >> t;

        for (int i=0; i!=t; ++i) {
                int x, y;
        cin >> x >> y;
        CheckValues<6>::check(x, y);
        cout << "\n";
        }
}
