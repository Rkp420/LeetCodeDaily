#include <iostream>
using namespace std;

// https://leetcode.com/problems/count-and-say/?envType=daily-question&envId=2025-04-18

class Solution
{
public:
    string solve(int n)
    {
        if (n == 1)
            return "1";

        string temp = solve(n - 1);

        string ans = "";
        int i = temp.size() - 1;
        while (i >= 0)
        {
            ans = temp[i] + ans;
            int count = 1;
            while (i > 0 && temp[i] == temp[i - 1])
            {
                count++;
                i--;
            }
            ans = to_string(count) + ans;
            i--;
        }

        return ans;
    }
    string countAndSay(int n)
    {
        return solve(n);
    }
};

int main()
{
    return 0;
}