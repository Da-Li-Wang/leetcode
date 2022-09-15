#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    vector<string> res;
    vector<int> mins;

    void dfs(int st, int sum, int cnt, bool flag) {
        if (cnt == 0) {
            if (flag) {
                mins.push_back(sum);
            } else {
                if (!mins.empty()) {
                    for (int m : mins) {
                        char time[6];
                        sprintf(time, "%d:%02d", sum, m);
                        res.emplace_back(string{ time });
                        // res.push_back(time);
                    }
                }
            }
            return;
        }

        for (int i = st; i < flag ? 6 : 4; i++) {
            int temp = pow(2, i);
            if (flag && sum + temp >= 60 || !flag && sum + temp >= 12) {
                break;
            }
            dfs(i + 1, sum + temp, cnt - 1, flag);
        }
    }
public:
    vector<string> readBinaryWatch(int num) {
        for (int i = 0; i < 6 && num >= i; i++) {
            dfs(0, 0, i, true);
            dfs(0, 0, num - i, false);
            mins.clear();
        }

        return res;
    }
};

