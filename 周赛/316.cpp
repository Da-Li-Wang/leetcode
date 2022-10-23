class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        int begin1 = ((event1[0][0]-'0')*10 + event1[0][1] - '0')*60 + ((event1[0][3]-'0')*10 + event1[0][4] - '0');
        int end1 = ((event1[1][0]-'0')*10 + event1[1][1] - '0')*60 + ((event1[1][3]-'0')*10 + event1[1][4] - '0');
        
        int begin2 = ((event2[0][0]-'0')*10 + event2[0][1] - '0')*60 + ((event2[0][3]-'0')*10 + event2[0][4] - '0');
        int end2 = ((event2[1][0]-'0')*10 + event2[1][1] - '0')*60 + ((event2[1][3]-'0')*10 + event2[1][4] - '0');

        if((begin2 <= end1 && begin2 >= begin1) || (end2 <= end1 && end2 >= begin1)) return true;
        return false;
    }
};

class Solution {
public:
    int gcd(int m, int n)
    {
	    if (m < n)
	    {
		    int tmp = m;
		    m = n;
		    n = tmp;
	    }
	    if (n == 0)
		    return m;
	    else
		    return gcd(n, m % n);
}
    int subarrayGCD(vector<int>& nums, int tar) {
        int ans = 0, n = nums.size();
        for(int i = 0; i < n; i++)
        {
            int num = nums[i];
            for(int j = i; j < n; j++)
            {
                num = __gcd(num, nums[j]);
                if(num == tar) ans++;
                if(num < tar) break;
            }
        }
        
        return ans;
    }
};

class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        vector<long long> flag;
        for(int i=0;i<cost.size();++i)//用flag数组指示nums从小到大的顺序
            flag.push_back(i);
        sort(flag.begin(),flag.end(),[&](int a,int b){return nums[a]<nums[b];});
        int sum = accumulate(cost.begin(), cost.end(), 0);
        int n = nums.size(),temp = 0, mid = sum / 2, record = 0;
        for(int i = 0; i < n; i++)
        {
            temp += cost[flag[i]];
            if(temp > mid)
            {
                record = flag[i];
                break;
            }
        }
        long long ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(flag[i] == record) continue;
            ans += abs(nums[flag[i]] - nums[record])*(long long)cost[i];
        }
        return ans;      
    }
};


class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        vector<long long> flag;
        for(int i=0;i<cost.size();++i)//用flag数组指示nums从小到大的顺序
            flag.push_back(i);
        sort(flag.begin(),flag.end(),[&](int a,int b){return nums[a]<nums[b];});
        long long sum = accumulate(cost.begin(), cost.end(), 0LL);//会爆int
        long long n = nums.size(),temp = 0, mid = sum / 2, record = 0;
        for(int i = 0; i < n; i++)
        {
            temp += cost[flag[i]];
            if(temp > mid)
            {
                record = flag[i];
                break;
            }
        }
        long long ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(flag[i] == record) continue;
            ans += abs(nums[flag[i]] - nums[record])*(long long)cost[flag[i]];
        }
        return ans;      
    }
};


class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        vector<int> a[2], b[2];
        int k = 2, n = nums.size();
        for(int i = 0; i < n; i++)
        {
            a[nums[i]%k].push_back(nums[i]);
            b[target[i]%k].push_back(target[i]);
        }

        sort(a[0].begin(), a[0].end());
        sort(a[1].begin(), a[1].end());
        sort(b[0].begin(), b[0].end());
        sort(b[1].begin(), b[1].end());

        long long ans = 0;
        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < a[i].size(); j++)
            {
                if(a[i][j] > b[i][j]) ans += (a[i][j] - b[i][j])/2;
            }
        }
        return ans;

    }
};