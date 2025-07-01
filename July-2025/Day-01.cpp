#include <iostream>
#include <unordered_set>
using namespace std;

// https://leetcode.com/problems/find-the-original-typed-string-i/?envType=daily-question&envId=2025-07-01

class Solution
{
public:
    int possibleStringCount(string word)
    {
        int n = word.size();
        unordered_set<string> possible;
        possible.insert(word); // original word is always one valid version

        for (int i = 0; i < n;)
        {
            int j = i;
            // find the end of the current group of same characters
            while (j < n && word[j] == word[i])
                j++;

            int groupLength = j - i;

            // only if group has more than 1 char, we can shorten it
            if (groupLength > 1)
            {
                for (int len = 1; len < groupLength; ++len)
                {
                    string shorter = word.substr(0, i) + string(len, word[i]) + word.substr(j);
                    possible.insert(shorter);
                }
            }

            i = j;
        }

        return possible.size();
    }
};

int main()
{
    return 0;
}