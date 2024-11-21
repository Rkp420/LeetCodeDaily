#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    char solveExpression(vector<char> &temp, char op)
    {
        if (op == '!')
            return temp[0] == 't' ? 'f' : 't';
        else if (op == '&')
        {
            return any_of(temp.begin(), temp.end(), [](char a)
                          { return a == 'f'; })
                       ? 'f'
                       : 't';
        }
        else
        {
            return any_of(temp.begin(), temp.end(), [](char a)
                          { return a == 't'; })
                       ? 't'
                       : 'f';
        }
        return 't'; // This case never hit
    }
    bool parseBoolExpr(string expression)
    {
        stack<char> s;
        int n = expression.length();
        for (int i = 0; i < n; i++)
        {
            if (expression[i] == ',')
                continue;
            else if (expression[i] == ')')
            {
                vector<char> temp;
                while (!s.empty() && s.top() != '(')
                {
                    temp.push_back(s.top());
                    s.pop();
                }
                s.pop();
                char op = s.top();
                s.pop();
                s.push(solveExpression(temp, op));
            }
            else
            {
                s.push(expression[i]);
            }
        }
        return s.top() == 't' ? true : false;
    }
};
int main()
{
    return 0;
}