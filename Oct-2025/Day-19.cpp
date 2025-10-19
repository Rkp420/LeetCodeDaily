// https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/description/?envType=daily-question&envId=2025-10-19

#include <iostream>
#include <set>
using namespace std;

// Dfs
class Solution
{
public:
    set<string> st;
    string ans;
    string addOperation(string s, int a)
    {
        for (int i = 1; i < s.size(); i += 2)
        {
            int digit = (s[i] - '0' + a) % 10;
            s[i] = '0' + digit;
        }
        return s;
    }

    string rotateOperation(string s, int b)
    {
        int n = s.size();
        return s.substr(n - b) + s.substr(0, n - b);
    }

    void dfs(string s, int a, int b)
    {
        if (st.find(s) != st.end())
            return;
        st.insert(s);
        ans = min(ans, s);
        dfs(addOperation(s, a), a, b);
        dfs(rotateOperation(s, b), a, b);
    }

    string findLexSmallestString(string s, int a, int b)
    {
        ans = s;
        dfs(s, a, b);
        return ans;
    }
};

// Bfs
class Solution
{
public:
    set<string> st;
    string addOperation(string s, int a)
    {
        for (int i = 1; i < s.size(); i += 2)
        {
            int digit = (s[i] - '0' + a) % 10;
            s[i] = '0' + digit;
        }
        return s;
    }

    string rotateOperation(string s, int b)
    {
        int n = s.size();
        return s.substr(n - b) + s.substr(0, n - b);
    }

    string findLexSmallestString(string s, int a, int b)
    {
        string ans = s;
        queue<string> q;
        st.insert(s);
        q.push(s);

        while (!q.empty())
        {

            string temp = q.front();
            q.pop();
            ans = min(ans, temp);

            string temp1 = addOperation(temp, a);
            if (st.find(temp1) == st.end())
            {
                q.push(temp1);
                st.insert(temp1);
            }
            string temp2 = rotateOperation(temp, b);
            if (st.find(temp2) == st.end())
            {
                q.push(temp2);
                st.insert(temp2);
            }
        }

        return ans;
    }
};

int main()
{
    return 0;
}