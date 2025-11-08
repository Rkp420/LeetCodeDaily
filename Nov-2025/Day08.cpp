#include <iostream>
using namespace std;

// https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/?envType=daily-question&envId=2025-11-08

// Most Optimised Approach
class Solution
{
public:
    int minimumOneBitOperations(int n)
    {
        int ans = 0;
        while (n != 0)
        {
            ans = ans ^ n;
            n >>= 1;
        }

        return ans;
    }
};

// Dp Approach

int main()
{
    return 0;
}