#include <iostream>
using namespace std;
class Solution
{
public:
    long long minimumSteps(string s)
    {
        long long ans = 0;
        long long noOfOnes = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '1')
                noOfOnes++;
            else
            {
                ans += noOfOnes;
            }
        }
        return ans;
    }
};
int main()
{
    return 0;
}