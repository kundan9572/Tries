#include <bits/stdc++.h>
using namespace std;

const int Alphabet_Size = 26;

struct TrieNode
{
    struct TrieNode *children[Alphabet_Size];
    bool isEndOfWord;
};

struct TrieNode *getNode(void)
{
    struct TrieNode *pNode = new TrieNode;

    pNode->isEndOfWord = false;

    for (int i = 0; i < Alphabet_Size; i++)
        pNode->children[i] = NULL;

    return pNode;
}

void insert(struct TrieNode *root, string key)
{
    struct TrieNode *node = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';

        if (!node->children[index])
            node->children[index] = getNode();

        node = node->children[index];
    }
    // mark the last node as leaf
    node->isEndOfWord = true;
};

// Return true is key is present in tries
//else false

bool search(struct TrieNode *root, string key)
{
    struct TrieNode *node = root;

    for (int i = 0; i < key.length(); i++)
    {

        int index = key[i] - 'a';
        if (!node->children[index])
        {
            return false;
        }
        node = node->children[index];
    }

    return (node != NULL && node->isEndOfWord);
}

// Driver
int main()
{
    //Input keys (use only 'a' through 'z')
    //and lower case

    string keys[] = {"abc", "abgl", "cdf",
                     "abcd", "lmn"};

    string str;
    cout << "Enter a string to search :\n"
         << endl;
    cin >> str;

    int n = sizeof(keys) / sizeof(keys[0]);

    struct TrieNode *root = getNode();

    //construct tries
    for (int i = 0; i < n; i++)
        insert(root, keys[i]);

    //search for different keys

    search(root, "cdf") ? cout << "Yes\n" : cout << "No\n";
    search(root, "lmn") ? cout << "Yes\n" : cout << "No\n";
    search(root, str) ? cout << "Yes\n" : cout << "No\n";

    return 0;
}