#include <iostream>
using namespace std;

// https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/?envType=daily-question&envId=2025-01-06

// Bruteforce
class Solution
{
public:
    vector<int> minOperations(string boxes)
    {
        int n = boxes.length();
        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (boxes[j] == '1')
                    ans[i] += abs(i - j);
            }
        }

        return ans;
    }
};

// Optimised
class Solution2
{
public:
    vector<int> minOperations(string boxes)
    {
        int n = boxes.length();
        vector<int> result(n, 0);

        // Left-to-right pass: Calculate moves from the left side
        int balls = 0, moves = 0;
        for (int i = 0; i < n; ++i)
        {
            result[i] += moves;
            if (boxes[i] == '1')
                ++balls;
            moves += balls;
        }

        // Right-to-left pass: Calculate moves from the right side
        balls = 0;
        moves = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            result[i] += moves;
            if (boxes[i] == '1')
                ++balls;
            moves += balls;
        }

        return result;
    }
};

int main()
{
    return 0;
}