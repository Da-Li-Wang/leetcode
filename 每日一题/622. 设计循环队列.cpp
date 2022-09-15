#include <iostream>
#include <vector>

using namespace std;

class MyCircularQueue {
private:
    vector<int> Asqueue;
    int begin, end, size; 
public:
    MyCircularQueue(int k) {
        Asqueue = vector<int>(k, -1);
        begin = 0, end = -1, size = k;
    }
    
    bool enQueue(int value) {
        if (size == 0)
        {
            return false;
        }
        
        if ((begin < end && end - begin == size - 1) || (begin > end && end == begin - 1 && end != -1) || (begin == end && size == 1))
        {
            return false; 
        }
        end = (end + 1) % size;
        Asqueue[end] = value;
        return true;
    }
    
    bool deQueue() {
        if ((begin == end && size != 1) || (end == -1))
        {
            return false;
        }
        if (size == 1)
        {
            end = -1;
        }
        else{
            begin = (begin + 1) % size;
        } 
        return true; 
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return Asqueue[begin];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return Asqueue[end];
    }
    
    bool isEmpty() {
        return (begin == end && size != 1) && end == -1;
    }
    
    bool isFull() {
        if ((begin < end && end - begin == size - 1) || (begin > end && end == begin - 1) || (begin == end && size == 1) )
        {
            return true; 
        }
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */


/*
class MyCircularQueue {
private:
    ListNode *head;
    ListNode *tail;
    int capacity;
    int size;

public:
    MyCircularQueue(int k) {
        this->capacity = k;
        this->size = 0;
        this->head = this->tail = nullptr;
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        ListNode *node = new ListNode(value);
        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
        size++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        ListNode *node = head;
        head = head->next;  
        size--;
        delete node;
        return true;
    }

    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return head->val;
    }

    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return tail->val;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};
*/

/*
class MyCircularQueue {
    int k, he, ta;
    int[] nums;
    public MyCircularQueue(int _k) {
        k = _k;
        nums = new int[k];
    }
    public boolean enQueue(int value) {
        if (isFull()) return false;
        nums[ta % k] = value;
        return ++ta >= 0;
    }
    public boolean deQueue() {
        if (isEmpty()) return false;
        return ++he >= 0;
    }
    public int Front() {
        return isEmpty() ? -1 : nums[he % k];
    }
    public int Rear() {
        return isEmpty() ? -1 : nums[(ta - 1) % k];
    }
    public boolean isEmpty() {
        return he == ta;
    }
    public boolean isFull() {
        return ta - he == k;
    }
}
*/
