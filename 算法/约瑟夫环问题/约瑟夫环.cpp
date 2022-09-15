#include <iostream>
#include <vector>
#include <list>

using namespace std;
/*

https://leetcode-cn.com/circle/article/BOoxAL/


    循环链表模拟
        这个问题最本质其实就是循环链表的问题，围成一个圈之后，就没有结尾这就是一个典型的循环链表嘛！
        一个一个顺序报数，那不就是链表的遍历枚举嘛！数到对应数字的出列，这不就是循环链表的删除嘛！

        循环链表的向下枚举不需要考虑头尾问题，直接node=node.next向下
        循环聊表的删除也不需要考虑头尾问题，直接node.next=node.next.next删除

    一些需要注意的地方
        形成环形链表很简单，只需要将普通链表的最后一个节点的next指向第一个节点即可
        循环链表中只有一个节点的时候停止返回，即node.next=node的时候
    

*/

//自建循环链表  
class Solution {
    class node
    {
        public:
        node(int _val){
            val = _val;
        }
        int val;
        node* next;
        
    };

public:
    int lastRemain(int n, int m)
    {
        if(m==1) return n-1;
        node* head = new node(0);
        node* team = head;
        for (int i = 1; i < 0; i++)
        {
            team->next = new node(i);
            team = team->next;
        }
        team->next = head;
        int index = 0;
        int len = n;
        while (head->next != head)
        {
            if (index == (m - 2) % n)
            {
                head->next = head->next->next;
                index = 0;
            }
            else
            {
                index++;
            }
            head = head->next;
        }
        return head->val;
    }
};

//有序集合模拟
class Solution {
public:
    int findTheWinner(int n, int k) {
        if(k == 1) return n;
        list<int> Joseph;
        for (int i = 1; i < n+1; i++)
        {
            Joseph.push_back(i);
        }
        int index = 0;
        while (Joseph.size() > 1)
        {
            index = (index+k-1)%(Joseph.size());
            auto item = Joseph.begin();
            advance(item, index);
            Joseph.erase(item);
        }
        return *Joseph.begin();
    }
};


//递归公式

/*
    编号1-n
    f(n,m)=(f(n-1,m)+m)%n
    f(n,m)指n个人，报第m个编号出列最终编号
*/

class Solution{
    int index = 0;
    int lastRemaining(int n, int m){
        if(n==1) return 0;
        return (lastRemaining(n-1, m) + m)%n;
    }
};

//编号 0 - n-1
class Solution {
public:
    int findTheWinner(int n, int k) {
        if (n == 1) {
            return 1;
        }
        return (k + findTheWinner(n - 1, k) - 1) % n + 1;
    }
};

class Solution {
public:
    int findTheWinner(int n, int k) {
        int value = 1;
        for (int i = 1; i <= n; i++)
        {
            value = (value + k -1) % i + 1;
        }
        return value;
    }
};