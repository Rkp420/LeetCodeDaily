#include <iostream>
using namespace std;

// https://leetcode.com/problems/maximum-difference-between-adjacent-elements-in-a-circular-array/?envType=daily-question&envId=2025-06-12

class Solution
{
public:
    int maxAdjacentDistance(vector<int> &nums)
    {
        int ans = abs(nums.front() - nums.back());

        for (int i = 0; i + 1 < nums.size(); ++i)
            ans = max(ans, abs(nums[i] - nums[i + 1]));

        return ans;
    }
};

int main()
{
    return 0;
}