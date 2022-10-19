class Solution {
public:
    int countDigitOne(int n) {
        string copy = to_string(n);
        int ans = 0, high = n / 10, low = 0;
        for(int i = copy.size()-1; i >=0; i--)
        {
            //cout << "------" << endl << copy[i] << endl << high << endl << low << endl << "------" << endl; 
            if(copy[i] == '0') ans += (high * pow(10, copy.size()-1-i));
            else if(copy[i] == '1') ans += (high * pow(10, copy.size()-1-i) + low + 1);
            else ans += ((high + 1) * pow(10, copy.size()-1-i));
            high /= 10;
            low = (copy[i] - '0') * pow(10, copy.size()-1-i) + low;
            //cout << ans << endl;
        }
        return ans;
    }
};