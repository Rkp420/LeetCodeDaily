#include <iostream>
using namespace std;
// Using Simple Recursion and sorting
class Solution1
{
public:
    int solve(vector<vector<int>> &pairs, int curr_idx, int prev_idx)
    {
        // Base Case
        if (curr_idx >= pairs.size())
            return 0;

        // Taken
        int take = 0, notTake = 0;
        if (prev_idx == -1 || pairs[prev_idx][1] < pairs[curr_idx][0])
        {
            take = 1 + solve(pairs, curr_idx + 1, curr_idx);
        }

        notTake = solve(pairs, curr_idx + 1, prev_idx);

        return max(take, notTake);
    }
    int findLongestChain(vector<vector<int>> &pairs)
    {
        sort(pairs.begin(), pairs.end());
        return solve(pairs, 0, -1);
    }
};

// Using Memoisation
class Solution2
{
public:
    int solve(vector<vector<int>> &pairs, int curr_idx, int prev_idx,
              vector<vector<int>> &dp)
    {
        // Base Case
        if (curr_idx >= pairs.size())
            return 0;

        // Check if
        if (prev_idx != -1 && dp[curr_idx][prev_idx] != -1)
            return dp[curr_idx][prev_idx];
        // Taken
        int take = 0, notTake = 0;
        if (prev_idx == -1 || pairs[prev_idx][1] < pairs[curr_idx][0])
        {
            take = 1 + solve(pairs, curr_idx + 1, curr_idx, dp);
        }

        notTake = solve(pairs, curr_idx + 1, prev_idx, dp);
        if (prev_idx != -1)
        {
            dp[curr_idx][prev_idx] = max(take, notTake);
        }

        return max(take, notTake);
    }
    int findLongestChain(vector<vector<int>> &pairs)
    {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(pairs, 0, -1, dp);
    }
};

// Using Button - Up Approach(Optimised);
class Solution3
{
public:
    int findLongestChain(vector<vector<int>> &pairs)
    {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        vector<int> dp(n, 1);
        int maxL = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (pairs[i][0] > pairs[j][1])
                {
                    dp[i] = max(dp[j] + 1, dp[i]);
                    maxL = max(dp[i], maxL);
                }
            }
        }
        return maxL;
    }
};

// Greedy Approach : Like Your Overlapping Intervals
// Sorting on the Basis of Starting Time 
class Solution4
{
public:
    int findLongestChain(vector<vector<int>> &pairs)
    {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        int ans = 1;
        vector<int> prev_picked_pairs = pairs[0];
        for (int i = 1; i < n; i++)
        {
            // Case 1 if intervals are conflicting
            if (prev_picked_pairs[1] >= pairs[i][0])
            {
                prev_picked_pairs[1] = min(prev_picked_pairs[1], pairs[i][1]);
                continue;
            }
            else
            {
                prev_picked_pairs[1] = pairs[i][1];
                ans++;
            }
        }
        return ans;
    }
};

//Sorting on the Basis of the Ending Time
class Solution5
{
public:
    static bool mycmp(vector<int> &P1, vector<int> &P2){
        return P1[1] < P2[1];
    }
    int findLongestChain(vector<vector<int>> &pairs)
    {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end(), mycmp);
        int ans = 1;
        vector<int> prev_picked_pairs = pairs[0];
        for (int i = 1; i < n; i++)
        {
            // Skiping the Conflicted Part (Because we using sorting on the Basis of End Time)
            // Whenever we can pick a interval
            if(prev_picked_pairs[1] < pairs[i][0])
            {
                prev_picked_pairs[1] = pairs[i][1];
                ans++;
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}