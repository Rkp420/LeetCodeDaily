#include <iostream>
using namespace std;

// https://leetcode.com/problems/maximum-number-of-operations-to-move-ones-to-the-end/?envType=daily-question&envId=2025-11-13

class Solution
{
public:
    int maxOperations(string s)
    {
        long long ans = 0;
        long long ones = 0;
        int n = s.size();

        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '1')
            {
                ones++;
            }
            else
            {

                if (i == 0 || s[i - 1] == '1')
                {
                    ans += ones;
                }
            }
        }

        return (int)ans;
    }
};

int main()
{
    return 0;
}