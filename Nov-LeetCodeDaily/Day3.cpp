
//https://leetcode.com/problems/rotate-string/description/?envType=daily-question&envId=2024-11-03

#include <iostream>
using namespace std;
class Solution
{
public:
    bool rotateString(string s, string goal)
    {

        int n = s.size();
        int m = goal.size();

        // Edge Case
        if (n != m)
            return false;

        for (int i = 0; i < n; i++)
        {
            int k = i, j = 0;
            while (j < m && s[k] == goal[j])
            {
                j++;
                k = (k + 1) % n;
            }

            if (j == m)
                return true;
        }

        return false;
    }
};
int main()
{
    return 0;
}