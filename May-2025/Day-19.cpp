#include <iostream>
#include <unordered_set>
using namespace std;

// https://leetcode.com/problems/type-of-triangle/description/?envType=daily-question&envId=2025-05-19

class Solution
{
public:
    string triangleType(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        if (nums[0] + nums[1] <= nums[2])
            return "none";

        int uniqueSides = unordered_set(nums.begin(), nums.end()).size();

        if (uniqueSides == 1)
            return "equilateral";
        else if (uniqueSides == 2)
            return "isosceles";
        else
            return "scalene";
    }
};

int main()
{
    return 0;
}