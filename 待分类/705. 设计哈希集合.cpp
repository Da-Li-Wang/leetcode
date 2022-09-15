#include <iostream>
#include <list>
#include <vector>

using namespace std;

class MyHashSet {
private:
vector<list<int>> date;
static const int base = 857;
int hash(int key){
    return key % base;
}
public:
    MyHashSet(): date(base) {
    }
    
    void add(int key) {
        int hashnum = hash(key);
        for (auto it = date[hashnum].begin(); it != date[hashnum].end(); it++)
        {
            if (*it == key)
            {
                return;
            }
            
        }
        date[hashnum].push_back(key);
    }
    
    void remove(int key) {
        int hashnum = hash(key);
        for (auto it = date[hashnum].begin(); it != date[hashnum].end(); it++)
        {
            if (*it == key)
            {
                date[hashnum].erase(it);
                return;
            }
        }
    }
    
    bool contains(int key) {
        int hashnum = hash(key);
        for (auto it = date[hashnum].begin(); it != date[hashnum].end(); it++)
        {
            if (*it == key)
            {
                return true;
            }
        }
        return false;
    }
};