#include <iostream>
using namespace std;

// Using Simple Recursion
class Solution1
{
public:
    int solve(int n)
    {
        // Base Cases
        if (n < 0)
            return 0;
        if (n == 0)
            return 1;

        // Case : One step
        int x = solve(n - 1);

        // Case : Two step
        int y = solve(n - 2);

        return x + y;
    }
    int climbStairs(int n)
    {
        return solve(n);
    }
};

// Using Memoisation Because Of overlapping Subproblems
class Solution2
{
public:
    int solve(int n, vector<int> &dp)
    {
        // Base Cases
        if (n < 0)
            return 0;
        if (n == 0)
            return 1;

        // Check if
        if (dp[n] != -1)
            return dp[n];

        // Case : One step
        int x = solve(n - 1, dp);

        // Case : Two step
        int y = solve(n - 2, dp);

        return dp[n] = x + y;
    }
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};

//Bottom - Up Approach

class Solution3
{
public:
    int climbStairs(int n)
    {

        vector<int> dp(n + 1, 0);
        // Base cases
        dp[0] = 1; // 1 way to stay on the ground (do nothing)
        dp[1] = 1; // 1 way to reach the first step (1 step)

        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

// Finally Optimised
class Solution4
{
public:
    int climbStairs(int n)
    {
        if(n <= 1) return 1;

        int prev = 1;
        int prev_of_prev = 1;
        int curr;

        for (int i = 2; i <= n; i++)
        {
           curr = prev + prev_of_prev;
           prev_of_prev = prev;
           prev = curr;
        }

        return prev;
    }
};
int main()
{
    return 0;
}