#include<iostream>
#include<mutex>
#include<bits/stdc++.h>

class LRUCache {
public:
    class Node{
        public: 
            int key;
            int val;
            Node* prev;
            Node* next;

            Node(int key, int val){
                this->key = key;
                this->val = val;
            }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    int cap;
    std::unordered_map<int, Node*> m;

    LRUCache(int capacity) {
        cap = capacity;
        head -> next = tail;
        tail -> prev = head;
    }

    void addNode(Node* newnode){
        Node* temp = head -> next;

        newnode -> next = temp;
        newnode -> prev = head;

        head -> next = newnode;
        temp -> prev = newnode;
    }

    void deleteNode(Node* delnode){
        Node* prevv = delnode -> prev;
        Node* nextt = delnode -> next;

        prevv -> next = nextt;
        nextt -> prev = prevv;
    }
    
    int get(int key) {
        if(m.find(key) != m.end()){
            Node* resNode = m[key];
            int ans = resNode -> val;

            m.erase(key);
            deleteNode(resNode);
            addNode(resNode);

            m[key] = head -> next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            Node* curr = m[key];
            m.erase(key);
            deleteNode(curr);
        }

        if(m.size() == cap){
            m.erase(tail -> prev -> key);
            deleteNode(tail -> prev);
        }

        addNode(new Node(key, value));
        m[key] = head -> next;
    }
};


// using the mutexes 
class LRUCache2 {

public:

    class Node2{
        public: 
            int key;
            int val;
            Node2* prev;
            Node2* next;

            Node2(int key, int val){
                this->key = key;
                this->val = val;
                prev = nullptr;
                next = nullptr;
            }
    };
    int cap;
    std::mutex mu;
    std::unordered_map<int, Node2*> m;

    Node2* head = new Node2(-1, -1);
    Node2* tail = new Node2(-1, -1);
    mutable std::mutex mut; // mutable keyword is used to modify the value of a const object
    // std::mutex mu2; // this is a normal mutex which is not mutable i.e it can't be modified

    LRUCache2(int capacity) {
        cap = capacity;
        head -> next = tail;
        tail -> prev = head;
    }

    void addNode(Node2* newnode){
        Node2* temp = head->next;

        newnode->next = temp;
        newnode->prev = head;

        head->next = newnode;
        temp->prev = newnode;
    }

    void deleteNode(Node2* newnode){
        Node2* prevv = newnode->prev;
        Node2* nextt = newnode->next;

        prevv->next = nextt;
        nextt->prev = prevv;
    }

    int get(int key){
        std::unique_lock<std::mutex> lock(mut);

        if(m.find(key)!=m.end()){
            int ans = m[key]->val;
            Node2* nodd = m[key];
            m.erase(key);
            deleteNode(nodd);
            addNode(new Node2(key,ans));
            m[key] = head->next;
            return ans;
        }
        return -1;
    }

    void put(int key , int val){
        std::unique_lock<std::mutex> lock(mut);
        if(m.find(key)!=m.end()){
            Node2* nodd = m[key];
            m.erase(key);
            deleteNode(nodd);
        }

        if(m.size() == cap){
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addNode(new Node2(key,val));
        m[key] = head->next;
    }
};