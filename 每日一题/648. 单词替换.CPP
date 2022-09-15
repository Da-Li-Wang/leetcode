#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:
    bool isSub(const string& word, const string& str){
        int n = str.size();
        for (int i = 0; i < n; i++)
        {
            if (word[i] != str[i]) break;

            if (i == n - 1) return true;
            
        }
        return false;
    }

    static bool less_int(string a,string b){

        return a.size()<b.size();

    }
    
    string replaceWords(vector<string>& dictionary, string sentence) {
        sort(dictionary.begin(), dictionary.end(), less_int);
        string res, word;
        stringstream input(sentence);
        while (input >> word)
        {
            for (auto str : dictionary)
            {
                if (isSub(word, str))
                {
                    word = str;
                }
                res += word;
                res += " ";
            }
            res.pop_back();
            return res;
        }
    }
};


/*
class Solution {
    bool isSub (const string& word, const string& str) {
        int n = str.size();
        for (int i = 0; i < n; ++i) {
            if (word[i] != str[i]) break;
            if (i == n - 1) return true;
        }
        return false;
    }

public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        // 单词按长度从大到小排列
        sort(dictionary.begin(), dictionary.end(), [](string& a, string& b) {return a.size() < b.size();});
        // 分割sentence（基于字节流）
        // input 可以使用 getline(input, word, 'c') 以字符 c 分割为 word
        string res, word;
        stringstream input(sentence);
        while(input >> word)
        {
            for (const string& str : dictionary) {
                if (isSub(word, str)) word = str;
            }
            res += word;
            res += " ";
        }
        res.pop_back();
        return res;
    }
};
*/