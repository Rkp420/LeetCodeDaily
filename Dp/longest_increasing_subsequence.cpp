#include <iostream>
using namespace std;

// Using Simple Recursion
class Solution
{
public:
    int solve(vector<int> &nums, int idx, int prevIdx)
    {
        // Base Case
        if (idx >= nums.size())
            return 0;

        // Case (Take)
        int take = INT_MIN;
        if (prevIdx == -1 || nums[prevIdx] < nums[idx])
        {
            take = 1 + solve(nums, idx + 1, idx);
        }

        // Case (Skip)
        int notTake = solve(nums, idx + 1, prevIdx);

        return max(take, notTake);
    }
    int lengthOfLIS(vector<int> &nums)
    {
        return solve(nums, 0, -1);
    }
};

// Using Memoisation
class Solution2
{
public:
    int solve(vector<int> &nums, int idx, int prevIdx, vector<vector<int>> &dp)
    {
        // Base Case
        if (idx >= nums.size())
            return 0;

        // Check if we already calculated
        if (dp[idx][prevIdx + 1] != -1)
            return dp[idx][prevIdx + 1];

        // Case (Take)
        int take = INT_MIN;
        if (prevIdx == -1 || nums[prevIdx] < nums[idx])
        {
            take = 1 + solve(nums, idx + 1, idx, dp);
        }

        // Case (Skip)
        int notTake = solve(nums, idx + 1, prevIdx, dp);

        return dp[idx][prevIdx + 1] = max(take, notTake);
    }

    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(nums, 0, -1, dp);
    }
};

// Using Simple Bottom - UP Approach
class Solution3
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int idx = n - 1; idx >= 0; idx--)
        {
            for (int prevIdx = idx - 1; prevIdx >= -1; prevIdx--)
            {
                // Case (Take)
                int take = 0;

                if (prevIdx == -1 || nums[prevIdx] < nums[idx])
                {
                    take = 1 + dp[idx + 1][idx + 1];
                }

                // Case (Skip)
                int notTake = dp[idx + 1][prevIdx + 1];

                dp[idx][prevIdx + 1] = max(take, notTake);
            }
        }

        return dp[0][0];
    }
};

// Optimised Bottom Up Approach
class Solution4
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);
        int maxLis = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                // If we can add the current element into any subsequence
                if (nums[j] < nums[i])
                {
                    dp[i] = max(dp[j] + 1, dp[i]);
                    maxLis = max(dp[i], maxLis);
                }
            }
        }

        return maxLis;
    }
};

// Using Lazy Sorting or Called as Patience approach or binary search approach
class Solution5
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        int len = 1;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > temp.back())
            {
                temp.push_back(nums[i]);
                len++;
            }
            else
            {
                // We need to find lower bound
                int idx = lower_bound(temp.begin(), temp.end(), nums[i]) -
                          temp.begin();
                temp[idx] = nums[i];
            }
        }
        return len;
    }
};

int main()
{
    return 0;
}