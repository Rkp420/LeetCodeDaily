#include <iostream>
using namespace std;

// https://leetcode.com/problems/number-of-laser-beams-in-a-bank/?envType=daily-question&envId=2025-10-27

class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {
        int ans = 0;
        int prev = 0;

        for (string &s : bank)
        {
            int currSD = 0;
            for (char ch : s)
            {
                if (ch == '1')
                    currSD++;
            }

            if (currSD == 0)
                continue;
            ans += (prev * currSD);
            prev = currSD;
        }

        return ans;
    }
};

int main()
{
    return 0;
}