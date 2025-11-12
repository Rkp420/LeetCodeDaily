#include <iostream>
using namespace std;

// https://leetcode.com/problems/ones-and-zeroes/?envType=daily-question&envId=2025-11-11

class Solution
{
public:
    vector<vector<vector<int>>> dp;
    vector<int> countBits(string str)
    {
        int x = 0, y = 0;
        for (char ch : str)
        {
            if (ch == '0')
                x++;
            else
                y++;
        }

        return {x, y};
    }

    int solve(vector<string> &str, int idx, int m, int n)
    {
        if (idx == str.size())
            return 0;

        if (dp[idx][m][n] != -1)
            return dp[idx][m][n];

        vector<int> count = countBits(str[idx]);
        int include = 0;
        if (count[0] <= m && count[1] <= n)
        {
            include = 1 + solve(str, idx + 1, m - count[0], n - count[1]);
        }

        int exclude = solve(str, idx + 1, m, n);

        return dp[idx][m][n] = max(include, exclude);
    }

    int findMaxForm(vector<string> &strs, int m, int n)
    {
        dp.assign(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return solve(strs, 0, m, n);
    }
};

int main()
{
    return 0;
}