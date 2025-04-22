#include <iostream>
using namespace std;

// BruteForce
class Solution
{
public:
#define mod 1000000007
    int solve(int n, int maxValue, vector<int> &temp)
    {
        if (temp.size() == n)
            return 1;

        int count = 0;
        for (int i = 1; i <= maxValue; i++)
        {
            if (temp.empty() || i % temp.back() == 0)
            {
                temp.push_back(i);
                count += solve(n, maxValue, temp) % mod;
                temp.pop_back();
            }
        }

        return count % mod;
    }

    int idealArrays(int n, int maxValue)
    {
        vector<int> temp;
        return solve(n, maxValue, temp);
    }
};

// Use Dp + Memoisation + Combinatorics
#define MOD 1000000007

class Solution
{
public:
    int idealArrays(int n, int maxValue)
    {
        vector<vector<int>> dp(15, vector<int>(maxValue + 1, 0));
        vector<int> primes;
        for (int i = 1; i <= maxValue; ++i)
        {
            dp[1][i] = 1;
        }

        for (int k = 2; k < 15; ++k)
        {
            for (int i = 1; i <= maxValue; ++i)
            {
                for (int j = 2 * i; j <= maxValue; j += i)
                {
                    dp[k][j] = (dp[k][j] + dp[k - 1][i]) % MOD;
                }
            }
        }

        // Precompute nCk (binomial coefficients)
        vector<vector<int>> comb(n + 1, vector<int>(15, 0));
        for (int i = 0; i <= n; ++i)
        {
            comb[i][0] = 1;
            for (int j = 1; j < 15 && j <= i; ++j)
            {
                comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
            }
        }

        int ans = 0;
        for (int len = 1; len < 15; ++len)
        {
            for (int val = 1; val <= maxValue; ++val)
            {
                ans = (ans + 1LL * dp[len][val] * comb[n - 1][len - 1]) % MOD;
            }
        }

        return ans;
    }
};


int main()
{
    return 0;
}