#include <iostream>
using namespace std;

// https://leetcode.com/problems/minimum-time-to-make-rope-colorful/?envType=daily-question&envId=2025-11-03

class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int totalTime = 0;

        for (int i = 1; i < colors.size(); i++)
        {
            if (colors[i] == colors[i - 1])
            {
                totalTime += min(neededTime[i], neededTime[i - 1]);
                neededTime[i] = max(neededTime[i], neededTime[i - 1]);
            }
        }

        return totalTime;
    }
};

int main()
{
    return 0;
}