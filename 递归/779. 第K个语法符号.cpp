#include <iostream>

using namespace std;

class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n == 1) return 0;
        int father = kthGrammar(n-1, (k+1)>>1);
        return k & 1 == 1 ? father : 1 ^ father; 

    }
};