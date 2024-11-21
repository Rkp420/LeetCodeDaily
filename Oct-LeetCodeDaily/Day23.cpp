#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//By Using Two Passes

class Solution1
{
public:
    TreeNode *replaceValueInTree(TreeNode *root)
    {
        if (root == NULL)
            return root;

        queue<TreeNode *> q;
        q.push(root);

        vector<int> levelSum;

        // Step 1 : (find sum at each level and store in levelSum in array)
        while (!q.empty())
        {
            int currLevelSum = 0;
            int n = q.size();

            while (n--)
            {

                TreeNode *curr = q.front();
                q.pop();
                currLevelSum += curr->val;

                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }

            levelSum.push_back(currLevelSum);
        }

        // Step 2 : Updating the value According to their Cousins

        q.push(root);
        root->val = 0;

        int i = 1;
        while (!q.empty())
        {
            int n = q.size();
            while (n--)
            {
                TreeNode *curr = q.front();
                q.pop();

                int siblingSum = curr->left != NULL ? curr->left->val : 0;
                siblingSum += curr->right != NULL ? curr->right->val : 0;

                if (curr->left)
                {
                    curr->left->val = levelSum[i] - siblingSum;
                    q.push(curr->left);
                }
                if (curr->right)
                {
                    curr->right->val = levelSum[i] - siblingSum;
                    q.push(curr->right);
                }
            }
            i++;
        }

        return root;
    }
};

// In one Pass

class Solution2
{
public:
    TreeNode *replaceValueInTree(TreeNode *root)
    {
        if (root == NULL)
            return root;

        queue<TreeNode *> q;
        q.push(root);
        int levelSum = root->val;

        while (!q.empty())
        {
            int n = q.size();
            int nextLevelSum = 0;

            while (n--)
            {
                TreeNode *curr = q.front();
                q.pop();

                curr->val = levelSum - curr->val;

                int siblingSum = curr->left != NULL ? curr->left->val : 0;
                siblingSum += curr->right != NULL ? curr->right->val : 0;

                if (curr->left)
                {
                    nextLevelSum += curr->left->val;
                    curr->left->val = siblingSum;
                    q.push(curr->left);
                }

                if (curr->right)
                {
                    nextLevelSum += curr->right->val;
                    curr->right->val = siblingSum;
                    q.push(curr->right);
                }
            }
            levelSum = nextLevelSum;
        }

        return root;
    }
};

int main()
{
    return 0;
}