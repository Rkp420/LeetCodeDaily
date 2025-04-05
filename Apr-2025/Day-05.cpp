#include <iostream>
using namespace std;

// https://leetcode.com/problems/sum-of-all-subset-xor-totals/description/?envType=daily-question&envId=2025-04-05

class Solution
{
public:
    int total = 0;
    void dfs(vector<int> &nums, int i, int currXor)
    {
        if (i == nums.size())
        {
            total += currXor;
            return;
        }

        // if Choose
        dfs(nums, i + 1, currXor ^ nums[i]);

        // if Not Choose
        dfs(nums, i + 1, currXor);
    }
    int subsetXORSum(vector<int> &nums)
    {
        dfs(nums, 0, 0);

        return total;
    }
};

int main()
{
    return 0;
}