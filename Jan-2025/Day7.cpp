#include <iostream>
using namespace std;

// https://leetcode.com/problems/string-matching-in-an-array/description/?envType=daily-question&envId=2025-01-07

// Brute Force Solution
class Solution
{
public:
    vector<string> stringMatching(vector<string> &words)
    {
        vector<string> result;
        for (int i = 0; i < words.size(); ++i)
        {
            for (int j = 0; j < words.size(); ++j)
            {
                if (i != j && words[j].find(words[i]) != string::npos)
                {
                    result.push_back(words[i]);
                    break;
                }
            }
        }
        return result;
    }
};

// Optimal Solution
class SolutionOptimal
{
public:
    vector<string> stringMatching(vector<string> &words)
    {
        vector<string> result;
        sort(words.begin(), words.end(), [](const string &a, const string &b)
             { return a.length() < b.length(); });
        for (int i = 0; i < words.size(); ++i)
        {
            for (int j = i + 1; j < words.size(); ++j)
            {
                if (words[j].find(words[i]) != string::npos)
                {
                    result.push_back(words[i]);
                    break;
                }
            }
        }
        return result;
    }
};

// KMP Algorithm Solution
class SolutionKMP
{
public:
    vector<string> stringMatching(vector<string> &words)
    {
        vector<string> result;
        for (int i = 0; i < words.size(); ++i)
        {
            for (int j = 0; j < words.size(); ++j)
            {
                if (i != j && isSubstringKMP(words[i], words[j]))
                {
                    result.push_back(words[i]);
                    break;
                }
            }
        }
        return result;
    }

private:
    bool isSubstringKMP(const string &needle, const string &haystack)
    {
        int m = needle.size(), n = haystack.size();
        vector<int> lps(m, 0);
        computeLPSArray(needle, m, lps);
        int i = 0, j = 0;
        while (i < n)
        {
            if (needle[j] == haystack[i])
            {
                ++i;
                ++j;
            }
            if (j == m)
                return true;
            else if (i < n && needle[j] != haystack[i])
            {
                if (j != 0)
                    j = lps[j - 1];
                else
                    ++i;
            }
        }
        return false;
    }

    void computeLPSArray(const string &pat, int m, vector<int> &lps)
    {
        int len = 0;
        lps[0] = 0;
        int i = 1;
        while (i < m)
        {
            if (pat[i] == pat[len])
            {
                ++len;
                lps[i] = len;
                ++i;
            }
            else
            {
                if (len != 0)
                    len = lps[len - 1];
                else
                {
                    lps[i] = 0;
                    ++i;
                }
            }
        }
    }
};


int main()
{
    return 0;
}