#include <iostream>
#include <vector>

using namespace std;

class MovingAverage {
public:

    vector<int> box;
    double count = 0;

    MovingAverage(int size) {
        count = size;
    }
    
    double next(int val) {
        
        
        if (box.empty())
        {
            box.push_back(val);
        }
        else
        {
            box.push_back(box.back() + val);
        }
        
        double n = box.size();

        if (n <= count)
        {
            return box.back()/n;
        }

        return (box[n-1] - box[n- count - 1]) / count;
    }
};