#include <iostream>
using namespace std;
class Solution
{
public:
    typedef pair<int, char> P;
    string longestDiverseString(int a, int b, int c)
    {
        // lets assume that repeatLimit is 2
        // Same Problem like Construct a string With repeat Limit
        priority_queue<P, vector<P>> pq;
        if (a > 0)
            pq.push({a, 'a'});
        if (b > 0)
            pq.push({b, 'b'});
        if (c > 0)
            pq.push({c, 'c'});

        string ans = "";

        while (!pq.empty())
        {
            int currChar = pq.top().second;
            int currFreq = pq.top().first;
            pq.pop();
            int len = ans.length();
            // Case 1 : if we can not push this Current Char
            if (len >= 2 && ans[len - 1] == currChar && ans[len - 2] == currChar)
            {
                if (pq.empty())
                    break;
                int fillerChar = pq.top().second;
                int fillerFreq = pq.top().first;
                pq.pop();
                ans.push_back(fillerChar);
                fillerFreq--;
                if (fillerFreq > 0)
                    pq.push({fillerFreq, fillerChar});
            }
            else
            {
                // Case 2 : if we can Push
                ans.push_back(currChar);
                currFreq--;
            }

            if (currFreq > 0)
                pq.push({currFreq, currChar});
        }

        return ans;
    }
};
int main()
{
    return 0;
}