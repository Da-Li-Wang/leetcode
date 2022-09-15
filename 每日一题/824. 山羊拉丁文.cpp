#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string toGoatLatin(string sentence) {
        vector<string> ans;
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        string temp;
        for (auto it : sentence)
        {
            if (isalpha(it))
            {
                temp += it;
            }
            else if (it == ' ')
            {
                ans.push_back(temp);
                temp = "";
            }
        }
        if (!temp.empty())
        {
            ans.push_back(temp);
        }

        for (int i = 0; i < ans.size(); i++)
        {
            if (vowels.count(ans[i][0]))
            {
                
            }
            
        }
        
        
    }
};

class Solution {
public:
    string toGoatLatin(string sentence) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        int n = sentence.size();
        int i = 0, cnt = 1;
        string ans;

        while (i < n) {
            int j = i;
            while (j < n && sentence[j] != ' ') {
                ++j;
            }

            ++cnt;
            if (cnt != 2) {
                ans += ' ';
            }
            if (vowels.count(sentence[i])) {
                ans += sentence.substr(i, j - i) + 'm' + string(cnt, 'a');
            }
            else {
                ans += sentence.substr(i + 1, j - i - 1) + sentence[i] + 'm' + string(cnt, 'a');
            }

            i = j + 1;
        }

        return ans;
    }
};

