#include <iostream>
#include <vector>

using namespace std;

class Bank {
public:
    Bank(vector<long long>& balance) {
        Bankers = vector<long long>(balance.size());
        for (int i = 0; i < balance.size(); i++)
        {
            Bankers[i] = balance[i];
        }
    }
    
    bool transfer(int account1, int account2, long long money) {
        
        if(!isID(account1-1) || !isID(account2-1))
        {
            return false;
        }
        if(Bankers[account1-1] < money)
        {
            return false;
        }
        Bankers[account1-1] -= money;
        Bankers[account2-1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if(!isID(account-1))
        {
            return false;
        }
        Bankers[account-1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(!isID(account-1))
        {
            return false;
        }
        if(Bankers[account-1] < money)
        {
            return false;
        }
        Bankers[account-1] -= money;
        return true;
    }

    bool isID(const int account)
    {
        if (account-1 >= Bankers.size() || account < 0)
        {
            return false;
        }
        return true;
    }
private:
    vector<long long> Bankers;
};
