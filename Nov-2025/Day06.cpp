#include <iostream>
#include <map>
#include <set>
using namespace std;

// https://leetcode.com/problems/power-grid-maintenance/?envType=daily-question&envId=2025-11-06

class Solution
{
public:
    void dfs(int id, int node, vector<vector<int>> &adj, vector<int> &vis, map<int, set<int>> &mp, map<int, int> &mpp)
    {
        vis[node] = 1;
        mp[id].insert(node);
        mpp[node] = id;

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs(id, it, adj, vis, mp, mpp);
            }
        }
    }

    vector<int> processQueries(int c, vector<vector<int>> &connections, vector<vector<int>> &queries)
    {
        vector<vector<int>> adj(c + 1);

        for (auto &edge : connections)
        {
            int x = edge[0];
            int y = edge[1];

            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        vector<int> visited(c + 1), online(c + 1, 1);
        int id = 1;

        map<int, set<int>> mp;
        map<int, int> mpp;

        for (int i = 1; i <= c; i++)
        {
            if (!visited[i])
            {
                dfs(id, i, adj, visited, mp, mpp);
                id++;
            }
        }

        vector<int> ans;
        for (auto &q : queries)
        {
            int type = q[0], node = q[1];
            int compId = mpp[node];

            if (type == 2)
            {
                mp[compId].erase(node);
                online[node] = 0;
                continue;
            }

            if (online[node])
            {
                ans.push_back(node);
            }
            else if (mp[compId].size() > 0)
            {
                ans.push_back(*mp[compId].begin());
            }
            else
            {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};

// Second Approach
class Solution
{
public:
    vector<int> parent, size;
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp;

    int findParent(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void Union(int u, int v)
    {
        int up = findParent(u);
        int vp = findParent(v);

        if (up == vp)
            return;

        if (size[up] > size[vp])
        {
            size[up] += size[vp];
            parent[vp] = up;
            while (!mp[vp].empty())
            {
                mp[up].push(mp[vp].top());
                mp[vp].pop();
            }
        }
        else
        {
            size[vp] += size[up];
            parent[up] = vp;
            while (!mp[up].empty())
            {
                mp[vp].push(mp[up].top());
                mp[up].pop();
            }
        }
    }

    vector<int> processQueries(int c, vector<vector<int>> &connections, vector<vector<int>> &queries)
    {
        vector<int> ans;
        parent.resize(c);
        size.resize(c, 1);
        vector<int> offline(c, 0);

        for (int i = 0; i < c; i++)
        {
            parent[i] = i;
            mp[i].push(i);
        }

        for (auto &it : connections)
        {
            int u = it[0] - 1, v = it[1] - 1;
            Union(u, v);
        }

        for (auto &it : queries)
        {
            int type = it[0];
            int node = it[1] - 1;

            if (type == 1)
            {
                if (offline[node] == 0)
                {
                    ans.push_back(node + 1);
                    continue;
                }
                int par = findParent(node);
                while (!mp[par].empty() && offline[mp[par].top()])
                {
                    mp[par].pop();
                }

                if (mp[par].empty())
                    ans.push_back(-1);
                else
                    ans.push_back(mp[par].top() + 1);
            }
            else
            {
                offline[node] = 1;
            }
        }

        return ans;
    }
};

int main()
{
    return 0;
}