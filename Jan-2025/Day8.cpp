#include <iostream>
using namespace std;

// https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/description/?envType=daily-question&envId=2025-01-08

class Solution
{
public:
    bool isPrefix(string &s1, string &s2)
    {
        int n = s1.length();
        int m = s2.length();

        if (m < n)
            return false;

        for (int i = 0; i < n; i++)
        {
            if (s1[i] != s2[i])
                return false;
        }

        return true;
    }

    bool isSuffix(string &s1, string &s2)
    {
        int n = s1.length();
        int m = s2.length();

        // It will be SuperFluous if We Check For m < n Because We Already did
        // this during isPrefix

        for (int i = 0; i < n; i++)
        {
            if (s1[i] != s2[m - (n - i)])
                return false;
        }

        return true;
    }

    int countPrefixSuffixPairs(vector<string> &words)
    {
        int n = words.size();
        int count = 0;

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (isPrefix(words[j], words[i]) &&
                    isSuffix(words[j], words[i]))
                    count++;
            }
        }

        return count;
    }
};

int main()
{
    return 0;
}