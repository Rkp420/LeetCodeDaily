#include <iostream>
using namespace std;

// https://leetcode.com/problems/rotating-the-box/?envType=daily-question&envId=2024-11-23

class Solution
{
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &box)
    {
        int n = box.size(), m = box[0].size();

        // Step 1 : Shifting the Stones Using Two Pointer Approach
        for (int i = 0; i < n; i++)
        {
            int start = m - 1, end = m - 1;
            while (start >= 0 && end >= 0)
            {
                start = min(start, end); // Make Sure Start is always Left side of End

                if (box[i][start] == '*')
                {
                    end = start - 1;
                    start--;
                }
                else if (box[i][start] == '#')
                {
                    if (box[i][end] == '.')
                    {
                        swap(box[i][start], box[i][end]);
                        start--;
                    }
                    end--;
                }
                else
                {
                    start--;
                }
            }
        }

        // Step 2 : Time to Convert Box n * m to m * n;
        vector<vector<char>> ans(m, vector<char>(n, '.'));
        int idx = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j < m; j++)
            {
                ans[j][idx] = box[i][j];
            }
            idx++;
        }

        return ans;
    }
};

// T.C ==> O(n * m)

int main()
{
    return 0;
}