#include <iostream>
using namespace std;

// https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/?envType=daily-question&envId=2025-06-06

class Solution
{
public:
    string robotWithString(string s)
    {
        int n = s.size();
        vector<char> minCharFromRight(n, s[n - 1]);

        for (int i = n - 2; i >= 0; i--)
        {
            minCharFromRight[i] = min(minCharFromRight[i + 1], s[i + 1]);
        }

        stack<char> st;
        string ans;

        for (int i = 0; i < s.size(); i++)
        {
            st.push(s[i]);

            // Keep popping while top is <= the minChar in remaining string
            while (!st.empty() && st.top() <= minCharFromRight[i])
            {
                ans.push_back(st.top());
                st.pop();
            }
        }

        // After processing s, pop the rest of the stack
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};

int main()
{
    return 0;
}