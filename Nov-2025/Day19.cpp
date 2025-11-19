#include <iostream>
using namespace std;

// https://leetcode.com/problems/keep-multiplying-found-values-by-two/?envType=daily-question&envId=2025-11-19

class Solution
{
public:
    int findX(vector<int> &nums, int x)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == x)
                return i;
        }

        return -1;
    }
    int findFinalValue(vector<int> &nums, int original)
    {
        long long ans = original;
        while (true)
        {
            int currIdx = findX(nums, original);
            if (currIdx == -1)
                break;

            original = original * 2;
            ans = original;
        }

        return (int)ans;
    }
};

int main()
{
    return 0;
}