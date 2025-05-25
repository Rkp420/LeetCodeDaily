#include <iostream>
using namespace std;

// https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/submissions/1643695418/?envType=daily-question&envId=2025-05-25

class Solution
{
public:
    int longestPalindrome(vector<string> &words)
    {

        // Store the Freq
        unordered_map<string, int> mp;
        for (string &word : words)
            mp[word]++;

        bool centerUsed = false;
        int result = 0;

        for (string &word : words)
        {
            string rev = word;
            reverse(rev.begin(), rev.end());

            if (rev != word)
            {
                if (mp[word] > 0 && mp[rev] > 0)
                {
                    mp[word]--;
                    mp[rev]--;
                    result += 4;
                }
            }
            else
            {
                if (mp[word] >= 2)
                {
                    mp[word] -= 2;
                    result += 4;
                }
                else if (mp[word] == 1 && !centerUsed)
                {
                    mp[word]--;
                    result += 2;
                    centerUsed = true;
                }
            }
        }

        return result;
    }
};

int main()
{
    return 0;
}