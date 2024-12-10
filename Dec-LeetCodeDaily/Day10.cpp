#include <iostream>
using namespace std;

class Solution
{
public:
    int &getMin(int &a, int &b, int &c)
    {
        if (a <= b and a <= c)
            return a;
        if (b <= a and b <= c)
            return b;

        return c;
    }

    int maximumLength(string s)
    {

        // Step 1 : Making an array to Store substrings
        vector<vector<int>> top3Sub(26, vector<int>(3, -1));

        // Step 2 : Start Traversing the String
        char prevChar = '*';
        int lenOfSub = 0;

        for (char currChar : s)
        {
            int idx = currChar - 'a';
            lenOfSub = (currChar == prevChar ? (lenOfSub + 1) : 1);
            prevChar = currChar;

            int &minimum = getMin(top3Sub[idx][0], top3Sub[idx][1], top3Sub[idx][2]);
            if (lenOfSub > minimum)
                minimum = lenOfSub;
        }

        // Step 3 : Finding the Best Answer
        int ans = -1;
        for (auto temp : top3Sub)
        {
            ans = max(ans, min({temp[0], temp[1], temp[2]}));
        }

        return ans;
    }
};

int main()
{
    return 0;
}