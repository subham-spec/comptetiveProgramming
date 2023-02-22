#include <bits/stdc++.h>
using namespace std;
class LFUCache {
public:
    class Node{
        public:
            int key, value, count;
            Node *prev, *next;
            Node(int key, int value){
                this->key = key;
                this->value = value;
                count = 1;
            }
    };
    class List{
        public: 
            int size;
            Node *head, *tail;
            List(){
                head = new Node(0,0);
                tail = new Node(0,0);
                head->next = tail;
                tail->prev = head;
                size = 0;
            }
            void addNode(Node* new_node){
                Node* temp = head->next;
                head->next = new_node;
                new_node->prev = head;
                new_node->next = temp;
                temp->prev = new_node;
                size++;
            }
            void deleteNode(Node* new_node){
                Node* prev = new_node->prev;
                Node* next = new_node->next;
                prev->next = next;
                next->prev = prev;
                size--;
            }
    };

    int cap=0;
    map<int, Node*> mp;
    map<int, List*> freq;
    int minfreq;
    int currsize;

    LFUCache(int capacity) {
        cap = capacity;
        minfreq = 0;
        currsize = 0;    
    }
    void updateFreq(Node* new_node){
        mp.erase(new_node->key);
        freq[new_node->count]->deleteNode(new_node);
        if(new_node->count == minfreq && freq[new_node->count]->size == 0)
            minfreq++;

        List* nextHigher = new List();
        if(freq.find(new_node->count+1) != freq.end())
            nextHigher = freq[new_node->count+1];

        new_node->count += 1;
        nextHigher->addNode(new_node);
        freq[new_node->count] = nextHigher;
        mp[new_node->key] = new_node;
    }
    int get(int key) {
        if(mp.find(key) != mp.end()){
            Node* new_node = mp[key];
            int val = new_node->value;
            updateFreq(new_node);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cap == 0)
            return;
        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            node->value = value;
            updateFreq(node);
        }
        else{
            if(currsize == cap){
                List* list = freq[minfreq];
                mp.erase(list->tail->prev->key);
                freq[minfreq]->deleteNode(list->tail->prev);
                currsize--;
            }
            currsize++;
            minfreq = 1;
            List* listfreq = new List();
            if(freq.find(minfreq) != freq.end())
                listfreq = freq[minfreq];

            Node* node = new Node(key, value);
            listfreq->addNode(node);
            mp[key] = node;
            freq[minfreq] = listfreq;
        }
    }
};

