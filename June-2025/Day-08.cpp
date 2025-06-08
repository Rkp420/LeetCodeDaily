#include <iostream>
using namespace std;

// https://leetcode.com/problems/lexicographical-numbers/description/?envType=daily-question&envId=2025-06-08

class Solution
{
public:
    void generateAllNum(int i, vector<int> &res, int n)
    {
        if (i > n)
            return;
        if (i != 0)
            res.push_back(i);

        for (int j = (i == 0 ? 1 : 0); j <= 9; j++)
            generateAllNum(i * 10 + j, res, n);
    }

    vector<int> lexicalOrder(int n)
    {
        vector<int> res;

        generateAllNum(0, res, n);

        return res;
    }
};

int main()
{
    return 0;
}