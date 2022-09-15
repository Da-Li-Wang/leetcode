#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Trie {
private:
Trie* children[26];
bool isEnd = false; 
public:
    Trie() {}
    
    void insert(string word) 
    {
        Trie* root = this;
        for (char ch : word)
        {
            ch -= 'a';
            if (root->children[ch] == nullptr)
            {
                root->children[ch] = new Trie();
            }
            root = root->children[ch];
        }
        root->isEnd = true;
    }
    
    bool search(string word) {
        Trie* root = this;
        for (char ch : word)
        {
            ch -= 'a';
            if (root->children[ch] == nullptr)
            {
                return false;
            }
            root = root->children[ch];
        }
        return root->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie* root = this;
        for (char ch : prefix)
        {
            ch -= 'a';
            if (root->children[ch] == nullptr)
            {
                return false;
            }
            root = root->children[ch];
        }
        return true;
        
    
    }
};