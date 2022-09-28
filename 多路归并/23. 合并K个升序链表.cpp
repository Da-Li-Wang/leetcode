#include <iostream>
#include <queue>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    struct cmp
    {
        bool operator()(ListNode* a, ListNode* b)
        {
            return a->val > b->val;
        } 
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode * head = new ListNode(0), *cur = head;

        priority_queue<ListNode*, vector<ListNode*>, cmp> que;
        for(auto it : lists)
        {
            que.push(it);
        }

        while(!que.empty())
        {
            auto it = que.top();
            que.pop();
            cur->next = new ListNode(it->val);
            cur = cur->next;
            if(it->next) que.push(it->next);
        }
        return head->next;
    }
};

class Solution {
public:
    /*谓词用法
    struct cmp
    {
        bool operator()(ListNode* a, ListNode* b)
        {
            return a->val > b->val;
        } 
    };
    */
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode * head = new ListNode(0), *cur = head;
        vector<int> temp = {1,3,5};
        sort(temp.begin(), temp.end(), [](int a, int b){return a < b;});
        
        //优先级队列不可以直接使用lamba表达式

        //不可以直接使用priority_queue<ListNode*, vector<ListNode*>, [&](ListNode* a, ListNode* b){return a->val > b->val;}> que;
        
        //正确用法
        auto cmp = [](ListNode* a, ListNode* b){return a->val > b->val;};
        
        priority_queue<ListNode*, vector<ListNode*>,  decltype(cmp)> que(cmp);
        for(auto it : lists)
        {
            if(it)
            {
                que.push(it);
            }
        }

        while(!que.empty())
        {
            auto it = que.top();
            que.pop();
            cur->next = new ListNode(it->val);
            cur = cur->next;
            if(it->next) que.push(it->next);
        }
        return head->next;
    }
};