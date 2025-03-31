
#include <iostream>
using namespace std;

// https://leetcode.com/problems/put-marbles-in-bags/description/?envType=daily-question&envId=2025-03-31

class Solution
{
public:
    long long putMarbles(vector<int> &weights, int k)
    {
        if (k == 1)
            return 0; // Only one group, so max - min = 0

        vector<long long> pairwise;
        int n = weights.size();

        // Compute adjacent pair sums
        for (int i = 0; i < n - 1; i++)
        {
            pairwise.push_back(weights[i] + weights[i + 1]);
        }

        // Sort the adjacent sums
        sort(pairwise.begin(), pairwise.end());

        long long minSum = 0, maxSum = 0;

        // Sum of the smallest (k-1) elements
        for (int i = 0; i < k - 1; i++)
        {
            minSum += pairwise[i];
        }

        // Sum of the largest (k-1) elements
        for (int i = 0; i < k - 1; i++)
        {
            maxSum += pairwise[n - 2 - i];
        }

        return maxSum - minSum;
    }
};

int main()
{
    return 0;
}