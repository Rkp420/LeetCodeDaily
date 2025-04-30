#include <iostream>
using namespace std;

// https://leetcode.com/problems/find-numbers-with-even-number-of-digits/?envType=daily-question&envId=2025-04-30

class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {
        int ans = 0;

        for (int num : nums)
            if (9 < num && num < 100 || 999 < num && num < 10000 || num == 100000)
                ++ans;

        return ans;
    }
};

int main()
{
    return 0;
}