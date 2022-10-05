#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

//if-else 判断

class Solution {
public:
    bool isNumber(string s) {
        if(s.size() == 0) return false;

        //跳过首尾空格
        int left = 0, right = s.length() - 1;
        while(left <= right && s[left] == ' '){
            left++;
        }
        if(left > right) return false;
        while(left < right && s[right] == ' '){
            right--;
        }

        bool isNum = false;
        bool isDot = false;
        bool isEe = false;
        bool isSign = false;

        for(int i = left; i <= right; i++){
            if(s[i] >= '0' && s[i] <= '9'){
                isNum = true;
            }
            // 一个'.'；e/E后面跟一个整数（不能有'.'）
            else if(s[i] == '.' && !isDot && !isEe){
                isDot = true;
            }
            // 一个'E'或'e'；前面需要出现过数字
            else if((s[i] == 'E' || s[i] == 'e') && isNum && !isEe){
                isEe = true;
                //// 避免e结尾的情况 e后面得跟一个整数
                isNum = false;
            }
            // '+''-'只能出现在开头或者'E'或'e'的后一位
            else if((s[i] == '+' || s[i] == '-') && (i == left || s[i - 1] == 'E' || s[i - 1] == 'e')){
                isSign = true;
            }
            else{
                return false;
            }
        }
        // 必须以数字结尾
        return isNum;
    }
};

// 状态机判断
class Solution {
public:
    
    typedef pair<char, int> charint;
    typedef unordered_map<char, int> unmap;

    bool isNumber(string s) {
        vector<unmap> states = {
            unmap{charint(' ', 0), charint('s', 1), charint('d', 2), charint('.', 4)},
            unmap{charint('d', 2), charint('.', 4)},
            unmap{charint('d', 2), charint('.', 3), charint('e', 5), charint(' ', 8)},
            unmap{charint('d', 3), charint('e', 5), charint(' ', 8)},
            unmap{charint('d',3)},
            unmap{charint('s',6),charint('d',7)},
            unmap{charint('d',7)},
            unmap{charint('d',7),charint(' ',8)},
            unmap{charint(' ',8)}
        };
        int p = 0;
        char t;
        for(char c:s){
            if(c >= '0' && c <= '9')
                t = 'd';
            else if(c == '+' || c == '-')
                t = 's';
            else if(c == 'e' || c == 'E')
                t = 'e';
            else if(c == '.' || c == ' ')
                t = c;
            else
                t = '?';
            if(!states[p].count(t))
                return false;
            p = (int) states[p][t];
        }
        return p == 2 || p == 3 || p == 7 || p == 8;
    }
};