#include <iostream>
using namespace std;

// https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/submissions/1667773313/?envType=daily-question&envId=2025-06-18

class Solution
{
public:
    vector<vector<int>> divideArray(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); i += 3)
        {
            if (nums[i + 2] - nums[i] > k)
            {
                return {};
            }
            ans.push_back({nums[i], nums[i + 1], nums[i + 2]});
        }
        return ans;
    }
};

int main()
{
    return 0;
}