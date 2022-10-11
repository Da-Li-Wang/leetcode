
//时间复杂度 NL
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int left = 0, right = 10;
        int n = s.size();
        if(n <= 10) return {};
        string temp = s.substr(0, 10);
        unordered_map<string, int> record;
        record[temp]++; 
        while(right < n)
        {
            temp += s[right];
            right++;
            temp.erase(temp.begin());
            record[temp]++;
        }
        
        vector<string> ans;
        for(auto it : record)
        {
            if(it.second > 1) ans.push_back(it.first); 
        }
        return ans;
    }
};


//时间复杂度 N
class Solution {
    const int L = 10;
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        unordered_map<string, int> cnt;
        int n = s.length();
        for (int i = 0; i <= n - L; ++i) {
            string sub = s.substr(i, L);
            if (++cnt[sub] == 2) {
                ans.push_back(sub);
            }
        }
        return ans;
    }
};

