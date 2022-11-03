#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int m = sequence.size(), n = word.size();
        sequence.insert(0, " ");
        word.insert(0, " ");
        vector<int> ne(n+1);

         //求next的过程
        for(int i = 2, j = 0; i <= n; i++)
        {
            while (j && word[i] != word[j+1]) j = ne[j];
            if(word[i] == word[j+1]) j++;
            ne[i] = j;
        }

        vector<int> f(m+1);
        
        //kmp匹配过程
        for(int i = 1, j = 0; i <= m; i++)
        {
            while(j && sequence[i] != word[j+1]) j = ne[j];
            if(sequence[i] == word[j+1]) j++;
            if(j == n)
            {
                f[i] = f[i-n] + 1;
                j = ne[j];
            }
        }

        return *max_element(f.begin(), f.end());
    }
};