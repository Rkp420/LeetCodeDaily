#include <iostream>
using namespace std;

// https://leetcode.com/problems/solving-questions-with-brainpower/?envType=daily-question&envId=2025-04-01

class Solution
{
public:
    vector<long long> dp;
    long long solve(vector<vector<int>> &questions, int i)
    {
        if (i >= questions.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        long long ifsolve = questions[i][0] + solve(questions, i + questions[i][1] + 1);
        long long ifnotSolve = solve(questions, i + 1);

        return dp[i] = max(ifsolve, ifnotSolve);
    }
    long long mostPoints(vector<vector<int>> &questions)
    {
        int n = questions.size();
        dp = vector<long long>(n + 1, -1);
        return solve(questions, 0);
    }
};

// Bottom - Up
class Solution
{
public:
    long long mostPoints(vector<vector<int>> &questions)
    {
        int n = questions.size();
        vector<long long> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            long long ifsolve = questions[i][0];
            if (i + questions[i][1] + 1 < n)
            {
                ifsolve += dp[i + questions[i][1] + 1]; // Jump correctly
            }
            long long ifnotSolve = dp[i + 1]; // Skip to the next question

            dp[i] = max(ifsolve, ifnotSolve);
        }
        return dp[0]; // The answer is stored in dp[0]
    }
};

int main()
{
    return 0;
}