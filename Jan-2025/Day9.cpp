#include <iostream>
using namespace std;

// BruteForce
class Solution1
{
public:
    int prefixCount(vector<string> &words, string pref)
    {
        int count = 0;
        for (auto &word : words)
        {
            if (word.find(pref) == 0)
                count++;
        }

        return count;
    }
};

// 2nd BruteForce
class Solution2
{
public:
    int prefixCount(vector<string> &words, string pref)
    {
        int count = 0;
        int prefLength = pref.size();

        for (auto &word : words)
        {
            // Check if the prefix length is less than or equal to the word length
            if (word.size() >= prefLength && word.substr(0, prefLength) == pref)
            {
                count++;
            }
        }

        return count;
    }
};

// Optimised Using Trie

class TrieNode
{
public:
    unordered_map<char, TrieNode *> children;
    int count; // Number of words passing through this node

    TrieNode() : count(0) {}
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    // Insert a word into the Trie
    void insert(const string &word)
    {
        TrieNode *node = root;
        for (char ch : word)
        {
            if (!node->children[ch])
            {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
            node->count++; // Increment count for each node in the path
        }
    }

    // Count words with the given prefix
    int countWordsWithPrefix(const string &prefix)
    {
        TrieNode *node = root;
        for (char ch : prefix)
        {
            if (!node->children[ch])
            {
                return 0; // Prefix not found
            }
            node = node->children[ch];
        }
        return node->count; // Return count of words with this prefix
    }
};

class Solution3
{
public:
    int prefixCount(vector<string> &words, string pref)
    {
        Trie trie;

        // Build the Trie with all words
        for (const string &word : words)
        {
            trie.insert(word);
        }

        // Count words with the given prefix
        return trie.countWordsWithPrefix(pref);
    }
};

int main()
{
    return 0;
}