#include <iostream>
using namespace std;

// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/description/?envType=daily-question&envId=2025-06-29

class Solution
{
public:
    int numSubseq(vector<int> &nums, int target)
    {
        int mod = 1e9 + 7, n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> power(n, 1);
        for (int i = 1; i < n; ++i)
        {
            power[i] = (power[i - 1] * 2) % mod;
        }

        int left = 0, right = n - 1, result = 0;

        while (left <= right)
        {
            if (nums[left] + nums[right] <= target)
            {
                result = (result + power[right - left]) % mod;
                ++left;
            }
            else
            {
                --right;
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}