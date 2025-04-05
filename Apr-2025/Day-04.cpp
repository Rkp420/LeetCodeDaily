#include <iostream>
using namespace std;

// https : // leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/description/?envType=daily-question&envId=2025-04-04

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
    pair<int, TreeNode *> solve(TreeNode *root)
    {
        if (root == NULL)
        {
            return {0, NULL};
        }

        auto l = solve(root->left);
        auto r = solve(root->right);

        if (l.first == r.first)
        {
            return {l.first + 1, root};
        }
        else if (l.first > r.first)
        {
            return {l.first + 1, l.second};
        }
        else
        {
            return {r.first + 1, r.second};
        }
    }

    TreeNode *lcaDeepestLeaves(TreeNode *root)
    {
        return solve(root).second;
    }
};

int main()
{
    return 0;
}