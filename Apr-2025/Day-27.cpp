#include <iostream>
using namespace std;

// https://leetcode.com/problems/count-subarrays-of-length-three-with-a-condition/?envType=daily-question&envId=2025-04-27

class Solution
{
public:
    int countSubarrays(vector<int> &nums)
    {
        int ans = 0;

        for (int i = 1; i + 1 < nums.size(); ++i)
            if (nums[i] == (nums[i - 1] + nums[i + 1]) * 2)
                ++ans;

        return ans;
    }
};

int main()
{
    return 0;
}