#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool oneEditAway(string first, string second) {
        int n1 = first.size(), n2 = second.size();
        int diff = abs(n1 - n2);
        if (first == second)
        {
            return true;
        }
        
        if (diff < 2)
        {
            if (diff == 1)
            {
                int i = 0, j = 0; 
                if (n1 > n2)
                {
                    while (i < n1 && j < n2)
                    {
                        if (first[i] == second[j])
                        {
                            j++;
                        }
                            i++;
                        if (i - j > 1)
                        {
                            return false;
                        }
                    }
                    return true;
                }
                else
                {
                    while (i < n1 && j < n2)
                    {
                        if (first[i] == second[j])
                        {
                            i++;
                        }
                            j++;
                        if (j - i > 1)
                        {
                            return false;
                        }
                    }
                    return true;
                }
                
            }
            else
            {
                int count = 0; 
                for (int i = 0; i < n1; i++)
                {
                    if (first[i] != second[i])
                    {
                        count++;
                    }
                    
                }
                return count < 2;
            }
            
        }
        return false;
    }


};

