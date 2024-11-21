#include <iostream>
using namespace std;

// LeatCode 2583 : https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/description/?envType=daily-question&envId=2024-10-22

//** Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    typedef long long ll;
    long long kthLargestLevelSum(TreeNode *root, int k)
    {
        // Creating a min heap to store the k largest sums
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        
        // For level order traversal
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int n = q.size();
            ll levelSum = 0;
            while (n--)
            {
                TreeNode *temp = q.front();
                q.pop();
                levelSum += temp->val;
                if (temp->left != NULL)
                    q.push(temp->left);
                if (temp->right != NULL)
                    q.push(temp->right);
            }

            pq.push(levelSum);

            // Mainting the size of the priority queue
            if (pq.size() > k)
                pq.pop();
        }

        //Finally returning the value
        
        return pq.size() < k ? -1 : pq.top();
    }
};

int main()
{
    return 0;
}