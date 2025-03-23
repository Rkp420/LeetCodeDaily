#include <iostream>
#include <unordered_set>
using namespace std;

// https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/?envType=daily-question&envId=2025-03-21

class Solution
{
public:
    vector<string> findAllRecipes(vector<string> &recipes, vector<vector<string>> &ingredients, vector<string> &supplies)
    {
        unordered_set<string> supply(supplies.begin(), supplies.end());
        vector<string> ans;
        bool addedNewRecipe = true;

        while (addedNewRecipe)
        {
            addedNewRecipe = false;

            for (int i = 0; i < recipes.size(); i++)
            {
                if (supply.find(recipes[i]) == supply.end())
                {
                    bool canMake = true;

                    for (const string &ingredient : ingredients[i])
                    {
                        if (supply.find(ingredient) == supply.end())
                        {
                            canMake = false;
                            break;
                        }
                    }

                    if (canMake)
                    {
                        ans.push_back(recipes[i]);
                        supply.insert(recipes[i]);
                        addedNewRecipe = true;
                    }
                }
            }
        }

        return ans;
    }
};

int main()
{
    return 0;
}