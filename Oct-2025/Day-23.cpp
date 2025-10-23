#include <iostream>
using namespace std;

// https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-i/?envType=daily-question&envId=2025-10-23

class Solution
{
public:
    bool hasSameDigits(string s)
    {
        while (s.length() > 2)
        {
            string next;
            for (int i = 0; i + 1 < s.length(); ++i)
            {
                int firstDigit = s[i] - '0';
                int secondDigit = s[i + 1] - '0';
                next += char('0' + (firstDigit + secondDigit) % 10);
            }
            s = next;
        }

        return s[0] == s[1];
    }
};

int main()
{
    return 0;
}