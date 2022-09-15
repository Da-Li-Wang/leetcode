#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        map<string, int> box;
        for (auto item : banned)
        {
            box.emplace(item, -1);
        }
        
        string ans;
        int max = 0;

        for (int i = 0; i < paragraph.length(); i++)
        {
            string temp;
            while (isalpha(paragraph[i]))
            {
                temp += tolower(paragraph[i]);
                i++;
            }
            
            
            if (!temp.empty())
            {
            
                if (!box.count(temp))
                {
                    cout << temp << endl;
                    box.emplace(temp, 1);
                }
                else if (box.count(temp) && box[temp] != -1)
                {
                    box[temp]++;
                }

                if (box[temp] > max)
                {
                    max = box[temp];
                    ans = temp;
                }               
            }            
        }

        return ans;
        
    }
};