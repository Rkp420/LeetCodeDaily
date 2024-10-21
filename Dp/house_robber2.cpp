#include <iostream>
using namespace std;
// Using Simple Recursion and Concept of House Robber I
class Solution1
{
public:
    int solve(int i, int j, vector<int> &nums)
    {
        if (i >= j)
            return 0;

        // Steal
        int x = nums[i] + solve(i + 2, j, nums);

        // Not Steal
        int y = solve(i + 1, j, nums);

        return max(x, y);
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        // In this 1st is neighbour of Last ie
        //  If we steal 0th house we ignore the last one
        int steal1st = solve(0, n - 1, nums);
        int notSteal1st = solve(1, n, nums);

        return max(steal1st, notSteal1st);
    }
};

//Using Memoisation
class Solution2
{
public:
    int solve(int i, int j, vector<int> &nums, vector<int> &dp)
    {
        if (i >= j)
            return 0;

        // Check if
        if (dp[i] != -1)
            return dp[i];

        // Steal
        int x = nums[i] + solve(i + 2, j, nums, dp);

        // Not Steal
        int y = solve(i + 1, j, nums, dp);

        return dp[i] = max(x, y);
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        // In this 1st is neighbour of Last ie
        //  If we steal 0th house we ignore the last one
        vector<int> dp1(n, -1);
        int steal1st = solve(0, n - 1, nums, dp1);

        vector<int> dp2(n, -1);
        int notSteal1st = solve(1, n, nums, dp2);

        return max(steal1st, notSteal1st);
    }
};

// Using Buttom Up approach
class Solution
{
public:
    // Helper function to perform bottom-up DP for a linear array of houses
    int robLinear(vector<int> &nums, int start, int end)
    {
        if (start == end)
            return nums[start];

        vector<int> dp(end - start + 1, 0);
        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start + 1]);

        for (int i = start + 2; i <= end; ++i)
        {
            dp[i - start] = max(dp[i - start - 1], dp[i - start - 2] + nums[i]);
        }

        return dp[end - start];
    }

    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0]; // Only one house to rob

        // Case 1: Rob houses from index 0 to n-2
        int robFirst = robLinear(nums, 0, n - 2);
        // Case 2: Rob houses from index 1 to n-1
        int robSecond = robLinear(nums, 1, n - 1);

        // Return the maximum profit from both cases
        return max(robFirst, robSecond);
    }
};

// Optimised
class Solution3
{
public:
    int robLinear(vector<int> &nums, int start, int end)
    {
        if (start > end)
            return 0;

        int prev2 = 0, prev1 = 0;
        for (int i = start; i <= end; ++i)
        {
            int current = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }

    int rob(vector<int> &nums)
    {

        int n = nums.size();
        if (n == 1)
            return nums[0]; // Only one house to rob

        // Case 1: Rob houses from index 0 to n-2
        int robFirst = robLinear(nums, 0, n - 2);
        // Case 2: Rob houses from index 1 to n-1
        int robSecond = robLinear(nums, 1, n - 1);

        // Return the maximum profit from both cases
        return max(robFirst, robSecond);
    }
};

int main()
{
    return 0;
}