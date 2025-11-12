#include <iostream>
using namespace std;

// https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1/?envType=daily-question&envId=2025-11-12

class Solution
{
public:
    int gcd(int a, int b)
    {
        if (b == 0)
            return a;

        return gcd(b, a % b);
    }
    int minOperations(vector<int> &nums)
    {
        int n = nums.size();
        int a = nums[0], ones = 0;
        if (a == 1)
            ones++;

        for (int i = 1; i < n; i++)
        {
            a = gcd(a, nums[i]);
            if (nums[i] == 1)
                ones++;
        }

        if (ones > 0)
            return n - ones;
        if (a != 1)
            return -1;

        int minLen = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int curr = nums[i];
            for (int j = i; j < n; j++)
            {
                curr = gcd(curr, nums[j]);
                if (curr == 1)
                {
                    minLen = min(minLen, j - i + 1);
                    break;
                }
            }
        }

        return (minLen - 1) + (n - 1);
    }
};

int main()
{
    return 0;
}