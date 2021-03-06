//https://www.hackerrank.com/challenges/counting-valleys/problem
#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s)
{
    int result{}, counter{};
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == 'U')
        {
            counter++;
        }
        else
        {
            counter--;
        }
        if (counter == -1 && s[i] == 'D')
        {
            result++;
        }
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
