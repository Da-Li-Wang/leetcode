#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        string out = "";
        set<string> dic;
        dic.emplace(out);
        for (auto word : words)
        {
            if (dic.find(string(word.begin(), word.end()-1)) != dic.end())
            {
                if (word.size() > out.size())
                {
                    out = word;
                }
                dic.insert(word);
            }
        }
        return out;
    }
};

/*
class Trie {
public:
    Trie() {
        this->children = vector<Trie *>(26, nullptr);
        this->isEnd = false;
    }
    
    bool insert(const string & word) {
        Trie * node = this;
        for (const auto & ch : word) {
            int index = ch - 'a';
            if (node->children[index] == nullptr) {
                node->children[index] = new Trie();
            }
            node = node->children[index];
        }
        node->isEnd = true;
        return true;
    }

    bool search(const string & word) {
        Trie * node = this;
        for (const auto & ch : word) {
            int index = ch - 'a';
            if (node->children[index] == nullptr || !node->children[index]->isEnd) {
                return false;
            }
            node = node->children[index];
        }
        return node != nullptr && node->isEnd;
    }
private:
    vector<Trie *> children;
    bool isEnd;
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie trie;
        for (const auto & word : words) {
            trie.insert(word);
        }
        string longest = "";
        for (const auto & word : words) {
            if (trie.search(word)) {
                if (word.size() > longest.size() || (word.size() == longest.size() && word < longest)) {
                    longest = word;
                }
            }
        }
        return longest;
    }
};
*/
//?????????LeetCode-Solution
//?????????https://leetcode-cn.com/problems/longest-word-in-dictionary/solution/ci-dian-zhong-zui-chang-de-dan-ci-by-lee-k5gj/
//??????????????????LeetCode???
//??????????????????????????????????????????????????????????????????????????????????????????????????????





class Solution {
    // Trie + ????????????
    // Trie?????????????????????????????????????????????????????????????????????
public:
    string longestWord(const vector<string> &words) {
        auto root = new Node();
        for (int i = 0; i < words.size(); ++i) {
            insert(root, words[i], i);
        }
        auto res = preOrder(root, 0);
        if (res.second == -1) {
            return "";
        }
        return words[res.second];
    }

private:
    struct Node {
        int idx;
        Node *items[26]{};

        Node() {
            idx = -1;
            for (auto &x: items) {
                x = nullptr;
            }
        }
    };

    void insert(Node *root, const string &w, const int idx) {
        for (const auto &ch: w) {
            auto i = ch - 'a';
            if (!root->items[i]) {
                root->items[i] = new Node();
            }
            root = root->items[i];
        }
        root->idx = idx;
    }

    pair<int, int> preOrder(Node *root, int l) {
        pair<int, int> res(l, root->idx);
        for (const auto kid: root->items) {
            if (!kid || kid->idx == -1) {  // ??????????????????idx == -1?????????
                continue;
            }
            auto t = preOrder(kid, l + 1);
            if (t.first > res.first) {
                res.first = t.first;
                res.second = t.second;
            }
        }
        return res;
    }
};

//?????????????????????????????????
class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        set<string> dic;
        int record = -1;
        for (int i = 0; i < words.size(); i++)
        {
            cout << i<< endl;
            if (record == -1 && words[i].size() == 1)
            {
                record = i;
                dic.emplace(words[i]);
            }
             else if(words[i].size() == 1)
            {
                dic.emplace(words[i]);
            }
            string temp(words[i].substr(0, words[i].size()-1));
            if (record != -1)
            {
                if (dic.count(temp))
                {
                    dic.emplace(words[i]);
                    if(words[i].size() > words[record].size())
                    {
                        record = i;
                    }
                }
                
            }
            //cout << words[record] <<endl;
        }
        if(record == -1) return "";
        return words[record];
    }
};

//??????????????????
class Trie {
public:
    Trie() 
    {
        this->children = vector<Trie *>(26, nullptr);
        this->isEnd = false;
    }

    bool insert(const string & word){
        Trie * node = this;
        for (const auto & ch : word)
        {
            int index = ch - 'a';
            if (!node->children[index])
            {
                node->children[index] = new Trie();
            }
            node = node->children[index];
        }
        node->isEnd = true;
        return true;
    }

    bool search(const string & word)
    {
        Trie * node = this;
        for (const auto & ch : word)
        {
            int index = ch - 'a';
            if (!node->children[index] || !node->children[index]->isEnd)
            {
                return false;
            }
            node = node->children[index];
        }
        return node != nullptr && node->isEnd;
    }
private:
    vector<Trie *> children;
    bool isEnd;
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie trie;
        for (const auto & word : words) {
            trie.insert(word);
        }
        string longest = "";
        for (const auto & word : words) {
            if (trie.search(word)) {
                if (word.size() > longest.size() || (word.size() == longest.size() && word < longest)) {
                    longest = word;
                }
            }
        }
        return longest;
    }
};


