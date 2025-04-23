#include <iostream>
using namespace std;

// https://leetcode.com/problems/count-largest-group/description/?envType=daily-question&envId=2025-04-23

class Solution
{
public:
    int sumOfDigits(int num)
    {
        int sum = 0;
        while (num > 0)
        {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    int countLargestGroup(int n)
    {
        unordered_map<int, int> digitSumCount;

        for (int i = 1; i <= n; ++i)
        {
            int digitSum = sumOfDigits(i);
            digitSumCount[digitSum]++;
        }

        int maxSize = 0, count = 0;

        for (auto &pair : digitSumCount)
        {
            if (pair.second > maxSize)
            {
                maxSize = pair.second;
                count = 1;
            }
            else if (pair.second == maxSize)
            {
                count++;
            }
        }

        return count;
    }
};

int main()
{
    return 0;
}