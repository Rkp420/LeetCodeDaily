#include <iostream>
using namespace std;

// https://leetcode.com/problems/count-the-number-of-substrings-with-dominant-ones/?envType=daily-question&envId=2025-11-15

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int zeros = 0;
            int ones = 0;
            for (int j = i; j < n; j++)
            {
                if (s[j] == '0')
                    zeros++;
                else
                    ones++;

                if ((zeros * zeros) <= ones)
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