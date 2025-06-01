#include <iostream>
using namespace std;

// https : // leetcode.com/problems/distribute-candies-among-children-ii/submissions/1650389390/?envType=daily-question&envId=2025-06-01

class Solution
{
public:
    // Same as 2927. Distribute Candies Among Children III
    long long distributeCandies(int n, int limit)
    {
        const int limitPlusOne = limit + 1;
        const long oneChildExceedsLimit = ways(n - limitPlusOne);
        const long twoChildrenExceedLimit = ways(n - 2 * limitPlusOne);
        const long threeChildrenExceedLimit = ways(n - 3 * limitPlusOne);
        // Principle of Inclusion-Exclusion (PIE)
        return ways(n) - 3 * oneChildExceedsLimit + 3 * twoChildrenExceedLimit -
               threeChildrenExceedLimit;
    }

private:
    // Returns the number of ways to distribute n candies to 3 children.
    long ways(int n)
    {
        if (n < 0)
            return 0;
        // Stars and bars method:
        // e.g. '**|**|*' means to distribute 5 candies to 3 children, where
        // stars (*) := candies and bars (|) := dividers between children.
        return nCk(n + 2, 2);
    }

    long nCk(int n, int k)
    {
        long res = 1;
        for (int i = 1; i <= k; ++i)
            res = res * (n - i + 1) / i;
        return res;
    }
};

int main()
{
    return 0;
}