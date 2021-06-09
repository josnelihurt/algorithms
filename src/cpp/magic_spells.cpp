//https://www.hackerrank.com/challenges/magic-spells/problem

/* Enter your code here. Read input from STDIN. Print output to STDOUT */
{
    auto p = dynamic_cast<Fireball *>(spell);
    if (p != nullptr)
    {
        p->revealFirepower();
        return;
    }
}
{
    auto p = dynamic_cast<Frostbite *>(spell);
    if (p != nullptr)
    {
        p->revealFrostpower();
        return;
    }
}
{
    auto p = dynamic_cast<Thunderstorm *>(spell);
    if (p != nullptr)
    {
        p->revealThunderpower();
        return;
    }
}
{
    auto p = dynamic_cast<Waterbolt *>(spell);
    if (p != nullptr)
    {
        p->revealWaterpower();
        return;
    }
}
{
    auto p = dynamic_cast<Waterbolt *>(spell);
    if (p != nullptr)
    {
        p->revealWaterpower();
        return;
    }
}
auto spellName = spell -> revealScrollName();
string spellJournal = SpellJournal::journal;
// LCS Algorithm
string &a = spellName, &b = spellJournal;
vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1));
for (int i = 1; i <= a.size(); i++)
{
    for (int j = 1; j <= b.size(); j++)
    {
        if (a[i - 1] == b[j - 1])
            dp[i][j] = 1 + dp[i - 1][j - 1];
        else
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
}
cout << dp[a.size()][b.size()] << endl;
