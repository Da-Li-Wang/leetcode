#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
//#include <utility>

using namespace std;

class MyHashMap 
{
private:
    vector<list<pair<int, int>>> date;
    static const int base = 857;
    int Hashnum(int key)
    {
        return key % base;
    }
public:
    MyHashMap(): date(base) {

    }
    
    void put(int key, int value) {
        int hash = Hashnum(key);
        for (auto &it : date[hash])
        {
            if (it.first == key)
            {
                it.second = value;
                return;
            }
            
        }
        date[hash].push_back(make_pair(key, value));
    }
    
    int get(int key) {
        int hash = Hashnum(key);
        for (auto it : date[hash])
        {
            if (it.first == key)
            {
                return it.second;
            }
        }
        return -1;
    }
    void remove(int key) {
        int h = Hashnum(key);
        for (auto it = date[h].begin(); it != date[h].end(); it++) {
            if ((*it).first == key) {
                date[h].erase(it);
                return;
            }
        }
    }



};


