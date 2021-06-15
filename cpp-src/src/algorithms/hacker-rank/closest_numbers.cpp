//https://www.hackerrank.com/challenges/closest-numbers/problem
#include <bits/stdc++.h>
#include <algorithm>
#include <climits>
using namespace std;

vector<string> split_string(string);

// Complete the closestNumbers function below.
vector<int> closestNumbers(vector<int> arr)
{
    vector<int> result(arr.size() * 2);
    int min_diff{INT_MAX}, index{0};
    std::sort(arr.begin(), arr.end());
    for (int i = 1; i < arr.size(); ++i)
    {
        int diff = arr[i] - arr[i - 1];
        if (diff == min_diff)
        {
            //add diff to result
            result[index++] = arr[i - 1];
            result[index++] = arr[i];
        }
        else if (diff < min_diff)
        {
            //new min_diff
            index = 0;
            min_diff = diff;
            result[index++] = arr[i - 1];
            result[index++] = arr[i];
        }
    }
    result.erase(result.begin() + index, result.end());
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<int> result = closestNumbers(arr);

    for (int i = 0; i < result.size(); i++)
    {
        fout << result[i];

        if (i != result.size() - 1)
        {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string)
{
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ')
    {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos)
    {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
