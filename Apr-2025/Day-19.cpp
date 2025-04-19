#include <iostream>
#include <set>
using namespace std;

// https://leetcode.com/problems/count-the-number-of-fair-pairs/description/?envType=daily-question&envId=2025-04-19

// BruteForce
class Solution
{
public:
    long long countFairPairs(vector<int> &nums, int lower, int upper)
    {
        int n = nums.size();
        long long count = 0;

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                long long sum = nums[i] + nums[j];
                if (lower <= sum && sum <= upper)
                    count++;
            }
        }

        return count;
    }
};

// using Binary Search
class Solution
{
public:
    long long countFairPairs(vector<int> &nums, int lower, int upper)
    {
        int n = nums.size();
        long long count = 0;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++)
        {
            int left = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
            int right = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin();

            count += (right - left);
        }

        return count;
    }
};

// Prefix + Binary Search
int countFairPairs(vector<int> &nums, int lower, int upper)
{
    multiset<int> seen;
    long long count = 0;

    for (int j = 0; j < nums.size(); ++j)
    {
        int lo = lower - nums[j];
        int hi = upper - nums[j];

        count += distance(seen.lower_bound(lo), seen.upper_bound(hi));
        seen.insert(nums[j]);
    }

    return count;
}

int main()
{
    return 0;
}