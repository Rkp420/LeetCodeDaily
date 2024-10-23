#include <iostream>
using namespace std;

// Using Simple Recursion (Time Limit Exceed)
class Solution1
{
public:
    static bool myCmp(string &s1, string &s2)
    {
        return s1.length() < s2.length();
    }

    bool isPred(string &s1, string &s2)
    {
        int M = s1.length();
        int N = s2.length();
        if (N - M != 1)
            return false;

        int i = 0;
        int j = 0;
        while (i < M && j < N)
        {
            if (s1[i] == s2[j])
            {
                i++;
            }
            j++;
        }
        return i == M ? true : false;
    }

    int solve(vector<string> &words, int curr_idx, int prev_idx)
    {
        if (curr_idx >= words.size())
            return 0;

        // Taken Case
        int take = 0, notTake = 0;
        if (prev_idx == -1 || isPred(words[prev_idx], words[curr_idx]))
        {
            take = 1 + solve(words, curr_idx + 1, curr_idx);
        }

        notTake = solve(words, curr_idx + 1, prev_idx);

        return max(take, notTake);
    }

    int longestStrChain(vector<string> &words)
    {
        // Sort For Better Compatibility
        sort(words.begin(), words.end(), myCmp);
        return solve(words, 0, -1);
    }
};

// Using Memoisation
class Solution2
{
public:
    static bool myCmp(string &s1, string &s2)
    {
        return s1.length() < s2.length();
    }

    bool isPred(string &s1, string &s2)
    {
        int M = s1.length();
        int N = s2.length();
        if (N - M != 1)
            return false;

        int i = 0;
        int j = 0;
        while (i < M && j < N)
        {
            if (s1[i] == s2[j])
            {
                i++;
            }
            j++;
        }
        return i == M ? true : false;
    }

    int solve(vector<string> &words, int curr_idx, int prev_idx,
              vector<vector<int>> &dp)
    {
        // Base Case
        if (curr_idx >= words.size())
            return 0;

        // Check if
        if (dp[prev_idx + 1][curr_idx] != -1)
            return dp[prev_idx + 1][curr_idx];

        // Taken Case
        int take = 0, notTake = 0;
        if (prev_idx == -1 || isPred(words[prev_idx], words[curr_idx]))
        {
            take = 1 + solve(words, curr_idx + 1, curr_idx, dp);
        }

        notTake = solve(words, curr_idx + 1, prev_idx, dp);

        return dp[prev_idx + 1][curr_idx] = max(take, notTake);
    }

    int longestStrChain(vector<string> &words)
    {
        int n = words.size();
        // Sort For Better Compatibility
        sort(words.begin(), words.end(), myCmp);
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(words, 0, -1, dp);
    }
};

// Using Buttom - Up Approach (Directly Optimised)
class Solution3
{
public:
    static bool myCmp(string &s1, string &s2)
    {
        return s1.length() < s2.length();
    }

    bool isPred(string &s1, string &s2)
    {
        int M = s1.length();
        int N = s2.length();
        if (N - M != 1)
            return false;

        int i = 0;
        int j = 0;
        while (i < M && j < N)
        {
            if (s1[i] == s2[j])
            {
                i++;
            }
            j++;
        }
        return i == M ? true : false;
    }

    int longestStrChain(vector<string> &words)
    {
        int n = words.size();
        // Sort For Better Compatibility
        sort(words.begin(), words.end(), myCmp);
        vector<int> dp(n + 1, 1);
        int maxi = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (isPred(words[j], words[i]))
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                    maxi = max(maxi, dp[i]);
                }
            }
        }
        return maxi;
    }
};

int main()
{
    return 0;
}
