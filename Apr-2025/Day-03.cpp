
#include <iostream>
using namespace std;

// https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii/?envType=daily-question&envId=2025-04-03

class Solution
{
public:
    long long maximumTripletValue(vector<int> &nums)
    {
        int n = nums.size();
        long long result = 0;

        long long maxDiff = 0;
        long long maxi = 0;

        for (int k = 0; k < n; k++)
        {
            result = max(result, maxDiff * nums[k]);
            maxDiff = max(maxDiff, maxi - nums[k]);
            maxi = max(maxi, (long long)nums[k]);
        }
        return result;
    }
};

int main()
{
    return 0;
}