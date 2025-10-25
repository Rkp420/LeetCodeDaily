#include <iostream>
using namespace std;

// https://leetcode.com/problems/calculate-money-in-leetcode-bank/?envType=daily-question&envId=2025-10-25

class Solution
{
public:
    int totalMoney(int n)
    {
        int onMonday = 1;
        int total = 0;
        int count = 0;

        int prev = onMonday;
        for (int i = 1; i <= n; i++)
        {
            total += prev;
            prev += 1;
            count++;

            if (count == 7)
            {
                onMonday += 1;
                count = 0;
                prev = onMonday;
            }
        }

        return total;
    }
};

int main()
{
    return 0;
}