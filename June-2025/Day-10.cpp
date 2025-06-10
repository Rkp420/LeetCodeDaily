#include <iostream>
using namespace std;

// https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i/?envType=daily-question&envId=2025-06-10

class Solution
{
public:
    int maxDifference(string s)
    {
        vector<int> freq(26, 0);

        for (char &ch : s)
        {
            freq[ch - 'a']++;
        }

        int ans = 0;
        int maxOdd = INT_MIN;
        int minEven = INT_MAX;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] == 0)
                continue;

            if (freq[i] % 2 == 0)
                minEven = min(minEven, freq[i]);
            else if (freq[i] % 2)
                maxOdd = max(maxOdd, freq[i]);
        }

        return maxOdd - minEven;
    }
};

int main()
{
    return 0;
}