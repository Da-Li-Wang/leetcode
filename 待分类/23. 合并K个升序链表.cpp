#include <iostream>
#include <vector>
#include <algorithm>
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
        {
            return nullptr;
        }
        
        vector<int> stupid;
        for (auto link : lists)
        {
            ListNode* cur = link;
            while (cur)
            {
                stupid.push_back(cur->val);
                cur = cur->next;
            }
        }
        if (stupid.size() == 0)
        {
            return nullptr;
        }
        sort(stupid.begin(), stupid.end());
        ListNode* head = new ListNode(stupid[0]);
        ListNode * curr = head;
        for (int i = 1; i < stupid.size(); i++)
        {
            curr->next = new ListNode(stupid[i]);
            curr = curr->next;
        }
        return head;
         
    }
};


class Solution {
public:
    struct Status {
        int val;
        ListNode *ptr;
        bool operator < (const Status &rhs) const {
            return val > rhs.val;
        }
    };

    priority_queue <Status> q;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (auto node: lists) {
            if (node) q.push({node->val, node});
        }
        ListNode head, *tail = &head;
        while (!q.empty()) {
            auto f = q.top(); q.pop();
            tail->next = f.ptr; 
            tail = tail->next;
            if (f.ptr->next) q.push({f.ptr->next->val, f.ptr->next});
        }
        return head.next;
    }
};

class Solution {
public:
    // 重载小根堆的回调函数
    struct cmp {
        bool operator()(ListNode *a, ListNode *b) {
            return a->val > b->val;
        }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0) return NULL;

        // 小根堆，元素为指针，最长长度为 k
        priority_queue<ListNode *, vector<ListNode *>, cmp> smallQ;
        for (ListNode *x : lists) {
            // 仅每个子链表的头 入堆
            if (x) smallQ.push(x);
        }

        ListNode *hair = new ListNode(0);
        ListNode *cur = hair;
        while (!smallQ.empty()) {
            ListNode *t = smallQ.top();
            smallQ.pop();
            cur->next = t;

            if (t->next) smallQ.push(t->next);
            cur = cur->next;
        }
        return hair->next;
    }
};

