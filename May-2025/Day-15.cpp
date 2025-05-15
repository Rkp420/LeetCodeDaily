#include <iostream>
using namespace std;

// https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-i/description/?envType=daily-question&envId=2025-05-15

// BruteForce (TLE)
class Solution
{
public:
    vector<string> longestAns = {};
    void f(int i, int prev, vector<string> &word, vector<int> &groups, vector<string> &curr)
    {
        if (i == word.size())
        {
            if (curr.size() > longestAns.size())
            {
                longestAns = curr;
            }
            return;
        }

        // not pick
        f(i + 1, prev, word, groups, curr);

        // pick
        if (prev != groups[i])
        {
            curr.push_back(word[i]);
            f(i + 1, groups[i], word, groups, curr);
            curr.pop_back();
        }
    }
    vector<string> getLongestSubsequence(vector<string> &words, vector<int> &groups)
    {
        vector<string> temp;
        f(0, -1, words, groups, temp);

        return longestAns;
    }
};

// 2nd Bruteforce
class Solution
{
public:
    vector<string> f(int i, int prev, vector<string> &word, vector<int> &groups)
    {
        if (i == word.size())
            return {};

        // not pick
        vector<string> temp1 = f(i + 1, prev, word, groups);

        // pick
        vector<string> temp2;
        if (prev != groups[i])
        {
            temp2.push_back(word[i]);
            vector<string> next = f(i + 1, groups[i], word, groups);
            for (string s : next)
                temp2.push_back(s);
        }

        return temp1.size() >= temp2.size() ? temp1 : temp2;
    }
    vector<string> getLongestSubsequence(vector<string> &words, vector<int> &groups)
    {

        return f(0, -1, words, groups);
    }
};

// Memoised
class Solution
{
public:
    // Memoization map
    unordered_map<string, vector<string>> dp;

    string getKey(int i, int prev)
    {
        return to_string(i) + "_" + to_string(prev);
    }

    vector<string> f(int i, int prev, vector<string> &word, vector<int> &groups)
    {
        if (i == word.size())
            return {};

        string key = getKey(i, prev);
        if (dp.count(key))
            return dp[key];

        // Not pick
        vector<string> notPick = f(i + 1, prev, word, groups);

        // Pick
        vector<string> pick;
        if (prev != groups[i])
        {
            pick.push_back(word[i]);
            vector<string> next = f(i + 1, groups[i], word, groups);
            pick.insert(pick.end(), next.begin(), next.end());
        }

        // Store and return the longer one
        return dp[key] = (pick.size() > notPick.size() ? pick : notPick);
    }

    vector<string> getLongestSubsequence(vector<string> &words, vector<int> &groups)
    {
        return f(0, -1, words, groups); // Use -1 as initial prev to allow any first group
    }
};

int main()
{
    return 0;

}