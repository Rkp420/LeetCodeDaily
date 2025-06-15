#include <iostream>
using namespace std;

// https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/description/?envType=daily-question&envId=2025-06-15

class Solution
{
public:
    int remap(int num, char fromDigit, char toDigit)
    {
        string s = to_string(num);
        for (char &c : s)
        {
            if (c == fromDigit)
                c = toDigit;
        }
        return stoi(s);
    }

    int maxDiff(int num)
    {
        string s = to_string(num);

        // Maximize: replace first non-'9' digit with '9'
        char maxReplace = ' ';
        for (char c : s)
        {
            if (c != '9')
            {
                maxReplace = c;
                break;
            }
        }
        int maxNum = (maxReplace != ' ') ? remap(num, maxReplace, '9') : num;

        // Minimize
        char minReplace = ' ';
        char target = s[0];
        if (target != '1')
        {
            minReplace = target;
            // replace it with '1' for minimum valid value (no leading zero)
            int minNum = remap(num, minReplace, '1');
            return maxNum - minNum;
        }
        else
        {
            // find first non-zero digit not equal to first digit
            for (int i = 1; i < s.size(); ++i)
            {
                if (s[i] != '0' && s[i] != target)
                {
                    minReplace = s[i];
                    break;
                }
            }
        }
        int minNum = (minReplace != ' ') ? remap(num, minReplace, '0') : num;
        return maxNum - minNum;
    }
};

int main()
{
    return 0;
}