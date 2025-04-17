#include <iostream>
#include <unordered_set>
using namespace std;

// https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/?envType=daily-question&envId=2025-04-17

class Solution
{
public:
    int gcd(int a, int b)
    {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }

    int countPairs(vector<int> &nums, int k)
    {
        int result = 0;
        // Step 1 : To Store each Num with their Respective Index
        unordered_map<int, vector<int>> indicesOfNum;

        for (int i = 0; i < nums.size(); i++)
        {
            indicesOfNum[nums[i]].push_back(i);
        }

        // Step 2 : Store all the Divisors of K
        unordered_set<int> divisors;
        for (int i = 1; i * i <= k; i++)
        {
            if (k % i == 0)
            {
                divisors.insert(i);
                divisors.insert(k / i);
            }
        }

        // Step 3 : Start Processing Each Number
        for (auto &[num, indices] : indicesOfNum)
        {
            unordered_map<int, int> factorsMap;

            for (int i : indices)
            {
                int GCD = gcd(i, k);
                int j = k / GCD;

                result += factorsMap[j];

                for (int f : divisors)
                {
                    if (i % f == 0)
                        factorsMap[f]++;
                }
            }
        }

        return result;
    }
};
int main()
{
    return 0;
}