#include <iostream>
using namespace std;

// https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/?envType=daily-question&envId=2025-06-13

class Solution
{
public:
    bool canFormPairs(vector<int> &nums, int p, int maxDiff)
    {
        int count = 0;
        int i = 0;
        while (i < nums.size() - 1)
        {
            if (abs(nums[i] - nums[i + 1]) <= maxDiff)
            {
                count++;
                i += 2;
            }
            else
            {
                i++;
            }
        }

        return count >= p;
    }
    int minimizeMax(vector<int> &nums, int p)
    {
        // We have to Pick P smallest pairs from nums such that the answer will also be minimized
        sort(nums.begin(), nums.end());

        int left = 0, right = nums.back() - nums[0];
        int ans = right;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (canFormPairs(nums, p, mid))
            {
                ans = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return ans;
    }
};
int main()
{
    return 0;
}