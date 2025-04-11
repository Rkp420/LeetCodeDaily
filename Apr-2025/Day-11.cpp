#include <iostream>
using namespace std;

// https://leetcode.com/problems/count-symmetric-integers/description/?envType=daily-question&envId=2025-04-11

class Solution
{
public:
    bool isSymmetric(int num)
    {
        int digits = floor(log10(num)) + 1;

        if (digits % 2)
            return false;
        int n = digits / 2;

        int temp = num;
        int sum = 0;
        while (temp)
        {
            int currDigit = temp % 10;
            if (digits > n)
                sum += currDigit;
            else
                sum -= currDigit;
            digits--;
            temp /= 10;
        }

        return sum == 0;
    }
    int countSymmetricIntegers(int low, int high)
    {
        int count = 0;
        for (int i = low; i <= high; i++)
        {
            if (isSymmetric(i))
                count++;
        }

        return count;
    }
};
int main()
{
    return 0;
}