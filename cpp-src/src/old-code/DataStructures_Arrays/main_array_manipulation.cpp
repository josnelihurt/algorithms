//https://www.hackerrank.com/challenges/crush
#include <bits/stdc++.h>
#include <cstdint>

using namespace std;

vector<string> split_string(string);

// Complete the arrayManipulation function below.
long arrayManipulation_timeout(int n, vector<vector<int>> queries) {
    //brutal force
    vector<long> elements(n);
    long max{0};
    std::fill(begin(elements), end(elements), 0);

    for(auto& q: queries){
        int a{q[0]},b{q[1]},k{q[2]};
        for(auto it = elements.begin() + a - 1;
            it != elements.begin() + b;
            ++it){
                *it += k;
                if(*it > max) max = *it;
            }
    }
    return max;
}
// Complete the arrayManipulation function below.
long arrayManipulation(int n, vector<vector<int>> queries) {
    //having noncontiguos data
    vector<int> start(n);
    vector<int> finish(n);
    std::fill(begin(start), end(start), 0);
    std::fill(begin(finish), end(finish), 0);

    for(auto& q: queries){
        int a{q[0]},b{q[1]},k{q[2]};
        start[a-1] += k;
        finish[b-1] += k;
    }

    long current{0},max{0};
    current = start[0];
    //accumulate
    for(int i = 1; i < n; ++i){
        current += start[i] - finish[i-1];
        if(current > max) max = current;
    }


    return max;
}
int main()
{
#ifdef LOCAL
    string raw = R"(10 4
 2 6 8
 3 5 7
 1 8 1
 5 9 15)";
    stringstream iss(raw);
    cin.rdbuf(iss.rdbuf());
#define fout cout
#else
    ofstream fout(getenv("OUTPUT_PATH"));
#endif

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<vector<int>> queries(m);
    for (int i = 0; i < m; i++) {
        queries[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> queries[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long result = arrayManipulation(n, queries);

    fout << result << "\n";

#ifndef LOCAL
    fout.close();
#endif
    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}


