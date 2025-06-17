#include <iostream>
using namespace std;

// https://leetcode.com/problems/count-the-number-of-arrays-with-k-matching-adjacent-elements/?envType=daily-question&envId=2025-06-17

const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

class Solution
{
public:
    vector<long long> fact, invFact;

    long long power(long long a, long long b)
    {
        long long res = 1;
        while (b > 0)
        {
            if (b % 2 == 1)
                res = res * a % MOD;
            a = a * a % MOD;
            b /= 2;
        }
        return res;
    }

    void precompute()
    {
        fact.resize(MAX);
        invFact.resize(MAX);

        fact[0] = 1;
        for (int i = 1; i < MAX; i++)
        {
            fact[i] = fact[i - 1] * i % MOD;
        }

        invFact[MAX - 1] = power(fact[MAX - 1], MOD - 2);
        for (int i = MAX - 2; i >= 0; i--)
        {
            invFact[i] = invFact[i + 1] * (i + 1) % MOD;
        }
    }

    long long nCr(int n, int r)
    {
        if (r < 0 || r > n)
            return 0;
        return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
    }

    int countGoodArrays(int n, int m, int k)
    {
        precompute();

        long long ways = m * nCr(n - 1, k) % MOD;
        ways = ways * power(m - 1, n - 1 - k) % MOD;

        return ways;
    }
};

// Dp Approaches
const int MOD = 1e9 + 7;

class Solution
{
public:
    int n, m, k;
    vector<vector<vector<int>>> dp;

    int solve(int pos, int eqCount, int prev)
    {
        // Base case
        if (pos == n)
        {
            return eqCount == k ? 1 : 0;
        }

        // Memoization
        if (dp[pos][eqCount][prev] != -1)
            return dp[pos][eqCount][prev];

        int ans = 0;

        for (int curr = 1; curr <= m; curr++)
        {
            int newEqCount = (curr == prev) ? eqCount + 1 : eqCount;

            // Only proceed if we don't exceed k
            if (newEqCount <= k)
            {
                ans = (ans + solve(pos + 1, newEqCount, curr)) % MOD;
            }
        }

        return dp[pos][eqCount][prev] = ans;
    }

    int countGoodArrays(int _n, int _m, int _k)
    {
        n = _n;
        m = _m;
        k = _k;

        // [position][equal_pairs_so_far][previous_value]
        dp = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(k + 1, vector<int>(m + 2, -1)));

        int res = 0;
        // Try all first elements from 1 to m
        for (int first = 1; first <= m; first++)
        {
            res = (res + solve(1, 0, first)) % MOD;
        }

        return res;
    }
};

// Bottom up 
const int MOD = 1e9 + 7;

class Solution
{
public:
    int countGoodArrays(int n, int m, int k)
    {
        // dp[i][j]: number of ways to build i-length array with j equal adj pairs
        vector<vector<int>> dp(n, vector<int>(k + 1, 0));

        // Base case: length = 1, 0 equal adjacents → we can pick any number
        dp[0][0] = m;

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                // Option 1: Extend previous with equal number
                if (j > 0)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;

                // Option 2: Use different number than previous (m - 1 choices)
                dp[i][j] = (dp[i][j] + (int)((1LL * dp[i - 1][j] * (m - 1)) % MOD)) % MOD;
            }
        }

        return dp[n - 1][k];
    }
};

// Bottom - up Optimised

const int MOD = 1e9 + 7;

class Solution
{
public:
    int countGoodArrays(int n, int m, int k)
    {
        // Space-optimized: Use two 1D arrays
        vector<int> prev(k + 1, 0);
        vector<int> curr(k + 1, 0);

        // Base case: length = 1, 0 equal adjacent => m choices
        prev[0] = m;

        for (int i = 1; i < n; i++)
        {
            fill(curr.begin(), curr.end(), 0); // clear current row

            for (int j = 0; j <= k; j++)
            {
                // Option 1: Keep previous value (creates an equal pair)
                if (j > 0)
                    curr[j] = (curr[j] + prev[j - 1]) % MOD;

                // Option 2: Change to different value (m - 1 options)
                curr[j] = (curr[j] + 1LL * prev[j] * (m - 1)) % MOD;
            }

            swap(prev, curr); // next iteration will use updated values
        }

        return prev[k];
    }
};

int main()
{
    return 0;
}