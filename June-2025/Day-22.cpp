#include <iostream>
using namespace std;

// https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/?envType=daily-question&envId=2025-06-22

class Solution
{
public:
    vector<string> divideString(string s, int k, char fill)
    {
        vector<string> res;
        int i = 0;

        while (i < s.size())
        {
            string temp = "";
            int count = 0;

            // Collect k characters or until end of string
            while (count < k && i < s.size())
            {
                temp.push_back(s[i]);
                count++;
                i++;
            }

            // If the last group is smaller than k, fill it
            while (temp.size() < k)
            {
                temp.push_back(fill);
            }

            res.push_back(temp);
        }

        return res;
    }
};

int main()
{
    return 0;
}