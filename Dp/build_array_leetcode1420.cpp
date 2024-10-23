#include <iostream>
#include <vector>
using namespace std;

// Using Simple Recursion
class Solution
{
public:
    int N, M, K;
    int MOD = 1e9 + 7;
    int solve(int idx, int searchCost, int maxSoFar)
    {
        // Base Case
        if (idx == N)
        {
            return searchCost == K ? 1 : 0;
        }

        // initilising a new Result variable to Caluculate all the possibilities
        // and update the result
        int result = 0;

        for (int i = 1; i <= M; i++)
        {
            if (i > maxSoFar)
            {
                result += solve(idx + 1, searchCost + 1, i);
            }
            else
            {
                result += solve(idx + 1, searchCost, maxSoFar);
            }
        }

        return result;
    }

    int numOfArrays(int n, int m, int k)
    {
        N = n;
        M = m;
        K = k;
        return solve(0, 0, 0);
    }
};

// Using Memoisation
class Solution2
{
public:
    int N, M, K;
    int MOD = 1e9 + 7;
    int solve(int idx, int searchCost, int maxSoFar, vector<vector<vector<int>>> &dp)
    {
        // Base Case
        if (idx == N)
        {
            return searchCost == K ? 1 : 0;
        }

        // Check if
        if (dp[idx][searchCost][maxSoFar] != -1)
            return dp[idx][searchCost][maxSoFar];

        // initilising a new Result variable to Caluculate all the possibilities
        // and update the result
        int result = 0;

        for (int i = 1; i <= M; i++)
        {
            if (i > maxSoFar)
            {
                result = (result + solve(idx + 1, searchCost + 1, i, dp)) % MOD;
            }
            else
            {
                result = (result + solve(idx + 1, searchCost, maxSoFar, dp)) % MOD;
            }
        }

        return dp[idx][searchCost][maxSoFar] = result % MOD;
    }

    int numOfArrays(int n, int m, int k)
    {
        N = n;
        M = m;
        K = k;

        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(m + 1, -1)));

        return solve(0, 0, 0, dp);
    }
};

//Bottom - Up Approach
//Need to understand mySelf Again 

class Solution3
{
public:
    /* let ways[i][j][k] = # ways to construct an array of length i with max element equal to j and a search cost of k. */
    long long ways[51][101][51];
    const int MOD = 1e9 + 7;

    int numOfArrays(int n, int m, int k)
    {
        /* There are our base cases. For each index 1 <= j <= m, we require ways[1][j][1] = 1 because the array consisting of only the element j
            has length 1, maximum element j, and it has a search cost of 1. */
        for (int j = 1; j <= m; j++)
        {
            ways[1][j][1] = 1;
        }

        for (int a = 1; a <= n; a++)
        {
            for (int b = 1; b <= m; b++)
            {
                for (int c = 1; c <= k; c++)
                {
                    long long s = 0;

                    /* In this first case, we can append any element from [1, b] to the end of the array. */
                    s = (s + b * ways[a - 1][b][c]) % MOD;

                    /* In this second case, we can append the element "b" to the end of the array. */
                    for (int x = 1; x < b; x++)
                    {
                        s = (s + ways[a - 1][x][c - 1]) % MOD;
                    }

                    ways[a][b][c] = (ways[a][b][c] + s) % MOD;
                }
            }
        }

        long long ans = 0;
        for (int j = 1; j <= m; j++)
        {
            ans = (ans + ways[n][j][k]) % MOD;
        }

        return int(ans);
    }
};

int main()
{
    return 0;
}