// https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/?envType=daily-question&envId=2024-11-22

#include <iostream>
using namespace std;

// Approach : Just observe and Do
class Solution1
{
public:
    int maxEqualRowsAfterFlips(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        int maxRows = 0;

        // Tc = O(m * ( n + (m * n))) ==> O(m * m * n)
        for (auto &currRow : matrix)
        {                            // O(m)
            vector<int> inverted(n); // O(n) --> Space Complexity

            // Creating a inverted Matrix for comparisons
            for (int i = 0; i < n; i++)
            { // O(n)
                inverted[i] = currRow[i] == 0 ? 1 : 0;
            }

            int count = 0;

            // Comparing with Inverted matrix and equal rows
            for (auto &row : matrix)
            { // O(m)
                if (row == currRow || row == inverted)
                    count++; // O(n)
            }

            maxRows = max(maxRows, count);
        }

        return maxRows;
    }
};

// Approach 2 : Using Map and a Pattern of Changing Or Not Changing
class Solution
{
public:
    int maxEqualRowsAfterFlips(vector<vector<int>> &matrix)
    {
        unordered_map<string, int> m; // S.c => O(n)

        int n = matrix[0].size();

        int maxRows = 0;

        // T.c = O(m * n);

        for (auto &currRow : matrix)
        { // O(m)
            string rowKaNature = "";

            int firstChar = currRow[0];
            for (int i = 0; i < n; i++)
            { // O(n)
                rowKaNature += (currRow[i] == firstChar ? "S" : "B");
            }

            m[rowKaNature]++;
        }

        for (auto &it : m)
        {
            maxRows = max(maxRows, it.second);
        }

        return maxRows;
    }
};

int main()
{
    return 0;
}