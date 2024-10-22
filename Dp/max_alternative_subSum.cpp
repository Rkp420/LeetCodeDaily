#include <iostream>
using namespace std;

// Using simple recursion 
class Solution1
{
public:
    typedef long long ll;
    ll solve(vector<int> &nums, int idx, bool flag)
    {
        // Base Case
        if (idx >= nums.size())
        {
            return 0;
        }
        // Take case
        ll val = nums[idx];
        if (flag == false)
            val = -val;
        ll take = solve(nums, idx + 1, !flag) + val;

        // Not Take Case
        ll notTake = solve(nums, idx + 1, flag);

        return max(take, notTake);
    }

    long long maxAlternatingSum(vector<int> &nums)
    {
        int n = nums.size();
        return solve(nums, 0, true);
    }
};

// Using Memoisation
class Solution2
{
public:
    typedef long long ll;
    ll t[1000001][2];
    ll solve(vector<int> &nums, int idx, bool flag)
    {
        // Base Case
        if (idx >= nums.size()) return 0;

        // Check if already solve 
        if(t[idx][flag] != -1) return t[idx][flag];

        // Take case
        ll val = nums[idx];
        if (flag == false)
            val = -val;
        ll take = solve(nums, idx + 1, !flag) + val;

        // Not Take Case
        ll notTake = solve(nums, idx + 1, flag);

        return t[idx][flag] = max(take, notTake);
    }

    long long maxAlternatingSum(vector<int> &nums)
    {
        int n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(nums, 0, true);
    }
};

// Using Bottom Up Approach

class Solution3
{
public:
    typedef long long ll;

    long long maxAlternatingSum(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;

        // Step 1: Initialize the dp array
        vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));

        // Step 2: Populate the dp array
        for (int i = 1; i <= n; i++)
        {
            // dp[i][0]: After adding the current element, it represents an even position
            dp[i][0] = max(dp[i - 1][1] + nums[i - 1], dp[i - 1][0]);

            // dp[i][1]: After adding the current element, it represents an odd position
            dp[i][1] = max(dp[i - 1][0] - nums[i - 1], dp[i - 1][1]);
        }

        // Step 3: Return the maximum alternating sum
        return max(dp[n][0], dp[n][1]);
    }
};

// Optimised Because Here there is only two values that are considered
class Solution4
{
public:
    typedef long long ll;

    long long maxAlternatingSum(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;

        ll prevEvenSum = 0;
        ll prevOddSum = 0;

        // Step 2: Populate the dp array
        for (int i = 0; i < n; i++)
        {
            // dp[i][0]: After adding the current element, it represents an even position
            prevEvenSum = max(prevOddSum + nums[i], prevEvenSum);

            // dp[i][1]: After adding the current element, it represents an odd position
            prevOddSum = max(prevEvenSum - nums[i], prevOddSum);
        }

        // Step 3: Return the maximum alternating sum
        return max(prevEvenSum, prevOddSum);
    }
};

// Some More Optimal in Case of line of Codes
class Solution5
{
public:
    long long maxAlternatingSum(vector<int> &nums)
    {
        long long evenSum = 0, oddSum = 0;
        for (int num : nums)
        {
            evenSum = max(evenSum, oddSum + num);
            oddSum = max(oddSum, evenSum - num);
        }
        return evenSum;
    }
};

int main()
{
    return 0;
}