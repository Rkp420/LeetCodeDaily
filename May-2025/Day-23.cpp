#include <iostream>
using namespace std;

// https://leetcode.com/problems/find-the-maximum-sum-of-node-values/submissions/1641731755/?envType=daily-question&envId=2025-05-23

class Solution
{
public:
    long long maximumValueSum(vector<int> &nums, int k,
                              vector<vector<int>> &edges)
    {
        long maxSum = 0;
        int changedCount = 0;
        int minChangeDiff = INT_MAX;

        for (const int num : nums)
        {
            maxSum += max(num, num ^ k);
            changedCount += ((num ^ k) > num) ? 1 : 0;
            minChangeDiff = min(minChangeDiff, abs(num - (num ^ k)));
        }

        if (changedCount % 2 == 0)
            return maxSum;
        return maxSum - minChangeDiff;
    }
};

int main()
{
    return 0;
}