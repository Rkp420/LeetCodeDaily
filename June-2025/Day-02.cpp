#include <iostream>
using namespace std;

// https://leetcode.com/problems/candy/?envType=daily-question&envId=2025-06-02D

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        if (n == 1)
            return 1;
        vector<int> left(n, 1);
        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                left[i] = left[i - 1] + 1;
            }
        }

        int right = 1;
        int sum = left[n - 1];
        for (int j = n - 2; j >= 0; j--)
        {
            if (ratings[j] > ratings[j + 1])
            {
                right++;
                left[j] = max(left[j], right);
            }
            else
            {
                right = 1;
            }
            sum += left[j];
        }

        return sum;
    }
};

int main()
{
    return 0;
}