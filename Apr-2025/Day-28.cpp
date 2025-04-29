#include <iostream>
using namespace std;

// https://leetcode.com/problems/count-subarrays-with-score-less-than-k/description/?envType=daily-question&envId=2025-04-28

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, long long k)
    {
        long ans = 0;
        long sum = 0;

        for (int l = 0, r = 0; r < nums.size(); ++r)
        {
            sum += nums[r];
            while (sum * (r - l + 1) >= k)
                sum -= nums[l++];
            ans += r - l + 1;
        }

        return ans;
    }
};
int main()
{
    return 0;
}