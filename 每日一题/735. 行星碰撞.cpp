#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//自己写的屎山 不通过
/*
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> book;
        int n = asteroids.size();
        book.push_back(asteroids[0]);
        int top = book.back();

        for (int i = 1; i < n; i++)
        {
            if (book.empty())
            {
                book.push_back(asteroids[i]);
                top = book.back();
                continue;
            }
            
            if (top * asteroids[i] < 0)
            {
                while (top * asteroids[i] < 0)
                {
                    if (abs(top) == abs(asteroids[i]))
                    {
                        book.pop_back();
                        i++;
                        break;
                    }
                    else if (abs(top) < abs(asteroids[i]))
                    {
                        book.pop_back();
                        if (!book.empty())
                        {
                            top = book.back();
                        }
                        else
                        {
                            break;
                        } 
                    }
                    else
                    {
                        break;
                    }
                }         
            }
            else
            {
                book.push_back(asteroids[i]);
                top = book.back();
            }            
        }
        return book;
    }
*/
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        for (auto aster : asteroids) {
            bool alive = true;
            while (alive && aster < 0 && !st.empty() && st.back() > 0) {
                alive = st.back() < -aster; // aster 是否存在
                if (st.back() <= -aster) {  // 栈顶行星爆炸
                    st.pop_back();
                }
            }
            if (alive) {
                st.push_back(aster);
            }
        }
        return st;
    }
};
