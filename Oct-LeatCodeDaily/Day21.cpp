#include <iostream>
#include <unordered_set>

// https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/?envType=daily-question&envId=2024-10-21

using namespace std;
class Solution
{
public:
    void solve(string s, unordered_set<string> st, int i, int currCount,
               int &maxCount)
    {
        // Pruning For UnNescessary Checks
        if (currCount + (s.length() - i) <= maxCount)
            return;
        // Base Case
        if (i >= s.length())
        {
            maxCount = max(currCount, maxCount);
            return;
        }

        for (int j = i; j < s.length(); j++)
        {
            string currSubString = s.substr(i, j - i + 1);
            if (st.find(currSubString) == st.end())
            {
                st.insert(currSubString);
                solve(s, st, j + 1, currCount + 1, maxCount);
                st.erase(currSubString);
            }
        }
    }
    int maxUniqueSplit(string s)
    {
        // it's Store Unique substring
        unordered_set<string> st;

        int maxCount = 0;
        // Starting index
        int i = 0;
        solve(s, st, i, 0, maxCount);

        return maxCount;
    }
};

int main()
{
    return 0;
}