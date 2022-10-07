class Solution {
public:
    const int MOD = 1e9 + 7;
    int beautifulBouquet(vector<int>& flowers, int cnt) {
        int n = flowers.size(), res = 0;
        unordered_map<int, int> mp;
        for (int i = 0, j = 0; j < n; ++j) {
            ++mp[flowers[j]];
            while (i <= j && mp[flowers[j]] > cnt) --mp[flowers[i++]];
            res = (res + j - i + 1) % MOD;
        }
        return res;
    }
};