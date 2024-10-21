#include <iostream>
using namespace std;

// Using Simple recursion
class Solution1
{
public:
    int solve(vector<int> &nums, int i)
    {
        // Base Case : Out of Bound Case
        if (i >= nums.size())
            return 0;

        // If we Steal Current House
        int x = nums[i] + solve(nums, i + 2);
        int y = solve(nums, i + 1);

        // Return max we can steal
        return max(x, y);
    }
    int rob(vector<int> &nums)
    {
        return solve(nums, 0);
    }
};

//Using Memoisation
class Solution2
{
public:
    int solve(vector<int> &nums, int i, vector<int> &dp)
    {
        // Base Case : Out of Bound Case
        if (i >= nums.size())
            return 0;

        // Check if
        if (dp[i] != -1)
            return dp[i];

        // If we Steal Current House
        int x = nums[i] + solve(nums, i + 2, dp);
        int y = solve(nums, i + 1, dp);

        // Return max we can steal
        return dp[i] = max(x, y);
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(nums, 0, dp);
    }
};

//Using Bottom Approach
class Solution3
{
public:
    int rob(vector<int> &nums)
    {

        int n = nums.size();
        // Base Case
        if (n == 1)
            return nums[0];

        // Making an Vector to Store the current Optimised Result;
        vector<int> dp(n, 0);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[n - 1];
    }
};

//Optimised
class Solution4
{
public:
    int rob(vector<int> &nums)
    {

        int n = nums.size();
        // Base Case
        if (n == 1)
            return nums[0];

        int prev_of_prev = nums[0];
        int prev = max(nums[0], nums[1]);
        int curr;

        for (int i = 2; i < n; i++)
        {
            curr = max(prev, prev_of_prev + nums[i]);
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