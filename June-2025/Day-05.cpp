#include <iostream>
using namespace std;

// https://leetcode.com/problems/lexicographically-smallest-equivalent-string/?envType=daily-question&envId=2025-06-05

class Solution
{
public:
    char dfs(char curr_ch, unordered_map<char, vector<char>> &adj, vector<bool> &visited)
    {
        visited[curr_ch - 'a'] = true;

        char minChar = curr_ch;
        for (char nbr : adj[curr_ch])
        {
            if (!visited[nbr - 'a'])
            {
                minChar = min(minChar, dfs(nbr, adj, visited));
            }
        }

        return minChar;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr)
    {
        int n = s1.size();

        unordered_map<char, vector<char>> adj;

        for (int i = 0; i < n; i++)
        {
            char u = s1[i], v = s2[i];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        string ans;
        for (int i = 0; i < baseStr.size(); i++)
        {
            vector<bool> visited(26, false);

            char minChar = dfs(baseStr[i], adj, visited);

            ans.push_back(minChar);
        }

        return ans;
    }
};

int main()
{
    return 0;
}