#include <iostream>
using namespace std;
// Simple Using Recursion
int fib(int n)
{
    if (n <= 1)
        return n;

    return fib(n - 1) + fib(n - 2);
}

// Using Memoisation
class solution1
{
    int solve(int n, vector<int> &dp)
    {
        // Base Case
        if (n <= 1)
            return n;

        // Check if we already calculated
        if (dp[n] != 1)
            return dp[n];

        // Store and return
        return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
    }
    int fib(int n)
    {
        // Base case
        if (n <= 1)
            return 1;

        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};

// Using Bottom Up

class solution2
{
    int fib(int n)
    {
        // Base case
        if (n <= 1)
            return 1;

        vector<int> dp(n + 1, -1);
        // Initialization of Base Cases
        dp[0] = 0;
        dp[1] = 1;

        for(int i = 2; i <= n; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

int main()
{
    // Finally Optimised 
    int n;
    cout << "Enter Your number : ";
    cin >> n;

    if(n <= 1) return n; 

    int prev = 1; 
    int prev_of_prev = 0;
    int curr;
    for(int i  = 2 ; i <= n; i++){
        curr = prev + prev_of_prev;
        prev_of_prev = prev;
        prev = curr;
    }
    cout << "The answer is : " << prev << endl;
    return 0;
}