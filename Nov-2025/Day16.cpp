#include <iostream>
using namespace std;

// https://leetcode.com/problems/number-of-substrings-with-only-1s/submissions/1831144276/?envType=daily-question&envId=2025-11-16

class Solution
{
public:
#define MOD 1000000007
    int numSub(string s)
    {
        int n = s.length();
        long long ans = 0;
        long long cnt = 0;

        for (char ch : s)
        {
            if (ch == '1')
                cnt++;
            else
            {
                ans = (ans + (cnt * (cnt + 1) / 2)) % MOD;
                cnt = 0;
            }
        }

        ans = (ans + (cnt * (cnt + 1) / 2)) % MOD;
        return (int)ans;
    }
};

int main()
{
    return 0;
}