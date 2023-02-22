#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
        int key, value;
        Node *prev, *next;
        Node(int key, int value){
            this->key = key;
            this->value = value;
        }
};
Node* head = new Node(0, 0);
Node* tail = new Node(0, 0);

int cap;
unordered_map<int, Node*> mp;

LRUCache(int capacity) {
    cap = capacity;
    head->next = tail;
    tail->prev = head;
}
void deleteNode(Node* node){
    Node* delnode = node->prev;
    Node* delnext = node->next;
    delnode->next = delnext;
    delnext->prev = delnode;
}
void addNode(Node* new_node){
    Node* temp = head->next;
    new_node->next = temp;
    new_node->prev = head;
    head->next = new_node;
    temp->prev = new_node;
}
int get(int key) {
    if(mp.find(key) != mp.end()){
        Node* new_node = mp[key];
        int res = new_node->value;
        mp.erase(key);
        deleteNode(new_node);
        addNode(new_node);
        mp[key] = head->next;
        return res;
    }
    return -1;
}
void put(int key, int value) {
    if(mp.find(key) != mp.end()){
        Node* new_node = mp[key];
        mp.erase(key);
        deleteNode(new_node);
    }
    if(mp.size() == cap){
        mp.erase(tail->prev->key);
        deleteNode(tail->prev);
    }

    addNode(new Node(key, value));
    mp[key] = head->next;
}
int main(){

}
