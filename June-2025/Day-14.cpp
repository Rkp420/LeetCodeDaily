#include <iostream>
using namespace std;

// https://leetcode.com/problems/maximum-difference-by-remapping-a-digit/description/?envType=daily-question&envId=2025-06-14

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
    int minMaxDifference(int num)
    {
        string s = to_string(num);

        // To acheive Max Value
        // Replace first digit with '9' which is smaller than 9
        char maxReplace = 0;
        for (char c : s)
        {
            if (c != '9')
            {
                maxReplace = c;
                break;
            }
        }
        int maxNum = (maxReplace != 0) ? remap(num, maxReplace, '9') : num;

        // To acheive Min Value
        // Replace first digit with '0' which is greater than 0
        char minReplace = 0;
        for (char c : s)
        {
            if (c != '0')
            {
                minReplace = c;
                break;
            }
        }

        int minNum = (minReplace != 0) ? remap(num, minReplace, '0') : num;

        return maxNum - minNum;
    }
};

int main()
{
    return 0;
}