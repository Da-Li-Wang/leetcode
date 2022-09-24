#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {} 
};


class MyLinkedList {
public:
    MyLinkedList() {
        this->Head = new Node(0);
        this->size = 0;
    }
    
    int get(int index) {
        if(index < 0 || index > size) return -1;
        Node* cur = Head;
        for(int i = 0; i <= index; i++)
        {
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(size, val);
    }
    
    void addAtIndex(int index, int val) {
        if(index > size) return;
        index = max(0, index);
        size++;
        Node* pred = Head;
        for (int i = 0; i < index; i++) {
            pred = pred->next;
        }
        Node * toAdd = new Node(val);
        toAdd->next = pred->next;
        pred->next = toAdd;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return;
        }
        size--;
        Node *pred = Head;
        for (int i = 0; i < index; i++) {
            pred = pred->next;
        }
        pred->next = pred->next->next;
    }
    Node* Head;
    int size;
};