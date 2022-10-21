//  数学
//           数字范围   位数   数字数量   数位数量
//            1 - 9      1        9          9
//           10 - 99     2        90         180
//          100 - 999    3        900        2700
//             ...      ...       ...        ...
//        start - end   digit    9*start   9*start*dight

class Solution {
public:
    int findNthDigit(int n) {
        int digit = 1;    // 数位
        long start = 1;   // 当前数字范围的左区间
        long count = 9;   // 数位数量

        // 定位目标数字所在数字范围
        while (n > count) {
            n -= count;       // 减去上一个数字范围的总数位数量
            digit += 1;       // "当前数字范围的"数位
            start *= 10;      // "当前数字范围的"左区间
            count = 9 * start * digit;   // "当前数字范围的"总数位数量
        }
        int num = (start - 1) + n / digit;   // 注："start-1"表示上一个数字范围的右区间
        int y = n % digit;                   
        // 如果"余数y"不为0，说明目标数字为 num+1
        if (y) {    
            num += 1;
            string s = std::to_string(num);  
            return s[y - 1] - '0';
        }
        //否则，第n位数即"数字num的个位"
        return num % 10;
    }
};