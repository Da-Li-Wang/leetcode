//贪心
class Solution {
public:
    int cuttingRope(int n) {
        int ans = 0;
        for(int i = 2; i <= n; i++)
        {
            int add = n % i, count = n / i, maxnum = 1;
            for(int j = 1; j <= i; j++)
            {
                int copycount = count;
                if(add)
                {
                    add--;
                    copycount++;
                }
                //cout << copycount << endl;
                maxnum *= copycount;
            }
            ans = max(ans, maxnum);
        }
        return ans;
    }
};
//数学
class Solution {
public:
    int cuttingRope(int n) {
        if (n <= 3) {
            return n - 1;
        }
        int quotient = n / 3;
        int remainder = n % 3;
        if (remainder == 0) {
            return (int)pow(3, quotient);
        } else if (remainder == 1) {
            return (int)pow(3, quotient - 1) * 4;
        } else {
            return (int)pow(3, quotient) * 2;
        }
    }
};
