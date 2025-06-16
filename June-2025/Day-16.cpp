#include <iostream>
using namespace std;

// https://leetcode.com/problems/maximum-difference-between-increasing-elements/submissions/1665524931/?envType=daily-question&envId=2025-06-16

class Solution
{
public:
    int maximumDifference(vector<int> &nums)
    {
        int n = nums.size();
        int minVal = nums[0];
        int maxDiff = -1;

        for (int i = 1; i < n; i++)
        {
            if (nums[i] > minVal)
            {
                maxDiff = max(maxDiff, nums[i] - minVal);
            }
            else
            {
                minVal = nums[i]; // update min so far
            }
        }

        return maxDiff;
    }
};

int main()
{
    return 0;
}