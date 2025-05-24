#include <iostream>
using namespace std;

// https://leetcode.com/problems/find-words-containing-character/?envType=daily-question&envId=2025-05-24

class Solution
{
public:
    bool isPresent(string &word, char x)
    {
        for (char ch : word)
        {
            if (ch == x)
                return true;
        }

        return false;
    }
    vector<int> findWordsContaining(vector<string> &words, char x)
    {

        vector<int> ans;
        for (int i = 0; i < words.size(); i++)
        {
            if (isPresent(words[i], x))
                ans.push_back(i);
        }

        return ans;
    }
};

int main()
{
    return 0;
}