#include <iostream>
#include <unordered_map>

using namespace std;

//官解
class Automaton {
    string state = "start";
    unordered_map<string, vector<string>> table = {
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end", "end"}}
    };

    int get_col(char c) {
        if (isspace(c)) return 0;
        if (c == '+' || c == '-') return 1;
        if (isdigit(c)) return 2;
        return 3;
    }
public:
    int sign = 1;
    long long ans = 0;

    void get(char c) {
        state = table[state][get_col(c)];
        if (state == "in_number") {
            ans = ans * 10 + c - '0';
            ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
        }
        else if (state == "signed")
            sign = c == '+' ? 1 : -1;
    }
};

class Solution {
public:
    int strToInt(string str) {
        Automaton automaton;
        for (char c : str)
            automaton.get(c);
        return automaton.sign * automaton.ans;
    }
};





class Solution {
public:
    int strToInt(string str) {
        vector<unordered_map<char,int> >status={
            unordered_map<char,int>{{'b',0},{'s',1},{'n',2},{'o',3}},
            unordered_map<char,int>{{'b',3},{'s',3},{'n',2},{'o',3}},
            unordered_map<char,int>{{'b',3},{'s',3},{'n',2},{'o',3}},
            unordered_map<char,int>{{'b',3},{'s',3},{'n',3},{'o',3}}
        };
        int st=0,sign=1,sum=0;
        char c;
        for(auto x:str){
            if(x==' ') c='b';
            else if(x=='+'||x=='-') c='s';
            else if(x>='0'&&x<='9') c='n';
            else c='o';
            st=status[st][c];
            if(st==3) return sum*sign;
            if(st==1) sign= x=='-'? -1:1;
            if(st==2){
                if(sign == 1 && sum > (INT_MAX - (x - '0')) / 10) return INT_MAX;
                if(sign == -1 && sum < (INT_MIN +  (x - '0')) / 10) return INT_MIN;
                sum*=10;
                sum+=x-'0';
            }
        }
        return sum*sign;
    }
};





class Solution {
public:
    int strToInt(string str) {
        int start = 0;
        int n = str.size();
        while(start < n && str[start] == ' ') start++;
        int sign = 1;
        if(start < n && str[start] == '-' || str[start] == '+'){
            sign = str[start] == '-' ? -1 : 1;
            start++;
        }
        int num = 0;
        while(start < n && isdigit(str[start])){
            if(sign == 1 && num > (INT_MAX - (str[start] - '0')) / 10) return INT_MAX;
            if(sign == -1 && num < (INT_MIN +  (str[start] - '0')) / 10) return INT_MIN;
            num = num * 10 + (str[start] - '0') * sign;
            start++;
        }
        return num;
    }
};
