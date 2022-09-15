#include <iostream>
#include <vector>

using namespace std;

class Trie {
public:
    vector<Trie *> children;
    bool isEnd;
    int val;
    Trie()
    {
        this->children = vector<Trie *>(10, nullptr);
        this->isEnd = false;
    }

    bool insert(const int & num)
    {
        Trie * node = this;
        int temp = num;
        while (temp != 0)
        {
            int tempnum = temp % 10;
            temp = temp / 10;
            if (!node->children[tempnum])
            {
                node->children[tempnum] = new Trie();
            }
            node = node->children[tempnum];
        }
        node->isEnd = true;
        node->val = num;
        return true;
    }

    bool search(const int & num)
    {
        Trie * node = this;
        int temp = num;
        while (temp != 0)
        {
            int tempnum = temp % 10;
            temp = temp / 10;
            if (!node->children[tempnum] || !node->children[tempnum]->isEnd)
            {
                return false;
            }
            node = node->children[tempnum];
        }
        return node != nullptr && node->isEnd;
    }
};

class Solution {
public:
    int findKthNumber(int n, int k) {
        Trie * root = new Trie;
        for(int i = 1; i < n; i++)
        {
            (*root).insert(i);
        }
        return preorder(root, k);
    }
    int out;
    int preorder(Trie* root, int count)
    {
        if (!root)
        {
            return NULL;
        }
        if (count == 1 && root->isEnd == true)
        {
            out = root->val;
            count = -1;
        }
        else if (count > 1 && root->isEnd == true)
        {
            
            count--;

        }
        for (int i = 0; i < root->children.size(); i++)
        {
            preorder(root->children[i], count);
        }
        return out;
    }
};