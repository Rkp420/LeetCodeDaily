#include <iostream>
using namespace std;
// Simple Recursion
class Solution
{
public:
    vector<int> solve(vector<int> &nums, int i, vector<int> &pickedElements)
    {
        if (i >= nums.size())
            return pickedElements;

        // Not take
        vector<int> notTake = solve(nums, i + 1, pickedElements);

        // Take
        vector<int> take;
        if (pickedElements.empty() ||
            pickedElements.back() % nums[i] == 0 || nums[i] % pickedElements.back() == 0)
        {
            pickedElements.push_back(nums[i]);
            take = solve(nums, i + 1, pickedElements);
            pickedElements.pop_back(); // backtrack
        }

        return (take.size() > notTake.size()) ? take : notTake;
    }

    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(nums.begin(), nums.end()); // ✅ Important
        vector<int> picked;
        return solve(nums, 0, picked);
    }
};

// Top - down
class Solution
{
public:
    vector<int> nums;
    vector<vector<vector<int>>> dp;

    vector<int> solve(int i, int prevIdx)
    {
        if (i == nums.size())
            return {};

        // Memoization
        if (dp[i][prevIdx + 1].size() != 0)
            return dp[i][prevIdx + 1];

        // Not take
        vector<int> notTake = solve(i + 1, prevIdx);

        // Take (only if divisible)
        vector<int> take;
        if (prevIdx == -1 || nums[i] % nums[prevIdx] == 0)
        {
            take = solve(i + 1, i);
            take.insert(take.begin(), nums[i]); // add current to front
        }

        return dp[i][prevIdx + 1] = (take.size() > notTake.size()) ? take : notTake;
    }

    vector<int> largestDivisibleSubset(vector<int> &input)
    {
        sort(input.begin(), input.end());
        nums = input;
        int n = nums.size();
        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(n + 1));

        return solve(0, -1);
    }
};
// Bottom _ Up
class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1), parent(n, -1);
        int maxSize = 1, maxIndex = 0;

        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if (dp[i] > maxSize)
            {
                maxSize = dp[i];
                maxIndex = i;
            }
        }

        // Reconstruct the subset
        vector<int> result;
        for (int i = maxIndex; i >= 0; i = parent[i])
        {
            result.push_back(nums[i]);
            if (parent[i] == -1)
                break;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
int main()
{
    return 0;
}